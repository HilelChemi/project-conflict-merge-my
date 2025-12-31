/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/
#ifdef _WIN32
#endif // _WIN32
#define _CRT_SECURE_NO_WARNINGS
#include "Pipe.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <chrono>
#include "Board.h"
#include "Player.h"
#include <cstring>

using std::cout;
using std::endl;
using std::string;


int main()
{
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return 1;
		}
	}
	
	Board board;
	//Player whitePlayer = Player(true, "", "");
	//Player blackPlayer = Player(false, "", "");
	board.resetBoard();
	board.printBoard();
	bool isWiteTurn = true;
	char msgToGraphics[1024];
	

	msgToGraphics[0] = '\0';
	strcpy(msgToGraphics, (board.getBoardString() + "0").c_str()); // current board + '0' for no check
	cout << "Initial board sent to graphics." << endl;
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	
	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// YOUR CODE
		msgToGraphics[0] = '\0';
		int moveResultCode = Player::pickingMove(board, msgFromGraphics, isWiteTurn);
		strcpy(msgToGraphics, (std::to_string(moveResultCode)).c_str()); // msgToGraphics should contain the result of the operation
		if (moveResultCode == 0 || moveResultCode == 1 || moveResultCode == 8)
		{
			isWiteTurn = !isWiteTurn;
		}


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   
		board.printBoard();
		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
	return 0;
}
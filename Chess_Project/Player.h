#pragma once
#include "Board.h"
#include "Piece.h"
#include <iostream>

class Player
{
	private:
		bool isWhite;
		std::string src;
		std::string dst;

	public:
		Player(bool isWhite, std::string src, std::string dst);
		~Player();
		void pickingMove(Board& board);//inputing leagle move from player and changing src and dst
		void movingPiece(Board& board) ;//moving piece on the board
};

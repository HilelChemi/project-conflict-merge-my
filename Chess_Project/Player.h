#pragma once
#include "Board.h"
#include "Piece.h"
#include <iostream>

class Player
{

	public:
		static int pickingMove(Board& board, std::string move,  bool isWite);//inputing leagle move from player and changing src and dst
		static void movingPiece(Board& board, std::string move, int code); //moving piece on the board
};

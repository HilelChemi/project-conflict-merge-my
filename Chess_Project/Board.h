#pragma once
#include <vector>
#include <string>
#include "Piece.h"
#include "Rook.h"
#include "King.h"
#define BOARD_SIZE 8
class Board
{
	private:
		Piece* board[BOARD_SIZE][BOARD_SIZE];
	public:
		Board();
		~Board();
		void resetBoard();
		std::vector<Piece> getBoard();
		Piece* getPiece(const std::string& position) const;
		void setPiece(Piece* piece, const std::string& position);
		void changeBoard(const std::string& fromPosition, const std::string& toPosition);
		void printBoard() const;
};
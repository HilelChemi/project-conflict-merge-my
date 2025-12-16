#pragma once
#include <vector>
#include <string>
#include "Piece.h"
class Board
{
	private:
		Piece* board[8][8];
	public:
		Board();
		~Board();
		std::vector<Piece> getBoard();
		Piece* getPiece(const std::string& position) const;
		void setPiece(Piece* piece, const std::string& position);
		void changeBoard(const std::string& fromPosition, const std::string& toPosition);
};
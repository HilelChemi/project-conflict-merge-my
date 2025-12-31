#pragma once
#include <vector>
#include <string>
#include "Piece.h"
#include "Board.h"

class Knight : public Piece
{
	public:
		Knight(bool isWhite, int coords[], char symbol);
		~Knight();
		std::vector<std::string> getPossibleMoves(Board& board)  override;
		std::vector<std::string> getAttackMoves( Board& board) override;
		void addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board) override;
};

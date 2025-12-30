#pragma once
#include <Vector>
#include <string>
#include "Piece.h"
#include "Board.h"

class Queen : public Piece
{
	public:
		Queen(bool isWhite, int coords[], char symbol);
		~Queen();
		std::vector<std::string> getPossibleMoves(Board& board)  override;
		std::vector<std::string> getAttackMoves( Board& board) override;
		void addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board) override;
};
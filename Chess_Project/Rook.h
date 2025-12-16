#pragma once
#include <Vector>
#include <string>
#include "Piece.h"

class Rook : public Piece
{
	public:
		Rook(bool isWhite, int coords[], char symbol);
		~Rook();
		std::vector<std::string> getPossibleMoves() const override;
};

#pragma once
#include <Vector>
#include <string>
#include "Piece.h"

class King : public Piece
{
	public:
		King(bool isWhite, int coords[], char symbol);
		~King();
		std::vector<std::string> getPossibleMoves() const override;
};

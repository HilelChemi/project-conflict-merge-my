#pragma once
#include <Vector>
#include <string>
#include "Piece.h"

class Rook : public Piece
{
	public:
		Rook();
		~Rook();
		std::vector<std::string> getPossibleMoves() override;
};

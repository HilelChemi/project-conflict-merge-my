#pragma once
#include <Vector>
#include <string>
#include "Piece.h"

class King : public Piece
{
	public:
		King();
		~King();
		std::vector<std::string> getPossibleMoves() override;
};

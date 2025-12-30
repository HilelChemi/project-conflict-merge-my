#pragma once
#include <Vector>
#include <string>
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{

public:
	Pawn(bool isWhite, int coords[], char symbol);
	~Pawn();
	std::vector<std::string> getPossibleMoves(Board& board)  override;
	std::vector<std::string> getAttackMoves(Board& board) override;
	void addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board) override;
	void addMovesAttack(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board);
};

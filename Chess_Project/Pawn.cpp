#include "Pawn.h"
#include <iostream>

Pawn::Pawn(bool isWhite, int coords[], char symbol) :Piece(isWhite, coords, symbol)
{
}
Pawn::~Pawn()
{
}

std::vector<std::string> Pawn::getPossibleMoves(Board& board)
{
	std::vector<std::string> AttackMoves = getAttackMoves(board);
	std::vector<std::string> possibleMoves;

	std::string current = getCurrentPosition();
	std::string newPos = current;
	int direction = 0;
	if (getIsWhite())
	{
		direction = 1;
	}
	else
	{
		direction = -1;
	}
	newPos[Y] += direction;
	if (canMoveTo(newPos, board))
	{
		addMoves(possibleMoves, newPos, board);//one step forward
		newPos[Y] += direction;
		if ((getIsWhite() && current[Y] == '2')||(!getIsWhite()&&current[Y] == '7'))//check if first turn
		{
			addMoves(possibleMoves, newPos, board);//two steps forward
		}
	}
	newPos = current;
	for (int i = 0; i < AttackMoves.size(); i++)
	{
		if (canMoveTo(AttackMoves[i], board))
		{
			possibleMoves.push_back(AttackMoves[i]);
		}
	}
	return possibleMoves;
}

std::vector<std::string> Pawn::getAttackMoves(Board& board)
{
	int direction = 0;
	if(getIsWhite())
	{
		direction = 1;
	}
	else
	{
		direction = -1;
	}
	std::vector<std::string> possibleMoves;
	std::string current = getCurrentPosition();
	std::string newPos = current;
	
	//attack moves
	newPos[X]++;//attack right
	newPos[Y]+= direction;
	addMovesAttack(possibleMoves, newPos, board);
	newPos[X] -=2;//attack left
	addMovesAttack(possibleMoves, newPos, board);
	return possibleMoves;
}


void Pawn::addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board)
{
	if (newPos[X] <= 'h' && newPos[X] >= 'a' && newPos[Y] <= '8' && newPos[Y] >= '1')//right
	{
		if (board.getPiece(newPos) == nullptr)
		{
			possibleMoves.push_back(newPos);
		}
	}
}
void Pawn::addMovesAttack(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board)
{
	if (newPos[X] <= 'h' && newPos[X] >= 'a' && newPos[Y] <= '8' && newPos[Y] >= '1')//right
	{
		if (board.getPiece(newPos) != nullptr && board.getPiece(newPos)->getIsWhite() != getIsWhite())
		{
			possibleMoves.push_back(newPos);
		}
	}
}


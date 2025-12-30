#include "Pawn.h"

Pawn::Pawn(bool isWhite, int coords[], char symbol) :Piece(isWhite, coords, symbol)
{
	isFirstTurn = true;
}
Pawn::~Pawn()
{
}

std::vector<std::string> Pawn::getPossibleMoves(Board& board)
{
	std::vector<std::string> AttackMoves = getAttackMoves(board);
	std::vector<std::string> possibleMoves;
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
	newPos[Y]+=direction;
	addMoves(possibleMoves, newPos, board);//one step forward
	if(isFirstTurn)//check if first turn
	{
		if (possibleMoves.size() == 1)//check if can move two steps forward
		{
			newPos[Y] +=  direction;
			addMoves(possibleMoves, newPos, board);//two steps forward
		}
	}
	//attack moves
	newPos = current;
	newPos[X]++;//attack right
	newPos[Y]+= direction;
	addMovesAttack(possibleMoves, newPos, board);
	newPos[X] -=2;//attack left
	addMovesAttack(possibleMoves, newPos, board);
	return possibleMoves;
}

void Pawn::changeFirstTurn() 
{
	isFirstTurn = false;
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


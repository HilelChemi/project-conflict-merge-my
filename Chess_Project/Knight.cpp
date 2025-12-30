#include "Knight.h"

Knight::Knight(bool isWhite, int coords[], char symbol) : Piece(isWhite,  coords, symbol)
{
}
Knight::~Knight()
{
}

std::vector<std::string> Knight::getPossibleMoves(Board& board)
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
std::vector<std::string> Knight::getAttackMoves(Board& board)
{
	std::vector<std::string> possibleMoves;
	std::string current = getCurrentPosition();
	std::string newPos = current;
	newPos[X] = current[X] + 2;//right-up
	newPos[Y] = current[Y] + 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] + 2;//right-down
	newPos[Y] = current[Y] - 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] - 2;//left-up
	newPos[Y] = current[Y] + 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] - 2;//left-down
	newPos[Y] = current[Y] - 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] + 1;//up-right
	newPos[Y] = current[Y] + 2;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] - 1;//up-left
	newPos[Y] = current[Y] + 2;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] + 1;//down-right
	newPos[Y] = current[Y] - 2;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] - 1;//down-left
	newPos[Y] = current[Y] - 2;
	addMoves(possibleMoves, newPos, board);
	return possibleMoves;
}

void Knight::addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board)
{
	if (newPos[X] <= 'h' && newPos[X] >= 'a' && newPos[Y] <= '8' && newPos[Y] >= '1')//right
	{
		if (!(board.getPiece(newPos) != nullptr && board.getPiece(newPos)->getIsWhite() == getIsWhite()))
		{
			possibleMoves.push_back(newPos);
		}
	}
}
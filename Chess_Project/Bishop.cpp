#include "Bishop.h"

Bishop::Bishop(bool isWhite, int coords[], char symbol) : Piece(isWhite,  coords, symbol)
{
}
Bishop::~Bishop()
{
}

std::vector<std::string> Bishop::getPossibleMoves(Board& board)
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
std::vector<std::string> Bishop::getAttackMoves(Board& board)
{
	std::vector<std::string> possibleMoves;
	std::string current = getCurrentPosition();
	std::string newPos = current;
	//up-right
	for (int i = current[X], j = current[Y]; i < 'h' && j < '8'; i++, j++)
	{
		newPos[X]++;
		newPos[Y]++;
		addMoves(possibleMoves, newPos, board);
		if (board.getPiece(newPos))//thare is a piece
		{
			break;
		}
	}
	newPos = current;
	//up-left
	for (int i = current[X], j = current[Y]; i > 'a' && j < '8'; i--, j++)
	{
		newPos[X]--;
		newPos[Y]++;
		addMoves(possibleMoves, newPos, board);
		if (board.getPiece(newPos))
		{
			break;
		}
	}
	newPos = current;
	//down-right
	for (int i = current[X], j = current[Y]; i < 'h' && j > '1'; i++, j--)
	{
		newPos[X]++;
		newPos[Y]--;
		addMoves(possibleMoves, newPos, board);
		if (board.getPiece(newPos))
		{
			break;
		}
	}
	newPos = current;
	//down-left
	for (int i = current[X], j = current[Y]; i > 'a' && j > '1'; i--, j--)
	{
		newPos[X]--;
		newPos[Y]--;
		addMoves(possibleMoves, newPos, board);
		if (board.getPiece(newPos))
		{
			break;
		}
	}
	return possibleMoves;
}
void Bishop::addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board)
{
	if (newPos[X] <= 'h' && newPos[X] >= 'a' && newPos[Y] <= '8' && newPos[Y] >= '1')//right
	{
		if (!(board.getPiece(newPos) != nullptr && board.getPiece(newPos)->getIsWhite() == getIsWhite()))
		{
			possibleMoves.push_back(newPos);
		}
	}
}

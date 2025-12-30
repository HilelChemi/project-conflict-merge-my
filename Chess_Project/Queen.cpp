#include "Queen.h"

Queen::Queen(bool isWhite, int coords[], char symbol) : Piece(isWhite,  coords, symbol)
{
}
Queen::~Queen()
{
}
std::vector<std::string> Queen::getPossibleMoves(Board& board)
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

std::vector<std::string> Queen::getAttackMoves(Board& board)
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
	newPos = current;
	for (int i = current[X]; i < 'h'; i++)//right
	{
		newPos[X]++;
		addMoves(possibleMoves, newPos, board);
		if (board.getPiece(newPos))//thare is a piece
		{
			break;
		}
	}
	newPos = current;
	for (int i = current[X]; i > 'a'; i--)//left
	{
		newPos[X]--;
		addMoves(possibleMoves, newPos, board);
		if (board.getPiece(newPos))
		{
			break;
		}
	}
	newPos = current;
	for (int i = current[Y]; i < '8'; i++)//up
	{
		newPos[Y]++;
		addMoves(possibleMoves, newPos, board);
		if (board.getPiece(newPos))
		{
			break;
		}
	}
	newPos = current;
	for (int i = current[Y]; i > '1'; i--)//down
	{
		newPos[Y]--;
		addMoves(possibleMoves, newPos, board);
		if (board.getPiece(newPos))
		{
			break;
		}
	}
	return possibleMoves;
}
void Queen::addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board)
{
	if (newPos[X] <= 'h' && newPos[X] >= 'a' && newPos[Y] <= '8' && newPos[Y] >= '1')//right
	{
		if (!(board.getPiece(newPos) != nullptr && board.getPiece(newPos)->getIsWhite() == getIsWhite()))
		{
			possibleMoves.push_back(newPos);
		}
	}
}
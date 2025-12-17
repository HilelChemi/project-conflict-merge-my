#include "King.h"

King::King(bool isWhite, int coords[], char symbol):Piece( isWhite,  coords, symbol)
{	
}
King::~King()
{
}
std::vector<std::string> King::getPossibleMoves(Board& board) 
{
	std::vector<std::string> AttackMoves = getAttackMoves(board);
	std::vector<std::string> possibleMoves;
	for (int i= 0; i < AttackMoves.size();i++)
	{
		if(canMoveTo(AttackMoves[i],board))
		{
			possibleMoves.push_back(AttackMoves[i]);
		}
	}
	return possibleMoves;
}
std::vector<std::string> King::getAttackMoves(Board& board)
{
	std::vector<std::string> possibleMoves;
	std::string current = getCurrentPosition();
	std::string newPos = current;
	newPos[X] = current[X] + 1;//right
	addMoves (possibleMoves,newPos, board);
	newPos = current;
	newPos[X] = current[X] - 1;//left
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[Y] = current[Y] + 1;//up
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[Y] = current[Y] - 1;//down
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] + 1;//up-right
	newPos[Y] = current[Y] + 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] - 1;//up-left
	newPos[Y] = current[Y] + 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] + 1;//down-right
	newPos[Y] = current[Y] - 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[X] = current[X] - 1;//down-left
	newPos[Y] = current[Y] - 1;
	addMoves(possibleMoves, newPos, board);
	return possibleMoves;
}

void King::addMoves(std::vector<std::string>& possibleMoves,const std::string& newPos, Board& board) 
{
	if (newPos[X] <= 'h'&&newPos[X]>='a'&&newPos[Y]<='8'&&newPos[Y] >= '1')//right
	{
		if (!(board.getPiece(newPos) != nullptr && board.getPiece(newPos)->getIsWhite() == getIsWhite()))
		{
			possibleMoves.push_back(newPos);
		}
	}
}

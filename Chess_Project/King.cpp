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
	newPos[0] = current[0] + 1;//right
	addMoves (possibleMoves,newPos, board);
	newPos = current;
	newPos[0] = current[0] - 1;//left
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[1] = current[1] + 1;//up
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[1] = current[1] - 1;//down
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[0] = current[0] + 1;//up-right
	newPos[1] = current[1] + 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[0] = current[0] - 1;//up-left
	newPos[1] = current[1] + 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[0] = current[0] + 1;//down-right
	newPos[1] = current[1] - 1;
	addMoves(possibleMoves, newPos, board);
	newPos = current;
	newPos[0] = current[0] - 1;//down-left
	newPos[1] = current[1] - 1;
	addMoves(possibleMoves, newPos, board);
	return possibleMoves;
}

void King::addMoves(std::vector<std::string>& possibleMoves,const std::string& newPos, Board& board) 
{
	if (newPos[0] <= 'h'&&newPos[0]>='a'&&newPos[1]<='8'&&newPos[1] >= '1')//right
	{
		if (!(board.getPiece(newPos) != nullptr && board.getPiece(newPos)->getIsWhite() == getIsWhite()))
		{
			possibleMoves.push_back(newPos);
		}
	}
}

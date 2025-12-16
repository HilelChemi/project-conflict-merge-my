#include "King.h"

King::King(bool isWhite, int coords[], char symbol):Piece( isWhite,  coords, symbol)
{	
}
King::~King()
{
}
std::vector<std::string> King::getPossibleMoves() const 
{
	int x = _coords[0];
	int y = _coords[1];
	std::vector<std::string> possibleMoves;
	std::string current = getCurrentPosition();
	std::string newPos = current;
	newPos[0] = current[0] + 1;//right
	if (canMoveTo(newPos))
	{
		possibleMoves.push_back(newPos);
	}
	newPos = current;

}
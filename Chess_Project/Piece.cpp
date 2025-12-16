#include "Piece.h"

Piece::Piece(bool isWhite, int coords[], char symbol) //builder
{
	_isWhite = isWhite;
	_symbol = symbol;
	_coords[0] = coords[0];
	_coords[1] = coords[1];
}
Piece::~Piece()//deconstructor
{
}

std::vector<int> Piece::getCoords(std::string& position) const//get coords from position
{
	std::vector<int> coords(2);
	coords[0] =position[0] - 'a';
	coords[1]= position[1] -  '1';
	return coords;
}

bool Piece::canMoveTo(std::string& newPosition) const//check if can move to new position
{
	std::vector<std::string> moves = getPossibleMoves();
	int i = 0;
	if (newPosition[0] < 'a' || newPosition[0]>'h' || newPosition[1] < '1' || newPosition[1]>'8')
	{
		return false;
	}

	for(i = 0; i < moves.size(); i++)
	{
		if (moves[i] == newPosition)
		{
			return true;
		}
	}
	return false;
}

bool Piece::isKingAttacked() const//check if king is attacked	(check)
{
	//later becuse neeed board info
	return false;
}

std::string Piece::getCurrentPosition()  const//get current position
{
	std::string position = "";
	position += (char)(_coords[0] + 'a');
	position += (char)(_coords[1] + '1');
	return position;
}

void Piece::setCurrentPosition(std::string& newPosition) //set current position
{
	if(canMoveTo(newPosition)==true)
	{
		_coords[0] = newPosition[0] - 'a';
		_coords[1] = newPosition[1] - '1';
	}
	
}

char Piece::getSymbol()  const//get symbol
{
	return _symbol;
}

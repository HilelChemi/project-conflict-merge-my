#include "Piece.h"
Piece::Piece(bool isWhite, int coords[],char symble) {
	this->isWhite = isWhite;
	char symbol = symble;
	this->coords[0] = coords[0];
	this->coords[1] = coords[1];
}
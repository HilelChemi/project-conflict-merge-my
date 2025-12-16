#pragma once
#include <vector>
#include <string>
#include "Board.h"
class Piece {
private:
	char _symbol;
	bool _isWhite;
protected://so son class can exses easely
	int _coords[2];
public:
	Piece(bool isWhite,int coords[],char symble);//builder
	~Piece();//deconstructor
	std::vector<int> getCoords(const std::string& posion) const;//get coords from position
	virtual std::vector<std::string> getPossibleMoves()const;//need to be override
	bool canMoveTo(const std::string& newPosition,  Board& board);//check if can move to new position
	virtual void changeFirstTurn();//only for pawns
	bool isKingAttacked(const Board& board) const;//check if king is attacked	(check)
	std::string getCurrentPosition() const;//get current position
	void setCurrentPosition(const std::string& newPosition,  Board& board);//set current position
	char getSymbol() const;//get symbol
};

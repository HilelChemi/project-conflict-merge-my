#pragma once
#include <vector>
#include <string>
class Piece {
private:
	char _symbol;
	bool _isWhite;
	int _coords[2];
public:
	Piece(bool isWhite,int courds[],char symble);//builder
	~Piece();//deconstructor
	std::vector<int> getCoords(std::string& posion) const;//get coords from position
	virtual std::vector<std::string> getPossibleMoves()const =0;//need to be override
	bool canMoveTo(std::string& newPosition) const;//check if can move to new position
	virtual void changeFirstTurn()=0;//only for pawns
	bool isKingAttacked() const;//check if king is attacked	(check)
	std::string getCurrentPosition() const;//get current position
	void setCurrentPosition(std::string& newPosition);//set current position
	char getSymbol() const;//get symbol
};

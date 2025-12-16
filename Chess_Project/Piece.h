#pragma once
#include <vector>
#include <string>
class Piece {
private:
	char symbol;
	bool isWhite;
	int coords[2];
public:
	Piece(bool isWhite,int courds[],char symble);
	~Piece();
	std::vector<int> getCoords(std::string posion);
	virtual std::vector<std::string> getPossibleMoves();
	bool canMoveTo(std::string newPosition);
	virtual void changeFirstTurn();
	bool isKingAttacked();
	std::string getCurrentPosition();
	void setCurrentPosition(std::string newPosition);
	char getSymbol();
};

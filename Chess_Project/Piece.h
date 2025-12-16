#pragma once
#include <vector>
#include <string>
class Piece {
private:
	char symbol;
	bool isWhite;
	int coords[2];
public:
	Piece(bool isWhite,int courds[]);
	~Piece();
	std::vector<int> getCoords(std::string posion);
	virtual std::vector<std::string> getPossibleMoves();
	bool canMove();
	virtual void changeFirstTurn();
	bool isKingAttaked();
	std::string getCurrentPosition();
	void setCurrentPosition(std::string newPosition);
	char getSymbol();
};

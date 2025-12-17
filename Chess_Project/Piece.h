#pragma once
#include <vector>
#include <string>
class Board; 
#define BOARD_SIZE 8
#define X 0
#define Y 1

class Piece 
{
	private:
			char _symbol;
			bool _isWhite;
	protected://so son class can exses easely
		int _coords[2];
	public:
		Piece(bool isWhite,int coords[],char symble);//builder
		~Piece();//deconstructor
		std::vector<int> getCoords(const std::string& posion) const;//get coords from position
		virtual std::vector<std::string> getPossibleMoves(Board& board);//need to be override
		virtual std::vector<std::string> getAttackMoves(Board& board) ; //need to be override
		virtual void addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board);//adding move to attacked moves
		bool canMoveTo(const std::string& newPosition,  Board& board);//check if can move to new position
		virtual void changeFirstTurn();//only for pawns
		bool isKingAttacked( Board& board)const ;//check if king is attacked	(check)
		std::string getCurrentPosition() const;//get current position
		void setCurrentPosition(const std::string& newPosition);//set current position
		char getSymbol() const;//get symbol
		bool getIsWhite() const;//get is white
};

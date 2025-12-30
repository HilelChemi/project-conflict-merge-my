#include "Board.h"
#include <iostream>


Board::Board()
{
	//add pieces to the board
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = nullptr;
		}
	}
}
Board::~Board()
{
	//delete pieces from the board
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] != nullptr)
			{
				delete board[i][j];
			}
		}
	}
}
void Board::resetBoard()
{
	//reset the board to initial position
	int pos[2] = { 0,0 };
	setPiece(new Rook(true, pos, WHITE_ROOK_SYMBOL), "a1");
	pos[X] = 7;
	setPiece(new Rook(true, pos, WHITE_ROOK_SYMBOL), "h1");
	pos[X] = 0;
	pos[Y] = 7;
	setPiece(new Rook(false, pos, BLACK_ROOK_SYMBOL), "a8");
	pos[X] = 7;
	setPiece(new Rook(false, pos, BLACK_ROOK_SYMBOL), "h8");
	pos[Y] = 0;
	pos[X] = 4;
	setPiece(new King(true, pos, WHITE_KING_SYMBOL), "e1");
	pos[X] = 4;
	pos[Y] = 7;
	setPiece(new King(false, pos, BLACK_KING_SYMBOL), "e8");
	pos[X] = 1;
	pos[Y] = 0;
	setPiece(new Knight(true, pos, WHITE_KNIGHT_SYMBOL), "b1");
	pos[X] = 6;
	setPiece(new Knight(true, pos, WHITE_KNIGHT_SYMBOL), "g1");
	pos[X] = 1;
	pos[Y] = 7;
	setPiece(new Knight(false, pos, BLACK_KNIGHT_SYMBOL), "b8");
	pos[X] = 6;
	setPiece(new Knight(false, pos, BLACK_KNIGHT_SYMBOL), "g8");
	pos[X] = 2;
	pos[Y] = 0;
	setPiece(new Bishop(true, pos, WHITE_BISHOP_SYMBOL), "c1");
	pos[X] = 5;
	setPiece(new Bishop(true, pos, WHITE_BISHOP_SYMBOL), "f1");
	pos[X] = 2;
	pos[Y] = 7;
	setPiece(new Bishop(false, pos, BLACK_BISHOP_SYMBOL), "c8");
	pos[X] = 5;
	setPiece(new Bishop(false, pos, BLACK_BISHOP_SYMBOL), "f8");
	pos[X] = 3;
	pos[Y] = 0;
	setPiece(new Queen(true, pos, WHITE_QUEEN_SYMBOL), "d1");
	pos[X] = 3;
	pos[Y] = 7;
	setPiece(new Queen(false, pos, BLACK_QUEEN_SYMBOL), "d8");

}
std::vector<Piece> Board::getBoard()
{
	std::vector<Piece> pieces;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] != nullptr)
			{
				pieces.push_back(*board[i][j]);
			}
		}
	}
	return pieces;
}
Piece* Board::getPiece(const std::string& position) const
{
	int x = position[0] - 'a';
	int y = position[1] - '1';
	return board[x][y];
}
void Board::setPiece(Piece* piece, const std::string& position)
{
	int x = position[0] - 'a';
	int y = position[1] - '1';
	board[x][y] = piece;
}
void Board::changeBoard(const std::string& fromPosition, const std::string& toPosition)
{
	int fromX = fromPosition[0] - 'a';
	int fromY = fromPosition[1] - '1';
	int toX = toPosition[0] - 'a';
	int toY = toPosition[1] - '1';
	board[toX][toY] = board[fromX][fromY];
	board[fromX][fromY] = nullptr;
	board[toX][toY]->setCurrentPosition(toPosition);
}
void Board::printBoard() const
{
	for (int j = BOARD_SIZE - 1; j >= 0; j--)
	{	
		std::cout << j + 1 << " ";
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			if (board[i][j] != nullptr)
			{
				std::cout << board[i][j]->getSymbol() << " ";
			}
			else
			{
				std::cout << VISUAL_BECKROUND<<" ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "  a b c d e f g h" << std::endl;
}

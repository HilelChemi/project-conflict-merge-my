#include "Board.h"
Board::Board()
{
	//add pieces to the board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = nullptr;
		}
	}
}
Board::~Board()
{
	//delete pieces from the board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != nullptr)
			{
				delete board[i][j];
			}
		}
	}
}
std::vector<Piece> Board::getBoard()
{
	std::vector<Piece> pieces;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
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
}

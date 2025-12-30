#pragma once
#include <vector>
#include <string>
#include "Piece.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "Pawn.h"
#define BOARD_SIZE 8
#define VISUAL_BECKROUND '.'
#define WHITE_KING_SYMBOL 'K'
#define BLACK_KING_SYMBOL 'k'
#define WHITE_ROOK_SYMBOL 'R'
#define BLACK_ROOK_SYMBOL 'r'
#define WHITE_KNIGHT_SYMBOL 'N'
#define BLACK_KNIGHT_SYMBOL 'n'
#define WHITE_BISHOP_SYMBOL 'B'
#define BLACK_BISHOP_SYMBOL 'b'
#define WHITE_QUEEN_SYMBOL 'Q'
#define BLACK_QUEEN_SYMBOL 'q'
#define WHITE_PAWN_SYMBOL 'P'
#define BLACK_PAWN_SYMBOL 'p'
class Board
{
	private:
		Piece* board[BOARD_SIZE][BOARD_SIZE];
	public:
		Board();
		~Board();
		void resetBoard();
		std::vector<Piece> getBoard();
		Piece* getPiece(const std::string& position) const;
		void setPiece(Piece* piece, const std::string& position);
		void changeBoard(const std::string& fromPosition, const std::string& toPosition);
		void printBoard() const;
};
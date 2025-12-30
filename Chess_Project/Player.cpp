#include "Player.h"
#include "Piece.h"
#include "Board.h"	
#include <stdio.h>

 int Player::pickingMove(Board& board, std::string move, bool isWite)//0=wite, 1=black
{
	 std::cout << "inside" << std::endl;
	int i = 0;
	int randCoords[] = {-1,-1};
	Piece enemiPiece = Piece(!isWite, randCoords, ' ');
	std::vector<std::string> possibleMoves;
	std::string src;
	std::string dst;
	src = move.substr(0, 2);
	dst = move.substr(2, 2);
	if(dst[X]< 'a' || dst[X]> 'h' || dst[Y] < '1' || dst[Y]>'8' || src[X]< 'a' || src[X]> 'h' || src[Y] < '1' || src[Y]>'8')//out of board
		return 5;
	if(dst==src)//src and dst are the same
		return 7;
	std::cout << "not 7" << std::endl;
	if (board.getPiece(src)==nullptr || board.getPiece(src)->getIsWhite() != isWite)//no piece in src or not player's piece
		return 2;
	std::cout << "not 2" << std::endl;
	if (board.getPiece(dst)!= nullptr && board.getPiece(dst)->getIsWhite() == isWite)//dst has player's piece
		return 3;
	std::cout << "not 3" << std::endl;
	if (!board.getPiece(src)->canMoveTo(dst, board))//piece can't move to dst because king is attacked after the move
		return 4;
	std::cout << "not 4" << std::endl;
	possibleMoves = board.getPiece(src)->getPossibleMoves(board);
	std::cout << "possible moves size: " << possibleMoves.size() << std::endl;
	for( i=0;i< possibleMoves.size();i++)
	{
		std::cout << "possible move: " << possibleMoves[i] << " dst = "<<dst<<std::endl;
		if (possibleMoves[i] == dst)//legal move
		{
			i=-1;
			break;
		}
	}
	std::cout << "possible moves size: " << possibleMoves.size() << std::endl;
	if(i!=-1)//illegal move
	{
		std::cout << "i=" <<i<< std::endl;
		return 6;
	}
	std::cout << "not 6" << std::endl;
	
	if (enemiPiece.isKingAttacked(board))//enemy king is attacked
	{
		//check if checkmate return 8
		for(int i=0;i<8*8;i++)//for all board positions
		{
			char x = 'a' + (i % 8);
			char y = '1' + (i / 8);
			std::string pos ="";
			pos += x;
			pos += y;
			Piece* piece = board.getPiece(pos);
			if (piece != nullptr && piece->getIsWhite() != isWite)//if there is an enemy piece
			{
				std::vector<std::string> enemyMoves = piece->getPossibleMoves(board);
				if(enemyMoves.size()!=0)//if enemy piece has possible moves
					return 1;
			}
		}
		return 8; // check if enemy king is in check
	}
	return 0;
	
}
void Player::movingPiece(Board& board, std::string move, int code)
{
	std::string src = move.substr(0, 2);
	std::string dst = move.substr(2, 2);
		board.changeBoard(src, dst);
}
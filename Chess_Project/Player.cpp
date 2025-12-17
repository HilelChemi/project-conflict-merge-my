#include "Player.h"
Player::Player(bool isWhite, std::string src, std::string dst)
{
	this->isWhite = isWhite;
	this->src = src;
	this->dst = dst;
}
Player::~Player()
{
}
void Player::pickingMove(Board& board)
{
	std::string input;
	std::vector<std::string> possibleMoves;
	bool findLeagleMove = false;
	while (!findLeagleMove)
	{
		if(isWhite)
			std::cout << "Enter White move: ";
		else
			std::cout << "Enter Black move: ";
		std::cin >> input;//inputing src,dst
		if(input.length() !=4)
		{
			std::cout << "illeagle input" << std::endl;
			continue;
		}
		src = input.substr(0, 2);
		dst = input.substr(2, 2);
		if (src[X] <= 'h' && src[X] >= 'a' && src[Y] >= '1' && src[Y] <= '8')
		{
			if (board.getPiece(src))
			{
				if (board.getPiece(src)->isKingAttacked(board))
				{
					std::cout << "King is attaked" << std::endl;
				}
				if(board.getPiece(src)->getIsWhite() == isWhite)
				{
					possibleMoves = board.getPiece(src)->getPossibleMoves(board);
					for (int i=0;i<possibleMoves.size();i++)
					{
						if (possibleMoves[i] == dst)
						{
							findLeagleMove = true;
							break;
						}
					}
				}
				else
					std::cout << "thare is opponent piece in thare" << std::endl;
			}
			else 
				std::cout << "thare is no piece in thare" << std::endl;
		}
		else
			std::cout << "illeagle input" << std::endl;
	}
	
}
void Player::movingPiece(Board& board) 
{
	pickingMove(board);
	board.changeBoard(src, dst);
}
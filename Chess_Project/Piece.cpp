#include "Piece.h"

#define BOARD_SIZE 8

Piece::Piece(bool isWhite, int coords[], char symbol) //builder
{
	_isWhite = isWhite;
	_symbol = symbol;
	_coords[0] = coords[0];
	_coords[1] = coords[1];
}
Piece::~Piece()//deconstructor
{
}

std::vector<int> Piece::getCoords(const std::string& position) const//get coords from position
{
	std::vector<int> coords(2);
	coords[0] =position[0] - 'a';
	coords[1]= position[1] -  '1';
	return coords;
}

std::vector<std::string> Piece::getPossibleMoves(Board& board) //need to be override
{
	return std::vector<std::string>();
}

std::vector<std::string> Piece::getAttackMoves(Board& board)
{
	return std::vector<std::string>();
}

void Piece::addMoves(std::vector<std::string>& possibleMoves, const std::string& newPos, Board& board)//adding move to attacked moves
{
	//willBeOverited
 }


bool Piece::canMoveTo(const std::string& newPosition,  Board& board) //check if can move to new position and the king wont be attaked
{
	std::string currentPosition = getCurrentPosition();
	int i = 0;
	if (newPosition[0] < 'a' || newPosition[0]>'h' || newPosition[1] < '1' || newPosition[1]>'8')
	{
		return false;
	}
	if (board.getPiece(newPosition) != nullptr)
	{
		if (board.getPiece(newPosition)->_isWhite == _isWhite)
		{
			return false;
		}
	}
	Piece* savePiece = board.getPiece(newPosition);
	int oldX = _coords[0];
	int oldY = _coords[1];
	board.changeBoard(currentPosition, newPosition);
	_coords[0] = newPosition[0] - 'a';
	_coords[1] = newPosition[1] - '1';
	if (!isKingAttacked(board))
	{
		board.changeBoard(newPosition, currentPosition);
		_coords[0] = oldX;
		_coords[1] = oldY;
		board.setPiece(savePiece, newPosition);
		return true;
	}
	board.changeBoard(newPosition, currentPosition);
	_coords[0] = oldX;
	_coords[1] = oldY;
	board.setPiece(savePiece, newPosition);
	return false;
}
void Piece::changeFirstTurn()//only for pawns
{
	//only for pawns
}

bool Piece::isKingAttacked( Board& board) const//check if king is attacked	(check)
{
	int i = 0;
	int j = 0;
	int z = 0;
	std::vector<std::string> possibleMovesForOponent;
	Piece* king = nullptr;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			Piece* piece = board.getPiece(std::string(1, (char)(i + 'a')) + std::string(1, (char)(j + '1')));
			if(piece != nullptr && piece->_symbol == 'K' && piece->_isWhite == this->_isWhite)
			{
				king = piece;
				break;
			}
		}
	}
	if(!king)
	{
		return false;//king not found
	}
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{	
			Piece* piece = board.getPiece(std::string(1, (char)(i + 'a')) + std::string(1, (char)(j + '1')));
			if (piece != nullptr &&  piece->_isWhite != this->_isWhite)
			{
				possibleMovesForOponent = piece->getAttackMoves(board);
				for (z = 0; z < possibleMovesForOponent.size(); z++)//chaeck if king is attacked
				{
					if (possibleMovesForOponent[z] == king->getCurrentPosition() )
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

std::string Piece::getCurrentPosition()  const//get current position
{
	std::string position = "";
	position += (char)(_coords[0] + 'a');
	position += (char)(_coords[1] + '1');
	return position;
}

void Piece::setCurrentPosition(const std::string& newPosition,  Board& board) //set current position
{
	if(canMoveTo(newPosition, board)==true)
	{
		_coords[0] = newPosition[0] - 'a';
		_coords[1] = newPosition[1] - '1';
	}
	
}

char Piece::getSymbol()  const//get symbol
{
	return _symbol;
}
bool Piece::getIsWhite() const//get is white
{
	return _isWhite;
}

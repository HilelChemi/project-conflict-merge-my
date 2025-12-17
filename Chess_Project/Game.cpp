#include "Game.h"
void Game::startGame()//start the game loop
{
	Board board;
	Player whitePlayer = Player(true, "", "");
	Player blackPlayer = Player(false, "", "");
	Piece whitePiece = Piece(true, new int[2] {0, 0}, 'W');
	Piece blackPiece = Piece(false, new int[2] {0, 0}, 'B');
	board.resetBoard();
	board.printBoard();
	while (true)
	{
		std::cout << "White's turn:" << std::endl;
		whitePlayer.movingPiece(board);
		board.printBoard();
		std::cout << "Black's turn:" << std::endl;
		blackPlayer.movingPiece(board);
		board.printBoard();
		
	}
}
int main()
{
	Game game;
	game.startGame();
	return 0;
}
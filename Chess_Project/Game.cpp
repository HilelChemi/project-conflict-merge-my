#include "Game.h"
void Game::startGame()//start the game loop
{
	Board board;
	Player whitePlayer = Player(true, "", "");
	Player blackPlayer = Player(false, "", "");
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
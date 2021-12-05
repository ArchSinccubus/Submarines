//#include "SubmarineHeader.h"

#include <iostream>
#include <string>
#include <Windows.h>
#include "SubmarineHeader.h"

using namespace std;

Board::Board()
{
<<<<<<< HEAD
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = '.';
		}
	}
}

bool Board::CheckPlacementValidity(int x, int y,int dir, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		if (board[x + (i * dir)][y + (i * (1 - dir))] != '.')
		{
			return true;
		}
	}
	return false;
}

Player::Player()
{
	Ships = 0;
	Score = 0;

	board = *new(Board);
}

Game::Game()
{
	direction = "";
	CurrPlayer = &player1;
	OtherPlayer = &player2;
}
=======
private:
	
	int i, j, xCoordinate, yCoordinate;
	string direction;
	int currShipLength;
>>>>>>> origin/master


<<<<<<< HEAD
void Game::StartGame(void)
{
	StartPickPhase(player1, false);
	StartPickPhase(player2, true);

	isGameOver = false;

	while (!isGameOver)
	{
		cout << "Your Board - " << endl;

		cout << endl;
=======
	bool isGameOver;
	int playerScore, pcScore, currentPlayer;

	Game(bool _isGameOver = false, int zero = 0, string _defString = "h")
	{
		isGameOver = _isGameOver;
		i = zero;
		j = zero;
		xCoordinate = zero;
		yCoordinate = zero;
		direction = _defString;
		currShipLength = 0;
	}

	void StartPickPhase(string board[10][10], int _shipLength)
	{
		//ResetBoardPlayer(board);

		for (;;)
		{
			currShipLength = _shipLength;
>>>>>>> origin/master

		DrawBoardPlayer(player1);

		cout << endl;

<<<<<<< HEAD
		cout << "PC Board - " << endl;
=======
			cout << "You are placing a short ship, with the length: " << currShipLength << endl;
>>>>>>> origin/master

		cout << endl;

		DrawBoardPlayer(player2);

		if (!CurrPlayer->PC)
		{
			cout << endl;

			cout << "Input the X coordinate of missile:\n" << endl;

			cin >> xCoordinate;

			cout << endl;

<<<<<<< HEAD
			cout << "Input the Y coordinate of missile:\n" << endl;
=======
			cout << "Input the Y coordinate for the ship: \n" << endl;
>>>>>>> origin/master

			cin >> yCoordinate;

			cout << endl;
		}
		else
		{
			cout << "The PC is thinking...\n" << endl;
			for (size_t i = 0; i < 3; i++)
			{
				Sleep(1000);
				cout << "." << endl;
			}

			srand(time(NULL));

			xCoordinate = rand() % 9 + 0;
			yCoordinate = rand() % 9 + 0;

		}


		if (OtherPlayer->board.board[xCoordinate][yCoordinate] == 'X')
		{
			OtherPlayer->board.board[xCoordinate][yCoordinate] = '#';

			cout << endl;

			if (!CurrPlayer->PC)
			{
				cout << "You hit one of the pc ships!\n";
			}
			else
			{
				cout << "The PC hit one of your ships!\n";
			}

			cout << endl;

		}
		else
		{
			if (OtherPlayer->board.board[xCoordinate][yCoordinate] == '.')
			{
				OtherPlayer->board.board[xCoordinate][yCoordinate] = '0';
			}

<<<<<<< HEAD
			if (!CurrPlayer->PC)
			{
				cout << "The PC missed!\n";
			}
			else
			{
				cout << "You missed!\n";
			}
=======
			if (SetShipOnBoard(xCoordinate, yCoordinate, direction, currShipLength, board))
			{
				break;
			}
			else
			{
				cout << "Please enter a valid location\n" << endl;

			}

>>>>>>> origin/master
		}


		isGameOver = CheckVictory();
	}
}

<<<<<<< HEAD
bool Game::CheckVictory(void)
{
	for (size_t x = 0; x < BOARD_SIZE; x++)
	{
		for (size_t y = 0; y < BOARD_SIZE; y++)
		{
			if (OtherPlayer->board.board[x][y] == 'X')
			{
				return false;
			}
		}
	}
=======
	void MainGameLoop(string board[10][10], string pcBoard[10][10], string pcBoardHidden[10][10])
	{
		cout << "Your Board - " << endl;

		cout << endl;

		DrawBoardPlayer(board);

		cout << endl;

		cout << "PC Board - " << endl;

		cout << endl;

		DrawBoardPlayer(pcBoard);

		cout << endl;

		cout << "Input the X coordinate of missile:\n" << endl;

		cin >> xCoordinate;

		cout << endl;

		cout << "Input the Y coordinate of missile:\n" << endl;

		cin >> yCoordinate;

		cout << endl;

		if (pcBoardHidden[xCoordinate][yCoordinate] == "$")
		{
			pcBoardHidden[xCoordinate][yCoordinate] = "X";

			pcBoard[xCoordinate][yCoordinate] = "X";

			pcScore--;

			cout << endl;

			cout << "You hit one of the pc ships!\n";

			cout << endl;

		}
		else if (pcBoardHidden[xCoordinate][yCoordinate] == "O")
		{
			pcBoard[xCoordinate][yCoordinate] = "*";
		}
		else
		{
		}

		srand(time(NULL));

		int rndX, rndY;

		rndX = rand() % 9 + 0;
		rndY = rand() % 9 + 0;

		if (board[rndX][rndY] == "$")
		{
			board[rndX][rndY] = "X";

			playerScore--;

			cout << endl;

			cout << "The PC hit one of your ships!\n";

			cout << endl;

		}
		else if (board[rndX][rndY] == "O")
		{
			board[rndX][rndY] = "*";

		}
		else
		{
		}

		if (playerScore == 0)
		{
			cout << "PC WON! Good Luck next time.\n";
			cout << endl;

			isGameOver = true;

		}
		if (pcScore == 0)
		{
			cout << "YOU WON! Well Played.\n";
			cout << endl;

			isGameOver = true;

		}
>>>>>>> origin/master

	return true;
}

void Game::StartPickPhase(Player player, bool PC)
{
	player.PC = PC;

	for (int i = 0; i < sizeof(shipArray); i++)
	{
<<<<<<< HEAD
		if (!PC)
		{
			cout << endl;
=======
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				board[i][j] = "O";
>>>>>>> origin/master

			DrawBoardPlayer(player);

			cout << endl;

			cout << "You are placing a ship, with the length: " << this->shipArray[i] << endl;

			cout << "\nInput the X coordinate for the ship: \n" << endl;

<<<<<<< HEAD
			cin >> xCoordinate;
=======
		for (i = 0; i < 10; i++)
		{
			cout << i << " ";
		}
>>>>>>> origin/master

			cout << endl;

			cout << "Input the Y coordinate for the ship: \n" << endl;

			cin >> yCoordinate;

<<<<<<< HEAD
			cout << endl;
		}
		else
=======
		for (i = 0; i < 10; i++)
>>>>>>> origin/master
		{
			srand(time(NULL));

			xCoordinate = rand() % 9 + 0;
			yCoordinate = rand() % 9 + 0;
		}

		for (;;) {
			cout << "Vertical or horizontal? Type H / V: \n" << endl;

<<<<<<< HEAD
			cin >> direction;

			cout << endl;

			if (direction == "H" || direction == "V" || direction == "h" || direction == "v") {

				if (direction == "H" || direction == "h" && xCoordinate + this->shipArray[i] < BOARD_SIZE && player.board.CheckPlacementValidity(xCoordinate, yCoordinate, true, this->shipArray[i]))
				{
					for (size_t i = 0; i < this->shipArray[i]; i++)
					{
						if (player.board.board[xCoordinate + i][yCoordinate] == '.')
						{
							player.board.board[xCoordinate + i][yCoordinate] = 'X';
						}
					}
				}
				else if (direction == "V" || direction == "v" && yCoordinate + this->shipArray[i] < BOARD_SIZE && player.board.CheckPlacementValidity(xCoordinate, yCoordinate, false, this->shipArray[i]))
				{
					for (size_t i = 0; i < this->shipArray[i]; i++)
					{
						if (player.board.board[xCoordinate][yCoordinate + i] == '.')
						{
							player.board.board[xCoordinate][yCoordinate + i] = 'X';
						}
					}
				}
=======
		for (i = 0; i < 10; i++)
		{
			cout << i << " # ";

			for (j = 0; j < 10; j++)
			{
>>>>>>> origin/master

				break;

			}
			else {

				cout << "Please enter a valid string\n" << endl;
				cin.clear();
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}

		}

	}

<<<<<<< HEAD

}

void Game::ResetBoardPlayer(Player player)
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			player.board.board[x][y] = 0;
		}
	}
}
=======
	// Set ships in random places for pc board.
	void InitPCDrawBoard(string board[10][10], string pcBoard[10][10])
	{
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				board[i][j] = "O";
				pcBoard[i][j] = "O";
			}

		}

	}

	void InitPCBoards(string board[10][10], int _ShipLength)
	{
		int x, y, direction;
		bool isShipPlaced = false;
		int canFitShipCounter = 0;

		srand(time(NULL));

		while (!isShipPlaced)
		{
			x = rand() % (10 - _ShipLength) + 0;
			y = rand() % (10 - _ShipLength) + 0;
			direction = rand() % 2 + 1;

			for (i = 0; i < _ShipLength; i++)
			{
				if (direction == 1)
				{
					if (board[x + i][y] == "O")
					{
						canFitShipCounter++;
					}

				}
				else if (direction == 2)
				{
					if (board[x][y + i] == "O")
					{
						canFitShipCounter++;
					}

				}
>>>>>>> origin/master


<<<<<<< HEAD
void Game::DrawBoardPlayer(Player player)
{
	cout << "    ";
=======
			if (canFitShipCounter == _ShipLength && direction == 1)
			{
				for (int d = 0; d < _ShipLength; d++)
				{
					board[x + d][y] = "$";
				}

				isShipPlaced = true;

			}
			else if (canFitShipCounter == _ShipLength && direction == 2)
			{
				for (int d = 0; d < _ShipLength; d++)
				{
					board[x][y + d] = "$";
				}

				isShipPlaced = true;

			}

			canFitShipCounter = 0;

		}
>>>>>>> origin/master

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << i << " ";
	}

<<<<<<< HEAD
	cout << endl;

	cout << "    ";

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << "#" << " ";
=======
	bool SetShipOnBoard(int x, int y, string direction, int shipLength, string board[10][10])
	{
		int canFitShipCounter = 0;

		for (i = 0; i < shipLength; i++)
		{
			if (direction == "v" || direction == "V")
			{
				if (board[x + i][y] == "O" && x < 11 - shipLength)
				{
					canFitShipCounter++;
				}
				else
				{
					return false;
				}

			}
			else if (direction == "h" || direction == "H")
			{
				if (board[x][y + i] == "O" && y < 11 - shipLength)
				{
					canFitShipCounter++;
				}
				else
				{
					return false;
				}

			}

		}

		if (canFitShipCounter == shipLength && direction == "v" || direction == "V")
		{
			for (int d = 0; d < shipLength; d++)
			{
				board[x + d][y] = "$";
			}

		}
		else if (canFitShipCounter == shipLength && direction == "h" || direction == "H")
		{
			for (int d = 0; d < shipLength; d++)
			{
				board[x][y + d] = "$";
			}

		}

		return true;

>>>>>>> origin/master
	}

	cout << endl;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << i << " # ";

		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (player.PC && player.board.board[i][j] == 'X')
			{
				cout << '.' << " ";
			}
			else
			{
				cout << player.board.board[i][j] << " ";
			}

		}

		cout << endl;

	}
}

void Game::SwitchPlayer(void)
{
<<<<<<< HEAD
	Player* temp = CurrPlayer;
=======
public:
	// Number of cells a ship takes.
	int ShortShip;
	int MediumShip;
	int LongShip;

	int* shipArray = new int[4]{ 3,3,4,5 };

	Ship(int _Short = 3, int _Medium = 4, int _Large = 5)
	{
		ShortShip = _Short;
		MediumShip = _Medium;
		LongShip = _Large;
	}
};
>>>>>>> origin/master

	CurrPlayer = OtherPlayer;
	OtherPlayer = temp;
}

int main()
{
	Game* game = new(Game);


<<<<<<< HEAD

	game->StartGame();
=======
	game.playerScore = 0;
	game.pcScore = 0;

	game.ResetBoardPlayer(board.boardPlayer);
	game.InitPCDrawBoard(board.boardPC, board.boardPCHidden);

	for (int i = 0; i < 4; i++)
	{
		int _shipLength = ship.shipArray[i];

		game.playerScore += _shipLength;
		game.pcScore += _shipLength;

		game.StartPickPhase(board.boardPlayer, _shipLength);

		game.InitPCBoards(board.boardPCHidden, _shipLength);

	}

	cout << "Placing phase over, time to play!\n" << endl;

	system("pause");

	cout << endl;

	while (!game.isGameOver)
	{
		game.MainGameLoop(board.boardPlayer, board.boardPC, board.boardPCHidden);
	}

	return(0);
>>>>>>> origin/master

	delete(game);
}
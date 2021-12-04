//#include "SubmarineHeader.h"

#include <iostream>

using namespace std;

class Game
{
private:
	
	int i, j, xCoordinate, yCoordinate;
	string direction;
	int currShipLength;

public:

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

			DrawBoardPlayer(board);

			cout << endl;

			cout << "You are placing a short ship, with the length: " << currShipLength << endl;

			cout << "\nInput the X coordinate for the ship: \n" << endl;

			cin >> xCoordinate;

			cout << endl;

			cout << "Input the Y coordinate for the ship: \n" << endl;

			cin >> yCoordinate;

			cout << endl;

			for (;;) {
				cout << "Vertical or horizontal? Type H / V: \n" << endl;

				cin >> direction;

				cout << endl;

				if (direction == "H" || direction == "V" || direction == "h" || direction == "v") {

					break;

				}
				else {

					cout << "Please enter a valid string\n" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

				}

			}

			if (SetShipOnBoard(xCoordinate, yCoordinate, direction, currShipLength, board))
			{
				break;
			}
			else
			{
				cout << "Please enter a valid location\n" << endl;

			}

		}


	};

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

	};

	// Array of int where 0 = Empty, 1 = Ship, 2 = Destroyed.
	void ResetBoardPlayer(string board[10][10])
	{
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				board[i][j] = "O";

			}

		}

	};

	// Array of int where 0 = Empty, 1 = Ship, 2 = Destroyed.
	void DrawBoardPlayer(string board[10][10])
	{
		cout << "    ";

		for (i = 0; i < 10; i++)
		{
			cout << i << " ";
		}

		cout << endl;

		cout << "    ";

		for (i = 0; i < 10; i++)
		{
			cout << "#" << " ";
		}

		cout << endl;

		for (i = 0; i < 10; i++)
		{
			cout << i << " # ";

			for (j = 0; j < 10; j++)
			{

				cout << board[i][j] << " ";

			}

			cout << endl;

		}

	};

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

			}

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

	}

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

	}

};

class Board
{
public:
	string boardPlayer[10][10];
	string boardPC[10][10];
	string boardPCHidden[10][10];
};

class Ship
{
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


int main()
{
	Game game;
	Board board;
	Ship ship;

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

}
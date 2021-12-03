//#include "SubmarineHeader.h"

#include <iostream>

using namespace std;

class Game
{
private:
	bool isPickPhaseOver = false;
	bool isGameOver = false;
	int i, j, xCoordinate, yCoordinate;
	string direction;
	int shipArray[4] = { 3,3,4,5 };

public:

	int playerScore, pcScore, currentPlayer;

	void StartPickPhase(string board[10][10])
	{
		ResetBoardPlayer(board);

		for (i = 0; i < 3; i++)
		{
			cout << endl;

			DrawBoardPlayer(board);

			cout << endl;

			cout << "You are placing a short ship, with the length: " << shipArray[i] << endl;

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

		}


	};

	void MainGameLoop()
	{

	};

	// Array of int where 0 = Empty, 1 = Ship, 2 = Destroyed.
	void ResetBoardPlayer(string board[10][10])
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				board[i][j] = "O";

			}

		}

	};

	// Array of int where 0 = Empty, 1 = Ship, 2 = Destroyed.
	void DrawBoardPlayer(string board[10][10])
	{
		cout << "    ";

		for (i = 0; i < 9; i++)
		{
			cout << i << " ";
		}

		cout << endl;

		cout << "    ";

		for (i = 0; i < 9; i++)
		{
			cout << "#" << " ";
		}

		cout << endl;

		for (i = 0; i < 9; i++)
		{
			cout << i << " # ";

			for (j = 0; j < 9; j++)
			{

				cout << board[i][j] << " ";

			}

			cout << endl;

		}

	};

	void InitPCBoard(string board[10][10])
	{


		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{

			}

		}

	}

};

class Player
{
public:

	int Score;

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
	const int ShortShip = 3;
	const int MediumShip = 4;
	const int LongShip = 5;
};


int main()
{
	Game game;
	Board board;
	Ship ship;

	game.StartPickPhase(board.boardPlayer);


}
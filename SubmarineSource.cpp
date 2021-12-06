//#include "SubmarineHeader.h"

#include <iostream>
#include <string>
#include <Windows.h>
#include "SubmarineHeader.h"

using namespace std;

Board::Board()
{
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


void Game::StartGame(void)
{
	StartPickPhase(player1, false);
	StartPickPhase(player2, true);

	isGameOver = false;

	while (!isGameOver)
	{
		cout << "Your Board - " << endl;

		cout << endl;

		DrawBoardPlayer(player1);

		cout << endl;

		cout << "PC Board - " << endl;

		cout << endl;

		DrawBoardPlayer(player2);

		if (!CurrPlayer->PC)
		{
			cout << endl;

			cout << "Input the X coordinate of missile:\n" << endl;

			cin >> xCoordinate;

			cout << endl;

			cout << "Input the Y coordinate of missile:\n" << endl;

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

			if (!CurrPlayer->PC)
			{
				cout << "The PC missed!\n";
			}
			else
			{
				cout << "You missed!\n";
			}
		}


		isGameOver = CheckVictory();
	}
}

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

	return true;
}

void Game::StartPickPhase(Player player, bool PC)
{
	player.PC = PC;

	for (int i = 0; i < sizeof(shipArray); i++)
	{
		if (!PC)
		{
			cout << endl;

			DrawBoardPlayer(player);

			cout << endl;

			cout << "You are placing a ship, with the length: " << this->shipArray[i] << endl;

			cout << "\nInput the X coordinate for the ship: \n" << endl;

			cin >> xCoordinate;

			cout << endl;

			cout << "Input the Y coordinate for the ship: \n" << endl;

			cin >> yCoordinate;

			cout << endl;
		}
		else
		{
			srand(time(NULL));

			xCoordinate = rand() % 9 + 0;
			yCoordinate = rand() % 9 + 0;
		}

		for (;;) {
			cout << "Vertical or horizontal? Type H / V: \n" << endl;

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

				break;

			}
			else {

				cout << "Please enter a valid string\n" << endl;
				cin.clear();
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}

		}

	}


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


void Game::DrawBoardPlayer(Player player)
{
	cout << "    ";

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << i << " ";
	}

	cout << endl;

	cout << "    ";

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << "#" << " ";
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
	Player* temp = CurrPlayer;

	CurrPlayer = OtherPlayer;
	OtherPlayer = temp;
}

int main()
{
	Game* game = new(Game);



	game->StartGame();

	delete(game);
}
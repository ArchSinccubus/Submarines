//#include "SubmarineHeader.h"

#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
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
		if (board[y + (i * (1 - dir))][x + (i * dir)] == 'X')
		{
			return false;
		}
	}
	return true;
}

Player::Player()
{
	Ships = 0;
	Score = 0;

	board = *new(Board);
}

Game::Game()
{
	direction = '\0';
	CurrPlayer = &player1;
	OtherPlayer = &player2;
}


void Game::StartGame(void)
{
	StartPickPhase(&player1, false);
	StartPickPhase(&player2, true);
	/*DrawBoardPlayer(&player2);

	system("pause");
	*/
	



	cout << "Both you and the PC finished setting up your boards!\n";
	system("pause");

	isGameOver = false;

	while (!isGameOver)
	{
		cout << "Your Board - " << endl;

		cout << endl;

		DrawBoardPlayer(&player1);

		cout << endl;

		cout << "PC Board - " << endl;

		cout << endl;

		DrawBoardPlayer(&player2);

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

void Game::StartPickPhase(Player* player, bool PC)
{
	bool PlacedSuccessfully;
	PlacedSuccessfully = false;
	int PCDir;
	player->PC = PC;

	for (int i = 0; i < sizeof(shipArray) / sizeof(int); i++)
	{
		PlacedSuccessfully = false;
		while (!PlacedSuccessfully)
		{
			if (!PC)
			{
				system("CLS");

				cout << endl;

				DrawBoardPlayer(player);

				cout << endl;

				cout << "You are placing a ship, with the length: " << this->shipArray[i] << endl;

				do
				{

					cout << "\nInput the X coordinate for the ship:\n" << endl;

					cin >> xCoordinate;

					while (!cin || !(xCoordinate >= 0 && xCoordinate <= 9))
					{
						cout << "Please enter a valid input\n" << endl;
						cin.clear();
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');

						cin >> xCoordinate;
					}

					cout << endl;

					cout << "Input the Y coordinate for the ship:\n" << endl;

					cin >> yCoordinate;

					while (!cin || !(yCoordinate >= 0 && yCoordinate <= 9))
					{
						cout << "Please enter a valid input\n" << endl;
						cin.clear();
						cin.ignore((numeric_limits<streamsize>::max)(), '\n');

						cin >> yCoordinate;
					}

					if (player->board.board[yCoordinate][xCoordinate] == 'X')
					{
						cout << "This spot already has a ship in it! Please try another spot.\n";
					}
					cout << endl;
				} while (player->board.board[yCoordinate][xCoordinate] == 'X');
			}
			else
			{
				srand(time(NULL));

				do
				{
					xCoordinate = rand() % 10 + 0;
					yCoordinate = rand() % 10 + 0;
				} while (player->board.board[yCoordinate][xCoordinate] == 'X');
			}


			do
			{
				if (!PC)
				{
					cout << "Vertical or horizontal? Type H / V: \n" << endl;

					cin >> direction;

					cout << endl;
				}
				else
				{
					srand(time(NULL));
					PCDir = rand() % 2;

					direction = PCDir ? 'H' : 'V';

				}

					if ((direction == 'V' || direction == 'v') && (yCoordinate + this->shipArray[i] <= BOARD_SIZE) && player->board.CheckPlacementValidity(xCoordinate, yCoordinate, 1, this->shipArray[i]))
					{
						for (size_t j = 0; j < this->shipArray[i]; j++)
						{
							if (player->board.board[yCoordinate + j][xCoordinate] == '.')
							{
								player->board.board[yCoordinate + j][xCoordinate] = 'X';
							}
						}
						PlacedSuccessfully = true;
					}
					else if ((direction == 'H' || direction == 'h') && (xCoordinate + this->shipArray[i] <= BOARD_SIZE) && player->board.CheckPlacementValidity(xCoordinate, yCoordinate, 0, this->shipArray[i]))
					{
						for (size_t j = 0; j < this->shipArray[i]; j++)
						{
							if (player->board.board[yCoordinate][xCoordinate + j] == '.')
							{
								player->board.board[yCoordinate][xCoordinate + j] = 'X';
							}
						}
						PlacedSuccessfully = true;
					}
					else if(!PC)
					{
						if (!(direction == 'H' || direction == 'V' || direction == 'h' || direction == 'v'))
						{
							cout << "Please enter valid input.\n" << endl;
						}
						else
						{
							cout << "The ship you want to place is invalid! Please try again.\n" << endl;
							PlacedSuccessfully = false;
							system("pause");
						}
					}

			} while (!(cin && (direction == 'H' || direction == 'V' || direction == 'h' || direction == 'v')));
		}
	}


}

void Game::ResetBoardPlayer(Player* player)
{
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			player->board.board[x][y] = 0;
		}
	}
}


void Game::DrawBoardPlayer(Player* player)
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
			
			//cout << player->board.board[i][j] << " ";

			/**/
			if (player->PC && player->board.board[i][j] == 'X')
			{
				cout << '.' << " ";
			}
			else
			{
				cout << player->board.board[i][j] << " ";
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
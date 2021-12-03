#pragma once

#define BOARD_SIZE 10;

class Game
{
public:

	Player player1, player2;
	Player* CurrPlayer;
	bool isPickPhaseOver = false;
	bool isGameOver = false;

	void StartGame(void);

};

class Player
{
public:

	int Ships;
	int Score;

};

class Board
{
public:
	int board[10][10];

	bool CheckBoard(void);

	// Array of int where 0 = Empty, 1 = Ship, 2 = Destroyed.
	void DrawBoard(int [10][10]);

};

class Ship
{
public:
	// Number of cells a ship takes.
	const int ShortShip = 3;
	const int MediumShip = 4;
	const int LongShip = 5;

	// If true, ship is horizontal. 
	// If false, ship is vertical.
	bool ShipOriantation;
};
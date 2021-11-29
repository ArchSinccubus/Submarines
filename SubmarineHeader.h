#pragma once

#define BOARD_SIZE 10;

class Game
{
public:

	Player player1, player2;
	Player* CurrPlayer;

	void InitializePlayers(void);
	void StartGame(void);

};

class Player
{
public:
	int Ships;
	int Score;

	void InitializePlayer(void);

};

class Board
{
public:
	bool board[10][10];

	bool CheckBoard(void);
	void DrawBoard(bool[10][10]);

};

class Ship
{
public:
	// Number of cells a ship takes.
	const int ShipLength = 4;
	// If true, ship is horizontal. 
	// If false, ship is vertical.
	bool ShipOriantation;
};
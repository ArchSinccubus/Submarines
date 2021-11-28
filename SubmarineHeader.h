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
	bool board[BOARD_SIZE][BOARD_SIZE];

	bool checkBoard(void);
};
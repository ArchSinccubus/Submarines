#pragma once
#include <string>

constexpr auto BOARD_SIZE = 10;

class Board
{
public:
	// Array of int where 0 = Empty, 1 = Ship, 2 = Destroyed.
	char board[BOARD_SIZE][BOARD_SIZE];

	Board();
	bool CheckPlacementValidity(int, int, int, int);
};

class Player
{
public:
	int Ships;
	int Score;
	bool PC;

	Player();
	Board board;

};

class Game
{
private:
	int xCoordinate, yCoordinate;
    std::string direction;
	bool PC;
	int shipArray[5] = { 2,3,3,4,5 };

public:

	Player player1, player2;
	Player* CurrPlayer;
	Player* OtherPlayer;
	bool isPickPhaseOver = false;
	bool isGameOver = false;

	Game();
	void StartGame(void);
	bool CheckVictory(void);
	void StartPickPhase(Player player, bool PC);
	void ResetBoardPlayer(Player player);
	void DrawBoardPlayer(Player player);
	void SwitchPlayer(void);
};






#pragma once

#include<iostream>
#include<string>
#include<Windows.h>
#include<exception>
#include<stdexcept>

using namespace std;

class Knight;
class Queen;
class King;
class Pawn;
class Bishop;
class Rook;
class Pieces;

enum Player { white, black };

class Game
{
public:
	Game(Player p1, Player p2);
	void play();
	~Game();

private:
	void display();
	void Promote_Pawn(Player obj, string board[][8], int row, int col);
	Player player1, player2;
	bool isPlayer1win;
	bool isPlayer2win;
	char available_move[8][8];
	string board[8][8];
	int row, col;
};

class Pieces
{
public:
	Pieces();
	~Pieces();
	virtual void legal_move(Player obj, int r, int c, char move[][8], string board[][8]) = 0;
};

class Pawn :public  Pieces
{
public:
	Pawn();
	void legal_move(Player obj, int r, int c, char move[][8], string board[][8]);
	~Pawn();
};

class Bishop :public  Pieces
{
public:
	Bishop();
	void legal_move(Player obj, int r, int c, char move[][8], string board[][8]);
	~Bishop();
};

class Rook :public  Pieces
{
public:
	Rook();
	void legal_move(Player obj, int r, int c, char move[][8], string board[][8]);
	~Rook();
};

class Knight :public  Pieces
{
public:
	Knight();
	void legal_move(Player obj, int r, int c, char move[][8], string board[][8]);
	~Knight();
};

class Queen :public  Pieces
{
public:
	Queen();
	void legal_move(Player obj, int r, int c, char move[][8], string board[][8]);
	~Queen();
};

class King :public Pieces
{
public:
	King();
	void legal_move(Player obj, int r, int c, char move[][8], string board[][8]);
	~King();
};
#include "Chess.h"

Game::Game(Player p1, Player p2)
{
	isPlayer1win = false;
	isPlayer2win = false;
	player1 = p1;
	player2 = p2;

	for (int x = 2; x < 6; ++x)
	{
		for (int j = 0; j < 8; j++)
		{
			board[x][j] = "  ";
		}
	}

	board[0][0] = "bR";
	board[0][1] = "bN";
	board[0][2] = "bB";
	board[0][3] = "bQ";
	board[0][4] = "bK";
	board[0][5] = "bB";
	board[0][6] = "bN";
	board[0][7] = "bR";
	board[1][0] = "bP";
	board[1][1] = "bP";
	board[1][2] = "bP";
	board[1][3] = "bP";
	board[1][4] = "bP";
	board[1][5] = "bP";
	board[1][6] = "bP";
	board[1][7] = "bP";
	
	board[7][0] = "wr";
	board[7][1] = "wn";
	board[7][2] = "wb";
	board[7][3] = "wk";
	board[7][4] = "wq";
	board[7][5] = "wb";
	board[7][6] = "wn";
	board[7][7] = "wr";
	board[6][0] = "wp";
	board[6][1] = "wp";
	board[6][2] = "wp";
	board[6][3] = "wp";
	board[6][4] = "wp";
	board[6][5] = "wp";
	board[6][6] = "wp";
	board[6][7] = "wp";
}

Game::~Game()
{

}

void Game::play()
{
	Pawn P; Queen Q; King K; Knight N; Rook R; Bishop B;
	Pieces* piece;
	bool iswhitemove = true, isblackmove = false;
	string temp;
	while (!(isPlayer1win || isPlayer2win))
	{
		for (int n = 0; n < 8; ++n)
		{
			for (int k = 0; k < 8; ++k)
				available_move[n][k] = 'N';
		}
		system("cls");
		display();
		while (iswhitemove) {
			cout << "Enter row column to select a WHITE piece : ";

			while (!(cin >> row >> col))
			{
				cout << "\a...BAD INPUT...\nPlease enter correct move : \n";
				cin.clear();
				cin.ignore();
			}


			if (row > 7 || row < 0 || col>7 || col < 0)
			{
				cout << "\nPlease enter correct move : \n";
				continue;
			}

			temp = board[row][col];

			if (temp[0] != 'w')
			{
				cout << "please select correct piece : \n";
				continue;
			}
			else
			{
				break;
			}
		}

		while (isblackmove)
		{
			cout << "Enter row column to select a BLACK piece : ";
			while (!(cin >> row >> col))
			{
				cout << "\a...BAD INPUT...\nPlease enter correct move : \n";
				cin.clear();
				cin.ignore();
			}

			if (row < 0 || row>7 || col < 0 || col>7)
			{
				cout << "\nPlease enter correct move : \n";
				continue;
			}

			temp = board[row][col];

			if (temp[0] != 'b')
			{
				cout << "please select correct piece : \n";
				continue;
			}
			else
			{
				break;
			}
		}

		switch (temp[1])
		{
		case 'p':
			piece = &P;
			piece->legal_move(player1, row, col, available_move, board);
			break;

		case 'P':
			piece = &P;
			piece->legal_move(player2, row, col, available_move, board);
			break;

		case 'b':
			piece = &B;
			piece->legal_move(player1, row, col, available_move, board);
			break;

		case 'B':
			piece = &B;
			piece->legal_move(player2, row, col, available_move, board);
			break;

		case 'r':
			piece = &R;
			piece->legal_move(player1, row, col, available_move, board);
			break;

		case 'R':
			piece = &R;
			piece->legal_move(player2, row, col, available_move, board);
			break;

		case 'q':
			piece = &Q;
			piece->legal_move(player1, row, col, available_move, board);
			break;

		case 'Q':
			piece = &Q;
			piece->legal_move(player2, row, col, available_move, board);
			break;

		case 'k':
			piece = &K;
			piece->legal_move(player1, row, col, available_move, board);
			break;

		case 'K':
			piece = &K;
			piece->legal_move(player2, row, col, available_move, board);
			break;

		case 'n':
			piece = &N;
			piece->legal_move(player1, row, col, available_move, board);
			break;

		case 'N':
			piece = &N;
			piece->legal_move(player2, row, col, available_move, board);
			break;

		default:
			continue;
		}

		bool ismove = false;

		for (int x = 0; x < 8; ++x)
		{
			for (int y = 0; y < 8; ++y)
			{
				if (available_move[x][y] == 'L')
				{
					ismove = true;
					break;
				}
			}
		}

		if (!ismove)
		{
			cout << "No move available for this piece please select another piece ..\n";
			system("pause");
			continue;
		}

		system("cls");
		display();
		string z = " ";
		cin.clear(); cin.ignore();
		cout << "To make move enter c : \nTo select another piece enter p : \n";
		getline(cin, z);
		if (z[0] == 'p' || z[0] == 'P')
			continue;

		bool make_move = true;

		while (make_move)
		{
			cout << "Enter row col to move : ";
			int r_, c_;
			while (!(cin >> r_ >> c_))
			{
				cout << "\a...BAD INPUT...\nPlease enter correct move : \n";
				cin.clear();
				cin.ignore();
			}

			if (available_move[r_][c_] == 'L')
			{
				make_move = false;
				string temp = board[row][col];

				if (board[r_][c_] == "wk" && temp[0] == 'b')
				{
					isPlayer2win = true;;
					board[r_][c_] = board[row][col];
					board[row][col] = "  ";
					display();
				}

				if (board[r_][c_] == "bK" && temp[0] == 'w')
				{
					isPlayer1win = true;
					board[r_][c_] = board[row][col];
					board[row][col] = "  ";
					display();
				}

				board[r_][c_] = board[row][col];
				board[row][col] = "  ";

				if (r_ == 0 && iswhitemove && board[r_][c_] == "wp")
				{
					Promote_Pawn(white, board, r_, c_);
				}

				if (r_ == 7 && isblackmove && board[r_][c_] == "bP")
				{
					Promote_Pawn(black, board, r_, c_);
				}
			}
			else
			{
				continue;
			}
		}

		if (iswhitemove)
		{
			iswhitemove = false;
			isblackmove = true;
		}

		else
			if (isblackmove)
			{
				isblackmove = false;
				iswhitemove = true;
			}
	}

	if (isPlayer1win)
	{
		cout << "\nGAME OVER\nPlayer1 White wins \n";
	}

	if (isPlayer2win)
	{
		cout << "\nGAME OVER\nPlayer2 Black wins \n";
	}
}

void Game::Promote_Pawn(Player obj, string board[][8], int row, int col)
{
	bool isPromoted = true;

	while (isPromoted) {
		cin.ignore();
		cin.clear();
		cout << "\nPromote Pawn...\nEnter R for rook ,Q for queen ,B for bisop ,K for knight : \n";
		string n = " ";
		getline(cin, n);

		switch (n[0])
		{
		case 'R':
		case 'r':
			if (obj == white)
				board[row][col] = "wr";
			else
				if (obj == black)
					board[row][col] = "bR";
			isPromoted = false;
			break;

		case 'Q':
		case 'q':
			if (obj == white)
				board[row][col] = "wq";
			else
				if (obj == black)
					board[row][col] = "bQ";
			isPromoted = false;
			break;

		case 'B':
		case 'b':
			if (obj == white)
				board[row][col] = "wb";
			else
				if (obj == black)
					board[row][col] = "bB";
			isPromoted = false;
			break;

		case 'K':
		case 'k':
			if (obj == white)
				board[row][col] = "wk";
			else
				if (obj == black)
					board[row][col] = "bK";
			isPromoted = false;
			break;

		default:
			cout << "You have not selected correct option ..\n";
			continue;
		}
	}
}

void Game::display()
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char t = 254u;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 13);
	cout << "   ";

	for (int x = 0; x < 8; ++x)
		cout << "   " << x << "   ";
	cout << endl;

	SetConsoleTextAttribute(hConsole, 11);
	cout << "  =========================================================";
	cout << endl;

	for (int x = 0; x < 8; ++x)
	{
		SetConsoleTextAttribute(hConsole, 13);
		cout << x << " ";
		SetConsoleTextAttribute(hConsole, 68);
		cout << "|";
		SetConsoleTextAttribute(hConsole, 12);

		for (int j = 0; j < 8; ++j)
		{
			string temp = board[x][j];

			if (available_move[x][j] == 'L')
			{

				SetConsoleTextAttribute(hConsole, 100);

				if (board[x][j] == "  ")
				{
					cout << "   " << t << "  |";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 200);
					cout << "   " << board[x][j] << " |";
				}
			}
			else
				if (temp[0] == 'w')
				{
					SetConsoleTextAttribute(hConsole, 15);
					cout << "  " << board[x][j] << "  ";
					SetConsoleTextAttribute(hConsole, 68);
					cout << "|";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << "  " << board[x][j] << "  ";
					SetConsoleTextAttribute(hConsole, 68);
					cout << "|";
				}
		}
		SetConsoleTextAttribute(hConsole, 13);
		cout << x << endl;
		SetConsoleTextAttribute(hConsole, 11);
		cout << "  =========================================================\n";
	}

	cout << "  ";

	for (int x = 0; x < 8; ++x)
	{
		SetConsoleTextAttribute(hConsole, 13);
		cout << "   " << x << "   ";
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
}

Pieces::Pieces()
{

}

Pieces::~Pieces()
{
}

Pawn::Pawn()
{
}

void Pawn::legal_move(Player obj, int r, int c, char move[][8], string board[][8])
{
	if (obj == white)
	{
		if (r == 0)
			return;

		string temp = board[r - 1][c];

		if (temp == "  " || temp[0] == 'b')
			move[r - 1][c] = 'L';

		if (r != 1 && board[r - 2][c] == "  " && board[r - 1][c] == "  ")
		{
			move[r - 2][c] = 'L';
		}
		//diagonal up right
		if (c == 0)
		{
			temp = board[r - 1][c + 1];
			if (temp[0] == 'b')
			{
				move[r - 1][c + 1] = 'L';
			}
			return;
		}
		//diagonal up left
		if (c == 7)
		{
			temp = board[r - 1][c - 1];
			if (temp[0] == 'b')
			{
				move[r - 1][c - 1] = 'L';
			}
			return;
		}
	}
	else
		if (obj == black)
		{
			if (r == 7)
				return;
			string temp = board[r + 1][c];
			if (temp == "  " || temp[0] == 'w')
				move[r + 1][c] = 'L';
			if (r != 6 && board[r + 2][c] == "  " && board[r + 1][c] == "  ")
			{
				move[r + 2][c] = 'L';
			}
			//diagonal down right
			if (c == 0)
				return;
			temp = board[r + 1][c - 1];
			if (temp[0] == 'w')
			{
				move[r + 1][c - 1] = 'L';
			}
			//diagonal down left
			if (c == 7)
				return;
			temp = board[r + 1][c + 1];
			if (temp[0] == 'w')
			{
				move[r + 1][c + 1] = 'L';
			}

		}
}

Pawn::~Pawn()
{
}

Bishop::Bishop()
{
}

void Bishop::legal_move(Player obj, int row, int col, char move[][8], string board[][8])
{
	string temp = "";

	if (obj == white || obj == black)
	{
		bool diagupright = true;
		bool diagupleft = true;
		bool diagdownright = true;
		bool diagdownleft = true;

		try {
			int r = row, c = col;
			while (diagupright)
			{
				if (r == 0 || c == 0)
					break;
				r = r - 1;
				c = c - 1;
				if (r == 0 || c == 0)
					diagupright = false;
				temp = board[r][c];
				if (board[r][c] == "  ")
				{
					move[r][c] = 'L';
				}
				if (obj == white && temp[0] == 'b')
				{
					move[r][c] = 'L';
					diagupright = false;
					break;
				}
				if (obj == white && temp[0] == 'w')
				{
					diagupright = false;
					break;
				}
				if (obj == black && temp[0] == 'w')
				{
					move[r][c] = 'L';
					diagupright = false;
					break;
				}
				if (obj == black && temp[0] == 'b')
				{
					diagupright = false;
					break;
				}
			}
		}
		catch (...)
		{
			cout << "\nexception diagnol up right\n";
			system("pause");
		}
		try {
			int r = row, c = col;
			while (diagupleft)
			{
				if (r == 0 || c == 7)
					break;
				r = r - 1;
				c = c + 1;
				if (r == 0 || c == 7)
					diagupleft = false;
				temp = board[r][c];
				if (board[r][c] == "  ")
				{
					move[r][c] = 'L';
				}
				if (obj == white && temp[0] == 'b')
				{
					move[r][c] = 'L';
					diagupleft = false;
					break;
				}
				if (obj == white && temp[0] == 'w')
				{
					diagupleft = false;
					break;
				}
				if (obj == black && temp[0] == 'w')
				{
					move[r][c] = 'L';
					diagupleft = false;
					break;
				}
				if (obj == black && temp[0] == 'b')
				{
					diagupleft = false;
					break;
				}
			}
		}
		catch (...)
		{
			cout << "\nexcept diag up left\n";
			system("pause");
		}
		try {
			int r = row, c = col;
			while (diagdownright)
			{
				if (r == 7 || c == 0)
					break;
				r = r + 1;
				c = c - 1;
				if (r == 7 || c == 0)
					diagdownright = false;
				temp = board[r][c];
				if (board[r][c] == "  ")
				{
					move[r][c] = 'L';
				}
				if (obj == white && temp[0] == 'b')
				{
					move[r][c] = 'L';
					diagupleft = false;
					break;
				}
				if (obj == white && temp[0] == 'w')
				{
					diagupleft = false;
					break;
				}
				if (obj == black && temp[0] == 'w')
				{
					move[r][c] = 'L';
					diagupleft = false;
					break;
				}
				if (obj == black && temp[0] == 'b')
				{
					diagupleft = false;
					break;
				}
			}
		}
		catch (...)
		{
			cout << "\nexcept diag down right\n";
		}
		try {
			int r = row, c = col;
			while (diagdownleft)
			{
				if (r == 7 || c == 7)
					break;
				r = r + 1;
				c = c + 1;
				if (r == 7 || c == 7)
					diagdownleft = false;
				temp = board[r][c];
				if (board[r][c] == "  ")
				{
					move[r][c] = 'L';
				}
				if (obj == white && temp[0] == 'b')
				{
					move[r][c] = 'L';
					diagdownleft = false;
					break;
				}
				if (obj == white && temp[0] == 'w')
				{
					diagdownleft = false;
					break;
				}
				if (obj == black && temp[0] == 'w')
				{
					move[r][c] = 'L';
					diagdownleft = false;
					break;
				}
				if (obj == black && temp[0] == 'b')
				{
					diagdownleft = false;
					break;
				}
			}
		}
		catch (...)
		{
			cout << "\nexcept down left\n";
		}

	}

}

Bishop::~Bishop()
{

}

Rook::Rook()
{

}

void Rook::legal_move(Player obj, int row, int col, char move[][8], string board[][8])
{
	bool upmove = true;
	bool downmove = true;
	bool leftmove = true;
	bool rightmove = true;
	string temp = "";
	{
		int r = row, c = col;
		while (upmove)
		{
			if (r == 0)
				break;
			r = r - 1;
			if (r == 0)
				upmove = false;
			temp = board[r][c];
			if (board[r][c] == "  ")
			{
				move[r][c] = 'L';
			}
			if (obj == white && temp[0] == 'b')
			{
				move[r][c] = 'L';
				upmove = false;
				break;
			}
			if (obj == white && temp[0] == 'w')
			{
				upmove = false;
				break;
			}
			if (obj == black && temp[0] == 'w')
			{
				move[r][c] = 'L';
				upmove = false;
				break;
			}
			if (obj == black && temp[0] == 'b')
			{
				upmove = false;
				break;
			}
		}
	}
	{
		int r = row, c = col;
		while (downmove)
		{
			if (r == 7)
				break;
			r = r + 1;
			if (r == 7)
				downmove = false;
			temp = board[r][c];
			if (board[r][c] == "  ")
			{
				move[r][c] = 'L';
			}
			if (obj == white && temp[0] == 'b')
			{
				move[r][c] = 'L';
				downmove = false;
				break;
			}
			if (obj == white && temp[0] == 'w')
			{
				downmove = false;
				break;
			}
			if (obj == black && temp[0] == 'w')
			{
				move[r][c] = 'L';
				downmove = false;
				break;
			}
			if (obj == black && temp[0] == 'b')
			{
				downmove = false;
				break;
			}
		}
	}
	{
		int r = row, c = col;
		while (rightmove)
		{
			if (c == 0)
				break;
			c = c - 1;
			if (c == 0)
				rightmove = false;
			temp = board[r][c];
			if (board[r][c] == "  ")
			{
				move[r][c] = 'L';
			}
			if (obj == white && temp[0] == 'b')
			{
				move[r][c] = 'L';
				rightmove = false;
				break;
			}
			if (obj == white && temp[0] == 'w')
			{
				rightmove = false;
				break;
			}
			if (obj == black && temp[0] == 'w')
			{
				move[r][c] = 'L';
				rightmove = false;
				break;
			}
			if (obj == black && temp[0] == 'b')
			{
				rightmove = false;
				break;
			}
		}
	}
	{
		int r = row, c = col;
		while (leftmove)
		{
			if (c == 7)
				break;
			c = c + 1;
			if (c == 7)
				leftmove = false;
			temp = board[r][c];
			if (board[r][c] == "  ")
			{
				move[r][c] = 'L';
			}
			if (obj == white && temp[0] == 'b')
			{
				move[r][c] = 'L';
				leftmove = false;
				break;
			}
			if (obj == white && temp[0] == 'w')
			{
				leftmove = false;
				break;
			}
			if (obj == black && temp[0] == 'w')
			{
				move[r][c] = 'L';
				leftmove = false;
				break;
			}
			if (obj == black && temp[0] == 'b')
			{
				leftmove = false;
				break;
			}
		}
	}
}

Rook::~Rook()
{

}

Knight::Knight()
{

}

void Knight::legal_move(Player obj, int row, int col, char move[][8], string board[][8])
{
	int r = row, c = col;
	string temp = "";
	try {
		if (row == 1 || row == 0 || col == 7)
		{
			throw exception("exception\n");
		}
		r = row - 2; c = col + 1;
		temp = board[r][c];

		if (temp == "  ")
			move[r][c] = 'L';
		else
			throw out_of_range("Out of range");
		if (obj == white && temp[0] == 'b')
			move[r][c] = 'L';
		if (obj == black && temp[0] == 'w')
			move[r][c] = 'L';
	}
	catch (...)
	{
		cout << "\nr-2 , c+1 \n";
	}
	try {
		if (row == 1 || row == 0 || col == 0)
		{
			throw exception(" ");
		}
		r = row - 2, c = col - 1;
		temp = board[r][c];
		//throw out_of_range("Out of range");
		if (temp == "  ")
			move[r][c] = 'L';
		else
			throw out_of_range("Out of range");
		if (obj == white && temp[0] == 'b')
			move[r][c] = 'L';
		if (obj == black && temp[0] == 'w')
			move[r][c] = 'L';

	}
	catch (...)
	{
		cout << "\nr-2,c-1\n";
	}
	try {
		if (row == 0 || col == 0 || col == 1)
		{
			throw exception(" ");
		}
		r = row - 1; c = col - 2;
		temp = board[r][c];
		//throw out_of_range("Out of range");
		if (temp == "  ")
			move[r][c] = 'L';
		else
			throw out_of_range("Out of range");
		if (obj == white && temp[0] == 'b')
			move[r][c] = 'L';
		if (obj == black && temp[0] == 'w')
			move[r][c] = 'L';
	}
	catch (...)
	{
		cout << "\nr-1 ,c-2\n";
	}
	try {
		if (row == 7 || col == 0 || col == 1)
		{
			throw exception(" ");
		}
		r = row + 1; c = col - 2;
		temp = board[r][c];
		//throw out_of_range("Out of range");
		if (temp == "  ")
			move[r][c] = 'L';
		else
			throw out_of_range("Out of range");
		if (obj == white && temp[0] == 'b')
			move[r][c] = 'L';
		if (obj == black && temp[0] == 'w')
			move[r][c] = 'L';
	}
	catch (...)
	{
		cout << "\nr+1,c-2\n";
	}
	try {
		if (row == 7 || row == 6 || col == 0)
		{
			throw exception(" ");
		}
		r = row + 2; c = col - 1;
		temp = board[r][c];
		//throw out_of_range("Out of range");
		if (temp == "  ")
			move[r][c] = 'L';
		else
			throw out_of_range("Out of range");
		if (obj == white && temp[0] == 'b')
			move[r][c] = 'L';
		if (obj == black && temp[0] == 'w')
			move[r][c] = 'L';
	}
	catch (...)
	{
		cout << "\nr+2,c-1\n";

	}
	try {
		if (row == 6 || row == 7 || col == 7)
		{
			throw exception(" ");
		}
		r = row + 2; c = col + 1;
		temp = board[r][c];
		//throw out_of_range("Out of range");
		if (temp == "  ")
			move[r][c] = 'L';
		else
			throw out_of_range("Out of range");
		if (obj == white && temp[0] == 'b')
			move[r][c] = 'L';
		if (obj == black && temp[0] == 'w')
			move[r][c] = 'L';
	}
	catch (...)
	{
		cout << "\nr+2,c+1";
	}
	try {
		if (row == 7 || col == 6 || col == 7)
		{
			throw exception(" ");
		}
		r = row + 1; c = col + 2;
		temp = board[r][c];
		//throw out_of_range("Out of range");
		if (temp == "  ")
			move[r][c] = 'L';
		else
			throw out_of_range("Out of range");
		if (obj == white && temp[0] == 'b')
			move[r][c] = 'L';
		if (obj == black && temp[0] == 'w')
			move[r][c] = 'L';
	}
	catch (...)
	{
		cout << "r+1,c+2\n";
	}
	try {
		if (row == 0 || col == 7 || col == 6)
		{
			throw exception(" ");
		}
		r = row - 1; c = col + 2;
		temp = board[r][c];
		//throw out_of_range("Out of range");
		if (temp == "  ")
			move[r][c] = 'L';
		else
			throw out_of_range("Out of range");
		if (obj == white && temp[0] == 'b')
			move[r][c] = 'L';
		if (obj == black && temp[0] == 'w')
			move[r][c] = 'L';
	}
	catch (...)
	{
		cout << "\nr-1,c+2\n";
	}
}

Knight::~Knight()
{

}

Queen::Queen()
{

}

void Queen::legal_move(Player obj, int r, int c, char move[][8], string board[][8])
{
	Bishop T; Rook T1;
	T.legal_move(obj, r, c, move, board);
	T1.legal_move(obj, r, c, move, board);
}

Queen::~Queen()
{

}

King::King()
{

}

void King::legal_move(Player obj, int r, int c, char move[][8], string board[][8])
{
	string temp = " ";
	for (int x = r - 1; x <= r + 1; ++x)
	{
		for (int y = c - 1; y <= c + 1; ++y)
		{
			try {
				if (x == r && y == c)
					continue;
				if ((r == 0 && x == r - 1) || (r == 7 && x == r + 1) || (c == 0 && y == c - 1) || (c == 7 && y == c + 1))
					continue;

				temp = board[x][y];
				if (board[x][y] == "  ")
					move[x][y] = 'L';
				if (obj == white && temp[0] == 'b')
					move[x][y] = 'L';
				if (obj == black && temp[0] == 'w')
					move[x][y] = 'L';
			}
			catch (...)
			{
				cout << "\nking\n";
			}
		}
	}
}

King::~King()
{

}
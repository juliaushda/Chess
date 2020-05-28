#include"Chess.h"

int main()
{
	try {
		Game game(white, black);
		game.play();
	}
	catch (...)
	{
		cout << "\nunhandled exception occured..\n";
	}
	cout << "\n";
	system("pause");
}


#include <iostream>

using namespace std;
 
class TicTacToe
{
	char  Arr[3][3] = { { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } };
	char player = 'X';
public:

	void Reset()
	{
		for (int c = 0; c < 9; c++)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Arr[i][j] = c + 1;
				}
			}
		}
		print();
	}

	void print()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << Arr[i][j] << "  ";
			}
			cout << "" <<endl <<endl;
		}
	}

	bool move(char space, int c)
	{

		if ((c % 2) == 0)
			player = 'O';
		else
		{
			player = 'X';
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Arr[i][j] != 'O' || Arr[i][j] != 'X')
				{

					if (Arr[i][j] == space)
					{
						Arr[i][j] = player;
						return true;
					}	
				}
				else if (Arr[i][j] != space)
				{
					return false;
				}
			}

		}

		return true;
	}

	char over()
	{

		int counting = 0;
		//checking if the any row contains equal character(Xs/Os)
		if (Arr[0][0] == Arr[0][1] && Arr[0][1]== Arr[0][2])
		{
			if (player == 'X')
				return 'X';
			else
				return 'O';
		}
		else if (Arr[1][0] == Arr[1][1] && Arr[1][1] ==Arr[1][2])
		{
			if (player == 'X')
				return 'X';
			else
				return 'O';
		}
		else if (Arr[2][0] == Arr[2][1] && Arr[2][1] == Arr[2][2])
		{
			if (player == 'X')
				return 'X';
			else
				return 'O';
		}

		//checking if the any column contains equal character(Xs/Os)
		if (Arr[0][0] == Arr[1][0] && Arr[1][0] == Arr[2][0])
		{
			if (player == 'X')
				return 'X';
			else
				return 'O';
		}
		else if (Arr[0][1] == Arr[1][1] && Arr[1][1] == Arr[2][1])
		{
			if (player == 'X')
				return 'X';
			else
				return 'O';
		}
		else if (Arr[0][2] == Arr[1][2] && Arr[1][2] == Arr[2][2])
		{
			if (player == 'X')
				return 'X';
			else
				return 'O';
		}

		//checking along the diagonals
		if (Arr[0][0] == Arr[1][1] && Arr[1][1] == Arr[2][2])
		{
			if (player == 'X')
				return 'X';
			else
				return 'O';
		}
		else if (Arr[2][0] == Arr[1][1] && Arr[1][1] == Arr[0][2])
		{
			if (player == 'X')
				return 'X';
			else
				return 'O';
		}

		//checking if the game is over or not
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Arr[i][j] == 'X' || Arr[i][j] == 'O')
					counting += 1;
				else
					counting = counting;
			}

		}
		if (counting == 9)
			return 'D';
		else if (counting<9)
			return 'P';

		
		return ' ';

	}
};



int main()
{
	TicTacToe Tic;

	char space = ' ';
	Tic.print();

	for (int c = 1; c < 100; c++)
	{
	
		cout << "Your turn to move to the 'VACANT' space number:  ";
		cin >> space;
		system("cls");

		Tic.move(space,c);
		if (Tic.move(space, c) == false)
		{
		cout << "The space is OCCUPIED/NOT VALID!!" << endl;
		}


		Tic.print();

		//Detemining the winner
		if (Tic.over() == 'O')
		{
			cout << "O WON!!" << endl;
			break;
		}
		if (Tic.over() == 'X')
		{
			cout << "X WON!!" << endl;
			break;
		}

		//determing the state of the game
		if (Tic.over() == 'P')
		{
			cout << "GAME IN PROGRESS" << endl;
		}
		if (Tic.over() == 'D')
		{
			cout << "It'S A DRAW '(*_*)'" << endl;
			break;
		}


		cout << endl;
		cout << "Chosen Space: " << space << endl;
		cout <<"LOOP NO: "<< c<< endl << endl;
		
	}
}
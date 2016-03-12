#include <iostream>

using namespace std;
 
class TicTacToe
{
	char  Arr[3][3] = { { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } };

public:

	/*TicTacToe()
	{
		 Arr[3][3]= { { '1', '2', '3' },{ '4', '5', '6' },{ '7', '8', '9' } };
	}
*/
	void print()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << Arr[i][j] << " ";
			}
			cout << "" << endl;
		}
	}
	bool move(char space)
	{
		int cnt = 1;
		char player = 'X';

		if ((cnt % 2) == 0)
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
						Arr[i][j] = player;
				}
				else
				{
					cout << "The space is occuppied!!"<<endl;
					break;

				}
			}

		}
		cnt += 1;
		return false;
	}
};



int main()
{
	TicTacToe Tic;

	char space = ' ';
	Tic.print();

	for (int c = 1; c < 10; c++)
	{
		int cnt=1;
		cout << "Your turn to move to the 'VACANT' space number:  ";
		cin >> space;
		system("cls");

		Tic.move(space);
		Tic.print();
		cout << endl << endl;
		cout << "Chosen Space: " << space << endl;
		cout << cnt << endl;
		cout << cnt << endl;
		cnt += 1;
		
	}	
	

}
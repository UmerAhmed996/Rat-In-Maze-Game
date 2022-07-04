#include"MyStack.h"
#include<time.h>

int** matrix(int** arr, int row, int col);
void Display(int** arr, int row, int col);
void Food(int** arr, int row, int col);
void rat_in_maze(int**arr, int row, int col, MyStack<char> s1);

int main()
{
	MyStack<char> s1;
	int row = 4, col = 4, i1 = 0, i2 = 0;

	int ** arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}


	srand(time(0));
	matrix(arr, row, col);
	Display(arr, row, col);
	Food(arr, row, col);

	cout << "\n\nPlease place the food: ";
	cin >> i1 >> i2;

	arr[i1][i2] = 2;
	Display(arr, row, col);
	rat_in_maze(arr, row, col,s1);


	return 0;
}

int ** matrix(int ** arr, int row, int col)
{
	int random = 0, step = -1;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (step < 1 || (step > 3 && step < 9) || step > 13)
			{
				step++;
				arr[i][j] = 1;
			}

			else if (step >= 2 || step < 4)
			{
				random = (rand() % 2);
				arr[i][j] = random;
				step++;
			}

			else if (step > 10 || step > 13 || step < 15)
			{
				random = (rand() % 2);
				arr[i][j] = random;
				step++;
			}
		}
	}

	arr[1][2] = 0;
	arr[2][2] = 0;

	return arr;
}

void Display(int ** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void Food(int ** arr, int row, int col)
{
	cout << "\n\nAvailable places to display food" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] != 1)
			{
				cout << i + 1 << j + 1 << " ";
			}
		}
		cout << endl;
	}
}

void rat_in_maze(int ** arr, int row, int col, MyStack<char> s1)
{
	char move = '\0';
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			while (cout << "Please enter your move 'R,L,U,D': ")
			{
				cin >> move;

				if (move == 'R')
				{
					if (arr[i][j + 1] == 1 || arr[i][j + 1] == 6)
					{
						arr[i][j++] = 6;
						arr[i][j] = 6;
						s1.push(move);
					}
					else if (arr[i][j + 1] == 2)
					{
						cout << "\nCongratulations" << endl;
						s1.push(move);
						s1.Display();
						i = 4, j = 4;
						break;
					}
					else if (arr[i][j] == -1)
					{
						cout << "NOT ALLOWED CHOOSE ANOTHER" << endl;
					}
					else
					{
						cout << "NOT ALLOWED MOVING BACKWORD" << endl;
						arr[i][j] = -1;
						s1.pop();
					}
					Display(arr, row, col);
				}
				
				else if (move == 'L')
				{
					if (arr[i][j - 1] == 1)
					{
						arr[i][--j] = 6;
						s1.push(move);
					}
					else if (arr[i][j - 1] == 2)
					{
						cout << "\nCongratulations" << endl;
						s1.push(move);
						s1.Display();

						i = 4, j = 4;
						break;
					}
					else if (arr[i][j - 1] == 6)
					{
						arr[i][--j] = 6;
					}
					else
					{
						cout << "NOT ALLOWED MOVING BACKWORD" << endl;
						arr[i][j--] = -1;
						s1.pop();
					}
					Display(arr, row, col);
				}
				else if (move == 'U')
				{
					if (arr[i - 1][j] == 1)
					{
						arr[i--][j] = 6;
						s1.push(move);
					}
					else if (arr[i - 1][j] == 2)
					{
						cout << "\nCongratulations" << endl;
						s1.push(move);
						s1.Display();
						i = 4, j = 4;
						break;
					}
					else if (arr[i - 1][j] == 6)
					{
						cout << "Moving upward" << endl;
						i--;
					}
					else
					{
						cout << "NOT ALLOWED MOVING BACKWORD" << endl;
						arr[i--][j] = -1;
						s1.pop();
					}
					Display(arr, row, col);
				}
				else if (move == 'D')
				{
					if (arr[i+1][j] == 1)
					{
						arr[++i][j] = 6;
						s1.push(move);
					}
					else if (arr[i+1][j] == 2)
					{
						cout << "\nCongratulations" << endl;
						s1.push(move);
						s1.Display();
						i = 4, j = 4;
						break;
					}
					else
					{
						cout << "NOT ALLOWED MOVING BACKWORD" << endl;
						arr[--i][j] = -1;
						s1.pop();
					}
					Display(arr, row, col);
				}
			}
		}
		cout << endl;
	}
}
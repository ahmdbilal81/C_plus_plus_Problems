#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <Windows.h>
using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

char direstions[] = { 'L','T','D','R' };

class ArrangePeople {

	vector<char> data;
	queue<char> Q;
	struct person {
		char gender;
		char direction;

		friend ostream& operator << (ostream& out, person& obj)
		{
			out << obj.gender << "," << obj.direction;
			return out;
		}

	};
	person** DataArray2D;
	int rows, columns;

	void readData(string name)
	{
		ifstream file;
		file.open(name);
		if (file.is_open())
		{
			char person;
			while (!file.eof())
			{
				file >> person;
				if (person != ',')
					data.push_back(person);
			}
			file.close();
		}
		else
			cout << "file cannot be open ! ";


		for (auto i : data)
			Q.push(i);
	}

	bool isSafe(person** arr, int row, int col, person p)
	{
		if (row >= rows || col >= columns)
			return false;
		if (row != 0)
		{
			if (arr[row - 1][col].gender == p.gender || arr[row - 1][col].direction == p.direction)
				return false;
		}
		if (col != 0)
		{
			if (arr[row][col - 1].gender == p.gender || arr[row][col - 1].direction == p.direction)
				return false;
		}
		return true;
	}

	bool checkEven()
	{
		stack<char> males, females;
		for (auto i : data)
		{
			if (i == 'M')
				males.push(i);
			else
				females.push(i);
		}

		if (males.size() == females.size())
			return true;
		return false;
	}

	bool solve(person** board, int x, int y)
	{
		if (Q.empty())
			return true;

		if (x < rows)
		{
			if (y >= columns)
			{
				y = 0;
				x++;
			}
			if (x >= rows)
				return false;
		}

		person p;

		p.gender = Q.front();
		for (int i = 0; i < 4; i++)
		{
			char a = Q.front();
			p.direction = direstions[i];

			if (isSafe(board, x, y, p))
			{
				Q.pop();

				board[x][y] = p;

				if (solve(board, x, y + 1))
					return true;

				if (checkEven())
					i--;

				board[x][y].direction = '.';
				board[x][y].gender = '.';
				Q.push(a);
			}
		}
		return false;
	}

	void Print()
	{
		for (int i = 0; i < columns; i++)
			cout << " " << i << "    ";
		cout << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << DataArray2D[i][j] << " | ";
			}
			cout << endl;
		}
	}


	bool isPrime(int num)
	{
		if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0 || num <= 1)
		{
			return false;
		}
		if (num == 3 || num == 5 || num == 7)
		{
			return true;
		}
		return true;
	}

	void find_row_cols()
	{
		int Size = data.size();
		int numRows = 0, numCol = 0;

		int sqrtSize = (sqrt(Size));

		for (int K = sqrtSize; K > 1; K--)
		{
			if (Size % K == 0)
			{
				numRows = K;
				numCol = Size / K;
				break;
			}
		}

		if (numRows == 0)
		{
			numRows++;
			numCol = Size;
		}
		else if (numRows == 1)
		{
			numRows = Size;
			numCol = 1;
		}
		rows = numRows;
		columns = numCol;
	}

public:

	void StartArranging()
	{
		readData("people.txt");
		int size = data.size();
		SetConsoleTextAttribute(hConsole, 6);
		cout << "We have " << size << " People to arrange. Lets do that\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		if (isPrime(data.size()))
		{
			cout << "Prime number of people cannot be arrange in nxm matrix.\n\n";
			return;
		}

		find_row_cols();

		DataArray2D = new person * [rows];
		for (int i = 0; i < rows; i++)
		{
			DataArray2D[i] = new person[columns];
			for (int j = 0; j < columns; j++)
			{
				DataArray2D[i][j].gender = '.';
				DataArray2D[i][j].direction = '.';
			}
		}

		int k = 0;
		int l = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				DataArray2D[i][j].gender = data[k++];
				DataArray2D[i][j].direction = direstions[l];
				if (k % 2 == 0)
					l++;
				if (l == 3)
					l = 0;
			}
		}
		Print();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				DataArray2D[i][j].gender = '.';
				DataArray2D[i][j].direction = '.';
			}
		}

		cout << endl << endl << endl;
		solve(DataArray2D, 0, 0);
		Print();
	}

	~ArrangePeople()
	{
		for (int i = 0; i < rows; i++)
			delete DataArray2D[i];
		delete DataArray2D;
		data.clear();
	}
};


int main()
{
	ArrangePeople Object;
	Object.StartArranging();
	return 0;
}
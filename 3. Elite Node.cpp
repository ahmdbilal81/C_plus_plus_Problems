#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class node {
public:
	int data;
	node* up;
	node* down;
	node* left;
	node* right;
	node()
	{
		data = 0;
		up = nullptr;
		down = nullptr;
		left = nullptr;
		right = nullptr;
	}
	node(int data)
	{
		this->data = data;
		up = nullptr;
		down = nullptr;
		left = nullptr;
		right = nullptr;
	}
	~node()
	{
		up = down = left = right = nullptr;
	}
};

class maze {

	node* next_node(int row, int column)
	{
		node* temp = start;
		for (int i = 1; i < column; i++)
		{
			temp = temp->right;
		}
		for (int j = 1; j < row; j++)
		{
			temp = temp->down;
		}
		return temp;
	}
public:
	node* start;
	int Total_rows;
	int Total_cols;
	vector<node*> visited_nodes;
	
	maze()
	{
		start = nullptr;
		Total_rows = 0;
		Total_cols = 0;
	}

	void Read(string filename)
	{
		ifstream in;
		
		in.open(filename);
		
		if (in.is_open())
		{
			string line;
			int row = 1,col=1;
			while (getline(in, line))
			{
				istringstream tokenStream(line);
				string values;
				col = 1;
				while (getline(tokenStream, values, ','))
				{
					int num = stoi(values);
					insert(num, row,col);
					col++;
				}
				row++;
			}
			Total_rows = row-1;
			Total_cols = col-1;
		}
		in.close();
	}

	void insert(int data, int row,int col)
	{
		node* newNode = new node(data);
		if (start == nullptr)
		{
			start = newNode;
		}
		else if (row == 1)
		{
			node* curr = start;
			while (curr->right != nullptr)
			{
				curr = curr->right;
			}
			curr->right = newNode;
			newNode->left = curr;
		}
		else
		{
			node* curr = start;
			if (curr->down == nullptr)
			{
				curr->down = newNode;
				newNode->up = curr;
			}
			else			
			{
				while(curr->down != nullptr)
				{
					curr = curr->down;
				}
				if (curr->down == nullptr && col ==1)
				{
					curr->down = newNode;
					newNode->up = curr;
					return;
				}
				while (curr->right != nullptr)
				{
					curr = curr->right;
				}
				curr->right = newNode;
				newNode->left = curr;
				node* temp = curr->up->right;
				temp->down = newNode;
				newNode->up = temp;
			}
		}
	}

	void Print(node* head)
	{
		if (head->left != nullptr && head->up != nullptr)
		{
			cout << "\nGiven node is not a head\n";
			return;
		}
		node* temp = head;
		node* cols = head;

		while (temp != nullptr)
		{
			while (temp != nullptr)
			{
				cout << temp->data << "  ";
				temp = temp->right;
			}
			cout << endl;
			temp = cols->down;
			cols = cols->down;
		}
		temp = cols = nullptr;
	}

	int ClueRow(int data)
	{
		int next = 0;
		while (data>0)
		{
			int remainder = data % 10;
			next += remainder;
			data = data / 10;
		}
		next = next % Total_rows;
		next = next + 1;
		return next;
	}

	int ClueColumn(int data)
	{
		int num = 0;
		while (data > 0)
		{
			data /= 10;
			num++;
		}
		if (num > Total_cols)
			return -1;
		return num;
	}

	node* visited(node* current)
	{
		int current_data = current->data;
		cout << current_data << " -> ";

		if (visited_nodes.size() == 0)
		{
			visited_nodes.push_back(current);
		}
		else {
			for (node* i : visited_nodes)
			{
				if (i == current)
				{
					Elite_node(nullptr);
					return nullptr;
				}
			}
			visited_nodes.push_back(current);
		}

		int row = ClueRow(current_data);
		int col = ClueColumn(current_data);
		if (col == -1)
		{
			cout << "Clue column exceed from matrix : ";
			return nullptr;
		}
		node* next = next_node(row, col);
		if (next == current)
		{
			Elite_node(next);
		    return nullptr;
		}
		return next;
	}

	void Elite_node(node* elite)
	{
		if (elite == nullptr)
		{
			cout << "\n\nElite node not found!!\n\n";
		}
		else {
			cout << "\n\nElite node is : " << elite->data << endl;
		}
	}

	~maze()
	{
		visited_nodes.clear();
		delete start;
		start = nullptr;
	}
};

int main()
{
	string fileName = "Question2.txt";
	maze mazeObj;
	mazeObj.Read(fileName);
	mazeObj.Print(mazeObj.start);

	cout << "\n\n\n\n";
	node* temp = mazeObj.start;
	while (temp != nullptr)
	{
		temp = mazeObj.visited(temp);
	}
	cout << "\n\n\n\n";
}
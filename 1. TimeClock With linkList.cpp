#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

class node {
public:
	node* left;
	node* right;
	node* up;
	node* down;
	node()
	{
		this->left = nullptr;
		this->right = nullptr;
		this->up = nullptr;
		this->down = nullptr;
	}
	~node()
	{
		this->left = nullptr;
		this->right = nullptr;
		this->up = nullptr;
		this->down = nullptr;
	}
};

class linked_list {
	node* start;//top right node
	int* time ;

public:
	linked_list()
	{
		start = nullptr;
		this->time = new int[4];
	}
	linked_list(int data)
	{
		this->time = new int[4];
		start = new node;
		create_list(data);
	}

	void create_list(int data)
	{
		if (data == 1)
		{
			node* rightmiddle = new node;
			node* rightbottom = new node;
			start->down = rightmiddle;
			rightmiddle->up = start;
			rightmiddle->down = rightbottom;
			rightbottom->up = rightmiddle;
		}
		else if (data == 0)
		{
			node* rightmiddle = new node;
			node* rightbotttom = new node;
			node* lefttop = new node;
			node* leftmiddle = new node;
			node* leftbottom = new node;
			this->start->left = lefttop;
			this->start->down = rightmiddle;
			rightmiddle->up = this->start;
			rightmiddle->down = rightbotttom;
			lefttop->right = this->start;
			lefttop->down = leftmiddle;
			leftmiddle->up = lefttop;
			leftmiddle->down = leftbottom;
			leftbottom->right = rightbotttom;
			leftbottom->up = leftmiddle;
			rightbotttom->left = leftbottom;
			rightbotttom->up = rightmiddle;
		}
		else if (data == 2)
		{
			node* lefttop = new node;
			node* leftmiddle = new node;
			node* leftbottom = new node;
			node* rightmiddle = new node;
			node* rightbottom = new node;
			start->left = lefttop;
			start->down = rightmiddle;
			lefttop->right = start;
			rightmiddle->up = start;
			rightmiddle->left = leftmiddle;
			leftmiddle->right = rightmiddle;
			leftmiddle->down = leftbottom;
			leftbottom->up = leftmiddle;
			leftbottom->right = rightbottom;
			rightbottom->left = leftbottom;
		}
		else if (data == 3)
		{
			node* lefttop = new node;
			node* leftmiddle = new node;
			node* leftbottom = new node;
			node* rightmiddle = new node;
			node* rightbottom = new node;
			start->left = lefttop;
			start->down = rightmiddle;
			lefttop->right = start;
			rightmiddle->up = start;
			rightmiddle->left = leftmiddle;
			rightmiddle->down = rightbottom;
			leftmiddle->right = rightmiddle;
			rightbottom->up = rightmiddle;
			rightbottom->left = leftbottom;
			leftbottom->right = rightbottom;
		}
		else if (data == 4)
		{
			node* lefttop = new node;
			node* leftmiddle = new node;
			node* rightmiddle = new node;
			node* rightbottom = new node;
			start->down = rightmiddle;
			lefttop->down = leftmiddle;
			rightmiddle->up = start;
			rightmiddle->left = leftmiddle;
			rightmiddle->down = rightbottom;
			leftmiddle->up = lefttop;
			leftmiddle->right = rightmiddle;
			rightbottom->up = rightmiddle;
		}
		else if (data == 5)
		{
			node* lefttop = new node;
			node* leftmiddle = new node;
			node* leftbottom = new node;
			node* rightmiddle = new node;
			node* rightbottom = new node;
			start->left = lefttop;
			lefttop->right = start;
			lefttop->down = leftmiddle;
			leftmiddle->up = lefttop;
			leftmiddle->right = rightmiddle;
			rightmiddle->left = leftmiddle;
			rightmiddle->down = rightbottom;
			rightbottom->up = rightmiddle;
			rightbottom->left = leftbottom;
			leftbottom->right = rightbottom;
		}
		else if (data == 6)
		{
			node* lefttop = new node;
			node* leftmiddle = new node;
			node* leftbottom = new node;
			node* rightmiddle = new node;
			node* rightbottom = new node;
			start->left = lefttop;
			lefttop->right = start;
			lefttop->down = leftmiddle;
			leftmiddle->up = lefttop;
			leftmiddle->right = rightmiddle;
			leftmiddle->down = leftbottom;
			rightmiddle->left = leftmiddle;
			rightmiddle->down = rightbottom;
			rightbottom->up = rightmiddle;
			rightbottom->left = leftbottom;
			leftbottom->right = rightbottom;
			leftbottom->up = leftmiddle;
		}
		else if (data == 7)
		{
			node* rightmiddle = new node;
			node* rightbottom = new node;
			node* lefttop = new node;
			start->down = rightmiddle;
			start->left = lefttop;
			lefttop->right = start;
			rightmiddle->up = start;
			rightmiddle->down = rightbottom;
			rightbottom->up = rightmiddle;
		}
		else if (data == 8)
		{
			node* rightmiddle = new node;
			node* rightbotttom = new node;
			node* lefttop = new node;
			node* leftmiddle = new node;
			node* leftbottom = new node;
			this->start->left = lefttop;
			this->start->down = rightmiddle;
			rightmiddle->up = this->start;
			rightmiddle->down = rightbotttom;
			rightmiddle->left = leftmiddle;
			lefttop->right = this->start;
			lefttop->down = leftmiddle;
			leftmiddle->up = lefttop;
			leftmiddle->down = leftbottom;
			leftmiddle->right = rightmiddle;
			leftbottom->right = rightbotttom;
			leftbottom->up = leftmiddle;
			rightbotttom->left = leftbottom;
			rightbotttom->up = rightmiddle;


		}
		else if (data == 9)
		{
			node* lefttop = new node;
			node* leftmiddle = new node;
			node* leftbottom = new node;
			node* rightmiddle = new node;
			node* rightbottom = new node;
			start->left = lefttop;
			start->down = rightmiddle;
			lefttop->right = start;
			lefttop->down = leftmiddle;
			rightmiddle->up = start;
			rightmiddle->left = leftmiddle;
			rightmiddle->down = rightbottom;
			leftmiddle->right = rightmiddle;
			leftmiddle->up = lefttop;
			rightbottom->up = rightmiddle;
			rightbottom->left = leftbottom;
			leftbottom->right = rightbottom;
		}
	}

	void gotoxy(short x, short y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	bool vec(vector<node*> &presentnodes,node* current)
	{
		if (current == nullptr)
		{
			return false;
		}
		for (node* i : presentnodes)
		{
			if (i == current)
			{
				return false;
			}
		}
		presentnodes.push_back(current);
		return true;
	}

	void print(linked_list* digit,int col1 , int col2)
	{
		node* temp = digit->start;
		
		vector<node*> presentnodes;
		presentnodes.push_back(temp);		
		
		for (int i = 0; i < presentnodes.size(); i++)
		{
			if (presentnodes[i]->left != nullptr)
			{
				vec(presentnodes, presentnodes[i]->left);
			}

			if (presentnodes[i]->down != nullptr)
			{
				vec(presentnodes, presentnodes[i]->down);
			}

			if (presentnodes[i]->up != nullptr)
			{
				vec(presentnodes, presentnodes[i]->up);
			}

			if (presentnodes[i]->right != nullptr)
			{
				vec(presentnodes, presentnodes[i]->right);
			}
		}
	
		int start_row = 10;
		for (int i=0;i<presentnodes.size();i++)
		{
			if (presentnodes[i]->left != nullptr)
			{
				if (presentnodes[i] == digit->start)
				{
					gotoxy(col1, start_row);
					cout << "***********";
				}
				else if (presentnodes[i]->up == start || presentnodes[i]->down != nullptr)
				{
					gotoxy(col1, start_row + 4);
					cout << "***********";
				}
				else
				{
					gotoxy(col1, start_row + 8);
					cout << "***********";
				}
			}
			else if (presentnodes[i]->right != nullptr)
			{
				if (presentnodes[i]->right == digit->start)
				{
					gotoxy(col1, start_row);
					cout << "***********";
				}
				else if (presentnodes[i]->up != nullptr && presentnodes[i]->down != nullptr)
				{
					gotoxy(col1, start_row + 4);
					cout << "***********";
				}
				else if (presentnodes[i]->right->up == digit->start || presentnodes[i]->right->down != nullptr)
				{
					gotoxy(col1, start_row + 4);
					cout << "***********";
				}
				else
				{
					gotoxy(col1, start_row + 8);
					cout << "***********";
				}
			}

			if (presentnodes[i]->up != nullptr)
			{
				if (presentnodes[i]->up == digit->start)
				{
					gotoxy(col2, start_row);
					cout << "*";
					gotoxy(col2, start_row + 1);
					cout << "*";
					gotoxy(col2, start_row + 2);
					cout << "*";
					gotoxy(col2, start_row + 3);
					cout << "*";
					gotoxy(col2, start_row + 4);
					cout << "*";
				}
				else if (presentnodes[i]->up->up == digit->start)
				{
					gotoxy(col2, start_row + 5);
					cout << "*";
					gotoxy(col2, start_row + 6);
					cout << "*";
					gotoxy(col2, start_row + 7);
					cout << "*";
					gotoxy(col2, start_row + 8);
					cout << "*";
				}
				else if (presentnodes[i]->down != nullptr && presentnodes[i]->up != nullptr && presentnodes[i]->up != digit->start)
				{
					gotoxy(col1, start_row);
					cout << "*";
					gotoxy(col1, start_row + 1);
					cout << "*";
					gotoxy(col1, start_row + 2);
					cout << "*";
					gotoxy(col1, start_row + 3);
					cout << "*";
					gotoxy(col1, start_row + 4);
					cout << "*";
					
				}
				else if (presentnodes[i]->up == nullptr && presentnodes[i]->down != nullptr)
				{
					gotoxy(col1, start_row + 5);
					cout << "*";
					gotoxy(col1, start_row + 6);
					cout << "*";
					gotoxy(col1, start_row + 7);
					cout << "*";
					gotoxy(col1, start_row + 8);
					cout << "*";
				}
				else if (presentnodes[i]->left != nullptr && presentnodes[i]->left->down != nullptr)
				{
					gotoxy(col1, start_row);
					cout << "*";
					gotoxy(col1, start_row + 1);
					cout << "*";
					gotoxy(col1, start_row + 2);
					cout << "*";
					gotoxy(col1, start_row + 3);
					cout << "*";
					gotoxy(col1, start_row + 4);
					cout << "*";
					
				}
				else if (presentnodes[i]->up->up != nullptr)
				{
					gotoxy(col1, start_row + 5);
					cout << "*";
					gotoxy(col1, start_row + 6);
					cout << "*";
					gotoxy(col1, start_row + 7);
					cout << "*";
					gotoxy(col1, start_row + 8);
					cout << "*";
				}
				else if (presentnodes[i]->up->right != nullptr && presentnodes[i]->up->right != digit->start)
				{
					gotoxy(col1, start_row + 5);
					cout << "*";
					gotoxy(col1, start_row + 6);
					cout << "*";
					gotoxy(col1, start_row + 7);
					cout << "*";
					gotoxy(col1, start_row + 8);
					cout << "*";
				}
				else if (presentnodes[i]->up->left != nullptr)
				{
					gotoxy(col2, start_row + 5);
					cout << "*";
					gotoxy(col2, start_row + 6);
					cout << "*";
					gotoxy(col2, start_row + 7);
					cout << "*";
					gotoxy(col2, start_row + 8);
					cout << "*";
				}
				else if (presentnodes[i]->right != nullptr && presentnodes[i]->right->down != nullptr)
				{
					gotoxy(col1, start_row);
					cout << "*";
					gotoxy(col1, start_row + 1);
					cout << "*";
					gotoxy(col1, start_row + 2);
					cout << "*";
					gotoxy(col1, start_row + 3);
					cout << "*";
					gotoxy(col1, start_row + 4);
					cout << "*";
					
				}
			}
		}
		gotoxy(0, 23);
	}

	void inputTime()
	{
		cout << "(format must be 23:23)\nEnter a time : ";
		string time = "";
		cin >> time;
		while (time.length() != 5 || time[2] != ':') {
			cout << "\nInvalid format. Please use HH:MM format: ";
			cin >> time; 
		}
		istringstream tokenStream(time);
		string values;
		int hours=0, minutes=0;
		for (int i = 0; getline(tokenStream, values, ':'); i++)
		{
			if (i == 0)
				hours = stoi(values);
			else
				minutes = stoi(values);
		}
		while (minutes >= 60)
		{
			hours++;
			minutes %= 60;
		}
		while (minutes < 0)
			minutes = minutes + 60;
		this->time[3] = minutes % 10;
		minutes = minutes / 10;
		this->time[2] = minutes;
		if (hours >= 24)
			hours %= 24;
		while (hours < 0)
			hours = 24 + hours;
		this->time[1] = hours % 10;
		hours = hours / 10;
		this->time[0] = hours;
		
	}

	void startcode()
	{
		bool loop = false;
		inputTime();
		int columns[] = { 10,20 ,25,35,40,50,55,65 };
		while(1)
		{	
			cout << "\nTime Represented in linked list is \n\n";

			linked_list* hour_digit_1 = new linked_list(this->time[0]);
			linked_list* hour_digit_2 = new linked_list(this->time[1]);
			linked_list* minutes_digit_1 = new linked_list(this->time[2]);
			linked_list* minutes_digit_2 = new linked_list(this->time[3]);

			print(hour_digit_1, columns[0], columns[1]);
			print(hour_digit_2, columns[2], columns[3]);
			print(minutes_digit_1, columns[4], columns[5]);
			print(minutes_digit_2, columns[6], columns[7]);

			gotoxy(38, 13);
			cout << "*";
			gotoxy(38, 15);
			cout << "*";
			gotoxy(0, 23);
			int choice;
			if (!loop)
			{
				cout << "\n\n1.Apply Functions\n2.Start a loop\n0.Exit\nEnter choice : ";
				cin >> choice;

			}
			else
				choice = 2;
			while (choice < 0 || choice > 2)
				cin >> choice;

			if (choice == 0)
			{
				delete hour_digit_1;
				delete hour_digit_2;
				delete minutes_digit_1;
				delete minutes_digit_2;
				return;
			}
			else if (choice == 2)
			{
				addInLoop(1);
				Sleep(1000);
				loop = true;
				if (_kbhit())//keyboard hit 
				{
					char key = _getch();
					loop = false;
				}
			}
			else
			{
				functionalityMenu();
			}
			system("CLS");
		}
		
	}
	
	void functionalityMenu()
	{
		system("CLS");
		cout << "Following functions can be apply on these lists\n1.Addition of Minutes\n2.Subtraction of Minutes\n3.Addition of Hours\n4.Subtraction of Hours\n\nEnter your choice : ";
		int choice;
		cin >> choice;
		while (choice < 0 || choice > 4)
			cin >> choice;

		if (choice == 1)
		{
			AdditionMinutes();
		}
		else if (choice == 2)
		{
			SubtractMinutes();
		}
		else if (choice == 3)
		{
			AdditionHours();
		}
		else if (choice == 4)
		{
			SubtractHours();
		}
	}

	void AdditionHours()
	{
		cout << "Enter hours to add in time(" << time[0] << time[1] << ":" << time[2] << time[3] << ") :";
		int hour;
		cin >> hour;

		int hours = (time[0] * 10) + time[1];
		int total = hour + hours;
		if (total >= 24)
			total %= 24;

		time[1] = total % 10;
		total = total / 10;
		time[0] = total;
	}

	void SubtractHours()
	{
		cout << "Enter hours to Suubtract from time(" << time[0] << time[1] << ":" << time[2] << time[3] << ") :";
		int hour;
		cin >> hour;

		int hours = (time[0] * 10) + time[1];
		int total = hours - hour;
		while (total < 0)
			total = 24 + total;

		time[1] = total % 10;
		total = total / 10;
		time[0] = total;
	}

	void SubtractMinutes()
	{
		cout << "Enter minutes to subtract from time(" << time[0] << time[1] << ":" << time[2] << time[3] <<") :";
		int minutes;
		cin >> minutes;

		int  mins = (time[2] * 10) + time[3];

		int total = mins - minutes;
		int hour = 0;
		for (int i = 0; total<0; i++)
		{
			hour++;
			total = total + 60;
		}

		time[3] = total % 10;
		total = total / 10;
		time[2] = total;

		int hours = (time[0] * 10) + time[1];
		total = hours - hour;
		while (total < 0)
		{
			total = 24 + total;
		}
		time[1] = total % 10;
		total = total / 10;
		time[0] = total;

	}

	void AdditionMinutes()
	{
		cout << "Enter minutes to add in time(" << time[0] << time[1] << ":" << time[2] << time[3] << ") :";
		int minutes;
		cin >> minutes;

		int  mins = (time[2] * 10) + time[3];

		int total = mins + minutes;
		int hour = 0;
		for (int i = 0; total >= 60; i++)
		{
			hour++;
			total = total - 60;
		}

		time[3] = total % 10;
		total = total / 10;
		time[2] = total;

		int hours = (time[0] * 10) + time[1];
		total = hours + hour;
		if (total >= 24)
		{
			total %= 24;
		}
		time[1] = total % 10;
		total = total / 10;
		time[0] = total;

	}

	void addInLoop(int mins)
	{
		int minutes = (time[2] * 10) + time[3];

		int total = mins + minutes;
		int hour = 0;
		for (int i = 0; total >= 60; i++)
		{
			hour++;
			total = total - 60;
		}

		time[3] = total % 10;
		total = total / 10;
		time[2] = total;

		int hours = (time[0] * 10) + time[1];
		total = hours + hour;
		if (total >= 24)
		{
			total %= 24;
		}
		time[1] = total % 10;
		total = total / 10;
		time[0] = total;

	}

	~linked_list()
	{
		delete time;
		time = nullptr;
		if (start != nullptr)
		{
			node* temp = this->start;
			vector<node*> presentnodes;
			presentnodes.push_back(temp);
			for (int i = 0; i < presentnodes.size(); i++)
			{
				if (presentnodes[i]->left != nullptr)
				{
					vec(presentnodes, presentnodes[i]->left);
				}

				if (presentnodes[i]->down != nullptr)
				{
					vec(presentnodes, presentnodes[i]->down);
				}

				if (presentnodes[i]->up != nullptr)
				{
					vec(presentnodes, presentnodes[i]->up);
				}

				if (presentnodes[i]->right != nullptr)
				{
					vec(presentnodes, presentnodes[i]->right);
				}
			}

			for (int i = 0; i < presentnodes.size(); i++)
			{
				delete presentnodes[i];
			}
		}
		start = nullptr; 
	}
};

int main()
{
	linked_list obj;
	obj.startcode();
	return 0;
}
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Solution{
	
	vector<pair<int, string>> data;
	queue<pair<int, string>> waitingQueue;
	stack<pair<int, string>> submittionStack;
	stack<pair<int, string>> marksStack;
	queue<pair<int, string>> DistributionQueue;


	void PrintVector()
	{
		cout << "All Students Are : \n";
		int k = 0;
		for (auto i : data)
		{
			if (k++ % 3 == 0)
				cout << endl;
			cout << i.first << "  " << i.second << "\t";
		}
	}

	void PrintStack(stack<pair<int,string>> Stack)
	{
		bool found = false;
		while (!Stack.empty())
		{
			if (Stack.top().first == 420)
			{
				SetConsoleTextAttribute(hConsole, 2);
				found = true;
			}
			cout << Stack.top().first << "  " << Stack.top().second << endl;
			Stack.pop();

			if (found)
			{
				found = false;
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
	}

	void PrintQueue(queue<pair<int, string>> Queue)
	{
		bool found = false;
		while (!Queue.empty())
		{
			if (Queue.front().first == 420)
			{
				SetConsoleTextAttribute(hConsole, 2);
				found = true;
			}
			cout << Queue.front().first << " " << Queue.front().second << endl;
			Queue.pop();
			if (found)
			{
				found = false;
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
	}

	int find420()
	{
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i].first == 420)
			{
				return i + 1;
			}
		}
	}

	pair<int, string> getRollNumber(int rollnumber)
	{
		for (auto i : data)
		{
			if (i.first == rollnumber)
			{
				return i;
			}
		}
		pair<int, string> notFound;
		notFound.first = -1;
		return notFound;
	}

	int getTotalNumberofStudents()
	{
		return data.size();
	}

	int find(stack<pair<int, string>> STack,int Rollnumber)
	{
		stack<pair<int, string>> temp;
		for (int i = 1; !STack.empty(); i++)
		{
			pair<int, string> person = STack.top();
			STack.pop();
			temp.push(person);
			if (person.first == Rollnumber)
			{
				return  i;
			}
		}

	}


	
	void readData(string filename)
	{
		ifstream file;
		file.open(filename);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				istringstream tokenString(line);
				string value;
				int rollNumber = -1;
				string name = "";
				for (int i=0;getline(tokenString, value, ',');i++)
				{
					if (i == 0)
					{
						rollNumber = stoi(value);
					}
					else
						name = value;
				}
				if (rollNumber != -1) {
					pair<int, string> student;
					student.first = rollNumber;
					student.second = name;
					data.push_back(student);
				}
			}
			file.close();
		}
		int occuranceOf420 = 0;
		for (auto i : data)
		{
			if (i.first == 420)
			{
				occuranceOf420++;
			}
		}
		if (occuranceOf420 > 1)
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Roll number 420 found in data more than 1 time. so provided data is incorrect \n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else if (occuranceOf420 == 0)
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Roll number 420 not found in data. so provided data is incorrect \n\n";
			SetConsoleTextAttribute(hConsole, 15);
		}

	}
	
	void remove37Percent()
	{
		int thirtySeven = ((float)37 / (float)100) * (float)getTotalNumberofStudents();
		cout << "\nOhh those " << thirtySeven << " students messed all the papers !!!" << endl;
		pair<int, string> person;
		person.first = -1;

		for (int i = 0; i < thirtySeven; i++)
		{
			if (i % 2 == 0) {
				if (marksStack.top().first == 420)
				{
					person = marksStack.top();
					i--;
				}
			}
			
			marksStack.pop();
		}


		if (person.first != -1)
			marksStack.push(person);

		stack<pair<int, string>> temp2,temp;
		for (int i=0;!marksStack.empty();i++)
		{
			if (i % 3 == 0)
			{
				temp2.push(marksStack.top());
			}
			else {
				temp.push(marksStack.top());
			}
			marksStack.pop();
		}

		for (int i =0 ; !temp.empty() || !temp2.empty(); i++)
		{
			if (i % 2 == 0 && !temp.empty())
			{
				marksStack.push(temp.top());
				temp.pop();
			}
			else if (!temp2.empty())
			{
				marksStack.push(temp2.top());
				temp2.pop();
			}
		}

		PrintStack(marksStack);
	}
	
	void Question1()
	{
		//After how many students John received his exam?
		sort(data.begin(), data.end());

		for (auto i : data)
		{
			DistributionQueue.push(i);
		}

		cout << "The distribution of paper in students is in given order \n";
		PrintQueue(DistributionQueue);
		SetConsoleTextAttribute(hConsole, 6);
		cout << "\n\nRoll Number 420 recieved the exam at " << find420() << "th number.\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\nSubmitted Papers : \n";
		PrintStack(submittionStack);
		cout << "\nStudents waiting to submitt: \n";
		PrintQueue(waitingQueue);
		cout << "\nMarked Papers : \n";
		PrintStack(marksStack);
	}

	void Question2()
	{
		//How long John had to wait to submit his exam after completing it

		int threePercent = ((float)3/(float)100) * (float)getTotalNumberofStudents();
		int sixtyNinePercent = ((float)69 / (float)100) * (float)getTotalNumberofStudents();
		pair<int, string> person;
		person.first = -1;

		stack<pair<int, string>> temp1, temp2;
		for (int i = 0; !DistributionQueue.empty(); i++)
		{
			if (i % 2 == 0)
				temp1.push(DistributionQueue.front());
			else
				temp2.push(DistributionQueue.front());
			DistributionQueue.pop();
		}

		for (int i = 0; !temp1.empty() || !temp2.empty(); i++)
		{
			if (i%2==0 && !temp1.empty()) {
				DistributionQueue.push(temp1.top());
				temp1.pop();
			}
			if (!temp2.empty()) {
				DistributionQueue.push(temp2.top());
				temp2.pop();
			}
		}


		//distribution queue has been shuffled so that we can remove sixtyNine percent papers without any order

		for (int i = 0; i < sixtyNinePercent; i++)
		{
			if (DistributionQueue.front().first == 420)
			{
				i--;
				person = DistributionQueue.front();
				DistributionQueue.pop();
			}
			else 
			{
				submittionStack.push(DistributionQueue.front());
				DistributionQueue.pop();
			}
		}

		for (int i = 0; i < threePercent; i++)
		{
			if (DistributionQueue.front().first == 420)
			{
				i--;
				person = DistributionQueue.front();
				DistributionQueue.pop();
			}
			else
			{
				waitingQueue.push(DistributionQueue.front());
				DistributionQueue.pop();
			}
		}

		if (person.first == -1)//not found in first 72 persent
		{
			person = getRollNumber(420);
		}
		waitingQueue.push(person);

		SetConsoleTextAttribute(hConsole, 6);
		cout << "\n\nRollNumber 420 has to wait for " << threePercent << " students to submit paper after completing it\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		cout << "\nSubmitted Papers : \n";
		PrintStack(submittionStack);
		cout << "\nStudents waiting to submitt: \n";
		PrintQueue(waitingQueue);
		cout << "\nMarked Papers : \n";
		PrintStack(marksStack);



		while (!waitingQueue.empty())
		{
			submittionStack.push(waitingQueue.front());
			waitingQueue.pop();
		}

		while (!DistributionQueue.empty())
		{
			if (DistributionQueue.front().first != 420)
				submittionStack.push(DistributionQueue.front());
			DistributionQueue.pop();
		}
	}

	void Question3()
	{
		// At what number was John’s exam placed in the submission stack?
		

		SetConsoleTextAttribute(hConsole, 6);
		cout << "\nRollNumber 420's exam placed in the submission stack at " << find(submittionStack, 420) << " from top or 420 submitted exam at " << (getTotalNumberofStudents() - find(submittionStack,420) + 1) << "th number " << endl;
		SetConsoleTextAttribute(hConsole, 15);

		cout << "\nSubmitted Papers : \n";
		PrintStack(submittionStack);
		cout << "\nStudents waiting to submitt: \n";
		PrintQueue(waitingQueue);
		cout << "\nMarked Papers : \n";
		PrintStack(marksStack);
	}

	void Question4()
	{
		//At what number was John’s exam marked ?

		SetConsoleTextAttribute(hConsole, 6);
		cout << "\nRollNumber exam was marked at " << find(submittionStack,420) << "th position";
		SetConsoleTextAttribute(hConsole, 15);
		while (!submittionStack.empty())
		{
			marksStack.push(submittionStack.top());
			if (marksStack.top().first == 420)
				break;
			submittionStack.pop();
		}
		submittionStack.pop();
		cout << "\nSubmitted Papers : \n";
		PrintStack(submittionStack);
		cout << "\nStudents waiting to submitt: \n";
		PrintQueue(waitingQueue);
		cout << "\nMarked Papers : \n";
		PrintStack(marksStack);
	}

	void Question5()
	{
		//What place John’s exam got in the marked exams stack?
		while (!submittionStack.empty())
		{
			marksStack.push(submittionStack.top());
			submittionStack.pop();
		}
		
		SetConsoleTextAttribute(hConsole, 6);
		cout << "\n\nRollnumber exam got " << find(marksStack, 420) << "th place in marked exams stack " << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\nSubmitted Papers : \n";
		PrintStack(submittionStack);
		cout << "\nStudents waiting to submitt: \n";
		PrintQueue(waitingQueue);
		cout << "\nMarked Papers : \n";
		PrintStack(marksStack);

		
	}

	void Question6()
	{
		//After how many students John received his exam back?
		int thirtySeven = ((float)37 / (float)100) * (float)getTotalNumberofStudents();
		SetConsoleTextAttribute(hConsole, 6);
		cout << "\n\nRollnumber exam got exam back after " << thirtySeven << " students" << endl;
		SetConsoleTextAttribute(hConsole, 15);

	}

	void Question7()
	{
		remove37Percent();
		//What is the maximum number of exams John would have been through while searching for his Paper
		SetConsoleTextAttribute(hConsole, 6);
		cout << "\nRoll number 420 whould have been through maximum " << find(marksStack, 420) - 1 << " papers while searching for his paper\n";
	}

	void Question8()
	{
		//What is the minimum number of exams John would have been through while searching for his Paper
		cout << "\nRoll number 420 whould have been through minimum " << find(marksStack, 420) - 1 << " papers while searching for his paper\n";
		SetConsoleTextAttribute(hConsole, 15);
		stack<pair<int, string>> temp;
		pair<int, string> person;
		
		while (!marksStack.empty())
		{
			person = marksStack.top();
			if (person.first != 420)
			{
				temp.push(person);
				marksStack.pop();
			}
			else
				break;
		}
		cout << "\nThese are the papers that rollNumber 420 have been through while searching for his own\n";
		PrintStack(temp);
		marksStack.pop();
		cout << "\n\nAfter removing his paper , he left the stack of papers in following order \n";
		while (!temp.empty())
		{
			marksStack.push(temp.top());
			temp.pop();
		}
		PrintStack(marksStack);
	}

	bool RollPresent(int rollnumber)
	{
		for (auto i : data)
		{
			if (i.first == rollnumber)
				return true;
		}
		return false;
	}

public:
	void SolutionMain()
	{
		readData("data.txt");

		if (RollPresent(420))
		{
			Question1();
			Question2();
			Question3();
			Question4();
			Question5();
			Question6();
			Question7();
			Question8();
		}
	}

	~Solution()
	{
		data.clear();
	}

};


int main()
{
	Solution obj;

	obj.SolutionMain();
}
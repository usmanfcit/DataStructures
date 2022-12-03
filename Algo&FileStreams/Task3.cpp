#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

int main()
{
	ifstream read;
	read.open("input2.txt");
	if (!read)
	{
		cerr << "Error Opening File" << endl;
		exit(0);
	}
	string toFind, temp;
	int tempCount = 0;
	int lineNum = 1;
	read >> toFind;

	cout << "The word '" << toFind << "' has Following occurrences"<< endl;

	while (read >> temp)
	{
		if ( (read.peek() == '\n') || read.eof())
		{
			cout << "Line " << lineNum << " : " << tempCount << endl;
			lineNum++;
			tempCount = 0;
		}
			if (temp == toFind)
			{
				tempCount++;
			}
	}

	return EXIT_SUCCESS;
}
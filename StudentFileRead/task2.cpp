#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{	
	ifstream temp("student.txt");
	if (!temp)
	{
		cout << " Error Opening File" << endl;
		exit(0);
	}
	int rNo, marks;
	string fName, lName;
	while (temp >> rNo >> fName >> lName >> marks)
	{
		cout << rNo << "\t" << fName << " " << lName << "\t" << marks << endl;
	}
	temp.close();

	return EXIT_SUCCESS;
}
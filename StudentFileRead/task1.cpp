#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	ofstream temp("student.txt");
	int rNo, marks;
	string fName, lName;
	if (!temp)
	{
		cout << " Error Opening File" << endl;
		exit(0);
	}
	
	while (1)
	{	
		cin >> rNo;
		if (rNo == -999)
		{
			exit(0);
		}
		cin >> fName >> lName >> marks;
		temp << rNo << "\t" << fName << " " << lName << "\t" << marks << endl;
	}
	temp.close();

	return EXIT_SUCCESS;
}

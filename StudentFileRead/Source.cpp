#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	ifstream read("input.txt");
	ofstream write("output.txt");

	if (!read && !write)
	{
		cout << " Error Opening File" << endl;
		exit(0);
	}
	int rNo;
	int m[10];
	while (read >> rNo >> m[0] >> m[1] >> m[2] >> m[3] >> m[4] >> m[5] >> m[6] >> m[7] >> m[8] >> m[9])
	{
		int max = m[0];
		int sMax;
		write << rNo << " ";
			for (int j = 0; j < 10; j++)
			{
				if (m[j] > max)
				{
					sMax = max;
					max = m[j];
					
				}
			}
		write << max << " " << sMax <<  endl;
	}

	read.close();
	write.close();
	return EXIT_SUCCESS;
}
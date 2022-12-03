#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	ifstream temp("input.txt");
	if (!temp)
	{
		cout << " Error Opening File" << endl;
		exit(0);
	}
	int rNo;
	int m[10];
	while (temp >> rNo >> m[0] >> m[1] >> m[2] >> m[3] >> m[4] >> m[5] >> m[6] >> m[7] >> m[8] >> m[9])
	{
		int max = m[0];
		cout << rNo << " ";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (m[j] > max)
				{
					max = m[j];
				}
			}

			cout << m[i] << " ";
		}
		cout << max << endl;
	}

	temp.close();
	return EXIT_SUCCESS;
}
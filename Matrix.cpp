#include <iostream>
using namespace std;

class Matrix
{
private:
	int* p;
	int nRows;
	int nCols;
public:
	Matrix(int rows, int cols)
	{
		nRows = rows;
		nCols = cols;

		p = new int[nRows * nCols];

		for (int i = 0; i < nRows; i++)
		{
			for (int j = 0; j < nCols; j++)
			{
				p[(i * nCols) + j] = 0;
			}
		}
	}

	~Matrix()
	{
		delete[] p;
	}

	void print()
	{
		for (int i = 0; i < nRows; i++)
		{
			for (int j = 0; j < nCols; j++)
			{
				cout << p[(i * nCols) + j] << "\t";
			}
			cout << endl;
		}
	}

	int get(int i, int j)
	{

		if ((i < nRows && i >= 0) && (j < nCols && i >= 0))
		{
			return p[(i * nCols) + j];
		}
	}

	void set(int i, int j, int v)
	{
		p[(i * nCols) + j] = v;
	}

	void transpose()
	{
		int* temp;
		temp = new int[nRows * nCols];
		swap(this->nRows, this->nCols);
		int a = 0;

		for (int i = 0; i < nRows; i++)
		{
			for (int j = 0; j < nCols; j++)
			{
				temp[a++] = p[(j * nRows) + i];
			}
		}

		for (int x = 0; x < nRows * nCols; x++)
		{
			p[x] = temp[x];
		}

		delete[] temp;
	}
	void printSubMatrix(int r1, int r2, int c1, int c2)
	{
		if ((r1 >= 0 && r2 < nRows) && (c1 >= 0 && c2 < nCols))
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j <= c2; j++)
				{
					cout << p[(i * nCols) + j] << "\t";
				}
				cout << endl;
			}
		}
		else
		{
			cout << "Sub Matrix range out of bound, can't Display Sub-Matrix" << endl;
		}
	}

	void makeEmpty(int n)
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				p[(i * nCols) + j] = 0;
			}
		}
	}

	void add(const Matrix& first, const Matrix& second)
	{
		if ((first.nRows == second.nRows) && (first.nCols == second.nCols))
		{
			for (int i = 0; i < nRows * nCols; i++)
			{
				this->p[i] = first.p[i] + second.p[i];
			}
		}
		else
		{
			cout << "Addition not possible, because array dimensions are diffrent" << endl;
		}
	}
};
int main()
{
	Matrix obj(4, 4);
	obj.print();

	cout << endl << "Inserting New elements" << endl;

	obj.set(0, 0, 0);
	obj.set(0, 1, 01);
	obj.set(0, 2, 02);
	obj.set(0, 3, 03);
	obj.set(1, 0, 10);
	obj.set(1, 1, 11);
	obj.set(1, 2, 12);
	obj.set(1, 3, 13);
	obj.set(2, 0, 20);
	obj.set(2, 1, 21);
	obj.set(2, 2, 22);
	obj.set(2, 3, 23);
	obj.set(3, 0, 30);
	obj.set(3, 1, 31);
	obj.set(3, 2, 32);
	obj.set(3, 3, 33);

	obj.print();

	cout << "Taking Tranpose" << endl;
	obj.transpose();
	obj.print();

	cout << endl << "Printing Sub Matrix" << endl;
	obj.printSubMatrix(0, 3, 0, 1);

	cout << "Adding Two Matrices" << endl;
	obj.add(obj, obj);
	obj.print();

	cout << "Emptying Matrix" << endl;
	obj.makeEmpty(2);
	obj.print();

	return EXIT_SUCCESS;
}
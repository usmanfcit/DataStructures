#include "iostream"
#include "fstream"
#include "ctime"

using namespace std;

//Add necessary instructions to count the Number of Key Comparsisons and Data Movements
//You are NOT Allowed to add any input/output instructions in sorting algorithms 
int comp, movements = 0;
//Bubble Sort
void bubbleSort(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			comp++;
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				movements++;
			}
		}
	}
}

//Selection Sort
void selectionSort(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			comp++;
			if (a[min] > a[j])
				min = j;
		}

		swap(a[i], a[min]);
		movements++;
	}
}

//Insertion Sort
void insertionSort(int a[], int size)
{
	int j = 0;

	for (int i = 0; i < size - 1; i++)
	{
		j = i + 1;
		comp++;
		while (j > 0 && a[j] < a[j - 1])
		{
			comp++;
			swap(a[j], a[j - 1]);
			movements++;
			j--;
			
		}
	}
}

int main()
{
	//Read the data from file here
	int i = 0;
	int value = 0;
	int size = 0;
	ifstream read;
	read.open("Data Files//in18000d.txt");
	if (!read)
	{
		cout << "File Error!" << endl;
		exit(0);
	}
	read >> size;
	int* array = new int[size];

	while (read >> value)
	{
		array[i] = value;
		if(i < size - 1 )
		{
			i++;
		}
	}

	clock_t startTime = clock();

	//Make a call to sorting algorithm. DO NOT perform any other operation here 
//	bubbleSort(array, size);
//	selectionSort(array, size);
	insertionSort(array, size);


	clock_t endTime = clock();
	double elapse = ((double)endTime - (double)startTime) / CLOCKS_PER_SEC;
	cout << "The operation took " << elapse << " seconds";
	//Add any other instructions here, if required
	cout <<  endl << "Comparisons = " << comp << endl << "Movements(swaps)  = " << movements << endl;
	delete[] array;
	read.close();

	return 0;
}
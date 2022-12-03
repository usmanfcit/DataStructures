#include <iostream>

using namespace std;

double power(double x, int n)		// Task 1
{
	if (n <= 0)
	{
		return 1;
	}

	return power(x, n - 1) * x;
}

int arraySum(int A[], int n)	// Task 2 // Working Horse
{
	if (n < 0)
	{
		return 0;
	}

	return arraySum(A, n - 1) + A[n];
}
int sumArrCall(int A[], int size)	//	Task 2
{
	int sum = 0;
	sum = arraySum(A, size - 1);
	return sum;
}

void reverseSubArray(int A[], int start, int end)	// Task 3
{
	if (start != end)
	{
		swap(A[start], A[end]);
		reverseSubArray(A, start + 1, end - 1);
	}
}

bool check(int array[], int i, int j, int k) {
	if (i == j) {
		return false;
	}
	if (array[i] + array[j] == k) {
		return true;
	}
	check(array, i, j - 1, k);
}

bool checksum(int array[], int start, int end, int k) {
	if (start == end) {
		return false;
	}
	if (check(array, start, end, k) == 1) {
		return true;
	}
	checksum(array, start + 1, end, k);
}


int main()
{
	//		TASK 1
	// 
//	cout << power(2, 4);

				
//	   TASK 2

/*	int temp[] = {1,3,5,6,7,8,9,100};
	int arrSize = sizeof(temp) / sizeof(temp[0]);
	cout << "Sum of Array = " << sumArrCall(temp, arrSize);	*/

	// TASK 3

/*	int task3[] = {1,2,3,4,5,6,7,8,9,11,199};
	reverseSubArray(task3, 0, 10);

	for (int i = 0; i < 11; i++)
	{
		cout << task3[i] << "\t";
	}								*/


//					TASK 4

/*	char c;
	int k = 0;
	int size = 0;
	cout << "Enter size of the array" << endl;
	cin >> size;

	int* arr = new int[size];

	cout << "Enter " << size << " elements of the array : ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << endl;
	
	do
	{
		cout << "Enter k : ";
		cin >> k;
		cout << endl;

		if ((checksum(arr, 0, size - 1, k)))
		{
			cout << k << " can be obtained by adding two elements of the array. " << endl;
		}
		else
		{
			cout << k << " can  NOT be obtained by adding two elements of the array. " << endl;
		}

		cout << "More (y/n) ? ";
		cin >> c;

	} while (c == 'y' || c == 'Y'); */
	

	return EXIT_SUCCESS;
}
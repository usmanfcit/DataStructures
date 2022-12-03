#include <iostream>
using namespace std;

bool binarySearch(int arr[], int n, int key)
{
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == key)
		{
			return true;
		}
		else if (arr[mid] < key)
		{
			low = mid + 1;
		}
		else if (arr[mid] > key)
		{
			high = mid - 1;
		}
	}
	return false;
}


int intersection1(int A[], int B[], int C[], int n)
{
	int cSize = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i] == B[j])
			{
				C[cSize++] = A[i];		//T(n) = 2n^2 + 2n + 1	||	O(n^2)
			}
		}
	}
	return cSize;
}

int intersection2(int A[], int B[], int C[], int n)
{
	int cSize = 0;
	for (int i = 0; i < n; i++)
	{
		if (binarySearch(A, n, B[i])) 
		{
			C[cSize++] = B[i];		//T(n) = n * lgn	||	O(nlgN)
		}
	}
	return cSize;
}


void display(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	int arr1[] = { 1,4,9,11, 13, 15 };
	int arr2[] = { 2,4,15, 16, 17, 20 };
	int arr3[6];
	int cSize = intersection2(arr1, arr2, arr3, 6);
	cout << endl << "cSize = " << cSize << endl;
	display(arr3, cSize);

	return EXIT_SUCCESS;
}
#include<iostream>
using namespace std;

void bubbleSort(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

int findKthSmallest(int A[], int n, int k)		// O(n^2)  //
{
	bubbleSort(A, n);		// O(n^2) //
	return A[k - 1];
}

int main()
{
	int arr[] = { 5,6,8,33,74,80,24,56,27,234,573,7,842,4 };
	int size = sizeof(arr) / sizeof(int);
	cout <<	findKthSmallest(arr, size, 5);
	

	return EXIT_SUCCESS;
}
#include<iostream>
using namespace std;


// -------------------------------------------------------------------------- //
// Algorithm Name - BubbleSort
//		worst O(n*n) average O(n*n) best O(n) // when sorted
//		stable
// -------------------------------------------------------------------------- //

void bubbleSort(int* arr, size_t n)
{
	if (!arr || n == 0)
		return;

	bool swapped = true;

	while (swapped)
	{
		swapped = false;

		for (size_t i = 0; i<n; ++i)
			for (size_t j = n - 1; j > i; --j)
			{
				if (arr[j - 1] > arr[j])
				{
					int tmp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = tmp;

					swapped = true;
				}
			}
	}
}

// -------------------------------------------------------------------------- //
// Algorithm Name - Selection Sort
//		worst O(n*n) average O(n*n) best O(n*n)
//		stable
// -------------------------------------------------------------------------- //

void selectionSort(int* arr, size_t n)
{
	if (!arr || n == 0)
		return;

	for (size_t i = 0; i < n; ++i)
	{
		size_t minIndex = i;
	
		for (size_t  j = i+1; j <n; j++)
		{
			if (arr[minIndex] > arr[j])
				minIndex = j;
			
		}

		if (arr[i] > arr[minIndex])
		{
			int tmp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = tmp;
		}
	}
}

// -------------------------------------------------------------------------- //
// Algorithm Name - Insertion sort
//		worst O(n*n) average O(n*n) best O(n) // sorted array
//      stable & adaptive
// -------------------------------------------------------------------------- //

void insertionSort(int* arr, size_t n)
{
	if (!arr || n == 0)
		return;

	for (size_t i = 1; i < n; ++i)
	{
		int value = arr[i];
		size_t j = i-1;
		
		while (arr[j] > value)
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = value;
	}
}





int main()
{

	int arr[] = { 5,1,2,5,7,3,8,9,3,24,64,2,4,6 };

	insertionSort(arr, 14);
	for (int i = 0; i < 14; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;



	return 0;
}

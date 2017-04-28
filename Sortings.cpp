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

// -------------------------------------------------------------------------- //
// Algorithm Name - Quck sort
//		Quick sort + Partition function 
// -------------------------------------------------------------------------- //

//  Partion with MIDDLE pivot
size_t partition(int* arr, size_t i, size_t j)
{
	const size_t mid = (i+j) / 2 ;
	const size_t pivot = arr[mid];

	while (i <= j) 
	{
		while (arr[i] < pivot) 
			i++;
		while (arr[j] > pivot) 
			j--;
		if (i <= j) 
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	return i;

}

void quickSort(int* arr, size_t left, size_t right)
{
	if (!arr || right-1<=left)
		return;

	size_t part = partition(arr, left, right);

	if(left <part-1)
		quickSort(arr,left,part-1);
	if (part <right)
		quickSort(arr,part,right);
}






int main()
{

	int arr[] = { 5,1,2,5,7,3,8,9,3,24,64,2,4,6 };

	insertionSort(arr, 14);
	for (size_t i = 0; i < 14; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;



	return 0;
}

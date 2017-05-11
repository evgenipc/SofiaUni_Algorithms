#include<iostream>
using namespace std;

// -------------------------------------------------------------------------- //
// Algorithm Name - BubbleSort
//		worst O(n*n) average O(n*n) best O(n) // when sorted
//		stable
// -------------------------------------------------------------------------- //

void bubbleSort(int* arr, size_t n)
{
	if(!arr || n==0)
		return;
	bool swapped = true;
	for (size_t i = 0; i < n && swapped; ++i)
	{
		swapped = false;
		for (size_t j = n - 1; j > i; --j)
		{
			if (arr[j] < arr[j - 1])
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

// -------------------------------------------------------------------------- //
// Algorithm Name - Merge Sort
// -------------------------------------------------------------------------- //

void mergeStep(int*, int*, size_t);
void merging(int*, int*, size_t, size_t, int*);
void mergeSort(int* arr, const size_t n)
{
	if (!arr || n<=1)
		return;

	int* tmp = new int[n];

	mergeStep(arr, tmp, n);

	delete[] tmp;
}

void mergeStep(int* arr, int* tmp, const size_t n)
{
	if (n <= 1)
		return;
	size_t mid = n / 2;

	mergeStep(arr, tmp, mid);
	mergeStep(arr + mid, tmp + mid, n - mid);

	merging(arr, arr + mid, mid , n - mid, tmp);

	for (size_t i = 0; i < n; i++)
		arr[i] = tmp[i];

}
void merging(int* arrA, int* arrB, size_t sizeA, size_t sizeB, int* result)
{
	size_t i = 0;
	size_t ia = 0;
	size_t ib = 0;

	while (ia < sizeA && ib < sizeB)
	{
		if (arrA[ia] < arrB[ib])
			result[i++] = arrA[ia++];
		else
			result[i++] = arrB[ib++];
	}
	while (ia < sizeA)
		result[i++] = arrA[ia++];
	while (ib < sizeB)
		result[i++] = arrB[ib++];
}



// -------------------------------------------------------------------------- //
// Algorithm Name - Quick Select
// -------------------------------------------------------------------------- //

int partition(int* arr, int start, int end) {
	int pivotIndex = (start + end)/2;
	int tmp;

	tmp = arr[pivotIndex];
	arr[pivotIndex] = arr[start];
	arr[start] = tmp;

	int index = start + 1;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] < arr[start]) {
			tmp = arr[index];
			arr[index] = arr[i];
			arr[i] = tmp;
			index++;
		}
	}
	--index;
	tmp = arr[index];
	arr[index] = arr[start];
	arr[start] = tmp;

	return index;
}
int quickSelect(int* arr, size_t n, const size_t k)
{
	int start = 0;
	int end = n - 1;
	int pivotIndex;

	while (start <= end)
	{
		pivotIndex = partition2(arr, start, end);

		if (pivotIndex < k - 1)
			start = pivotIndex + 1;
		else if (pivotIndex > k - 1)
			end = pivotIndex - 1;
		else
			return arr[k - 1];
	}
	return arr[k - 1];
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

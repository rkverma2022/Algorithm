// C++ program for Merge Sort
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int SwapCount = 0;
int iterations = 0;
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
template <class T>
void merge(T array[], int const left, int const mid,
		   int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new T[subArrayOne],
		 *rightArray = new T[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
	{
		leftArray[i] = array[left + i];
		iterations +=1;
	}
		
	for (auto j = 0; j < subArrayTwo; j++)
	{
		rightArray[j] = array[mid + 1 + j];
		iterations +=1;
	}
		

	auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
		indexOfSubArrayTwo = 0;	   // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
		iterations += 1;
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else
		{
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne)
	{
		iterations +=1;

		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		iterations +=1;

		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
template <class T>
void mergeSort(T array[], int const begin, int const end)
{
	iterations +=1;

	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
template <class T>
void printArray(T A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int n;
	cout << "How many Data point want to take: " << endl;
	cin >> n;
	float brr[n];

	ifstream myfile;
	myfile.open("09_ND_data.data");

	for (int i = 0; i < n; i++)
	{
		myfile >> brr[i];
	}

	myfile.close();

	mergeSort(brr, 0, n - 1);

	cout << "\nSorted array is \n";
	printArray(brr, n);

	ofstream datafile;
	datafile.open("11_ND_MergeSort.data");
	for (int i = 0; i < n; i++)
	{
		datafile << brr[i] << endl;
	}
	datafile.close();

	ofstream complexity_file;
    complexity_file.open("12_ND_Complexity_MergeSort.data", ios::app);
    complexity_file<<n<<", "<<iterations<<", "<<SwapCount<<endl;
    complexity_file.close();

	return 0;
}

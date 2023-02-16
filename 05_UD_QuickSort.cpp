#include<iostream>
#include<fstream>
using namespace std;


int SwapCount =0;
int iterations =0;
template<class T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;

    SwapCount +=1;
}

template<class T>
int partition(T array, int l, int r)
{
    int pivote = array[r];
    int i = l-1;
    for( int j = l; j< r -1; j++)
    {
        if(array[j] < pivote)
        {
            i++;
            swap(&array[i], &array[j]);
        }

        iterations +=1;
    }

    swap(array[i + 1], array[r]);
    return (i + 1);
}

template<class T>
void quicksort(T array, int l, int r)
{
    iterations += 1;

    if(l>=r)
    {
        return;
    }

    int piv_indx = partition(array, l, r);

    quicksort(array, l, piv_indx - 1 );
    quicksort(array, piv_indx + 1, r);

}



int main()
{
    ifstream myfile;
    myfile.open("02_UD_unsorted.data");

    int n;
    cout<<"Number of Elements: "<<endl;
    cin>>n;

    int arr[n];
    for(int i =0; i<n; i++)
    {
        myfile>>arr[i];
    }

    myfile.close();

    quicksort(arr, 0, n-1);

    ofstream writingPad;
    writingPad.open("06_UD_QuickSorted.data");
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<endl;
        writingPad<<arr[i]<<endl;
    }
    writingPad.close();

    ofstream complexity_file;
    complexity_file.open("07_UD_Complexity_QuickSort.data", ios::app);
    complexity_file<<n<<", "<<iterations<<", "<<SwapCount<<endl;
    complexity_file.close();
    
    return 0;
}
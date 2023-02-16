#include <bits/stdc++.h>
using namespace std;

unsigned int iter = 0;

/*
    Congratulations...... I did it......   :) --------- :)

*/
template <class T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

// partition at np

template <class T>
int partition(T array[], int l, int r, int np)
{

    int step = (r - l + 1) / np;
    vector<int> medians;

    int idx = l;
    int count = 1;

    vector<int> subarr;
    for (idx; idx < r; idx++)
    {
        iter += 1;

        subarr.push_back(array[idx]);

        if (count % np == 0)
        {
            sort(subarr.begin(), subarr.end());
            // subarr.pop_back();
            // subarr.pop_back();

            sort(subarr.begin(), subarr.end());

            int mx = subarr.max_size();

            for (int p = 0; p < (mx / 2) + 1; p++)
            {
                subarr.pop_back();

                iter += 1;
            }
            medians.push_back(subarr.front());

            subarr.clear();
        }

        count++;
    }
    if (!subarr.empty())
    {
        iter += 1;

        sort(subarr.begin(), subarr.end());
        int mx = subarr.max_size();

        for (int p = 0; p < mx / 2; p++)
        {
            subarr.pop_back();
        }
        medians.push_back(subarr.front());
    }

    sort(medians.begin(), medians.end());
    int max_size = medians.max_size();

    int pivotal_ele;
    for (int t = 0; t < max_size / 2; t++)
    {
        iter += 1;

        pivotal_ele = medians.front();
        medians.pop_back();
    }

    int idx_pivote;

    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        iter += 1;

        if (array[j] == pivotal_ele)
        {
            idx_pivote = j;
            continue;
        }

        if (array[j] < pivotal_ele)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(array[i + 1], array[idx_pivote]);
    return (i + 1);
}

template <class T>
void QuickSort_MOM(T array[], int l, int r, int np)
{

    if (l >= r)
    {
        return;
    }
    iter += 1;
    int piv_indx = partition(array, l, r, np);

    QuickSort_MOM(array, l, piv_indx - 1, np);
    QuickSort_MOM(array, piv_indx + 1, r, np);

    return;
}

int main()
{
    int array[] = {1, 5, 2, 56, 37, 95, 26, 0, 98, 94, 100, -188, 889, 262, -383, 839, 262, 493, -383, 3763, 2636};
    int n = sizeof(array) / sizeof(array[0]);
    int np[5] = {3, 5, 7, 9, 11};

    ofstream complexity_file;

    complexity_file.open("24_Different_Pivotes_diff_pivotes.data", ios::app);
    complexity_file << "Pivot_Group"
                    << ", "
                    << "iter" << endl;
    for (int i = 0; i < 5; i++)
    {
        iter = 0;
        QuickSort_MOM(array, 0, n, np[i]);

        complexity_file << np[i] << ", " << iter << endl;
        iter = 0;
    }
    complexity_file.close();

    return 0;
}
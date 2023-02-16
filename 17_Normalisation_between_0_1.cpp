
#include <bits/stdc++.h>
using namespace std;

class Bucket_Normalisation
{

public:
    template <class T>
    int Normalise_UD(string file_name, T ub)
    {
        vector<float> data;
        int count = 0;

        ifstream myfile;
        myfile.open(file_name);

        string ch;
        // myfile>>ch;
        while (myfile >> ch)
        {
            data.push_back(stof(ch) / ub);
            count++;
        }
        myfile.close();

        ofstream fin;
        fin.open("18_UD_Normalized.data");
        for (auto a : data)
        {
            // cout << a << endl;
            fin << to_string(a) << endl;
        }
        fin.close();

        return count;
    }

    int Normalise_ND(string file_name)
    {
        vector<float> data;
        int count = 0;

        ifstream myfile;
        myfile.open(file_name);

        string ch;
        // myfile>>ch;
        while (myfile >> ch)
        {
            data.push_back(abs(stof(ch)));
            count++;
        }
        myfile.close();

        ofstream fin;
        fin.open("19_ND_Normalized.data");
        for (auto a : data)
        {
            // cout << a << endl;
            fin << to_string(a) << endl;
        }
        fin.close();

        return count;
    }

    int bucketSort(string file_name, int n = 10)
    {
        int iterator_counter = 0;

        // 1) Create n empty buckets
        vector<float> b[n];

        ifstream myfile;
        myfile.open(file_name);

        string ch;
        // myfile>>ch;
        while (myfile >> ch)
        {
            b[int(10 * (stof(ch)))].push_back(stof(ch));
            iterator_counter += 1;
        }
        myfile.close();

        // 3) Sort individual buckets
        for (int i = 0; i < n; i++)
        {
            sort(b[i].begin(), b[i].end());
            iterator_counter += 1 + (i + 1)*log(i + 1);
        }

        ofstream fin;
        string file = "20_BS";

        file.append(file_name);
        fin.open(file, ios::app);
        for (int i = 0; i < n; i++)
        {
            for (auto a : b[i])
            {
                fin << to_string(a) << endl;
            }
        }

        fin.close();

        return iterator_counter;
    }
}

;
int main()
{
    cout << ":::::: Normalising UD Data :::::::::::" << endl;
    Bucket_Normalisation BN;
    int count1 = 0;
    string file_name1 = "02_UD_unsorted.data";
    count1 = BN.Normalise_UD(file_name1, 6.0);

    cout << "::::: Normalising ND Data :::::::" << endl;
    string file_name2 = "09_ND_data.data";
    int count2 = 0;
    count2 = BN.Normalise_ND(file_name2);

    cout << ":::: Bucket Sort On ND Data ::::::" << endl;
    string file_name4 = "19_ND_Normalized.data";
    int count4 = BN.bucketSort(file_name4, 10); // Number of Bucket = 10

    ofstream f2;
    string prefix2 = "21_BS_complexity_";
    prefix2.append(file_name4);
    f2.open(prefix2, ios::app);
    f2 << to_string(count2) << ", " << to_string(count4) << endl;
    f2.close();


    cout << "::::: Bucket Sort on UD Data ::::::" << endl;
    string file_name3 = "18_UD_Normalized.data";
    int count3 =0;
    count3 = BN.bucketSort(file_name3, 10);

    cout << "::::: Writing In File :::::" << endl;
    ofstream f1;
    string prefix1 = "21_BS_complexity_";
    prefix1.append(file_name3);
    f1.open(prefix1, ios::app);
    f1 << to_string(count1) << ", " << to_string(count3) << endl;
    f1.close();

    

    

    return 0;
}
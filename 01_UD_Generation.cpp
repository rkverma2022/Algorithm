#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

/* Author : Rajkumar Verma */


int main()
{
   
    int a = 0, b = 5;
    // cout<<"Enter Lower Bound: X= a: "<<endl;
    // cin>>a;
    // cout<<"Enter Upper Bound: X= b: "<<endl;
    // cin>>b;
    int n;
    cout<<"How many Data point want to take: "<<endl;
    cin>>n;
    
    //opening a txt file 
    ofstream myfile;
    myfile.open("02_UD_unsorted.data");       //--> append mode
   
    for(int i=0;i<n;i++)
    {
        myfile<<rand()%((b - a) + 1) + a<<endl;
    }
    myfile.close();

    return 0;
}


#include<iostream>
using namespace std;

//Q. Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo


void print(int *a, int n)
{
    if(n>1)
    {
        for(int i=0;i<n-1;i++)
        {
            cout << a[i] << " ";
        }
    }
    cout << a[n-1] << endl;
    
}



int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    
    // ITERATIVE WAY
    //T.C = 0(n)
    int num_of_zeros = 0;
    int num_of_ones = 0;
    int res[n];
    for(int i=0;i<n;i++)
    {
        if(a[i] == 0)
        {
            num_of_zeros += 1;
        }
        if(a[i] == 1)
        {
            num_of_ones += 1;
        }
    }
    int counter = 0;
    for(int i=0;i<num_of_zeros;i++)
    {
        res[counter] = 0;
        counter += 1;
    }
    for(int i=0;i<num_of_ones;i++)
    {
        res[counter] = 1;
        counter += 1;
    }
    for(int i=counter;i<n;i++)
    {
        res[i] = 2;
    }
    print(res, n);
}



/*
Test Cases ---
7
1 1 0 0 2 1 0


3
2 0 1
*/

#include<iostream>
using namespace std;

//Q. Reverse an Array

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


void recursive_way(int *a, int n, int start_index, int end_index)
{
    if(start_index > end_index)
    {
        return;
    }

    int temp = a[start_index];
    a[start_index] = a[end_index];
    a[end_index] = temp;
    start_index += 1;
    end_index -= 1;
    recursive_way(a, n, start_index, end_index);
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
    for(int i=0;i<n/2;i++)
    {
        int temp = a[i];
        a[i] = a[n-i-1];
        a[n-1-i] = temp;
    }
    print(a, n);

    //RECURSIVE WAY
    //T.C = 0(n)
    recursive_way(a, n, 0, n-1);
    print(a, n);
}



/*
Test Cases ---
3
1 2 3


4
4 5 1 2
*/
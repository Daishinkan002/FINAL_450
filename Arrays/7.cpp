


#include<iostream>
using namespace std;

// Q. Write a program to cyclically rotate an array by one.





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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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
    int temp = a[0];
    int new_val = a[1];
    a[0] = a[n-1];
    for(int i=1;i<n;i++)
    {
        new_val = temp;
        if(i<n)
        {
            temp = a[i];
        }
        a[i] = new_val;
        
    }
    

    
    print(a, n);


    return 0;
}



/*
Test Cases ---
5
1 2 3 4 5

Output : 5, 1, 2, 3, 4




*/

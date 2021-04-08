


#include<bits/stdc++.h>
using namespace std;

// Q. find Largest sum contiguous Subarray [V. IMP]





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



//KADANE'S ALGORITHM
int maximum_sum_subarray(int *a, int n)
{
    int i;
    int max_ending_here = 0;
    int max_so_far = INT_MIN;
    for(i=0;i<n;i++)
    {
        max_ending_here += a[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
            
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
    cout << maximum_sum_subarray(a, n) << endl;
    
    return 0;
}



/*
Test Cases ---
5
1 2 3 -2 5
Output: 9


4
-1 -2 -3 -4
*/

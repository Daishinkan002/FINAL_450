
#include<iostream>
using namespace std;

//Q. Move all the negative elements to one side of the array 


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

    
    // ITERATIVE WAY
    //T.C = 0(n)
    int neg_index = 0;
    int counter = 0;
    while((neg_index < n) and (counter < n))
    {
        while((a[counter] >= 0) && (counter < n))
        {
            counter ++;
        }
        if((counter != neg_index) && (counter < n))
        {
            swap(&a[neg_index], &a[counter]);
            neg_index += 1;
        }
        else{
            counter += 1;
        }
        

    }
    print(a, n);


    return 0;
}



/*
Test Cases ---
5
-3 1 4 -2 -5


4
4 5 1 2

9
1 1 2 2 -2 -2 -1 2 1
*/

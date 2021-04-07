

#include<iostream>
using namespace std;

// Q. Minimum no. of Jumps to reach end of an array

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



int get_min_jumps(int *arr, int n)
{
    int i, index_to_iterate = 0, sum = n, distance;
    int step = 0;
    i = n-1;
    int temp_sum = n;
    while(i>0 and sum > 0)
    {
        for(int j = i;j>=0;j--)
        {
            distance = sum-1-j;
            if(arr[j] - distance >=0)
            {
                index_to_iterate = j;
                temp_sum = j+1;
            }
        }
        i = index_to_iterate;
        sum = temp_sum;
        step += 1;
    }
    return step;
}

// Badhiyan wala approach
int get_minimum_jumps(int *a, int n)
{
    int i=0, j=0, index_to_iterate = 0;
    int steps = 1;
    int limit = 0;
    while(limit < n)
    {
        int max = 0;
        for(j=0;j<a[i];j++)
        {
            if((i+j+1) < n)
            {
                if(max < a[i+j+1])
                {
                    max = a[i+j];
                    index_to_iterate = i+j+1;
                }
            }

        }
        i = index_to_iterate;
        limit = i+a[i];
        steps++;
    }
    return steps;

}

int maximum(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

//Majedar wala approach
int get_min_jump(int *a, int n)
{
    int i;
    int distance_calc = a[0]; // Maximum sair kahan tak kar sakte hain
    int limit = a[0]; // Kahan tak ka fuel hai 
    int steps = 1; // Kitna bar fuel bharwaye

    for(i=1;i<n-1;i++)
    {
        distance_calc = maximum(distance_calc, i+a[i]);
        limit--;
        if(limit == 0)
        {
            steps += 1;
            limit = distance_calc - i;
            
        }
        if(limit <= 0)
        {
            return -1;
        }
        
        cout << distance_calc << " " << limit << " " << steps << endl;
    }
    return steps;
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

    int steps = get_min_jump(a, n);
    cout << steps << endl;

    return 0;
}



/*
Test Cases ---
Input : 
6
1 4 3 2 6 7
Output: 2

11
1 3 5 8 9 2 6 7 6 8 9
Output : 3

10
2 3 1 1 2 4 2 0 1 1
Output: 4

4
2 1 0 3
Output: -1

*/

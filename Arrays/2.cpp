#include<iostream>
using namespace std;

//Q. Find the maximum and minimum element in an array

struct min_max{
    int min;
    int max;
};




//Tournament Method
/*
Min_max_struct get_min_max(array, array_size)
   if array_size = 1
      return element as both max and min
   else if arry_size = 2
      one comparison to determine max and min
      return that pair
   else    # array_size  > 2 
      recur for max and min of left half
      recur for max and min of right half
      one comparison determines true max of left and right
      one comparison determines true min of left and right
      return the pair of max and min
*/
//T.C = 0(n)
struct min_max get_min_max(int *a, int start_index, int end_index)
{
    struct min_max left, right, result;
    if(start_index == end_index)
    {
        result.min = a[start_index];
        result.max = a[end_index];
        return result;
    }

    if(start_index+1 == end_index)
    {
        if(a[start_index] < a[end_index])
        {
            result.min = a[start_index];
            result.max = a[end_index];
        }
        else
        {
            result.max = a[start_index];
            result.min = a[end_index];
        }

        return result;
    }
    int middle_index = start_index + end_index /2;
    left = get_min_max(a, start_index, middle_index);
    right = get_min_max(a, middle_index, end_index);


    result.max = right.max;
    result.min = right.min;
    if(left.max > right.max)
    {
        result.max = left.max;
    }
    if(left.min < right.min)
    {
        result.min = left.min;
    }

    return result;
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

    //Iterative Approach
    int min, max;
    min, max = a[0], a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
        if(a[i] < min)
        {
            min = a[i];
        }
    }

    cout << min << " " << max << endl;
    

   struct min_max result = get_min_max(a, 0, n-1);
   cout << result.min << " " << result.max << endl;
}




/* Test Cases --
4
2 4 2 1

5
9 -1 3 0 8
*/


#include<bits/stdc++.h>
using namespace std;

//Q. Find the Union and Intersection of the two sorted arrays.

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


void print_vector(vector<int> a)
{
    for(auto itr = a.begin(); itr!=a.end(); ++itr)
    {
        cout << *itr << " ";
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
    }
    
    vector<int> union_arr;
    vector<int> intersection_arr;

    int i=0, j=0;
    while(i<n && j<m)
    {
        if(i!=n-1 && a[i+1] == a[i])
        {
            i+= 1;
        }
        if(j!=m-1 && b[j+1] == b[j])
        {
            j+=1;
        }
        else
        {
            if(a[i] < b[j])
            {
                union_arr.push_back(a[i]);
                i++;
            }
            else if(a[i] == b[j])
            {
                union_arr.push_back(a[i]);
                intersection_arr.push_back(a[i]);
                i++;
                j++;
                
            }
            else
            {
                union_arr.push_back(b[j]);
                j++;
                
            }
        }
    }
    if(i<n)
    {
        for(i; i<n;i++)
        {
            if((i<n-1) && (a[i+1] == a[i]))
            {
                i+= 1;
            }
            else
            {
                union_arr.push_back(a[i]);
            }
        }
    }
    if(j<m)
    {
        for(j;j<m;j++)
        {
            if(((j< m-1) && (b[j+1] == b[j])))
                j+=1;
            else
                union_arr.push_back(b[j]);
                
        }
    }
    cout << "Union : ";
    print_vector(union_arr);
    cout << "\nIntersection : ";
    print_vector(intersection_arr);
    cout << endl;

    return 0;
}



/*
Test Cases ---
2 6
4 4
1 2 3 4 4 5
Output:
Union : 1 2 3 4 5
Intersection : 5
*/

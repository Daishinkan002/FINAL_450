

#include<bits/stdc++.h>
using namespace std;

// Q. 
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




void print_vector(vector<int> a){
    int n = a.size();
    for(int i=0;i<n-1;i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
}




void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return;
        else{
            for(int i=n-1;i>0;i--)
            {
                if(nums[i]>nums[i-1])
                {
                    int distance = 10;
                    int least_distance_index = n-1;
                    cout << "NUms[i-1] = " << nums[i-1] << endl;
                    for(int j=i;j<n;j++)
                    {
                        cout << nums[j] << " " << nums[i-1] << endl;
                        if(((nums[j]-nums[i-1])>0) && ((nums[j]-nums[i-1])<distance)){}
                            distance = nums[i-1]-nums[j];
                            cout << "Distance = " << distance << endl;
                            least_distance_index = j;
                        }
                    }
                    cout << "least_distance_index = " << least_distance_index << endl;
                    swap(nums[i], nums[least_distance_index]); 
                    for(int j=i;j<(n-(i+1))/2;j++)
                    {
                        swap(nums[j], nums[n-j-1]);
                    }
                    
                    return;
                }
            }
            for(int i=0;i<n/2;i++)
            {
                swap(nums[i], nums[n-i-1]);
            }
        }
    }


int main()
{
    vector<int> a;
    int n=3, temp;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        a.push_back(temp);
        
    }

    
    nextPermutation(a);
    print_vector(a);


    return 0;
}



/*
Test Cases ---
Input:
3 2 1
Output: 1 2 3



*/

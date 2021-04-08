#include<bits/stdc++.h>
using namespace std;

// Q. find duplicate in an array of N+1 Integers


struct iters{
    int value;
    int link;
};


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


// Rabbit tortoise_approach
int rabbit_tortoise(vector<int>& nums)
{
    int length = nums.size();
    struct iters rabbit;
    struct iters tortoise;
    tortoise.link = nums[0];
    tortoise.value = nums[0];
    rabbit.link = nums[nums[0]];
    rabbit.value = nums[nums[0]];
    //cout << "t link = " << tortoise.link << " r link = " << rabbit.link << endl;
    if(length == 1)
        return -1;
    
    else{
        while(rabbit.link != tortoise.link){
            rabbit.link = nums[nums[rabbit.link]];
            //cout << nums[rabbit.link] << " --> " << nums[nums[rabbit.link]] << endl;
            tortoise.link = nums[tortoise.link];
            //cout << "t link = " << tortoise.link << " r link = " << rabbit.link << endl;
        }
        rabbit.link = nums[rabbit.link];
        tortoise.link = nums[0];
        //cout << "t link = " << tortoise.link << " r link = " << rabbit.link << endl;
        while(nums[tortoise.link] != nums[rabbit.link])
        {
            tortoise.link = nums[tortoise.link];
            rabbit.link = nums[rabbit.link];
            //cout << "tortoise link = " << tortoise.link << " rabbit link = " << rabbit.link << endl;
        }
        if(rabbit.link == tortoise.link)
            return rabbit.link;
        else
            return nums[rabbit.link];
    }
    return -1;
}
int main()
{
    vector<int> a;
    int temp;
    int n = 3;
    int av[] = {1,1,2};
    cout << n << endl;
    for(int i=0;i<n;i++)
    {
        temp = av[i];
        a.push_back(temp);
    }
    int res = rabbit_tortoise(a);
    cout << "Output: " << res << endl;
    print_vector(a);
    return 0;
}



/*
Test Cases ---
Input: nums = [1,3,4,2,2]
Output: 2


Input: nums = [3,1,3,4,2]
Output: 3

Input: nums = [1,1]
Output: 1

Input: nums = [1,1,2]
Output: 1

*/

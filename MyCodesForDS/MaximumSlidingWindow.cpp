//Code for Maximum Sliding Window

//Question: Given an array and a window size, find the maximum in every window of size k

#include<bits/stdc++.h>
using namespace std;

#define INT_MAX 4294967295

vector<int> find(int a[], int k)
{
    deque<int> d;
    //d stores indices, not the values at the indices
    vector<int> ans;
    for(int i = 0 ; i < a.size(); i++)
    {
        //First, we remove elements which are not in the current window
        //Suppose k = 3 
        //then, for i = 3, we mean the fourth element, and hence, we don't need the first element 
        //Given that the size of the window is 3 
        if(!d.empty() && d.front() == i - k)
        {
            d.pop_front();
        }
        
        //We are supposed to be inserting an element from the array into the deque
        //Now, we cannot have an element in the deque smaller than the current element before it in the deque
        //Because we are supposed to add elements in the final answer using pop_front
        //Hence, we remove all the elements smaller than it from the deque
        //Logic is: if we find a larger element after a smaller one 
        //There is no way that the smaller element can be a max in any of the future windows
        //So we remove it
        while(!d.empty() && a[i] > a[d.back()])
                d.pop_back();
        
        d.push_back(a[i]);
        
        if(i >= k - 1)
            ans.push_back(a[d.front()]);
    }
    return ans;
}

int main()
{
    long int l;
    cin>>l;
    stack<int>s;
    string str;
    long long int g = 1;
    while(l--)
    {
        if(g <= INT_MAX)
        {
            
        }
    }
    return 0;
}

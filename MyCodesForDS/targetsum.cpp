// CPP program to find the targetsum effeciently usig memorization

#include<bits/stdc++.h>
using namespace std;
int static t[102][1002];
// Function to calculate the subsetsum
int subsetsum(int wt[],int sum,int n)
{
	//Declaration of matrix to store the smaller targetsum.
	int t[n+1][sum+1];
	
	//initialization of the matrix
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
			{
				t[i][j] = false;
			}
			if(j==0)
			{
				t[i][j] = true;
			}
		}
	}
	
	// the main logic
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(wt[i-1]<=j)
			{
				t[i][j] = t[i-1][j-wt[i-1]] + t[i-1][j];
			}
			else
			{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][sum];
}
// Driver function
int main()
{
	int W,n,profit,sum=0,dif,sum1,total;
	
	cout<<"Enter the number of elements:";
	cin>>n;
	//cout<<"Enter the maximum sum:";
	//cin>>W;
	int wt[n];
	cout<<"Enter the array elements:";
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	cout<<"Enter the sum:";
	cin>>total;
	for(int i=0;i<n;i++)
	{
		sum = sum+wt[i];
	}
	sum1 = (total+sum)/2;
	profit = subsetsum(wt,sum1,n);
	cout<<"Hence the subsets possible are: "<<profit;
	
	
}


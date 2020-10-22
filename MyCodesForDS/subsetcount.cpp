//cpp program to find the number of possible subsets of the array which gives the required sum 
#include<bits/stdc++.h>
using namespace std;
int static t[102][1002];

int subsetsum(int wt[],int sum,int n)
{
	int t[n+1][sum+1];
	
	
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

int main()
{
	int W,n,profit,sum;
	
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
	cout<<"Enter the sum intended: ";
	cin>>sum;
	profit = subsetsum(wt,sum,n);
	cout<<"Hence the subsets possible are: "<<profit;
	
	
}


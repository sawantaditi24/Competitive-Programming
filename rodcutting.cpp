// CPP program to find the maximum profit that can be earned by cutting the rod and selling the pieces

#include<bits/stdc++.h>
using namespace std;
int static t[102][1002];

// function to compute the maximum profit to be earned
int rodprofit(int length[],int price[],int W,int n)
{
	int t[n+1][W+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0||j==0)
			{									//Initialization of matrix
				t[i][j]=0;
			}
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<W+1;j++)
		{
			if(length[i-1]<=j)
			{
				t[i][j] = max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
			}
			else
			
			{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][W];					// the maximum profit earned
}

//Driver function
int main()
{
	int W,n,profit;
	
	cout<<"Enter the number of number of prices:";
	cin>>n;
	cout<<"Enter the length of the rod:";
	cin>>W;
	int length[n],price[n];
	cout<<"Enter the length of rod with respect to its price:";
	for(int i=0;i<n;i++)
	{
		cin>>length[i];
	}
	cout<<"Enter the price of each length";
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	profit = rodprofit(length,price,W,n);
	cout<<"The maximum profit is:"<<profit;
	
	//return 0;
	
}


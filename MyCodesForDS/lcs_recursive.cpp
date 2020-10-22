// Longest common subsequence problem soultion using recursion

// Given two sequences find the length of longest subsequence present in both of them 


#include<bits/stdc++.h>
using namespace std;
int lcs(string x,string y,int m,int n)
{
	if(m==0||n==0)
	{
		return 0;
	}
	if(x[m-1]==y[n-1])
	{
		return 1+lcs(x,y,m-1,n-1);
	}
	else
	{
		return max(lcs(x,y,m-1,n),lcs(x,y,m,n-1));
	}
}


int main()
{
	string x,y;
	int m,n,count;
	
	cout<<"Enter the first string:";
	cin.ignore();
	getline(cin,x);
	cout<<"Enter the second string:";
	cin.ignore();
	getline(cin,y);
	m = x.size()+1;
	cout<<"Length of string 1:"<<m<<endl;
	n = y.size()+1;
	cout<<"Length of string 2:"<<n<<endl;
	
	
	count = lcs(x,y,m,n);
	cout<<"The length of longest common subsequence is:"<<count;
	
	return 0;
}

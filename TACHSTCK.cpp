#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, d, a[1222222];
  for(int i = 0 ; i < n; i++)
    cin>>a[i];
  sort(a, a+n);
  int pos = 0;
  //Shows position of the shorter stick of the pair
  int res = 0;
  /Represents the total number of legit pairs
  
  while(pos < n)
  {
      if(abs(a[pos] - a[pos + 1]) <= d)
      {
          res ++;
          pos += 2;
      }
      else
          pos ++;
  }
  
  cout<<res<<endl;
  
  return 0;
}

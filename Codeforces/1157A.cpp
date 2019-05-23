#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, num;
    cin>>n;
    num = n;
    int count = 9;
    while(num >= 10)
    {
        if(num %10 == 0)
        {
            count ++;
            num++;
        }
        while(num %10 != 0)
        {
            num++;
            count++;
        }
        while(num %10 == 0)
            num = num/10;
    }
    cout<<count;
    return 0;
    
}

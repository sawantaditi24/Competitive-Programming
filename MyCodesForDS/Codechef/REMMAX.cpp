#include <bits/stdc++.h>
#include<string>
using namespace std;

int main() {
    int t; long long int n = 0, i, j, nod = 0;
    cin>>t;
    while(t--)
    {
        cin>>i;
        if(i <= 8)
        {
            n = 8;
        }
        else
        {
            int j = i;
            stack<int> s;
            while(j != 0)
            {
                s.push(j%10);
                j /= 10;
                nod++;
            }
            //int k = X % pow(10, (nod-1));//First digit
            if(s.top() == 1)
            {
                int k1 = s.top();
                s.pop();
                int k2 = s.top();
                s.pop();
                if(k2 > 0)
                    k2--;
                else
                {
                    k1 = 0;
                    k2 = 9;
                }
                s.push(k2);
                s.push(k1);
                int l = nod - 1;
                while(!s.empty())
                {
                    if(l >= nod - 2)
                    {
                        n += (s.top()*pow(10, l));
                        s.pop();
                    }
                    else
                    {
                        n += 9*pow(10, l);
                    }
                    l--;
                }
            }
            else
            {
                int l = nod - 1;
                n += (s.top() - 1)*pow(10, l);
                l--;
                while(!s.empty())
                {
                    n += 9 * pow(10, l);
                    l--;
                }
            }
        }
    
        cout<<n<<endl;
    }
	return 0;
}
      

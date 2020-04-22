    /* Logic
        2^0 + 2^1 + ..... 2^(k-1) = 2^k - 1
        Therefore, (2^k-1)x=n
        Therefore x = n/(2^k-1)
        Hence, we need to divide n by a power of 2 that is a factor. 
        Since O(n) is 10^9, and 2^30 - 1 > 10^9, we only need to check till k = 29, that is, from k=2, to k=29
    */
    #include <bits/stdc++.h>
    using namespace std;


    int main()
    {
        int t;
        int n, x;
        cin >> t;
        while (t--)
        {
            cin >> n;

            for (int i = 2 ; i <= 29 ; i++)
            {
                x = pow(2, i) - 1;
                if (n % x == 0)
                {
                    cout<< n/x<<endl;
                    break;
                }
            }
        }
    }

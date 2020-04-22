    /*
        For a YES, n has to be divisible by 4. Only then can we partition the array correctly. 
        The numbers will be of the form 2, 4, 6, 8...n, 1, 3, 5...(n-1 + n/2) 
    */
    #include <bits/stdc++.h>

    using namespace std;

    int main() {


      int t;
      cin >> t;
      while (t--) {
        int n;
        cin >> n;
        n /= 2;
        if (n & 1) {
          cout << "NO" << endl;
          continue;
        }
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i) {
          cout << i * 2 << " ";
        }
        for (int i = 1; i < n; ++i) {
          cout << i * 2 - 1 << " ";
        }
        cout << 3 * n - 1 << endl;
      }

      return 0;
    }

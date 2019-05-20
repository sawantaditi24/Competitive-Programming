#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while( t-- ) {
        int n, d, f;
        cin >> n;
        vector<long int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        int d1 = a[1] - a[0];
        int d2 = a[2] - a[1];
        int d3 = a[3] - a[2];
        if(2*d1 == (a[2] - a[0]) || 2*d1 == (a[3] - a[1]))
        //that is, if d1 is the actual difference
        {
            d = d1;
            f = a[0];//If d1 is the actual difference, a[0] has to be unchanged.
            for(int i=0; i<n; i++){
                cout<< f + (i*d) << " ";//an = a +(n-1)d
            }
        }
        else if(2*d2 == (a[2] - a[0]) || 2*d2 == (a[3] - a[1]))
        {
            d = d2;//If d1 is not the actual difference, a[0] will be modified.
            f = a[1] - d;
            for(int i=0; i<n; i++){
                cout<< f + (i*d) << " ";
            }
        }
        else if(2*d3 == (a[2] - a[0]) || 2*d3 == (a[3] - a[1])){
            d = d3;
            f = a[2] - (2*d);
            for(int i=0; i<n; i++){
                cout<< f + (i*d) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a;
        cin >> a;
        int ans = 0;
        map<int, int> m;
        for(int i = 0;i < a; i++) {
            int x;
            cin >> x;
            m[abs(x)]++;
        }



        cout << st.size() << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cntL = 0,cntR = 0,cntU = 0,cntD = 0;
        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] == 'L')
                cntL++;
            else if (s[i] == 'R')
                cntR++;
            else if (s[i] == 'U')
                cntU++;
            else
                cntD++;
        }
        int mn = min(cntL,cntR);
        cntL = mn;
        cntR = mn;
        mn = min(cntU,cntD);
        cntU = cntD = mn;
        if (cntL == 0) {
            if (cntU > 0 && cntD > 0) {
                cout << 2 << endl;
                cout << "UD\n";
            }
            else {
                cout << 0 << endl;
            }
            continue;
        }
        if (cntU == 0) {
            if (cntL && cntR) {
                cout << 2 << endl;
                cout << "LR\n";
            }
            else {
                cout << 0 << endl;
            }
            continue;
        }
        cout << cntU + cntD + cntL + cntR << endl;
        for (int i = 1 ; i <= cntL ; i++)
            cout << 'L';
        for (int i = 1 ; i <= cntU ; i++)
            cout << 'U';
        for (int i = 1 ; i <= cntR ; i++)
            cout << 'R';
        for (int i = 1 ; i <= cntD ; i++)
            cout << 'D';
        cout << endl;
    }
}
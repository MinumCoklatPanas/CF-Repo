#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

map<string,int> mp;
map<string,bool> ada;
string tab[15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        mp.clear();
        ada.clear();
        for (int i = 1 ; i <= n ; i++) {
            string ta;
            cin >> ta;
            mp[ta]++;
            tab[i] = ta;
            ada[tab[i]] = 1;
        }
        int cnt = 0;
        for (auto it : mp)  {
            ada[it.first] = 1; 
            cnt += it.second - 1;
            // cout << it.first << " AWAL\n";
            // cout << "================================\n";
            for (int j = 1 ; j < it.second ; j++) {
                // cout << "asu\n";
                for (int i = 0 ; i < 10 ; i++) {
                    string tmp = it.first;
                    tmp[3] = (char)('0' + i);
                    // cout << tmp << " tmp " << ada[tmp] << endl;
                    if (!ada[tmp]) {
                        // "yo\n";
                        for (int k = 1 ; k <= n ; k++) {
                            if (tab[k] == it.first) {
                                tab[k] = tmp;
                                break;
                            }
                        }
                        // for (int k = 1 ; k <= n ; k++)
                        //     cout << tab[k] << endl;
                        ada[tmp] = 1;
                        break;
                    }
                }
            }
            // cout << "================================\n";
        } 
        cout << cnt << endl;
        for (int i = 1 ; i <= n ; i++) 
            cout << tab[i] << endl;
    }
}
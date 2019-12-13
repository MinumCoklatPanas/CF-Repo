#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e3;
const double EPS = 1e-9;

bool cek(string a,string b) {
    int cur = 0;
    for (int i = 0 ; i < b.length() ; i++) {
        if (cur == 3) return true;
        if (a[cur] == b[i])
            ++cur;
    }
    return (cur == 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector< string > tab;
    for (int i = 0 ; i < 10 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            for (int k = 0 ; k < 10 ; k++) {
                string tmp;
                tmp += (char)(i + '0');
                tmp += (char)(j + '0');
                tmp += (char)(k + '0');
                tab.push_back(tmp);
            }
        }
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0 ; i < tab.size() ; i++) {
        if (cek(tab[i],s))
            ++cnt;
    }
    cout << cnt << endl;
}
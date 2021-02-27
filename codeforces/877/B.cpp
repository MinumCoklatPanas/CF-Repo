#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get(int l,int r,vector<int> &pref)
{
    if (l == 0) return pref[r];
    return pref[r] - pref[l - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<int> pref(s.length());
    pref[0] = (s[0] == 'a');
    for (int i = 1 ; i < s.length() ; i++)
    {
        pref[i] = pref[i - 1] + (s[i] == 'a');
    }
    if (pref.back() == 0 || pref.back() == s.length())
    {
        cout << s.length() << endl;
        return 0;
    }
    int mn = INF;
    for (int i = 0 ; i < s.length() ; i++)
    {
        for (int j = i ; j < s.length() ; j++)
        {
            int hapusKiri = 0;
            if (i != 0)
            {
                hapusKiri = i - pref[i - 1];
            }
            int hapusKanan = 0;
            if (j != s.length() - 1)
            {
                hapusKanan = (s.length() - (j + 1)) - get(j + 1,s.length() - 1,pref);
            }
            int hapusTengah = get(i,j,pref);
            // cout << i << " " << j << ": " << hapusKiri << " " << hapusTengah << " " << hapusKanan << endl;
            mn = min(mn,hapusKiri + hapusTengah + hapusKanan);
        }
    }
    int ans = s.length() - mn;
    cout << ans << endl;
    return 0;
}
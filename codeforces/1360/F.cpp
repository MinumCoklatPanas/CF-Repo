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

int cnt(string a,string b)
{
    // assert(a.length() == b.length());
    
    int ret = 0;
    for (int i = 0 ; i < a.length() ; i++)
    {
        ret += (a[i] != b[i]);
    }
    return ret;
}

string tab[15];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        for (int i = 1 ; i <= n ; i++)
            cin >> tab[i];
        string ans = "-1";
        for (int i = 0 ; i < m ; i++)
        {
            string tmp = tab[1];
            // cout << i << " i\n";
            for (char j = 'a' ; j <= 'z' ; j++)
            {
                tmp[i] = j;
                // tmp = "aaa";
                // cout << tmp << ": tmp\n";
                bool cek = 1;
                for (int j = 1 ; j <= n ; j++)
                {
                    int ret = cnt(tmp,tab[j]);
                    // cout << i << " " << ret << endl;
                    if (ret > 1)
                    {
                        // cout << tmp << " " << j << endl;
                        cek = 0;
                        break;
                    }
                }
                // cout << cek << endl;
                // break;
                if (cek)
                {
                    ans = tmp;
                    break;
                }
            }
            if (ans != "-1") break;
        }
        cout << ans << endl;
    }
    return 0;
}
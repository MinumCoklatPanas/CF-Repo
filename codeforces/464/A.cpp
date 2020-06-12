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

bool cek(string s,int ix)
{
    if (ix > 0 && s[ix] == s[ix - 1]) 
    {
        
        return false;
    }
    if (ix > 1 && s[ix] == s[ix - 2]) 
    {
        // cout << "yo\n";
        return false;
    }
    // cout << "yo\n";
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,p;
    cin >> n >> p;
    char bound = 'a' + p - 1;
    string s;
    cin >> s;
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        string tmp = s;
        for (char j = s[i] + 1 ; j <= bound ; j++)
        {
            tmp[i] = j;
            if (cek(tmp,i))
            {
                // cout << i << " " << tmp << endl;
                for (int k = i + 1 ; k < n ; k++)
                {
                    char simpan = tmp[k];
                    bool can = 0;
                    // cout << k << " k\n";
                    for (char l = 'a' ; l <= bound ; l++)
                    {
                        tmp[k] = l;
                        // cout << tmp << " aft\n";
                        if (cek(tmp,k))
                        {
                            can = 1;
                            break;
                        }
                    }
                    if (!can)
                    {
                        goto hell;
                    }
                }
                cout << tmp << endl;
                return 0;
            }
            hell:;
        }
    }
    cout << "NO\n";
    return 0;
}
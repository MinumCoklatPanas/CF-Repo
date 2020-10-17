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

void print(string ans)
{
    reverse(ans.begin(),ans.end());
    while (ans.size() > 1 && ans.back() == 0)
        ans.pop_back();
    reverse(ans.begin(),ans.end());
    cout << "YES\n";
    cout << ans << endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0 ; i < s.length() ; i++)
        for (int j = 0 ; j < s.length() ; j++)
            for (int k = 0 ; k < s.length() ; k++)
            {
                int tmp = s[i] - '0';
                if (j > i)
                {
                    tmp *= 10;
                    tmp += s[j] - '0';
                    if (k > j)
                    {
                        tmp *= 10;
                        tmp += s[k] - '0';
                        if (tmp % 8 == 0)
                        {
                            string ans;
                            ans += s[i];
                            ans += s[j];
                            ans += s[k];
                            print(ans);
                        }
                    }
                    else
                    {
                        if (tmp % 8 == 0)
                        {
                            string ans;
                            ans += s[i];
                            ans += s[j];
                            print(ans);
                        }
                    }
                }
                else
                {
                    if (tmp % 8 == 0)
                    {
                        string ans;
                        ans += s[i];
                        print(ans);
                    }
                }
            }
    cout << "NO\n";
    return 0;
}
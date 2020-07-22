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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        int l = 0;
        int r = n - 1;
        bool flip = 0;
        vector<int> ans;
        for (int i = 0 ; i < n ; i++)
        {
            // cout << l << " " << r << " " << flip << endl;
            if (!flip)
            {
                if (s[l] == t.back())
                {
                    ans.push_back(1);
                }
                ans.push_back(t.length());
            }
            else
            {
                if (s[l] != t.back())
                {
                    ans.push_back(1);
                }
                ans.push_back(t.length());
            }
            flip ^= 1;
            if (l < r)
                ++l;
            else
                --l;
            swap(l,r);
            t.pop_back();
        }
        cout << ans.size() << " ";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
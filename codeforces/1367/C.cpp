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

int cei(int x,int y)
{
    return ((x / y) + (x % y != 0));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        set<int> st;
        for (int i = 0 ; i < s.length() ; i++) if (s[i] == '1')
            st.insert(i);
        // cout << st.size() << endl;
        for (int i = 0 ; i < s.length() ; i++) if (s[i] == '0')
        {
            // cout << i << " i\n";
            if (st.empty())
                st.insert(i);
            else
            {
                int dist_bef = INF,dist_aft = INF;
                auto it = st.lower_bound(i);
                if (it != st.begin())
                {
                    --it;
                    dist_bef = abs(i - (*it)) - 1;
                }
                it = st.upper_bound(i);
                if (it != st.end())
                {
                    dist_aft = abs(i - (*it)) - 1;
                }
                // cout << dist_bef << " " << dist_aft << endl;
                if (dist_aft >= k && dist_bef >= k)
                    st.insert(i);
            }
        }
        int cnt = 0;
        for (int i = 0 ; i < s.length() ; i++) cnt += (s[i] == '1');
        cout << st.size() - cnt << endl;
    }
    return 0;
}
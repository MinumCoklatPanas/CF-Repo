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

bool cek1(string s)
{
    for (int i = 0 ; i + 1 < s.length() ; i++)
    {
        if (s[i] == 'y' && s[i + 1] == 'x') return true;
    }
    return false;
}

bool cek2(string s)
{
    for (int i = 0 ; i + 1 < s.length() ; i++)
    {
        if (s[i] == 'x' && s[i + 1] == 'y') return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector< pair<char,ll> > vp;
    for (ll i = 0 ; i < s.length() ; i++)
    {
        if (vp.size() == 0)
        {
            vp.push_back({s[i],1});
        }
        else
        if (vp.back().first == s[i])
            ++vp.back().second;
        else
            vp.push_back({s[i],1}); 
    }
    stack< pair<char,int> > st;
    st.push(vp[0]);
    for (int i = 1 ; i < vp.size() ; i++)
    {
        if (vp[i].first == st.top().first)
            st.top().second += vp[i].second;
        else
        {
            if (st.top().second > vp[i].second)
            {
                st.top().second -= vp[i].second;
            }
            else
            {
                vp[i].second -= st.top().second;
                st.pop();
                st.push(vp[i]);
            }
        }
    }
    assert(st.size() == 1);
    for (int i = 1 ; i <= st.top().second ; i++)
        cout << st.top().first;
    cout << endl;
    return 0;
}
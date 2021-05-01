#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
#define int long long
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> tab(n);
    for (auto &it : tab) cin >> it;
    vector<int> NLE_kiri(n,-1),NLE_kanan(n,-1);
    vector<int> dp_kiri(n,0),dp_kanan(n,0);
    const auto computeNLEKanan = [&]() -> void
    {
        stack<int> st;
        st.push(0);
        for (int i = 1 ; i < n ; i++)
        {
            while (!st.empty() && tab[st.top()] > tab[i])
            {
                NLE_kanan[st.top()] = i;
                st.pop(); 
            } 
            st.push(i);
        }
    };

    const auto computeNLEKiri = [&]() -> void
    {
        stack<int> st;
        st.push(n - 1);
        for (int i = n - 1 ; i >= 0 ; i--)
        {
            while (!st.empty() && tab[st.top()] > tab[i])
            {
                NLE_kiri[st.top()] = i;
                st.pop(); 
            } 
            st.push(i);
        }
    };

    computeNLEKanan();
    computeNLEKiri();

    for (int i = 0 ; i < n ; i++)
    {
        if (NLE_kiri[i] == -1)
            dp_kiri[i] = (i + 1) * tab[i];
        else
            dp_kiri[i] = (i - NLE_kiri[i]) * tab[i] + dp_kiri[NLE_kiri[i]];
    }

    for (int i = n - 1 ; i >= 0 ; i--)
    {
        if (NLE_kanan[i] == -1)
            dp_kanan[i] = (n - i) * tab[i];
        else
            dp_kanan[i] = (NLE_kanan[i] - i) * tab[i] + dp_kanan[NLE_kanan[i]];
    }

    int mx = 0;
    int ix = -1;
    for (int i = 0 ; i < n ; i++)
    {
        int sum = dp_kiri[i] + dp_kanan[i] - tab[i];
        if (sum > mx)
        {
            mx = sum;
            ix = i;
        }
    }
    int last = tab[ix];
    for (int i = ix ; i >= 0 ; i--)
    {
        last = min(last,tab[i]);
        tab[i] = last;
    }
    last = tab[ix];
    for (int i = ix ; i < n ; i++)
    {
        last = min(last,tab[i]);
        tab[i] = last;
    }
    for (auto it : tab)
        cout << it << " ";
    cout << endl;
    return 0;
}
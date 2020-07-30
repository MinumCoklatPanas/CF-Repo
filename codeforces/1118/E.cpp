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

bool cek(vector<pair<int,int>> &tab,int k)
{
    map<pair<int,int>,bool> ada;
    for (int i = 0 ; i < tab.size() ; i++)
    {
        if (tab[i].first > k || tab[i].second > k) return false;
        if (tab[i].first == tab[i].second) return false;
        if (ada[tab[i]]) return false;
        ada[tab[i]] = 1;
        if (i > 0)
        {
            if (tab[i].first == tab[i - 1].first || tab[i].second == tab[i - 1].second) return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin >> n >> k;
    if (k * (k - 1) < n)
    {
        cout << "NO\n";
        return 0;
    }
    deque<int> dq;
    for (int i = 1 ; i <= k ; i++)
        dq.push_back(i);
    dq.pop_front();
    dq.push_back(1);
    int ptr = 0;
    vector< pair<int,int> > tab;
    cout << "YES\n";
    for (int i = 1 ; i <= n ; i++)
    {
        int tmp = i % k;
        if (tmp == 0)
            tmp = k;
        cout << tmp << " " << dq[ptr] << endl;
        tab.emplace_back(tmp,dq[ptr]);
        ++ptr;
        if (ptr == k)
        {
            tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
            ptr = 0;
        }
    }
    assert(cek(tab,k));
    return 0;
}
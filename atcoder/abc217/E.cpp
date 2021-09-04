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
    int q;
    cin >> q;
    multiset<int> ms;
    queue<int> buffer;
    while (q--)
    {
        int ask;
        cin >> ask;
        if (ask == 1)
        {
            int x;
            cin >> x;
            buffer.push(x);
        }
        else
        if (ask == 2)
        {
            if (ms.empty())
            {
                int tmp = buffer.front();
                buffer.pop();
                cout << tmp << endl;
            }
            else
            {
                cout << *(ms.begin()) << endl;
                ms.erase(ms.begin());
            }
        }
        else
        {
            while (!buffer.empty())
            {
                int cur = buffer.front();
                buffer.pop();
                ms.insert(cur);
            }
        }
    }
    return 0;
}
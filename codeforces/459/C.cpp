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

int ans[1010][1010];
int n,k,d;

void fill(int ix,int num)
{
    stack<int> st;
    while (st.size() < d)
    {
        st.push(num % k);
        num /= k;
    }
    for (int i = 1 ; i <= d ; i++)
    {
        int cur = st.top();
        st.pop();
        ans[i][ix] = cur + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> d;
    if (log2(n) - (1.0 * d * log2(k)) > EPS)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0 ; i < n ; i++)
        fill(i + 1,i);
    for (int i = 1 ; i <= d ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
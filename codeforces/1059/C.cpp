// time-limit: 2000
// problem-url: https://codeforces.com/contest/1059/problem/C
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
#define MULTI_TC 0

int getTC()
{
    if (MULTI_TC)
    {
        int t;
        cin >> t;
        return t;
    }
    else return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<bool> isPrime(1000001,1);
    isPrime[1] = 0;
    vector<int> primes;
    for (int i = 2 ; i <= 1000000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (int j = i + i ; j <= 1000000 ; j += i)
            isPrime[j] = 0;
    }
    vector<int> largestPrime(1000001,-1);
    for (int i = 2 ; i <= 1000000 ; i++)
    {
        if (isPrime[i])
            largestPrime[i] = i;
        else
            largestPrime[i] = largestPrime[i - 1];
    }
    vector<int> ans;
    const auto solve = [&](int l,int r,int mul) -> void
    {
        while (1)
        {
            // cout << l <<" " << r << endl;
            if (l == r)
            {
                assert(l == 1);
                ans.push_back(mul);
                return;
            }
            int mn = INF;
            int ambil = -1;
            for (auto it : primes)
            {
                if (it > r) break;
                int kelipatan = r / it;
                int sisa = r - kelipatan;
                // cout << it << " " << sisa << endl;
                if (sisa <= mn)
                {
                    // sisa = mn;
                    mn = sisa;
                    ambil = it;
                }
            }
            // return;
            // assert(mn != INF);
            for (int i = 1 ; i <= mn ; i++)
                ans.push_back(mul);
            r /= ambil;
            mul *= ambil;
        }
    };
    solve(1,n,1);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = getTC();
    while (t--)
    {
        solve();
    }
    return 0;
}
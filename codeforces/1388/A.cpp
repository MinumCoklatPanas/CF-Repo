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

bool isPrime[200010];

bool almost(int x)
{
    for (ll i = 1 ; i * i < x ; i++) if (x % i == 0)
    {
        if (isPrime[i] && isPrime[x / i]) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 1 ; i <= 200000 ; i++) if (isPrime[i])
    {
        for (int j = i + i ; j <= 200000 ; j += i)
            isPrime[j] = 0;
    }
    vector<int> tab;
    for (int i = 1 ; i <= 200000 ; i++) if (almost(i))
        tab.push_back(i);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 30)
            cout << "NO\n";
        else
        {
            bool ada = 0;
            int rem = n - 16;
            for (int i = 2 ; i < tab.size() ; i++)
            {
                if (rem - tab[i] > 0 && rem - tab[i] != tab[i] && rem - tab[i] != 6 && rem - tab[i] != 10)
                {
                    cout << "YES\n";
                    cout << 6 << " " << 10 << " " << tab[i] << " " << rem - tab[i] << endl;
                    goto hell;
                }
            }
            cout << "NO\n";
            hell:;
        }
    }
    return 0;
}
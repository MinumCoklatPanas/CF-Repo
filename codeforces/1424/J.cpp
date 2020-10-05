#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#define int long long

int readInt ()
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true)
    {
            if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

vector<int> primes;
int isPrime[1000010];

signed main()
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2 ; i <= 1000000 ; i++) if (isPrime[i])
    {
        primes.push_back(i);
        for (int j = i * i ; j <= 1000000 ; j += i)
            isPrime[j] = 0;
    }
    int t = readInt();
    while (t--)
    {
        int n = readInt();
        int tmp = (int)sqrt(n);
        int pos = upper_bound(primes.begin(),primes.end(),tmp) - primes.begin();
        int right_bound = upper_bound(primes.begin(),primes.end(),n) - primes.begin();
        int ans = right_bound - pos + 1;
        printf("%lld\n",ans);
    }
    return 0;
}
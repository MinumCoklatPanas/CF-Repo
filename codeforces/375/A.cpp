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

bool cek(int a)
{
    bool ada1 = 0;
    bool ada6 = 0;
    bool ada8 = 0;
    bool ada9 = 0;
    while (a)
    {
        ada1 |= (a % 10 == 1);
        ada6 |= (a % 10 == 6);
        ada8 |= (a % 10 == 8);
        ada9 |= (a % 10 == 9);
        a /= 10;
    }
    return (ada1 && ada6 && ada8 && ada9);
}

bool cek(string s)
{
    if (s[0] == '0') return 0;
    int cur = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {
        cur = (cur * 10) % 7;
        int tmp = s[i] - '0';
        cur = (cur + tmp) % 7;
    }
    return (cur == 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    auto start = clock();
    string s;
    cin >> s;
    string tmp;
    int cnt = 0;
    for (int i = 0 ; i < s.length() ; i++)
    {   
        if (s[i] == '0')
            ++cnt;
        else
            tmp += s[i];
    }
    while (1)
    {
        auto cur = clock();
        double rt = (double) (cur - start) / (double) CLOCKS_PER_SEC;
        if (rt >= 0.98) break;
        if (cek(tmp))
        {
            for (int i = 1 ; i <= cnt ; i++)
                tmp += '0';
            cout << tmp << endl;
            return 0;
        }
        shuffle(tmp.begin(),tmp.end(),rng);
    }
    cout << 0 << endl;
    return 0;
}
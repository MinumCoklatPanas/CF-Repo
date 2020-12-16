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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int lost_kiri = 0;
    int lost_kanan = 0;
    int sum_kiri = 0;
    int sum_kanan = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (i < n / 2)
        {
            if (s[i] == '?')
                lost_kiri++;
            else
                sum_kiri += (s[i] - '0');
        }
        else
        {
            if (s[i] == '?')
                lost_kanan++;
            else
                sum_kanan += (s[i] - '0');
        }
    }
    if (lost_kiri + lost_kanan == 0)
    {
        if (sum_kiri == sum_kanan)
            cout << "Bicarp\n";
        else
            cout << "Monocarp\n";
        return 0;
    }
    int tot = lost_kiri + lost_kanan;
    int curBal = sum_kiri - sum_kanan;
    int minBal = curBal - 9 * lost_kanan;
    int maxBal = curBal + 9 * lost_kiri;
    if (minBal + maxBal == 0)
        cout << "Bicarp\n";
    else
        cout << "Monocarp\n";
    return 0;
}
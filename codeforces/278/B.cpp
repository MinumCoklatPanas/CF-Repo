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

string tab[35];
int n;

bool cek(string s)
{
    for (int i = 1 ; i <= n ; i++)
    {
        if (tab[i].find(s) != string::npos) return false;
    }
    return true;
}

void rec(int maxDepth,string s)
{
    if (s.length() == maxDepth)
    {
        if (cek(s))
        {
            cout << s << endl;
            exit(0);
        }
        else return;
    }
    for (char i = 'a' ; i <= 'z' ; i++)
    {
        rec(maxDepth,s + i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> tab[i];
    rec(1,"");
    rec(2,"");
    rec(3,"");
    return 0;
}
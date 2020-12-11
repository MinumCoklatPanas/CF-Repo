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

pair<string,int> tab[510];
char ans[510];
int n;

bool cmp(pair<string,int> a,pair<string,int> b)
{
    return (a.first.length() < b.first.length());
}

bool isPrefix(string a,string b)
{
    for (int i = 0 ; i < a.size() ; i++) if (a[i] != b[i]) return false;
    return true;
}

bool isSuffix(string a,string b)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    return isPrefix(a,b);
}

void getAns(string s)
{
    for (int i = 1 ; i <= 2 * n - 2 ; i += 2)
    {
        if (isPrefix(tab[i].first,s))
        {
            if (!isSuffix(tab[i + 1].first,s)) return;
            // assert(isSuffix(tab[i + 1].first,s));
            ans[tab[i].second] = 'P';
            ans[tab[i + 1].second] = 'S';
        }
        else
        {
            if (!isSuffix(tab[i].first,s)) return;
            if (!isPrefix(tab[i + 1].first,s)) return;
            ans[tab[i].second] = 'S';
            ans[tab[i + 1].second] = 'P';
        }
    }
    for (int i = 1 ; i <= 2 * n - 2 ; i++)
        cout << ans[i];
    cout << endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= 2 * n - 2 ; i++)
    {
        cin >> tab[i].first;
        tab[i].second = i;
    }
    sort(tab + 1,tab + (2 * n - 2) + 1,cmp);
    string smol1 = tab[1].first;
    string smol2 = tab[2].first; 
    string big1 = tab[2 * n - 2].first;
    string big2 = tab[2 * n - 3].first;

    string a = smol1 + big1;
    string b = smol2 + big2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = smol1 + big1;
    b = big2 + smol2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = big1 + smol1;
    b = smol2 + big2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = big1 + smol1;
    b = big2 + smol2;
    if (a == b) getAns(a);

    swap(smol1,smol2);

    a = smol1 + big1;
    b = smol2 + big2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = smol1 + big1;
    b = big2 + smol2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = big1 + smol1;
    b = smol2 + big2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = big1 + smol1;
    b = big2 + smol2;
    if (a == b) getAns(a);

    swap(smol1,smol2);
    swap(big1,big2);

    a = smol1 + big1;
    b = smol2 + big2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = smol1 + big1;
    b = big2 + smol2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = big1 + smol1;
    b = smol2 + big2;
    if (a == b) getAns(a);
    // cout << a << " " << b << endl;

    a = big1 + smol1;
    b = big2 + smol2;
    if (a == b) getAns(a);

    cout << "hehe\n";
    return 0;
}
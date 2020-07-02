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

int tab[200010];

bool cmp(int a,int b)
{
    return tab[a] < tab[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> neg,pos,nol;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta == 0)
            nol.push_back(i);
        else
        if (ta > 0)
            pos.push_back(i);
        else
            neg.push_back(i);
        tab[i] = ta;
    }
    // cout << (int)pos.size() << " " << (int)neg.size() << endl;
    if ((int)neg.size() % 2 == 0)
    {
        // cout << "yo\n";
        if ((int)nol.size() > 1)
        {
            for (int i = 0 ; i < (int)nol.size() - 1 ; i++)
            {
                cout << 1 << " " << nol[i] << " " << nol.back() << endl;
            }
        }
        // return 0;
        if ((int)nol.size() > 0 && (int)nol.size() != n)
            cout << 2 << " " << nol.back() << endl;
        if ((int)pos.size() > 0)
        {
            for (int i = 0 ; i < (int)pos.size() - 1 ; i++)
                cout << 1 << " " << pos[i] << " " << pos.back() << endl;
            for (int i = 0 ; i < (int)neg.size() ; i++)
                cout << 1 << " " << neg[i] << " " << pos.back() << endl;
        }
        else
        if ((int)neg.size() > 0)
        {
            for (int i = 0 ; i < (int)neg.size() - 1 ; i++)
                cout << 1 << " " << neg[i] << " " << neg.back() << endl; 
        }
    }
    else
    {
        sort(neg.begin(),neg.end(),cmp);
        if ((int)nol.size() > 0)
        {
            for (auto it : nol)
                cout << 1 << " " << it << " " << neg.back() << endl;

        }
        if (nol.size() == n - 1) return 0;
        cout << 2 << " " << neg.back() << endl;
        neg.pop_back();
        if ((int)pos.size() > 0)
        {
            for (int i = 0 ; i < (int)pos.size() - 1 ; i++)
                cout << 1 << " " << pos[i] << " " << pos.back() << endl;
            for (int i = 0 ; i < (int)neg.size() ; i++)
                cout << 1 << " " << neg[i] << " " << pos.back() << endl;
        }
        else
        if ((int)neg.size() > 1)
        {
            for (int i = 0 ; i < (int)neg.size() - 1 ; i++)
                cout << 1 << " " << neg[i] << " " << neg.back() << endl; 
        }
    }
    return 0;
}
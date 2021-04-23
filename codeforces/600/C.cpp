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

deque<char> makePalindrome(vector<int> &frek)
{
    deque<char> dq;
    int simpan = -1;
    for (int i = 0 ; i < 26 ; i++)
    {
        if (frek[i] % 2 == 0)
        {
            for (int j = 1 ; j <= frek[i] / 2 ; j++)
                dq.push_back('a' + i);
            // frek[i] -= (frek[i] / 2);
            frek[i] /= 2;
        }
        else
        {
            for (int j = 1 ; j <= frek[i] / 2 ; j++)
                dq.push_back('a' + i);
            frek[i] -= (frek[i] / 2);
            simpan = i;
        }
    }
    if (simpan != -1)
    {
        dq.push_back('a' + simpan);
        frek[simpan]--;
    }
    for (int i = 25 ; i >= 0 ; i--)
    {
        for (int j = 1 ; j <= frek[i] ; j++)
            dq.push_back('a' + i);
    }
    return dq;
}

bool isPalindrome(deque<char> dq)
{
    deque<char> tmp = dq;
    reverse(tmp.begin(),tmp.end());
    return (tmp == dq);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int n;
    // cin >> n;

    string s;
    cin >> s;
    int n = s.length();
    vector<int> frek(26,0);
    for (int i = 0 ; i < n ; i++)
        frek[s[i] - 'a']++;
    // for (auto it : frek)
    //     cout << it << " ";
    // cout << endl;
    // for (int i = 0 ; i < 26 ; i++)
    //     cout << (char)('a' + i) << " ";
    // cout << endl;
    vector<int> ganjil;
    for (int i = 0 ; i < 26 ; i++) if (frek[i] % 2 == 1)
    {
        ganjil.push_back(i);
    }
    if (n % 2 == 0)
    {
        if (ganjil.size() > 0)
        {
            int sz = ganjil.size();
            for (int i = sz / 2 ; i < ganjil.size() ; i++)
            {
                --frek[ganjil[i]];
                ++frek[ganjil[i - (sz / 2)]];
            }
        }
    }
    else
    {
        if (ganjil.size() > 1)
        {
            // ganjil.pop_back();
            int sz = ganjil.size();
            for (int i = (sz + 1) / 2 ; i < ganjil.size() ; i++)
            {
                --frek[ganjil[i]];
                ++frek[ganjil[i - ((sz + 1) / 2)]];
            }
        }
    }
    deque<char> ans = makePalindrome(frek);
    assert(ans.size() == n);
    assert(isPalindrome(ans));
    for (auto it : ans)
        cout << it;
    cout << endl;
    return 0;
}
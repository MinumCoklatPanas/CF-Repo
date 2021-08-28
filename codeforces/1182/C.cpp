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

struct lyrics
{
    pair<string,string> atas;
    pair<string,string> bawah;
    lyrics()
    {
        atas = {"-","-"};
        bawah = {"-","-"};
    }
};


void solve()
{
    int n;
    cin >> n;
    vector<multiset<string>> allString(1000010);
    vector<vector<multiset<string>>> endWith(1000010,vector<multiset<string>>(5));
    const auto vowel = [&](char c) -> int
    {
        if (c == 'a') return 0;
        if (c == 'i') return 1;
        if (c == 'u') return 2;
        if (c == 'e') return 3;
        if (c == 'o') return 4;
        return -1;
    };
    for (int i = 1 ; i <= n ; i++)
    {
        string s;
        cin >> s;
        int cntVowel = 0,lastVowel = -1;
        for (auto it : s) if (vowel(it) != -1)
        {
            cntVowel++;
            lastVowel = vowel(it);
        }
        allString[cntVowel].insert(s);
        endWith[cntVowel][lastVowel].insert(s);
    }
    vector<lyrics> ans;
    for (int len = 1 ; len <= 1000000 ; len++)
    {
        for (int lastVowel = 0 ; lastVowel < 5 ; lastVowel++)
        {
            while (endWith[len][lastVowel].size() > 1)
            {
                string a = *endWith[len][lastVowel].begin();
                endWith[len][lastVowel].erase(endWith[len][lastVowel].begin());
                string b = *endWith[len][lastVowel].begin();
                endWith[len][lastVowel].erase(endWith[len][lastVowel].begin());
                ans.push_back(lyrics());
                ans.back().atas.second = a;
                ans.back().bawah.second = b;
                allString[len].erase(allString[len].find(a));
                allString[len].erase(allString[len].find(b));
            }
        }
    }
    int ptr = 0;
    for (int len = 1 ; len <= 1000000 ; len++) 
    {
        while (allString[len].size() > 1 && ptr < ans.size())
        {
            string a = *allString[len].begin();
            allString[len].erase(allString[len].begin());
            string b = *allString[len].begin();
            allString[len].erase(allString[len].begin());
            ans[ptr].atas.first = a;
            ans[ptr].bawah.first = b;
            ++ptr;
        }
    }
    vector<lyrics> all;
    for (int i = 0 ; i < ptr ; i++) 
    {
        all.push_back(ans[i]);
    }
    for ( ; ptr + 1 < ans.size() ; ptr += 2)
    {
        lyrics tmp;
        tmp.atas.first = ans[ptr].atas.second;
        tmp.bawah.first = ans[ptr].bawah.second;
        tmp.atas.second = ans[ptr + 1].atas.second;
        tmp.bawah.second = ans[ptr + 1].bawah.second;
        all.push_back(tmp);
    }
    cout << all.size() << endl;
    for (auto it : all)
    {
        cout << it.atas.first << " " << it.atas.second << endl;
        cout << it.bawah.first << " " << it.bawah.second << endl; 
    }
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
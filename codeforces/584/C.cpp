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

bool valid(string ans,string s1,string s2,int t)
{
    if (ans == "-1") return true;
    int f1 = 0;
    for (int i = 0 ; i < ans.size() ; i++) f1 += (s1[i] != ans[i]);
    int f2 = 0;
    for (int i = 0 ; i < ans.size() ; i++) f2 += (s2[i] != ans[i]);
    // cout << f1 << " " << f2 << endl;
    return ((f1 == f2) && (f1 == t));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin >> n >> t;
    int simpen = t;
    string s1,s2;
    cin >> s1 >> s2;
    int f1 = 0,f2 = 0;
    string ans;
    for (int i = 1 ; i <= n ; i++) ans += '-';
    vector<int> beda,sama;
    for (int i = 0 ; i < n ; i++)
    {
        if (s1[i] != s2[i])
            beda.push_back(i);
        else
            sama.push_back(i);
    }
    if (beda.size() <= t)
    {
        for (auto it : beda)
        {
            int tmp = uniform_int_distribution<int>(0,25)(rng);
            char ta = 'a' + tmp;
            while (ta == s1[it] || ta == s2[it])
            {
                tmp = uniform_int_distribution<int>(0,25)(rng);
                ta = 'a' + tmp;
            }
            ans[it] = ta;
        }
        t -= beda.size();
        for (int i = 0 ; i < t ; i++)
        {
            int it = sama[i];
            int tmp = uniform_int_distribution<int>(0,25)(rng);
            char ta = 'a' + tmp;
            while (ta == s1[it] || ta == s2[it])
            {
                tmp = uniform_int_distribution<int>(0,25)(rng);
                ta = 'a' + tmp;
            }
            ans[it] = ta;
        }
        for (int i = t ; i < sama.size() ; i++)
        {
            ans[sama[i]] = s1[sama[i]];
        }
    }
    else
    {
        if (0)
            ans = "-1";
        else
        {
            int diff = (beda.size() - t);
            if (diff * 2 > beda.size())
            {
                ans = "-1";
            }
            else
            {
                for (int i = 0 ; i < diff ; i++)
                {
                    int ambilA = beda[2 * i];
                    int ambilB = beda[2 * i + 1];
                    ans[ambilA] = s1[ambilA];
                    ans[ambilB] = s2[ambilB];
                }
                for (int i = 2 * diff ; i < beda.size() ; i++)
                {
                    int it = beda[i];
                    int tmp = uniform_int_distribution<int>(0,25)(rng);
                    char ta = 'a' + tmp;
                    while (ta == s1[it] || ta == s2[it])
                    {
                        tmp = uniform_int_distribution<int>(0,25)(rng);
                        ta = 'a' + tmp;
                    }
                    ans[it] = ta;
                }
                for (auto it : sama)
                {
                    ans[it] = s1[it];
                }
            }
        }
    }
    cout << ans << endl;
    assert(valid(ans,s1,s2,simpen));
    return 0;
}
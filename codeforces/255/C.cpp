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

vector<int> pos[1000010];
int frek[1000010];
int tab[4010];

int calc(vector< vector<int> > &a)
{
    int ix = 1;
    int cur = a[0][0];
    int ans = 1;
    while (1)
    {
        int nxt = lower_bound(a[ix].begin(),a[ix].end(),cur) - a[ix].begin();
        if (nxt == a[ix].size()) break;
        ++ans;
        cur = a[ix][nxt];
        ix ^= 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> tab[i];
        nums.push_back(tab[i]);
        pos[tab[i]].push_back(i);
        frek[tab[i]]++;
    }
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    // cout << nums.size() << endl;
    // return 0;
    int ans = 0;
    for (auto it : nums)
        ans = max(ans,frek[it]);
    for (int i = 0 ; i < nums.size() ; i++)
    {
        for (int j = i + 1 ; j < nums.size() ; j++)
        {
            // ans = max(ans,frek[nums[i]]);
            // ans = max(ans,frek[nums[j]]);
            if (frek[nums[i]] + frek[nums[j]] <= ans) continue;
            // cout << nums[i] << " " << nums[j] << endl;
            // continue;
            vector< vector<int> > a(2);
            if (pos[nums[i]][0] < pos[nums[j]][0])
            {
                a[0] = pos[nums[i]];
                a[1] = pos[nums[j]];
            }
            else
            {
                a[0] = pos[nums[j]];
                a[1] = pos[nums[i]];
            }
            // continue;
            ans = max(ans,calc(a));
            // swap(a[0],a[1]);
            // ans = max(ans,calc(a));
        }
    }
    cout << ans << endl;
    return 0;
}
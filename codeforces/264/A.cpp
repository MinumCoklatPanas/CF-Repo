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

char tmp[1000010];

int main()
{
    deque<int> dq;
    scanf("%s",tmp);
    string s;
    s = tmp;
    dq.push_back(s.length());
    reverse(s.begin(),s.end());
    int cur = dq.back() - 1;

    for (int i = 1 ; i < s.length() ; i++)
    {
        if (s[i] == 'l')
            dq.push_back(cur);
        else
            dq.push_front(cur);
        --cur;
    }
    for (int i = 0 ; i < dq.size() ; i++)
        printf("%d\n",dq[i]);
    return 0;
}
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

int f(int x,int y,int z)
{
    int sum = x * x + y * y + z * z + x * y + x * z + y * z;
    return sum;
}

pair<int,int> akar(int x,int y,int n)
{
    int a = 1;
    int b = x + y;
    int c = x * x + y * y + x * y - n;
    int D = b * b - 4 * a * c;
    if (D < 0) return {-1,-1};
    pair<int,int> res;
    //plus
    double tmp = (-b + sqrt(1.0 * D)) / 2.0;
    // cout << tmp << " ";
    if (f(x,y,(int)tmp) == n)
        res.first = (int)tmp;
    else
        res.first = -1;
    
    tmp = (-b - sqrt(1.0 * D)) / 2.0;
    // cout << tmp << endl;
     if (f(x,y,(int)tmp) == n)
        res.second = (int)tmp;
    else
        res.second = -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << f(1,1,-2) << endl;
    // return 0;
    // auto tmp = akar(2,2,17);
    // return 0;
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        int ans = 0;
        for (int x = 1 ; x * x <= i ; x++)
            for (int y = 1 ; y * y <= i ; y++)
            {
                auto root = akar(x,y,i);
                // cout << x << " " << y << ": " << root.first << " " << root.second << endl;
                ans += (root.first >= 1);
                ans += (root.second >= 1);
            }
        cout << ans << endl;
        // cout << i << ": " << ans << endl;
        // cout << ans << endl;
    }
    return 0;
}
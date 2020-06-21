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

bool cek(int a,int b,int c)
{
    return (a * a + b * b == c * c);
}

vector< pair<int,int> > fnd(int c)
{
    vector< pair<int,int> > ret;
    for (int i = 1 ; i <= c ; i++)
        for (int j = i + 1 ; j <= c ; j++)
        {
            if (cek(i,j,c))
            {
                ret.emplace_back(i,j);
            }
        }
    if (ret.size() == 0)
    {
        cout << "NO\n";
        exit(0);
    }
    return ret;
}

void print(pair<int,int> a,pair<int,int> b,int sum)
{
    int dx = abs(a.first - b.first); 
    dx *= dx;
    int dy = abs(a.second - b.second);
    dy *= dy;
    if (dx == 0 || dy == 0) return;
    if (dx + dy == sum)
    {
        cout << "YES\n";
        cout << "0 0\n";
        cout << a.first << " " << a.second << endl;
        cout << b.first << " " << b.second;
        exit(0);
    }
}

void test(pair<int,int> it,pair<int,int> it2,int sum)
{
    auto tmp1 = it;
    auto tmp2 = it2;
    print(tmp1,tmp2,sum);

    tmp2.first *= -1;
    print(tmp1,tmp2,sum);
    tmp2.first *= -1;

    swap(tmp2.first,tmp2.second);
    print(tmp1,tmp2,sum);
    swap(tmp2.first,tmp2.second);

    swap(tmp2.first,tmp2.second);
    tmp2.first *= -1;
    print(tmp1,tmp2,sum);
    swap(tmp2.first,tmp2.second);
    tmp2.first *= -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin >> a >> b;
    auto deltaA = fnd(a);
    auto deltaB = fnd(b);
    int sum = a * a + b * b;
    // assert(abs(deltaA.first + deltaB.second) * (abs(deltaA.first + deltaB.second)) + abs(deltaA.second - deltaB.first) * abs(deltaA.second - deltaB.first) == a * a + b * b);
    for (auto it : deltaA)
    {
        for (auto it2 : deltaB)
        {
            auto tmp1 = it;
            auto tmp2 = it2;
            test(tmp1,tmp2,sum);
            test(tmp2,tmp1,sum);
        }
    }
    cout << "NO\n";
    return 0;
}
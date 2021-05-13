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

void bf()
{
    string s = "";
    for (int i = 1 ; i <= 99 ; i++)
    {
        for (int j = 1 ; j <= i ; j++)
            s += to_string(j);
        if (i > 9)
            cerr << i << " " << s.length() << endl;
    }
    cerr << s.length() << endl;
}

void solve()
{
    // bf();
    int n;
    cin >> n;
    const auto cnt = [&](int a,int x,int b) -> int
    {   
        int un = a + (x - 1) * b;
        int sn = ((a + un) * x) / 2;
        return sn;
    };

    vector<int> prec;
    vector<int> starts;

    int cur = 0;
    int len = 1;
    int pengali = 9;
    int lst = 0;
    while (cur <= INFF)
    {
        lst += len;
        cur += cnt(lst,pengali,len);
        starts.push_back(lst);
        // cout << len << " " << lst << " " << pengali << " " << cur << endl;
        lst = lst + (pengali - 1) * len;
        ++len;
        pengali *= 10;
        prec.push_back(cur);
    }
    int cari = 0;
    while (prec[cari] < n) ++cari;
    // cout << cari << endl;
    int now = (cari == 0 ? 0 : prec[cari - 1]);
    int angka = 1;
    int ub = 9;
    for (int i = 1 ; i <= cari ; i++) angka *= 10,ub *= 10;

    const auto valid = [&](int x) -> bool
    {
        return (now + cnt(starts[cari],x,cari + 1) <= n);
    };

    // cout << now + cnt(starts[cari],1,cari + 1) << endl;
    // return;

    const auto cariBatas = [&]() -> int
    {
        int l = 1;
        int r = ub;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (valid(mid))
                l = mid;
            else
                r = mid - 1;
        }
        if (valid(r))
            return r;
        else
        if (valid(l))
            return l;
        else
            return 0;
    };

    int batas = cariBatas();
    // cout << batas << " batas\n";
    
    int sisa = n - (now + cnt(starts[cari],batas,cari + 1));
    angka += batas;
    // cout << angka << " " << sisa << endl;
    if (sisa == 0)
    {
        cout << (angka - 1) % 10 << endl;
        return;
    }

    const auto cariAns = [&]() -> void
    {
        int pengali = 9;
        int cur = 0;
        int panjang;
        for (int i = 1 ; i <= cari + 1 ; i++)
        {
            if (cur + (i * pengali) >= sisa)
            {
                panjang = i;
                break;
            }
            else
                cur += i * pengali;
            pengali *= 10;
        }
        sisa -= cur;
        int awal = 1;
        for (int i = 1 ; i < panjang ; i++) 
        {
            awal *= 10;
        }
        int angkaKe = (sisa / panjang) + (sisa % panjang != 0);
        awal += angkaKe - 1;
        string str = to_string(awal);
        sisa %= panjang;
        if (sisa == 0)
            cout << str.back() << endl;
        else
            cout << str[sisa - 1] << endl;
    };

    cariAns();
    // cout << len << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> ganjil,genap;
    set<int> nums;
    vector<int> tab;
    map<int,int> frek;
    for (int i = 1 ; i <= n ; i++)
    {
        int ta;
        cin >> ta;
        if (ta & 1)
            ganjil.push_back(ta);
        else
            genap.push_back(ta);
        nums.insert(ta);
        tab.push_back(ta);
        frek[ta]++;
    }
    int avail_ganjil,avail_genap;
    avail_genap = m / 2;
    avail_ganjil = avail_genap + (m % 2);
    for (auto it : nums)
    {
        if (it <= m)
        {
            if (it & 1)
                avail_ganjil--;
            else
                avail_genap--;
        }
    }
    int need_ganjil = 0,need_genap = 0;
    const auto countDuplicate = [](vector<int> a) -> int
    {
        int cnt = 1;
        int cur = -1;
        int ret = 0;
        sort(a.begin(),a.end());
        for (auto it : a)
        {
            if (cur != it)
            {
                ret += cnt - 1;
                cnt = 1;
                cur = it;
            }
            else
            {
                cnt++;
            }
        }
        ret += cnt - 1;
        // cerr << ret << " ret\n";
        return ret;
    };
    int changes = 0;
    if (ganjil.size() == genap.size())
    {
        need_ganjil = countDuplicate(ganjil);
        need_genap = countDuplicate(genap);
        if (need_ganjil > avail_ganjil || need_genap > avail_genap)
        {
            cout << -1 << endl;
            return;
        }
        for (auto &it : tab)
        {
            if (frek[it] > 1)
            {
                int ganti = 1 + rng() % m;
                while (frek.count(ganti) || (ganti % 2 != it % 2))
                {
                    ganti = 1 + rng() % m;
                }
                frek[it]--;
                frek[ganti]++;
                it = ganti;
                ++changes;
            }
        }
    }
    else
    if (ganjil.size() > genap.size())
    {
        need_genap = (ganjil.size() - genap.size()) / 2;
        need_genap += countDuplicate(genap);
        need_ganjil = countDuplicate(ganjil) - ((ganjil.size() - genap.size()) / 2);
        if (need_ganjil > avail_ganjil || need_genap > avail_genap)
        {
            cout << -1 << endl;
            return;
        }
        int ganti_genap = (ganjil.size() - genap.size()) / 2;
        //bikin genap jadi unique
        for (auto &it : tab) if (it % 2 == 0 && frek[it] > 1)
        {
            int ganti = 1 + rng() % m;
            while (frek.count(ganti) || ganti % 2 == 1)
            {
                ganti = 1 + rng() % m;
            }
            frek[it]--;
            frek[ganti]++;
            it = ganti;
            changes++;
        }
        //ganti ganjil yang duplicate jadi genap
        for (auto &it : tab) if (it % 2 == 1 && frek[it] > 1 && ganti_genap > 0)
        {
            int ganti = 1 + rng() % m;
            while (frek.count(ganti) || ganti % 2 == 1)
            {
                ganti = 1 + rng() % m;
            }
            frek[it]--;
            frek[ganti]++;
            it = ganti;
            changes++;
            --ganti_genap;
        }
        for (auto &it : tab) if (it % 2 == 1)
        {
            //kalau masih belum balance, ganti jadi genap
            //kalau sudah balance, ganti yang duplicate
            int ganti;
            if (ganti_genap) //yang duplicate pasti sudah habis
            {
                ganti = 1 + rng() % m;
                while (frek.count(ganti) || ganti % 2 == 1)
                {
                    ganti = 1 + rng() % m;
                }
                frek[it]--;
                frek[ganti]++;
                it = ganti;
                changes++;
                --ganti_genap;
            }
            else
            if (frek[it] > 1) //ganti yang duplicate saja
            {
                ganti = 1 + rng() % m;
                while (frek.count(ganti) || ganti % 2 == 0)
                {
                    ganti = 1 + rng() % m;
                }
                frek[it]--;
                frek[ganti]++;
                it = ganti;
                changes++;
            }
        }
    }
    else
    {
        //prioritize ganti yang duplicate jadi ganjil
        //kalo habis baru ganti yang non-duplicate
        need_ganjil = (genap.size() - ganjil.size()) / 2;
        need_ganjil += countDuplicate(ganjil);
        need_genap = countDuplicate(genap) - ((genap.size() - ganjil.size()) / 2);
        if (need_ganjil > avail_ganjil || need_genap > avail_genap)
        {
            cout << -1 << endl;
            return;
        }
        int ganti_ganjil = (genap.size() - ganjil.size()) / 2;
        //bikin ganjil jadi unique
        for (auto &it : tab) if (it % 2 == 1 && frek[it] > 1)
        {
            int ganti = 1 + rng() % m;
            while (frek.count(ganti) || ganti % 2 == 0)
            {
                ganti = 1 + rng() % m;
            }
            frek[it]--;
            frek[ganti]++;
            it = ganti;
            changes++;
        }
        //ganti genap yang duplicate jadi ganjil
        for (auto &it : tab) if (it % 2 == 0 && frek[it] > 1 && ganti_ganjil > 0)
        {
            int ganti = 1 + rng() % m;
            while (frek.count(ganti) || ganti % 2 == 0)
            {
                ganti = 1 + rng() % m;
            }
            frek[it]--;
            frek[ganti]++;
            it = ganti;
            changes++;
            --ganti_ganjil;
        }
        for (auto &it : tab) if (it % 2 == 0)
        {
            //kalau masih belum balance, ganti jadi ganjil
            //kalau sudah balance, ganti yang duplicate
            int ganti;
            if (ganti_ganjil) //yang duplicate pasti sudah habis
            {
                ganti = 1 + rng() % m;
                while (frek.count(ganti) || ganti % 2 == 0)
                {
                    ganti = 1 + rng() % m;
                }
                frek[it]--;
                frek[ganti]++;
                it = ganti;
                changes++;
                --ganti_ganjil;
            }
            else
            if (frek[it] > 1) //ganti yang duplicate saja
            {
                ganti = 1 + rng() % m;
                while (frek.count(ganti) || ganti % 2 == 1)
                {
                    ganti = 1 + rng() % m;
                }
                frek[it]--;
                frek[ganti]++;
                it = ganti;
                changes++;
            }
        }
    }
    cout << changes << endl;
    for (auto it : tab)
        cout << it << " ";
    cout << endl;
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
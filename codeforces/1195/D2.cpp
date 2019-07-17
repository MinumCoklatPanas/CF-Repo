#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 998244353;

vector<ll> sekarangKiri[15][15];
vector<ll> sekarangKanan[15][15];
ll pref[15][100010];
ll tab[100010];
ll kali[25];

ll add(ll x,ll y)
{
	return ((x % MOD) + (y % MOD)) % MOD;
}

ll mul(ll x,ll y)
{
	return ((x % MOD) * (y % MOD)) % MOD;
}

ll dig(ll x)
{
	ll ret = 0;
	while (x)
	{
		++ret;
		x /= 10;
	}
	return ret;
}

void Precom()
{
	//kiri->kanan
	for (ll digitKiri = 1 ; digitKiri <= 10 ; digitKiri++)
		for (ll digitKanan = 1 ; digitKanan <= 10 ; digitKanan++)
		{
			if (digitKiri <= digitKanan)
			{
				for (ll i = 1 ; i <= digitKiri ; i++)
					sekarangKiri[digitKiri][digitKanan].push_back(i * 2);
			}
			else
			{
				for (ll i = 1 ; i <= digitKanan ; i++)
					sekarangKiri[digitKiri][digitKanan].push_back(i * 2);
				for (ll i = 2 * digitKanan + 1 ; i <= digitKiri + digitKanan ; i++)
					sekarangKiri[digitKiri][digitKanan].push_back(i);
			}
			assert(sekarangKiri[digitKiri][digitKanan].size() == digitKiri);
		}
	//kanan -> kiri
	for (ll digitKanan = 1 ; digitKanan <= 10 ; digitKanan++)
		for (ll digitKiri = 1 ; digitKiri <= 10 ; digitKiri++)
		{
			if (digitKanan <= digitKiri)
			{
				for (ll i = 1 ; i <= digitKanan ; i++)
					sekarangKanan[digitKanan][digitKiri].push_back(2 * i - 1);
			}
			else
			{
				for (ll i = 1 ; i <= digitKiri ; i++)
					sekarangKanan[digitKanan][digitKiri].push_back(2 * i - 1);
				for (ll i = 2 * digitKiri + 1 ; i <= digitKiri + digitKanan ; i++)
					sekarangKanan[digitKanan][digitKiri].push_back(i);
			}
			assert(sekarangKanan[digitKanan][digitKiri].size() == digitKanan);
		}
	kali[0] = 1;
	for (ll i = 1 ; i <= 23 ; i++)
		kali[i] = mul(kali[i - 1],10);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Precom();
	// for (int i = 1 ; i <= 10 ; i++)
	// 	for (int j = 1 ; j <= 10 ; j++)
	// 	{
	// 		reverse(sekarangKanan[i][j].begin(),sekarangKanan[i][j].end());
	// 		reverse(sekarangKiri[i][j].begin(),sekarangKiri[i][j].end());
	// 	}
	// for (int i = 0 ; i < 2 ; i++)
	// 	cout << sekarangKanan[2][2][i] << " ";
	// cout << endl;
	// return 0;
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++)
		cin >> tab[i];
	for (ll i = 1 ; i <= n ; i++)
	{
		for (ll j = 1 ; j <= 10 ; j++)
			pref[j][i] = pref[j][i - 1];
		pref[dig(tab[i])][i]++; 
	}
	ll ans = 0;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll jadiKiri = 0;
		ll curDig = dig(tab[i]);
		for (ll j = 1 ; j <= 10 ; j++)
		{
			ll diKanan = pref[j][n];
			// if (diKanan > 0 && i == 1)
			// 	cout << j << endl;
			// if (diKanan > 0 && i == 1)
			// 	cout << diKanan << endl;
			ll tmp = tab[i];
			ll tmpCnt = 0;
			for (ll k = 0 ; k < curDig ; k++)
			{
				tmpCnt = add(tmpCnt,mul(tmp % 10,kali[sekarangKiri[curDig][j][k] - 1]));
				tmp /= 10;
			}
			// if (i == 1 && diKanan > 0)
			// 	cout << tmpCnt << endl;
			jadiKiri = add(jadiKiri,mul(tmpCnt,diKanan));
		}
		// if (i == 1)
		// 	cout << jadiKiri << endl;
		// --pref[curDig][n];
		ll jadiKanan = 0;
		for (ll j = 1 ; j <= 10 ; j++)
		{
			ll diKiri = pref[j][n];
			if (1){
			ll tmp = tab[i];
			ll tmpCnt = 0;
			for (ll k = 0 ; k < curDig ; k++)
			{
				tmpCnt = add(tmpCnt,mul(tmp % 10,kali[sekarangKanan[curDig][j][k] - 1]));
				tmp /= 10;
			}
			// cout << tmpCnt << endl;
			jadiKanan = add(jadiKanan,mul(tmpCnt,diKiri));
			}
		}
		// ++pref[curDig][n];
		// if (i == 1)
		// 	cout << jadiKanan << endl;
		ans = add(ans,jadiKiri);
		ans = add(ans,jadiKanan);
	}
	cout << ans << endl;
}
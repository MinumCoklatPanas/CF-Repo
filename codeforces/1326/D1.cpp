#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;
const ll prime = 137;

ll hashKiri[5010];
ll hashKanan[5010];
ll pan[5010];
string s;
ll pembagi[5010];

ll add(ll x,ll y)
{
	return ((x % MOD) + (y % MOD)) % MOD;
}

ll mul(ll x,ll y)
{
	return ((x % MOD) * (y % MOD)) % MOD;
}

ll sub(ll x,ll y)
{
	ll ret = ((x % MOD) - (y % MOD)) % MOD;
	if (ret < 0)
		ret += MOD;
	return ret;
}

ll modpow(ll x,ll y)
{
	if (!y) return 1;
	ll z = modpow(x,y / 2);
	z = mul(z,z);
	if (y & 1)
		z = mul(z,x);
	return z;
}

ll inv(ll x)
{
	return modpow(x,MOD - 2);
}

ll getNum(char a)
{
	return a - 'a' + 1;
}

ll getLength(pair<ll,ll> a)
{
	ll kiri = a.first + 1;
	ll kanan = s.length() - a.second;
	return kiri + kanan;
}

void precompute()
{
	string tmp = s;
	ll curVal1 = 0;
	ll curVal2 = 0;
	reverse(tmp.begin(),tmp.end());
	// cout << s << " " << tmp << endl;
	for (ll i = 0 ; i < s.length() ; i++)
	{
		hashKiri[i] = add(curVal1,mul(getNum(s[i]),pan[i]));
		hashKanan[i] = add(curVal2,mul(getNum(tmp[i]),pan[i]));
		// cout << hashKiri[i] << " " << hashKanan[i] << endl;
		curVal1 = hashKiri[i];
		curVal2 = hashKanan[i];
		// cout << curVal1 << " " << curVal2 << endl;
		
	}
	// cout << hashKiri[s.length() - 1] << " " << hashKanan[s.length() - 1] << endl;
}

bool isPalin(string a)
{
	string tmp = a;
	reverse(a.begin(),a.end());
	return (a == tmp);
}

ll getPartialKiri(ll l,ll r,ll start)
{
	// ll pembagi = inv(pan[l - start]);
	ll sum = sub(hashKiri[r],hashKiri[l - 1]);
	ll ret = mul(sum,pembagi[l - start]);
	return ret;
}

ll getPartialKanan(ll l,ll r,ll start)
{
	// ll pembagi = inv(pan[l - start]);
	ll sum = sub(hashKanan[r],hashKanan[l - 1]);
	ll ret = mul(sum,pembagi[l - start]);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	pan[0] = 1;
	for (int i = 1 ; i <= 5000 ; i++)
	{
		pan[i] = mul(pan[i - 1],prime);
		pembagi[i] = inv(pan[i]);
	}
	while (t--)
	{
		cin >> s;
		// cout << s << endl;
		if (isPalin(s))
		{
			// cout << "yo\n";
			cout << s << endl;
			continue;
		}
		precompute();
		pair<ll,ll> ans = {-1,s.length()};
		for (ll i = 0 ; i < s.length() ; i++)
		{
			for (ll j = i + 1 ; j < s.length() ; j++)
			{
				ll hashValKiri = add(hashKiri[i],getPartialKiri(j,s.length() - 1,i + 1));
				ll hashValKanan = add(hashKanan[s.length() - 1 - j],getPartialKanan(s.length() - 1 - i,s.length() - 1,s.length() - j));
				if (hashValKiri == hashValKanan)
				{
					// cout << hashValKiri << " " << hashValKanan << endl;
					// cout << i << " " << j << endl;
					// cout << hashKanan[s.length() - 1 - j] << endl;
					pair<ll,ll> tmp = {i,j};
					if (getLength(tmp) > getLength(ans))
						ans = tmp;
				}
			}
		}
		string cek;
		for (ll i = 0 ; i < s.length() ; i++)
		{
			ll hashValKiri =  hashKiri[i];
			ll hashValKanan = getPartialKanan(s.length() - 1 - i,s.length() - 1,0);
			if (hashValKiri == hashValKanan)
			{
				pair<ll,ll> tmp = {i,s.length()};
				if (getLength(tmp) > getLength(ans))
					ans = tmp;
			}
		}
		cek = "";
		for (ll i = s.length() - 1 ; i >= 0 ; i--)
		{

			ll hashValKiri =  getPartialKiri(i,s.length() - 1,0);
			ll hashValKanan = hashKanan[s.length() - 1 - i];
			if (hashValKiri == hashValKanan)
			{
				// cout << i << endl;
				pair<ll,ll> tmp = {-1,i};
				if (getLength(tmp) > getLength(ans))
					ans = tmp;
			}
		}
		assert(getLength(ans) != 0);
		// assert(ans.first < ans.second);
		// cout << ans.first << " " << ans.second << endl;
		string ret;
		for (ll i = 0 ; i <= ans.first ; i++)
			ret += s[i];
		for (ll i = ans.second ; i < s.length() ; i++)
			ret += s[i];
		cout << ret << endl;
	}
	return 0;
}
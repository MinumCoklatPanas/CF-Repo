#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modA[1000010],modB[1000010];
ll pref[1000010];

ll mul(ll a,ll b,ll mod)
{
	return ((a%mod)*(b%mod))%mod;
}

ll add(ll a,ll b,ll mod)
{
	return ((a%mod)+(b%mod))%mod;
}

ll MOD(ll x,ll mod)
{
	return (x<0 ? x+mod : x%mod);
}

ll subs(ll a,ll b,ll mod)
{
	return MOD((a%mod)-(b%mod),mod);
}

int tab[1000010];

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++)
	 tab[i]=s[i]-'0';
	ll a,b;
	cin>>a>>b;
	modA[0]=modB[0]=1;
	for (int i=1;i<=1000000;i++)
	{
		modA[i]=mul(modA[i-1],10,a);
		modB[i]=mul(modB[i-1],10,b);
	}
	int n=s.length()-1;
	pref[n]=tab[n]%b;
	for (int i=n-1;i>=0;i--)
	{
		pref[i]=add(mul(tab[i],modB[n-i],b),pref[i+1],b);
	}
	ll nowA=0ll;
	ll nowB;
	string ansA,ansB;
	ansA=s;
	ansB=s;
	for (int i=0;i<n;i++)
	{
		nowA=add(mul(nowA,10,a),tab[i],a);
		if (tab[i+1]==0) continue;
		ll nowB=pref[i+1];
		if (nowA==0 && nowB==0)
		{
			ansA.erase(i+1,n-i+1);
			ansB.erase(0,i+1);
			cout<<"YES\n";
			cout<<ansA<<"\n";
			cout<<ansB<<"\n";
			return 0;
		}
	}
	cout<<"NO\n";
}

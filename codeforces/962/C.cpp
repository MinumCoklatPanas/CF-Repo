#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool nyala[15];

int main()
{
	string s;
	cin>>s;
	ll ans=1e9;
	for (ll mask=0;mask<(1<<s.length());mask++)
	{
		memset(nyala,1,sizeof(nyala));
		string tmp;
		tmp="";
		ll cnt=__builtin_popcount(mask);
		if (cnt==s.length()) continue;
		for (ll i=0;i<s.length();i++)
		 if (mask&(1<<i)) nyala[i]=0;
		for (ll i=0;i<s.length();i++)
		 if (nyala[i]) tmp+=s[i];
		if (tmp[0]=='0') continue;
		ll a;
		istringstream(tmp) >> a;
		ll akar=(ll)sqrt(a);
		if (akar*akar==a)
		 {
		 	ans=min(ans,cnt);
		 }
	}
	if (ans==1e9)
	 ans=-1;
	cout<<ans<<"\n";
}

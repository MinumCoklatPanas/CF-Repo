#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
ll i,j,k,n,tab[100010];

int main()
{
	ll sum=0;
	cin>>k;
	string s;
	cin>>s;
	for (i=0;i<s.length();i++)
	{
		int asc=(int)s[i];
		tab[i]=asc%48;
		sum+=tab[i];
	}
	if (sum>=k)
	{
		cout<<0<<"\n";
		return 0;
	}
	sort(tab,tab+s.length());
	int ans=0;
	for (i=0;i<s.length();i++)
	{
		sum+=abs(9-tab[i]);
		ans++;
		if (sum>=k)
		 break;
	}
	cout<<ans<<"\n";
}

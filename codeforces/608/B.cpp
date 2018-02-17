#include <bits/stdc++.h>
using namespace std;

long long pref0[200010];
long long pref1[200010];
bool A[200010];
bool B[200010];

int main()
{
//	freopen("input.txt","r",stdin);
	string a,b;
	cin>>a;
	long long Na=a.length();
	for (long long i=0;i<a.length();i++)
	 A[i+1]=(a[i]=='1');
	cin>>b;
	long long Nb=b.length();
	for (long long i=0;i<b.length();i++)
	 B[i+1]=(b[i]=='1');
	pref0[1]=(!B[1]);
	for (long long i=2;i<=Nb;i++)
	{
		pref0[i]=pref0[i-1]+(!B[i]);
	}
	pref1[1]=(B[1]);
	for (long long i=2;i<=Nb;i++)
	{
		pref1[i]=pref1[i-1]+(B[i]);
	}
	long long ans=0;
	for (long long i=1;i<=Na;i++)
	{
		if (A[i])
		{
			ans+=pref0[Nb-Na+i]-pref0[i-1];
		}
		else
		 ans+=pref1[Nb-Na+i]-pref1[i-1];
	}
	cout<<ans<<"\n";
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	ll A=0;
	for (int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		A+=k;
	}
	int B[100010];
	for (int i=1;i<=n;i++)
	 cin>>B[i];
	sort(B+1,B+n+1);
	cout<<(A<=B[n]+B[n-1] ? "YES" : "NO")<<"\n";
}

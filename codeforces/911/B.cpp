#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int ans=0;
	for (int i=1;i<n;i++)
	{
		int piringA=i;
		int piringB=n-i;
		if (piringA>a) continue;
		if (piringB>b) continue;
		int kueA=a/piringA;
		int kueB=b/piringB;
		int now=min(kueA,kueB);
		ans=max(now,ans);
	}
	cout<<ans<<"\n";
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> beautiful;
	int dua[25];
	memset(dua,0,sizeof(dua));
	dua[0]=1;
	for (int i=1;i<=20;i++)
	 dua[i]=dua[i-1]*2;
//	cout<<dua[3]<<"\n";
//	return 0;
	int i=1;
	while (1)
	{
		int now=(dua[i]-1)*(dua[i-1]);
//		cout<<now<<"\n";
		if (now>1e5) break;
		beautiful.push_back(now);
		++i;
	}
	int n;
	cin>>n;
	int ans=1;
	for (int i=0;i<beautiful.size();i++)
	{
		if (n%beautiful[i]==0)
		 ans=max(beautiful[i],ans);
	}
	cout<<ans<<"\n";
}

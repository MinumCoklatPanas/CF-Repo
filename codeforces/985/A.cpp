#include <bits/stdc++.h>
using namespace std;

bool ada[110];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	vector<int> sudahB,sudahW,belumB,belumW;
	for (int i=1;i<=n/2;i++)
	{
		int a;
		cin>>a;
		ada[a]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (ada[i])
		{
			if (i%2==1)
			 sudahB.push_back(i);
			else
			 sudahW.push_back(i);
		}
		else
		{
			if (i%2==1)
			 belumB.push_back(i);
			else
			 belumW.push_back(i);
		}
	}
	int ans=1e9;
	int tmp=0;
	for (int i=0;i<sudahB.size();i++)
	{
		tmp+=abs(sudahB[i]-belumW[i]);
	}
	ans=min(ans,tmp);
	tmp=0;
	for (int i=0;i<sudahW.size();i++)
	{
		tmp+=abs(sudahW[i]-belumB[i]);
	}
	ans=min(ans,tmp);
	cout<<ans<<"\n";
}

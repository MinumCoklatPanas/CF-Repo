#include <bits/stdc++.h>
using namespace std;

int tab1[2000010],tab2[2000010];
bool ada[2000010];

int main()
{
	//map<int,int> mp;
	int n;
	int sum=0;
	int a=1^6;
	//cout<<a<<"\n";
	scanf("%d",&n);
	memset(ada,0,sizeof(ada));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&tab1[i]);
		ada[tab1[i]]=1;
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&tab2[i]);
		ada[tab2[i]]=1;
	}
	cout<<"Karen\n";
	return 0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
		//	cout<<i<<" "<<j<<"\n";
			int res=tab1[i]^tab2[j];
		//	cout<<res<<" res\n";
			if (ada[res]) ++sum;
		}
	}
	//cout<<sum<<"\n";
	cout<<(sum%2==1 ? "Koyomi" : "Karen")<<"\n";
}

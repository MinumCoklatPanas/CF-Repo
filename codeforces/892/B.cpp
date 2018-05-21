#include <bits/stdc++.h>
using namespace std;

int state[1000010];
int tab[1000010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	for (int i=1;i<=n;i++)
	{
		int kurang=i-tab[i];
		kurang=max(kurang,0);
		state[kurang]++;
		state[i]--;
//		state[kurang]=min(state[kurang],1);
//		state[i]=max(state[i],-1);
	}
//	for (int i=0;i<=n;i++)
//	 cout<<state[i]<<" ";
//	cout<<"\n";
	for (int i=1;i<=n;i++)
	 state[i]+=state[i-1];
//	for (int i=0;i<=n;i++)
//	 cout<<state[i]<<" ";
//	cout<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++)
	 ans+=!state[i];
	cout<<ans<<"\n";
}

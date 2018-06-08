#include <bits/stdc++.h>
using namespace std;

const
 int INF=1e9;

char dir[200010];
int pos[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>dir[i];
	for (int i=1;i<=n;i++) 
	 cin>>pos[i];
	int ans=INF;
	for (int i=1;i<n;i++)
	{
		if (dir[i]=='R' && dir[i+1]=='L')
		{
			ans=min(ans,(pos[i+1]-pos[i])/2);
		}
	}
	cout<<(ans==INF ? -1 : ans)<<"\n";
}

#include <bits/stdc++.h>
using namespace std;

int asli[200010];
int disc[200010];
bool sudah[200010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	 cin>>asli[i];
	for (int i=1;i<=n;i++)
	 cin>>disc[i];
	priority_queue< pair<int,int> > pq;
	for (int i=1;i<=n;i++)
	 pq.push({disc[i]-asli[i],i});
	int cnt=0;
	int ans=0;
	while ((pq.top().first>0 || cnt<k) && (!pq.empty()))
	{
		pair<int,int> depan=pq.top();
		pq.pop();
		ans+=asli[depan.second];
		sudah[depan.second]=1;
		++cnt;
	}
	for (int i=1;i<=n;i++)
	 ans+=disc[i]*(!sudah[i]);
	cout<<ans<<"\n";
}

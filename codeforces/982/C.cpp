#include <bits/stdc++.h>
using namespace std;

int sub[100010];
vector<int> adj[100010];
bool vis[100010];
int root;
int ans=0;

int cnt(int u,int par)
{
	int res=1;
//	cout<<u<<" u\n";
	for (int i=0;i<adj[u].size();i++)
	{
		if (adj[u][i]!=par)
		 res+=cnt(adj[u][i],u);
	}
	return sub[u]=res;
}

void potong(int u,int par)
{
	int sum=0;
	int simpan=-1;
//	vector<int> ganjil;
//	cout<<u<<" "<<par<<" upar\n";
	for (int i=0;i<adj[u].size();i++)
	{
		if (adj[u][i]==par) continue;
//		cout<<adj[u][i]<<"\n";
		if (sub[adj[u][i]]%2==0)
		{
			++ans;
			potong(adj[u][i],u);
//			cout<<u<<" "<<adj[u][i]<<" edge\n";
		}
		else
		 {
		 	potong(adj[u][i],u);
		 }
	}
//	if (sum%2!=1)
//	{
////		cout<<sum<<" "<<u<<"\n";
//	}
//	assert(sum%2==1);
//	cout<<sum<<" "<<u<<" sumu\n";
//	cout<<simpan<<" simpan\n";
//	assert(simpan!=-1);
//	if (sum==1)
//	 {
////	 	cout<<simpan<<"\n";
//	 	potong(simpan,u);
//	 }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
//	srand(time(NULL));
	int n;
	cin>>n;
	if (n%2==1)
	{
		cout<<"-1\n";
		return 0;
	}
	for (int i=1;i<n;i++)
	 {
	 	int a,b;
	 	cin>>a>>b;
	 	adj[a].push_back(b);
	 	adj[b].push_back(a);
	 }
	root=1;
//	cout<<root<<" root\n";
	int tot=cnt(root,-1);
//	for (int i=1;i<=n;i++)
//	 cout<<sub[i]<<" ";
//	cout<<"\n";
	assert(tot==n);
	potong(root,-1);
//	if (ans==0 && n%2==1)
//	 --ans;
	cout<<ans<<"\n";
}

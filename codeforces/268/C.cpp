#include <bits/stdc++.h>
using namespace std;

bool bulat(int x1,int y1,int x2,int y2)
{
	int dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	int disst=(int)sqrt(dist);
	return (disst*disst==dist);
}

bool vis[110][110];

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<min(n,m)+1<<"\n";
	int now=0;
	for (int i=min(n,m);i>=0;i--)
	 cout<<i<<" "<<now++<<"\n";
}

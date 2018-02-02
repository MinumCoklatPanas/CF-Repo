#include <bits/stdc++.h>
using namespace std;

queue< pair<int,int> > q;
bool ada[1010];
pair<int,int> tab[1010];
int leave[1010];
int n;

void reset()
{
	while (!q.empty())
	 q.pop();
	memset(ada,1,sizeof(ada));
	memset(tab,0,sizeof(tab));
	memset(leave,0,sizeof(leave));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt","r" ,stdin);
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		reset();
		int now=1;
		for (int i=1;i<=n;i++)
		{
//			cout<<i<<" i\n";
			int l,r;
			cin>>l>>r;
//			cout<<now<<" now\n";
			now=max(now,l);
			if (now>r)
			 cout<<0;
			else
			 {
			 	cout<<now;
			 	++now;
			 }
//			++now;
			if (i==n)
			 cout<<"\n";
			else
			 cout<<" ";
		}
	}
}

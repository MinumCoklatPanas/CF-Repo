#include <bits/stdc++.h>
using namespace std;

pair<int,int> LastRow[5010];
pair<int,int> LastColumn[5010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++)
	{
		int ask,ix,a;
		cin>>ask>>ix>>a;
		if (ask==1)
		{
			LastRow[ix]={i,a};
		}
		else
		{
			LastColumn[ix]={i,a};
		}
	}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
		pair<int,int> row=LastRow[i];
		pair<int,int> column=LastColumn[j];
		if (row.first>column.first)
		 cout<<row.second;
		else
		 cout<<column.second;
		if (j==m)
		 cout<<"\n";
		else
		 cout<<" ";
	 }
}

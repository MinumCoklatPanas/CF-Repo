#include <bits/stdc++.h>
using namespace std;

int tab[200010];
priority_queue< pair<int,int> > kecil;
priority_queue< pair<int,int> > besar;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>tab[i];
		kecil.push({-tab[i],i});
	}
	string s;
	cin>>s;
	for (int i=0;i<2*n;i++)
	{
		if (s[i]=='0')
		{
			pair<int,int> depan=kecil.top();
			kecil.pop();
			cout<<depan.second;
			besar.push({-depan.first,depan.second});
		}
		else
		{
			pair<int,int> depan=besar.top();
			besar.pop();
			cout<<depan.second;
		}
		if (i==2*n-1)
		 cout<<"\n";
		else
		 cout<<" ";
	}
	
}

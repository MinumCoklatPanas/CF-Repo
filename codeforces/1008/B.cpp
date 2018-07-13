#include <bits/stdc++.h>
using namespace std;

int a[100010],b[100010];
int h[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>a[i]>>b[i];
	h[1]=max(a[1],b[1]);
	for (int i=2;i<=n;i++)
	{
		if (a[i]>h[i-1] && b[i]>h[i-1])
		{
			cout<<"NO\n";
			return 0;
		}
		else
		if (a[i]<=h[i-1] && b[i]>h[i-1])
		 h[i]=a[i];
		else
		 if (a[i]>h[i-1] && b[i]<=h[i-1])
		  h[i]=b[i];
		 else
		  if (a[i]<=h[i-1] && b[i]<=h[i-1])
		   h[i]=max(a[i],b[i]);
	}
	cout<<"YES\n";
	
}
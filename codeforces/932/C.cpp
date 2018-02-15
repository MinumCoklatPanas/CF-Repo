#include <bits/stdc++.h>
using namespace std;

int ans[2000100];
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	
	for (int i=0;i<=n;i++)
	{
		int sisa=n-(i*a);
		if (sisa<0) break;
		if (sisa%b==0)
		{
			int aa=i;
			int bb=sisa/b;
//			cout<<aa<<" "<<bb<<"\n";
			int l=1;
			for (int j=1;j<=aa;j++)
			{
				int r=l+a-1;
//				cout<<l<<" "<<r<<"\n";
				for (int k=l;k<=r;k++)
				 {
				 	if (k==r)
				 	 ans[k]=l;
				 	else
				 	 ans[k]=k+1;
				 }
				l=r+1;
			}
			l=1+a*i;
//			cout<<l<<" l\n";
			for (int j=1;j<=bb;j++)
			{
				int r=l+b-1;
//				cout<<l<<" "<<r<<"\n";
				for (int k=l;k<=r;k++)
				{
					if (k==r)
					 ans[k]=l;
					else
					 ans[k]=k+1;
				}
				l=r+1;
			}
			for (int i=1;i<=n;i++)
			{
				if (i==n)
				 cout<<ans[i]<<"\n";
				else
				 cout<<ans[i]<<" ";
			}
			return 0;
		}
	}
	cout<<-1<<"\n";
}

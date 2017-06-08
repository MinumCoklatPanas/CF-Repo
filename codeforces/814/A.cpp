#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x,int y)
{
	return (x>y);
}

int main()
{
	int i,j,k,n,a[210],b[210],m;
	cin>>n>>m;
	int sum=0;
	for (i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	if (a[i]==0)
	 	 sum++;
	 }
	for (i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+m+1,cmp);
	int point=1;
	for (i=1;i<=n;i++)
	{
		if (a[i]==0)
		{
			swap(a[i],b[point]);
			point++;
		}
	}
	bool cek=false;
	for (i=1;i<n;i++)
	{
		if (a[i]>=a[i+1])
		{
			//cout<<a[i]<<" "<<a[i+1]<<"\n";
			cek=true;
			break;
		}
	}
	if (cek)
	 cout<<"Yes\n";
	else
	 cout<<"No\n";
}

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
	bool cek[200010];
	int i,j,k,n,m;
	vector<int> satu;
	cin>>n>>m;
	memset(cek,0,sizeof(cek));
	for (i=1;i<=m;i++)
	{
		cin>>j>>k;
		if (j==1)
		 satu.push_back(k);
		if (k==n)
		 cek[j]=1;
	}
	for (i=0;i<satu.size();i++)
	{
		if (cek[satu[i]])
		{
			cout<<"POSSIBLE\n";
			return 0;
		}
	}
	cout<<"IMPOSSIBLE\n";
}
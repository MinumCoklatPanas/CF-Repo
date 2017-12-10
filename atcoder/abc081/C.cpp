#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int frek[200010];
	memset(frek,0,sizeof(frek));
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		++frek[a];
	}
	vector<int> angka;
	for (int i=1;i<=n;i++)
	 if (frek[i])
	  angka.push_back(frek[i]);
	if (angka.size()<=k)
	 cout<<0<<"\n";
	else
	 {
	 	sort(angka.begin(),angka.end());
	 	int ans=0;
//	 	for (int i=0;i<)
	 	for (int i=0;i<angka.size()-k;i++)
	 	 ans+=angka[i];
	 	cout<<ans<<"\n";
	 }
}
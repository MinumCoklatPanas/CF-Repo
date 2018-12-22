#include <bits/stdc++.h>
using namespace std;

int frek[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		frek[a]++;
		frek[a]%=2;
	}
	vector<int> nums;
	for (int i=1;i<=100;i++)
	{
		if (frek[i])
			nums.push_back(i);
	}
	int ans=0;
	for (int i=0;i<nums.size();i+=2)
	{
		ans+=nums[i+1]-nums[i];
	}
	cout<<ans<<"\n";
}
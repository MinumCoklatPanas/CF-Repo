#include <bits/stdc++.h>
using namespace std;

map<int,int> frek;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> nums;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		frek[a]++;
		nums.push_back(a);
	}
	sort(nums.begin(),nums.end());
	nums.erase(unique(nums.begin(),nums.end()),nums.end());
	if (k==0)
	{
		if (nums[0]==1)
		 cout<<-1<<"\n";
		else
		 cout<<nums[0]-1<<"\n";
		return 0;
	}
	int sum=0;
	for (int i=0;i<nums.size();i++)
	{
		sum+=frek[nums[i]];
		if (sum>k) break;
		if (sum==k)
		{
			cout<<nums[i]<<"\n";
			return 0;
		}
	}
	cout<<-1<<"\n";
}

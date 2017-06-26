#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int a,b;
	map <int,int> mp;
	mp[1]=1;
	mp[2]=3;
	mp[3]=1;
	mp[4]=2;
	mp[5]=1;
	mp[6]=2;
	mp[7]=1;
	mp[8]=1;
	mp[9]=2;
	mp[10]=1;
	mp[11]=2;
	mp[12]=1;
	cin>>a>>b;
	if (mp[a]==mp[b])
	{
		cout<<"Yes\n";
		return 0;
	}
	cout<<"No\n";
	return 0;
}
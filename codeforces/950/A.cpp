#include <bits/stdc++.h>
using namespace std;

int main()
{
	int mn,mx,tambah;
	cin>>mn>>mx>>tambah;
	if (mn>mx)
	 swap(mn,mx);
	int diff=mx-mn;
	mn+=min(diff,tambah);
	tambah-=min(diff,tambah);
//	cout<<mn<<"\n";
//	cout<<tambah<<"\n";
	int ans=2*mn+((tambah/2)*2);
	cout<<ans<<"\n";
}

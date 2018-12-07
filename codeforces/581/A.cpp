#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	cin>>a>>b;
	int c,d;
	int mn=min(a,b);
	c=a;
	d=b;
	int tmp=max(c-mn,d-mn);
	tmp=(tmp/2);
	cout<<mn<<" "<<tmp<<"\n";
}
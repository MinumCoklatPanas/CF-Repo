#include <bits/stdc++.h>
using namespace std;

const
 float pi=acos(-1);
const
 float eps=1e-8;

int main()
{
	float d,h,v,e;
	cin>>d>>h>>v>>e;
	float he=v/(pi*d*d/4.0);
	if (e-he>=eps)
	{
		cout<<"NO\n";
		return 0;
	}
	float ans=h/(he-e);
	cout<<"YES\n";
	printf("%.10f\n",ans);
}

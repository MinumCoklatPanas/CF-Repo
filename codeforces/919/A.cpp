#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main()
{
	float mn=INF;
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		float A=a*1.0;
		float B=b*1.0;
		float cost=A/B;
		cost=cost*m*1.0;
//		cout<<cost<<" cost\n";
		if (cost-mn<1e-8)
		 mn=cost;
	}
	printf("%.13lf\n",mn);
}

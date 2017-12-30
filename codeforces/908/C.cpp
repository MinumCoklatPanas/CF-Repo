#include <bits/stdc++.h>
using namespace std;

const
 float eps=1e-9;

int main()
{
	int n;
	float r;
	cin>>n>>r;
	float awal[1010];
	for (int i=1;i<=n;i++)
	 cin>>awal[i];
	pair<float,float> center[1010];
	for (int i=1;i<=n;i++)
	{
//		cout<<i<<" i\n";
		center[i].first=awal[i];
		if (i==1)
		{
			printf("%.11f ",1.0*r);
			center[i].second=1.0*r;
		}
		else
		 {
		 	float ans=-1.0;
		 	for (int j=1;j<i;j++)
		 	{
		 		float jarakX=fabs(center[i].first-center[j].first);
		 		jarakX*=jarakX;
		 		float jarakCari=4.0*r*r;
		 		if (jarakX-jarakCari>eps) continue;
		 		float d=sqrt(jarakCari-jarakX)+center[j].second;
//		 		cout<<d<<" d\n";
		 		if (d-ans>eps)
		 		 ans=d;
			}
			if (ans==-1.0)
			 ans=1.0*r;
			if (i==n)
			 printf("%.11f\n",ans);
			else
			printf("%.11f ",ans);
			center[i].second=ans;
		 }
	}
}

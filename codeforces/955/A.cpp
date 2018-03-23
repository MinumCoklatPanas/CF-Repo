#include <bits/stdc++.h>
using namespace std;

const
 double EPS=1e-9;

int cei(double x,double y)
{
	double f=x/y;
	int e=(int)x/y;
	return (fabs(e-f)<=EPS ? e : e+1);
}

int main()
{
	int wtf;
	int hh,mm;
	cin>>hh>>mm;
	double h,d,c,n;
	cin>>h>>d>>c>>n;
	if (hh>=20)
	{
		int bagi=cei(h,n);
		double res=bagi*c*1.0*0.8;
		printf("%.13lf\n",res);
		return 0;
	}
	int menit=60-mm;
	int jam=19-hh;
	int waktu=60*jam+menit;
	double h1=(h+(d*waktu))*1.0;
	int bagi1=cei(h1,n);
	double res1=bagi1*c*1.0*0.8;
	int bagi=cei(h,n);
	double res2=bagi*c*1.0;
	if (res1-res2>EPS)
	 printf("%.13lf\n",res2);
	else
	 printf("%.13lf\n",res1);
}

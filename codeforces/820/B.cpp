#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 1e9
typedef long long ll;

int main()
{
	ll i,j,k,n,jarak;
	float a;
	float min=INF;
	cin>>n>>a;
	ll sudut_total=(n-2)*180;
	//cout<<sudut_total%n<<"\n";
	float sudut=(float)180/n;
	float patokan=sudut;
	//cout<<sudut<<"\n";
	jarak=1;
	ll ans;
	for (jarak=1;jarak<=n-2;jarak++)
	{
		sudut=patokan*jarak;
		//cout<<sudut<<"\n";
		float diff=abs(a-sudut);
		//cout<<diff<<" diff\n";
		if (diff<min)
		 {
		 	min=diff;
		 	ans=jarak;
		 }
	}
	ans=n-(ans-1);
	cout<<1<<" "<<2<<" "<<ans<<"\n";
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;
	while (k--)
	{
		int ta,fa,tb,fb;
		cin>>ta>>fa>>tb>>fb;
//		cout<<ta<<" "<<fa<<" "<<tb<<" "<<fb<<"\n";
		int ans=0;
		if (ta==tb)
		{
			ans=abs(fa-fb);
		}
		else
		if ((a<=fa) && (fa<=b))
		{
			ans+=abs(ta-tb);
			ans+=abs(fa-fb);
		}
		else
		 if (fa>b)
		 {
		 	ans+=abs(fa-b);
		 	ans+=abs(b-fb);
		 	ans+=abs(ta-tb);
		 }
		else
		 if (fa<a)
		 {
		 	ans+=abs(fa-a);
		 	ans+=abs(a-fb);
		 	ans+=abs(ta-tb);
		 }
		cout<<ans<<"\n";
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue< ll > A,B;

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll awalA=0,awalB=0;
	for (ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		A.push(k);
		awalA+=k;
	}
	for (ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		B.push(k);
		awalB+=k;
	}
	bool now=1;
	ll sumA=0,sumB=0;
	while ((!A.empty()) || (!B.empty()))
	{
		if (now)
		{
			if (A.empty())
			 B.pop();
			else
			 if (B.empty())
			  {
			  	sumA+=A.top();
			  	A.pop();
			  }
			 else
			  if (A.top()>=B.top())
			  {
			  	sumA+=A.top();
			  	A.pop();
			  }
			  else
			   B.pop();
		}
		else
		{
			if (A.empty())
			{
				sumB+=B.top();
				B.pop();
			}
			else
			 if (B.empty())
			 {
			 	A.pop();
			 }
			else
			 if ((B.top()>=A.top()))
			 {
			 	sumB+=B.top();
			 	B.pop();
			 }
			else
			 A.pop();
		}
		now^=1;
//		cout<<sumA<<" "<<sumB<<"\n";
	}
//	cout<<sumA<<" "<<sumB<<"\n";
	cout<<sumA-sumB<<"\n";
}
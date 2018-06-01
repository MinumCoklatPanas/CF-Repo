#include <bits/stdc++.h>
using namespace std;

set< int > st;
int ix[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		st.insert(a);
		ix[a]=i;
	}
	if (st.size()<k)
	 cout<<"NO\n";
	else
	 {
	 	cout<<"YES\n";
	 	for (set<int>::iterator it=st.begin();it!=st.end();++it)
	 	{
	 		--k;
	 		cout<<ix[*it];
	 		if (!k)
	 		 {
	 		 	cout<<"\n";
	 		 	break;
			  }
			else
			 cout<<" ";
		}
	 }
}

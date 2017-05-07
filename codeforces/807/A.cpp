#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,j,k;
	bool b;
	pair <int,int> tab[1010];
	cin>>n;
	b=false;
	for (i=1;i<=n;i++)
	{
		k=0;
		cin>>tab[i].first>>tab[i].second;
		k=abs(tab[i].first-tab[i].second);
		if (k>0)
		 b=true;
	}
	if (b)
	{
		cout<<"rated\n";
	}
	else
	 {
	 	b=true;
	 	for (i=1;i<n;i++)
	 	{
	 		if (tab[i].first<tab[i+1].first)
	 		 {
	 		 	b=false;
	 		 	break;
			  }
		 }
		 if (b)
		  cout<<"maybe\n";
		else
		 cout<<"unrated\n";
	 }
	 return 0;
}

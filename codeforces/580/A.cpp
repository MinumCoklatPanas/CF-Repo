#include <iostream>
using namespace std;

int main()
{
	int i,j,sum,seq,n,tab[100010];
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	sum=tab[1];
	i=2;
	seq=1;
	int max;
	max=seq;
	while (i<=n)
	{
		if (tab[i]>=sum)
		{
			sum=tab[i];
			seq++;
			if (seq>max)
			 max=seq;
		}
		else
		 {
		 	seq=1;
		 	sum=tab[i];
		 }
		 i++;
	}
	cout<<max<<"\n";
}

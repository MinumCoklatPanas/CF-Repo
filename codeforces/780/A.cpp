#include <iostream>
using namespace std;

int main ()
{
	int i,j,n,tab[200010],data[100010];
	cin>>n;
	for (i=1;i<=2*n;i++)
	 cin>>tab[i];
	i=2;
	j=tab[1];
	data[j]++;
	int hasil=1,max=0;
	max=hasil;
	while (i<2*n)
	{
		if (data[tab[i]]==0)
		{
			//cout<<tab[i]<<"\n";
			hasil++;
			if (hasil>max)
			 max=hasil;
			data[tab[i]]++;
		}
		else 
			if (data[tab[i]]>0)
			{
				hasil--;
				data[tab[i]]=0;
				if (hasil==0)
				{
					hasil=1;
					j=tab[i+1];
					data[j]++;
					i++;
				}
			}
		i++;
	}
	cout<<max<<"\n";
}

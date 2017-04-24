#include <iostream>
using namespace std;

int main ()
{
	int i,j,sum,n,k,tab[100010]{};
	bool b=false;
	cin>>n>>k;
	i=2;
	sum=1;
	int x;
	tab[1]=1;
	while ((i<=n)&&(sum<k))
	{
		if (n%i==0)
		{
			tab[i]++;
			//cout<<tab[i]<<" "<<i<<"\n";
			sum++;
			n=n/i;
			x=i;
			//cout<<n<<" n\n";
		}
		else
		 i++;
	}
	//cout<<sum<<"\n";
	//cout<<tab[2]<<"\n";
	if ((sum==k)&&(n>1)){
	for  (i=2;i<=x;i++)
	{
		b=true;
		if (tab[i]>0)
		 {
		 	for (j=1;j<=tab[i];j++)
		 	 cout<<i<<" ";
		 }
	}
	//cout<<b<<" \n";
	if ((not b)&&(k>1))
	 cout<<1<<" ";
	cout<<n<<"\n";
	}
	else
	 cout<<-1<<"\n";
}

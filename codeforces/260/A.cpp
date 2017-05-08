#include <iostream>
using namespace std;

int digit (int x)
{
	int count=0;
	while (x>0)
	 {
	 	count++;
	 	x=x/10;
	 }
	return count;
}

int main ()
{
	int a,b,n,i,j;
	int tab[100010]{};
	cin>>a>>b>>n;
	int c=a;
	for (i=digit(c);i>=1;i--)
	{
		tab[i]=c%10;
		c=c/10;
	}
	a=a*10;
	bool bo=false;
	for (i=0;i<=9;i++)
	{
		if ((a+i)%b==0)
		{
			tab[digit(a)]=i;
			bo=true;
			break;
		}
	}
	if (bo){
	for (i=1;i<=digit(a)+n-1;i++)
	 cout<<tab[i];
	cout<<"\n";
	}
	else
	 cout<<-1<<"\n";
}

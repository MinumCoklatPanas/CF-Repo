#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	long long i,j,n,k,tab[200010],l,r,m;
	cin>>n>>k;
	long long num=n-k+1;
	//cout<<num<<"\n";
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	long long sum=0;
	l=1;
	r=n;
	int pengali;
	if (k>n/2)
	 pengali=num;
	else
	 pengali=k;
	//cout<<pengali<<"\n";
	while (l<=r)
	{
		//cout<<l<<" "<<r<<"\n";
		if (l==r)
		 {
		 	//cout<<l<<" "<<r<<" 3\n";
		 	long long a=pengali*tab[l];
		 	sum+=a;
		 }
		 else
		 if ((l<num)&&(r>num))
		 {
		 	//cout<<l<<" "<<r<<" 1\n";
		 	long long a=l*tab[l];
		 	sum+=a;
		 	
		 	long long b=l*tab[r];
		 	sum+=b;
		 	
		 }
		 else
		  //if ((l>=num)||(r<=num))
		  {
		  	//cout<<l<<" "<<r<<" 2\n";
		  	long long a=pengali*tab[l];
		  	long long b=pengali*tab[r];
		  	sum+=a;
		  	sum+=b;
		  }
		
		
		l++;
		r--;
	}
	//cout<<sum<<"\n";
	double rat=(float)sum/(num);
	printf("%.6lf\n",rat);
}

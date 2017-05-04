#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int floor(int x,int y)
{
	float a=(float)x/y;
	int b= (int) a;
	return
	 b;
}

int ceil(int x1,int y1)
{
	float a=(float)x1/y1;
	int b= (int) a;
	if (b==a)
	 return b;
	else
	 return b+1;
}

int main ()
{
	int i,sum,k,n,m;
	cin>>n>>m;
	i=2;
	sum=0;
	int a=n-m+1;
	int max=0;
	int b=0;
	int out=i;
	if (n==m)
	 cout<<n<<"\n";
	else{
	while ((sum<=a/2)&&(i<=m))
	{
		int x=ceil(n,i);
		int y=floor(n,i);
		b=x+y-1;
		sum+=b;
		if (b>max){
		 max=b;
		 out=i;
		}
		i++;
	}
	cout<<out<<"\n";
	}
}

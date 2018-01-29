#include <bits/stdc++.h>
using namespace std;

bool fibo[1010];
int fib[1010];

void generate()
{
	fib[1]=1;
	fib[2]=1;
	fibo[1]=1;
	int n=3;
	while (1)
	{
		fib[n]=fib[n-1]+fib[n-2];
		fibo[fib[n]]=1;
		if (fib[n]>1000) return;
		++n;
	}
	
}

int main()
{
	generate();
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cout<<(fibo[i]? 'O' : 'o');
	cout<<"\n";
}

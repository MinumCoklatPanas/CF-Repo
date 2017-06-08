#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int i,j,k,n,a[1010],b[1010],in_a1,in_a2,in_b1,in_b2;
	bool cek[1010];
	cin>>n;
	memset(cek,0,sizeof(cek));
	for (i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	if (!cek[a[i]])
	 	 cek[a[i]]=1;
	 	else
	 	 {
	 	 	in_a2=i;
	 	 	for (j=1;j<i;j++)
	 	 	{
	 	 		if (a[j]==a[i])
	 	 		{
	 	 			in_a1=j;
	 	 			break;
				 }
		    }
		 }
	 }
	//cout<<in_a1<<" "<<in_a2<<"\n";
	int ganti_a,ganti_b;
	for (i=1;i<=n;i++)
	 {
	 	if (!cek[i])
	 	{
	 		ganti_a=i;
	 		break;
		 }
	 }
	memset(cek,0,sizeof(cek));
	for (i=1;i<=n;i++)
	{
		cin>>b[i];
		if (!cek[b[i]])
		 cek[b[i]]=1;
		else
		  {
		  	in_b2=i;
		  	for (j=1;j<i;j++)
		  	{
		  		if (b[j]==b[i])
		  		{
		  			in_b1=j;
		  			break;
				  }
			  }
		  }
	}
	for (i=1;i<=n;i++)
	{
		if (!cek[i])
		{
			ganti_b=i;
			break;
		}
	}
	bool bo=true;
	for (i=1;i<=1;i++)
	{
		
		a[in_a1]=ganti_a;
	}
	for (i=1;i<=1;i++)
	{
		b[in_b1]=ganti_b;
		
	}
	bool check=true;
	for (i=1;i<=n;i++)
	{
		if (a[i]!=b[i])
		{
			check=false;
			break;
		}
	}
	if (check)
	 {
		for (i=1;i<=n;i++)
		 {
		 	if (i==n)
			 cout<<a[i]<<"\n";
		 	else
		 	 cout<<a[i]<<" ";
		  }
	 }
	else
	 {
	 	//cout<<"yo2\n";
	 	a[in_a1]=a[in_a2];
	 	b[in_b1]=b[in_b2];
	 	for (i=1;i<=n;i++)
		{
			
			a[in_a1]=ganti_a;
			break;
		}
		for (i=1;i<=n;i++)
		{
			
			b[in_b2]=ganti_b;
			break;
		}
		bool check=true;
		for (i=1;i<=n;i++)
		{
			if (a[i]!=b[i])
			{
				check=false;
				break;
			}
		}
		if (check)
	 	{
			for (i=1;i<=n;i++)
		 	{
		 		if (i==n)
			 	cout<<a[i]<<"\n";
		 		else
		 		 cout<<a[i]<<" ";
		  	}
	 	}
		else
		{
			//cout<<"yo3\n";
			a[in_a1]=a[in_a2];
			b[in_b2]=b[in_b1];
			for (i=1;i<=n;i++)
			{
				a[in_a2]=ganti_a;
				break;
			}
			for (i=1;i<=n;i++)
			{
				b[in_b1]=ganti_b;
				break;
			}
			bool check=true;
			for (i=1;i<=n;i++)
			{
				if (a[i]!=b[i])
				{
					check=false;
					break;
				}
			}
			if (check)
	 		{
				for (i=1;i<=n;i++)
		 		{
		 			if (i==n)
			     	 cout<<a[i]<<"\n";
		 			else
		 			 cout<<a[i]<<" ";
		  		}
	 		}
	 		else
	 		 {
	 		 	//cout<<"yo4\n";
	 		 	a[in_a2]=a[in_a1];
	 		 	b[in_b1]=b[in_b2];
	 		 	for (i=1;i<=n;i++)
				{	
					a[in_a2]=ganti_a;
					break;
				}
				for (i=1;i<=n;i++)
				{
					b[in_b2]=ganti_b;
					break;
				}
				bool check=true;
				for (i=1;i<=n;i++)
				{
					if (a[i]!=b[i])
					{
						check=false;
						break;
					}
				}
				if (check)
	 			{	
					for (i=1;i<=n;i++)
		 			{
		 				if (i==n)
			     	 	cout<<a[i]<<"\n";
		 				else
		 			 	cout<<a[i]<<" ";
		  			}
	 			}
			  }
		 }		
	 }
}

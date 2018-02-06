#include <bits/stdc++.h>
using namespace std;

int INF=1e9;
struct soal{
	int huruf=INF;
	int angka=INF;
	int simbol=INF;
};

bool letter(char c)
{
	return ('a'<=c && c<='z');
}

bool number(char c)
{
	return ('0'<=c && c<='9');
}

bool symbol(char c)
{
	return (c=='#' || c=='*' || c=='&');
}

char tab[55][55];
soal dist[55];
int ada1,ada2,ada3;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 dist[i].angka=dist[i].huruf=dist[i].simbol=INF;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  {
	  	cin>>tab[i][j];
	  	if (j==1){
	  	ada1+=letter(tab[i][j]);
	  	ada2+=number(tab[i][j]);
	  	ada3+=symbol(tab[i][j]);
	  	}
	  }
	int kurang=(m)/2;
	for (int i=1;i<=n;i++)
	{
		if (letter(tab[i][1]))
		{
			for (int j=2;j<=m;j++)
			{
				if (letter(tab[i][j])) continue;
				int step=j-1;
				if (step>kurang) step=m-j+1;
				if (number(tab[i][j]))
				 dist[i].angka=min(dist[i].angka,step);
				else
				 dist[i].simbol=min(dist[i].simbol,step);
			}
		}
		else
		 if (number(tab[i][1]))
		 {
		 	for (int j=2;j<=m;j++)
			{
				if (number(tab[i][j])) continue;
				int step=j-1;
				if (step>kurang) step=m-j+1;
				if (letter(tab[i][j]))
				 dist[i].huruf=min(dist[i].huruf,step);
				else
				 dist[i].simbol=min(dist[i].simbol,step);
			}
		 }
		 else
		  if (symbol(tab[i][1]))
		  {
		  	for (int j=2;j<=m;j++)
			{
				if (symbol(tab[i][j])) continue;
				int step=j-1;
				if (step>kurang) step=m-j+1;
				if (number(tab[i][j]))
				 dist[i].angka=min(dist[i].angka,step);
				else
				 dist[i].huruf=min(dist[i].huruf,step);
			}
		  }
	}
//	cout<<ada1<<" "<<ada2<<" "<<ada3<<"\n";
//	for (int i=1;i<=n;i++)
//	 cout<<dist[i].huruf<<" "<<dist[i].angka<<" "<<dist[i].simbol<<" i\n";
//	cout<<kurang<<" kurang\n";
	for (int i=1;i<=n;i++)
	{
		if (dist[i].angka!=INF && dist[i].angka>kurang) dist[i].angka-=kurang;
		if (dist[i].huruf!=INF && dist[i].huruf>kurang) dist[i].huruf-=kurang;
		if (dist[i].simbol!=INF && dist[i].simbol>kurang) dist[i].simbol-=kurang; 
	}
	if (ada1 && ada2 && ada3)
	 cout<<0<<"\n";
	//1 huruf 2 angka 3 simbol
	else
	 {
//	 	cout<<"yo\n";
	 	int count=(!ada1)+(!ada2)+(!ada3);
//	 	cout<<count<<"\n";
	 	int ans=0;
	 	if (count==1)
	 	{
	 		ans=1000;
	 		if (ada1 && ada2)
	 		{
	 			for (int i=1;i<=n;i++)
	 			 {
	 			 	if (ada1==1)
	 			 	 if (letter(tab[i][1])) continue;
	 			 	if (ada2==1)
	 			 	 if (number(tab[i][1])) continue;
//	 			 	cout<<i<<" i\n";
	 			 	ans=min(ans,dist[i].simbol);
//	 			 	cout<<ans<<" ans\n";
				 }
			}
			else
			 if (ada1 && ada3)
			 {
			 	for (int i=1;i<=n;i++)
			 	 {
			 	 	if (ada1==1)
	 			 	 if (letter(tab[i][1])) continue;
	 				if (ada3==1)
	 			 	 if (symbol(tab[i][1])) continue;
	 			 	ans=min(ans,dist[i].angka);
				 }
			 }
			 else
			  {
			  	
			  	for (int i=1;i<=n;i++)
			  	 {
			  	 	if (ada2==1)
	 			  	 if (number(tab[i][1])) continue;
	 				if (ada3==1)
	 			     if (symbol(tab[i][1])) continue;
	 			    ans=min(ans,dist[i].huruf);
				 }
			  }
			cout<<ans<<"\n";
		}
		else
		 {
		 	ans=1e9;
		 	if (ada1)
		 	{
		 		for (int i=1;i<n;i++)
		 		 for (int j=i+1;j<=n;j++)
		 		  ans=min(ans,dist[i].angka+dist[j].simbol);
			}
			else
			 if (ada2)
			 {
			 	for (int i=1;i<n;i++)
			 	 for (int j=i+1;j<=n;j++)
			 	  ans=min(ans,dist[i].huruf+dist[j].simbol);
			 }
			 else
			  {
//			  	cout<<"yo\n";
			  	for (int i=1;i<n;i++)
			  	 for (int j=i+1;j<=n;j++)
			  	  ans=min(ans,dist[i].huruf+dist[j].angka);
			  }
			cout<<ans<<"\n";
		 }
	 }
}

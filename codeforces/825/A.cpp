#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int i,j,k,n;
	vector <int> vec;
	cin>>n;
	string s;
	cin>>s;
	i=0;
	//int pos=1;
	while (i<s.length())
	{
		int count=0;
		while (s[i]=='1')
		 {
		 	count++;
		 	i++;
		 }
		vec.push_back(count);
		i+=1;
	}
	if (s[s.length()-1]=='0')
	 vec.push_back(0);
	for (vector<int>::iterator it=vec.begin(); it!=vec.end();it++)
	{
		cout<<*it;
	}
	cout<<"\n";
}

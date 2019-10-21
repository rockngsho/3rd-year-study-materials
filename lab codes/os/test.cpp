#include<bits/stdc++.h>
using namespace std;
vector < pair<int,int> > bp[10];
vector < pair<int,int> > :: iterator itr; 
int n,a,b,p;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p>>a>>b;
		bp[b].push_back(make_pair(a,p));
	}
	for(int i=1;i<10;i++)
		sort(bp[i].begin(), bp[i].end());
		
		
	for(int i=1;i<10;i++)
	{
		cout<<"\n"<<i<<"-";
			
		for(itr=bp[i].begin();itr!=bp[i].end();itr++)
		{
			cout<<"("<<(*itr).first<<","<<(*itr).second<<"),";
			bp[i-1].push_back(make_pair((*itr).first,(*itr).second));
			bp[i].erase(itr);
		}
	}
	
	for(int i=1;i<10;i++)
	{
		cout<<"\n"<<i<<"-";
			
		for(itr=bp[i].begin();itr!=bp[i].end();itr++)
		{
			cout<<"("<<(*itr).first<<","<<(*itr).second<<"),";
		}
			
	}
}

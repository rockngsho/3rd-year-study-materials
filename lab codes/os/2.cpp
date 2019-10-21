//SJF arrival time same
#include<bits/stdc++.h>
using namespace std;
multimap <int,int> m;
int a,b,comp,p,temp,n;
float avg;
main()
{
    
    cin>>n;
    for(int j=0;j<n;j++)
    {
        cin>>p>>a>>b;
		m.insert(make_pair(b,p));
    }
    for(auto u:m)
    {
		avg+=comp;
		temp=comp;
		comp=comp+u.first;
        cout<<"completion time of process "<<u.second<<": "<<comp<<"\n";
        cout<<"waiting time of  process "<<u.second<<": "<<temp<<"\n\n";
		//i++;
    }
	
    cout<<"average waiting time:"<<(avg/n)<<"\n";
    cout<<"turn around time:"<<comp;
}

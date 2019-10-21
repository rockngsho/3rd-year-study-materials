//FCFS 
#include<bits/stdc++.h>
using namespace std;
multimap <int,int> m;
int n,comp,i=0,temp,b,a;
float avg=0;
main()
{
    cout<<"enter the no of processes:";
    cin>>n;
    for(int j=0;j<n;j++)
    {
    	cin>>a>>b;
    	m.insert(make_pair(a,b));
    }
    for(auto u:m)
    {
		temp=comp;
		avg+=(temp-u.first);
		comp=comp+u.second;
        cout<<"completion time of process "<<i<<": "<<comp<<"\n";
        cout<<"turn around time of  process "<<i<<": "<<(comp-u.first)<<"\n";
        cout<<"waiting time of  process "<<i<<": "<<(temp-u.first)<<"\n\n";
	i++;
    }
	
    cout<<"average waiting time:"<<(avg/n)<<"\n";
    cout<<"total turn around time:"<<comp;
}

#include<iostream>
#define _ std::
#define FOR(i,e) for(int i=1;i<e;i++)
main(){int T;_ cin>>T;while(T--){int n,b[101][101]={{0}},m=0;_ cin>>n;FOR(i,n+1)FOR(j,i+1)_ cin>>b[i][j],b[i][j]+=_ max(b[i-1][j-1],b[i-1][j]),m=_ max(m,b[i][j]);_ cout<<m<<"\n";}}

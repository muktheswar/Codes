#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int i;
	if(n>=m){
		cout<<m+1<<"\n";
		for(i=0;i<m+1;i++){
			cout<<i<<" "<<m-i<<"\n";
		}
	}
	else{
		cout<<n+1<<"\n";
		for(i=0;i<n+1;i++){
			cout<<n-i<<" "<<i<<"\n";
	}
	}
		return 0;
	}

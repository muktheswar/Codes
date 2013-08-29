#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==1)cout<<"0\n";
	else{
	char ch[n];
	int po[n];
	int i;
	for(i=0;i<n;i++)po[i]=0;
	cin>>ch;
	int curr=1,last=0,count=0;
	while(curr!=n){
		if(ch[curr]==ch[last]){count++;}
		curr++;last++;
	}
	cout<<count<<"\n";
	}
	return 0;
	}


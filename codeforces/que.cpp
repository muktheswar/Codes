#include<iostream>
using namespace std;
int main(){
	int n,time;
	cin>>n>>time;
	char a[n];
	cin>>a;
	int i,t,j;
	for(j=0;j<time;j++){
	for(i=0;i<n;i++){
		if(a[i]=='B'){
			if(i<n-1 && a[i+1]=='G' ){
				t=a[i+1];
				a[i+1]=a[i];
				a[i]=t;
				i++;
			}
		}
	}
	}
cout<<a<<"\n";
return 0;
}
				

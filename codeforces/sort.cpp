#include<iostream>
#include<algorithm>
using namespace std;
bool fun(int x,int y){
	return x>y;
}
int main(){
	int a[10]={1,2,4,3,7,6,5,8,9,10};
	int *p =&a[1];
	stable_sort(a+1,a+10,fun);
	for(int i=0;i<10;i++)cout<<a[i]<<" ";
	cout<<"\n"<<*p<<"\n";
}

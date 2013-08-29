#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;
struct playlist{
	float l;
	float p;
};
/*void sort(playlist x[],float first,float last){
	int pivot;
	int j,i;
	playlist temp;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while(x[i].p>=x[pivot].p&&i<last)
				i++;
			while(x[j].p<x[pivot].p)
				j--;
			if(i<j){
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}

		temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
		sort(x,first,j-1);
		sort(x,j+1,last);

	}
}
void sort1(playlist x[],float first,float last){
	int pivot;
	int j,i;
	playlist temp;

	if(first<last){
		pivot=first;
		i=first;
		j=last;

		while(i<j){
			while(x[i].l>=x[pivot].l&&i<last)
				i++;
			while(x[j].l<x[pivot].l)
				j--;
			if(i<j){
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}

		temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
		sort1(x,first,j-1);
		sort1(x,j+1,last);

	}
}*/
bool compare( const playlist &x, const playlist &y ) {
	     return (x.l)*(x.p)*(100-y.p) > (y.l)*(y.p)*(100-x.p);
}
int main(){
	int n;
	cin>>n;
	int i;
	playlist a[n];
	for(i=0;i<n;i++){cin>>a[i].l>>a[i].p;}
	sort( a, a+n, compare );
float sum=0;
float prev=0;
for(i=0;i<n;i++){
	sum+=a[i].l*a[i].p/100+(1-a[i].p/100)*(a[i].l+prev);
	prev+=a[i].l*a[i].p/100;
	}
//cout<<sum<<"\n";
printf("%.20f\n",sum);
return 0;
}

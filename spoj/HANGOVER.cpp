#include<stdio.h>
#include<vector>
using namespace std;
int bsearch(vector<float>&cal,float n,int low,int high){
if(low>high)return -1;
int mid=low+(high-low)/2;
int index=-1;
index=bsearch(cal,n,low,mid-1);
if(index==-1){if(cal[mid]>=n)return mid;
else index=bsearch(cal,n,mid+1,high);
}
return index;
}

int main(){
vector<float> cal;
float n=5.20;
int count=1;
float sum=0;
while(sum<n){
sum+=1*1.0/(count+1);
cal.push_back(sum);
count++;
}
count--;
while(1){
float n;
scanf("%f",&n);
if(n==0.0)break;
printf("%d card(s)\n",bsearch(cal,n,0,count-1)+1);
}
return 0;
}


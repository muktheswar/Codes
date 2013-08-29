#include<stdio.h>
int main(){
int i;
int co=0,f=0;
for(i=0;i<20;i++){
int n;
scanf("%d",&n);
if(n==1)f=1;
if(n==0 && f==1){co++;f=0;}
if(n==0)f=0;
}
printf("%d\n",co);
return 0;
}

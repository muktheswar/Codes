#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
int main(){
srand(time(NULL));
int n,k,t;
n=200000;
k=1;
printf("%d %d\n",n,k);
for(int i=0;i<n;i++)printf("%d ",rand()%1000000000+1);
printf("\n");
}

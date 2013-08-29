#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
//srand(time(NULL));
for(int T=0;T<100;T++){
int n=rand()%10000+1;
printf("%d\n",n);
for(int i=0;i<n;i++)printf("%d ",rand()%13+1);
printf("\n");
}
printf("0\n");
return 0;
}


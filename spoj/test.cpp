#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;
int main(){
srand(time(NULL));
printf("500001\n");
for(int i=0;i<500001;i++){
printf("%d\n",i);
if(i<500000)
printf("%d\n",i);
i++;
}
return 0;
}

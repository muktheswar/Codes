#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rem(char *b,int n){
int i;
int sum=0;
int ten=1;
int len=strlen(b);
for(i=len-1;i>=0;i--){
sum+=(ten*(b[i]-48))%n;
ten=(ten*10)%n;
//printf("%d %d\n",ten,sum);
}
return sum%n;
}
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
int main(){
int T;
scanf("%d",&T);
while(T--){
char a[260];
char b[260];
scanf("%s%s",a,b);
int n=atoi(a);
if(n==0){printf("%s\n",b);continue;}
int ans=rem(b,n);
printf("%d\n",gcd(n,ans));
}
return 0;
}

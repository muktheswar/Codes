#include<cstdio>
int a[99],l,t,b;
char c[30];
main(){a[68]=a[76]=a[70]=a[84]=1;while((t++)<10){b=1;gets(c);l=0;while(c[l]){if(a[c[l]])b*=2;l++;}printf("%d\n",b);}}

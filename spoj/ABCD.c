#include<stdio.h>
#include<string.h>
//consider min val
int main(){
int n,po=0;
scanf("%d",&n);
char r1[100010],prev=0,r2[100010];
int al[4]={0,0,0,0};
scanf("%s",r1);
int i,j;
for(i=0;i<2*n;i++){al[r1[i]-65]++;}
/*for(i=1;i<2*n;i++){
if(al[r1[i]-65]<n && prev!=r1[i]){r2[po++]=r1[i];prev=r1[i];al[prev-65]++;}
else {for(j='A';j<='D';j++){if(al[j-'A']!=n){
if(prev==0){
if(r1[i-1]!=j){r2[po++]=j;prev=j;al[j-65]++;break;}
}
else{
if(j!=prev && j!=r1[i-1]){r2[po++]=j;prev=j;al[j-65]++;break;}
}
}
}
}
}*/
for(i=0;i<2*n;i++){
int m=al[0];
char l='A';
int f=0;
if(al[0]>=n || r1[i]=='A'||prev=='A')f=1;
if(prev!='B' && (al[1]<m||f)){f=0;m=al[1];l='A'+1;if(r1[i]=='B' || prev=='B' || al[1]>=n)f=1;}
if(prev!='C' && (al[2]<m || f)){f=0;m=al[2];l='A'+2;if(r1[i]=='C'||prev=='C'||al[2]>=n)f=1;}
if(prev!='D' && (al[3]<m || f)){f=0;m=al[3];l='A'+3;if(r1[i]=='D'||prev=='D'||al[3]>=n)f=1;}
if(al[l-65]<n && f==0){r2[po++]=l;prev=l;
al[l-65]++;}
}
for(i=0;i<4;i++)if(al[i]<n){r2[po-1]=i+65;break;}
//int f=0;
//for(j='A';j<='D';j++){if(prev!=j && j!=r1[2*n-1] && al[j-65]!=n){r2[po++]=j;f=1;break;}}
if(i<4){
for(j=po-1;j>0;j--){
if(r2[j]==r1[j] || r2[j]==r2[j-1]){int t=r2[j];r2[j]=r2[j-1];r2[j-1]=t;continue;}
if(j+1<po && r2[j]==r2[j+1]){int t=r2[j];r2[j]=r2[j-1];r2[j-1]=t;continue;}
break;
}
}
for(i=0;i<po;i++)printf("%c",r2[i]);
printf("\n");
return 0;
}

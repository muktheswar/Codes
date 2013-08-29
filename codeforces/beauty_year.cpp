#include<string>
#include<sstream>
#include<iostream>
using namespace std;
char num[10];
/*bool distinct(string c){
	int i=0;
	while(c[i]!=0){
		if(num[c[i]-48]=='1')return false;
		else num[c[i]-48]='1';
		i++;
		cout<<"hi";
	}
	return true;
}
*/
int main(){
	int n;
	cin>>n;
	int flag=0;
	char num[10];
	string Result;
	while(flag==0){
	n++;	
	ostringstream convert;   // stream used for the conversion
	convert << n;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str();
	int i;
	for(i=0;i<10;i++)num[i]='0';
	for(i=0;i<4;i++){
		if(num[Result[i]-48]=='1'){break;}
		else num[Result[i]-48]='1';
	}
	if(i==4)flag=1;
	}
	cout<<n<<"\n";
	return 0;
}


// AUTHOR: AMAN JAIN
#include <iostream>
#include<iomanip>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <deque>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;

#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LL long long
#define LLU unsigned long long
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size()) 
#define SORT(c) sort(ALL(c)) 
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9
template <class T> string str(T Number){

	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	return Result;
}
LL gcd(LL a,LL b){
	if(b==0)return a;
	return gcd(b,a%b);
}
double rnd(float d)
{
	  return floor(d + 0.49);
}
int main(){
	LL x,y,n;
	cin>>x>>y>>n;
	float min=1000000;
	LL a,b;
	LL a1,b1;
	for(int i=n;i>=1;i--){
		b=i;
		a=rnd(x*b*1.0/y);
//		cout<<x*b*1.0/y<<" "<<a<<"\n";
//		cout<<a<<" "<<b<<"\n"<<fabs((x*b-y*a)*1.0/(y*b))<<"\n";
		if(fabs((x*b-y*a)*1.0/(y*b))<=min){min=fabs((x*b-y*a)*1.0/(y*b));a1=a;b1=b;}
	}
//	cout<<a1<<"/"<<b1<<"\n";
	LL t;
 	if(a1<b1){
	t=gcd(b1,a1);
	}
	else t=gcd(a1,b1);
	cout<<a1/t<<"/"<<b1/t<<"\n";
	return 0;
}

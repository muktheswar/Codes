
// AUTHOR: AMAN JAIN
#include <iostream>
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
double rnd(float d) //for rounding values
{
	          return floor(d + 0.49);
}
bool check(pair<int,int> a,pair<int,int> b,pair<int,int>c,pair<int,int>d){
//	cout<<"ans"<<(b.second-a.second)*(c.second-a.second)<<" "<<(b.first-a.first)*(c.first-a.first)<<"\n";
if((b.second-a.second)*(c.second-b.second)+(b.first-a.first)*(c.first-b.first)!=0){return false;}
int t=(b.second-a.second)*(b.second-a.second)+(b.first-a.first)*(b.first-a.first);
if((b.second-c.second)*(b.second-c.second)+(b.first-c.first)*(b.first-c.first)!=t){return false;}
if((d.second-c.second)*(d.second-c.second)+(d.first-c.first)*(d.first-c.first)!=t){return false;}
if((d.second-a.second)*(d.second-a.second)+(d.first-a.first)*(d.first-a.first)!=t){return false;}
return true;
}
bool checkr(pair<int,int> a,pair<int,int> b,pair<int,int>c,pair<int,int>d){
//	cout<<"ans"<<(b.second-a.second)*(c.second-a.second)<<" "<<(b.first-a.first)*(c.first-a.first)<<"\n";
if((b.second-a.second)*(c.second-b.second)+(b.first-a.first)*(c.first-b.first)!=0){return false;}
if((d.second-c.second)*(d.second-c.second)+(d.first-c.first)*(d.first-c.first)!=(b.second-a.second)*(b.second-a.second)+(b.first-a.first)*(b.first-a.first)){return false;}
if((d.second-a.second)*(d.second-a.second)+(d.first-a.first)*(d.first-a.first)!=(b.second-c.second)*(b.second-c.second)+(b.first-c.first)*(b.first-c.first)){return false;}
return true;
}
int main(){
	vector< pair<int,int> > v(8);
	for(int i=0;i<8;i++){
		cin>>v[i].first;
		cin>>v[i].second;
	}
/*	for(int i=0;i<8;i++){
		cout<<v[i].first<<" ";
		cout<<v[i].second<<"\n";
	}*/
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i==j)continue;
			for(int k=0;k<8;k++){
				if(k==i || k==j)continue;
				for(int l=0;l<8;l++){
				if(l==i || l==j || l==k)continue;
					//cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<"\n";
				if(check(v[i],v[j],v[k],v[l])){
					int count=0;
					vector<int> a;
					for(int t=0;t<8;t++){
						if(t!=i && t!=j && t!=k && t!=l ){
							count++;
							a.pb(t);
							if(count==4)break;
						}
					}
				sort(all(a));
				do{
				if(checkr(v[a[0]],v[a[1]],v[a[2]],v[a[3]]))
				{
					cout<<"YES\n";
					cout<<i+1<<" "<<j+1<<" "<<k+1<<" "<<l+1<<"\n";
					cout<<a[0]+1<<" "<<a[1]+1<<" "<<a[2]+1<<" "<<a[3]+1<<"\n";
					return 0;
				}
				}while(next_permutation(all(a)));
				}
			}
		}
	}
	}
cout<<"NO\n";

	return 0;
}

// BEGIN CUT HERE

// END CUT HERE
#line 5 "Marketing.cpp"


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
#define FOR(i,start,end) for(int i=start;i<end;i++)
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9
#define mt(x, y, z) mp(mp(x,y),z)
template <class T> string str(T Number){

	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	return Result;
}
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
double rnd(float d) //for rounding values
{
	          return floor(d + 0.49);
}
       typedef struct node{
int val;
int color;
}node;

int bfs(int start,vector<vector<int> > &a,vector<bool>&visit,vector<int>&color){
queue<node> Q;
node t;
t.val=start;
t.color=0;
visit[start]=true;
Q.push(t);
while(!Q.empty()){
node top=Q.front();
Q.pop();
int val=top.val;
//cout<<"val:"<<val<<"\n";
for(int i=0;i<sz(a[val]);i++){
if(!visit[a[val][i]]){node temp;temp.val=a[val][i];temp.color=(top.color+1)%2;color[temp.val]=temp.color;visit[temp.val]=true;Q.push(temp);}
else if(color[val]==color[a[val][i]])return -1;
}
}
return 0;
}

 class Marketing{ 
        public: 
 

long long int howMany(vector<string> a){
int n=sz(a);
vector<vector<int> > b(n);
FOR(i,0,n){
	istringstream in(a[i]); 
	int k; 
	while(in>>k) 
	{ 
		b[i].pb(k);b[k].pb(i);
	} 
	}
//FOR(i,0,sz(b)){FOR(j,0,sz(b[i]))cout<<b[i][j]<<" ";cout<<"\n";} 	
vector<bool> visit(n);
vector<int> color(n);
LL ans=1;
FOR(i,0,n)if(!visit[i]){int t=bfs(i,b,visit,color);if(t==-1)return -1; else ans=ans*(LL)2;/*cout<<"ans:"<<ans<<"\n";*/}
return ans;
}
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 4","2","3","0",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"1","2","0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -1LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"1","2","3","0","0 5","1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"","","","","","","","","","",
 "","","","","","","","","","",
 "","","","","","","","","",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1073741824LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"1","2","3","0","5","6","4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -1LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE
 
 }; 

    // BEGIN CUT HERE 
 int main(){
        Marketing ___test; 
        ___test.run_test(-1); 
 } 
    // END CUT HERE

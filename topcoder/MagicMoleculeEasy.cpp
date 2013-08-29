// BEGIN CUT HERE

// END CUT HERE
#line 5 "MagicMoleculeEasy.cpp"


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
#define SLL ({LL x;scanf("%lld",&x);x;})
#define SLLU ({LLU x;scanf("%llu",&x);x;})
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

	    bool func(const std::pair<int,int> &left, const std::pair<int,int> &right) {
		            return left.first > right.first;
			        }
	    bool func1(const std::pair<int,int> &left, const std::pair<int,int> &right) {
		            return left.second > right.second;
			        }

std::sort(v.begin(), v.end(), sort_pred());
 class MagicMoleculeEasy{ 
        public: 
        int maxMagicPower(vector <int> magicPower, vector <string> magicBond, int k) 
            {
		    int n=sz(magicPower);
		    pair<int,int> a(0,0);
		    vector< pair<int,int> > nodes(n,a);
		    int i,j;
		    for(i=0;i<n;i++){
			    nodes[i].second=magicPower[i];
			    for(j=i;j<n;j++)if(magicBond[i][j]=='Y'){nodes[i].first++;nodes[j].first++;}
		    }
sort(all(nodes),func);
int st=0;
for(i=0;i<n-1;i++)if(nodes[i].first!=node[i+1].first){sort(nodes.begin()+start,nodes.begin()+i,func1);start=i+1;}
if(nodes[n-2].first==nodes[n-1].first)sort(nodes.begin()+start,nodes.end(),func1);
for
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NY",
 "YN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {100, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 200; verify_case(2, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4, 7, 5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 15; verify_case(3, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {46474, 60848, 98282, 58073, 42670, 50373}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNNY", "YNNYNY", "NNNYYY", "NYYNNN", "NNYNNN", "YYYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 209503; verify_case(4, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYYYNYYNYNNY", "NNYNYYYYYYYNY", "YYNYYNYYYYYYY", "YNYNYYNYYYYYY",
 "YYYYNNYYYYYNY", "NYNYNNYYYYYNN", "YYYNYYNYYYYYY", "YYYYYYYNYNYYY",
 "NYYYYYYYNYYYY", "YYYYYYYNYNNNN", "NYYYYYYYYNNYN", "NNYYNNYYYNYNN", "YYYYYNYYYNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = -1; verify_case(5, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NN", "NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(6, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {1,1,2,5,2,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNNN","NNYNNNN","NYNNNYN","NNNNNNY","NNNNNNN","NNYNNNN","NNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 11; verify_case(7, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
 }; 

    // BEGIN CUT HERE 
 int main(){
        MagicMoleculeEasy ___test; 
        ___test.run_test(-1); 
 } 
    // END CUT HERE

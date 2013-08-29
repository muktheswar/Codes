// BEGIN CUT HERE

// END CUT HERE
#line 5 "GooseTattarrattatDiv1.cpp"

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#define N 100
using namespace std;
 
int cnt[100];
int father[100];
vector<int>vec[N];
 
void reset(int n)
{
  for (int i=0;i<=n;i++)
    father[i]=i;
}
 
int find(int u)
{
  if (u==father[u])
    return u;
  else
    return father[u]=find(father[u]);
}
 
void merge(int a,int b)
{
  int fa=find(a);
  int fb=find(b);
  if (fa!=fb)
    father[fa]=fb;
}
 
class GooseTattarrattatDiv1
{
  public:
 
  int getmin(string str)
  {
    int n=str.size(),res=0,tmp,i,j;
 
    memset(cnt,0,sizeof(cnt));
    reset(26);
 
    for (i=0;i<n;i++)
      cnt[str[i]-'a']++;
    for (i=0;i<n/2;i++)
      merge(str[i]-'a',str[n-i-1]-'a');
    for (i=0;i<26;i++)
      if (cnt[i])
        vec[find(i)].push_back(cnt[i]);
 
    for (i=0;i<26;i++)
    {
      if ((int)vec[i].size()==0)
        continue;
 
      sort(vec[i].begin(),vec[i].end());
      tmp=0;
      for (j=0;j<vec[i].size();j++)
        tmp+=vec[i][j];
      tmp-=vec[i][vec[i].size()-1];
      res+=tmp;
    }
 
    return res;
  }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE
 
 }; 

    // BEGIN CUT HERE 
 int main(){
        GooseTattarrattatDiv1 ___test; 
        ___test.run_test(-1); 
 } 
    // END CUT HERE

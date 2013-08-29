
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
#define dr(i) i*PI/180
template <class T> string str(T Number){

	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	return Result;
}
pair<float,float> inter(pair<float,float> p1,pair<float,float> p2,pair<float,float> p3,pair<float,float> p4){
		float x1,x2,y1,y2;
		x1=p1.first;
		x2=p2.first;
		y1=p1.second;
		y2=p2.second;

		float x3,x4,y3,y4;
		x3=p3.first;
		x4=p4.first;
		y3=p3.second;
		y4=p4.second;
		float A1 = y2-y1;
		float B1 = x1-x2;
		float C1 = A1*x1+B1*y1;
		float A2 = y4-y3;
		float B2 = x3-x4;
		float C2 = A2*x3+B2*y3;
		float det = A1*B2 - A2*B1;
			float x = (B2*C1 - B1*C2)/det;
			float y = (A1*C2 - A2*C1)/det;
			//cout<<x<<" "<<y<<"\n";
			pair<float,float> t(x,y);
			return t;

}
int main(){
	int w1,h1,a1;
	float w,h,a;
	cin>>w1>>h1>>a1;
	w=(float)w1;
	h=(float)h1;
	a=(float)a1;
	if(a>90)a=180-a;
	w=w/2.0;
	h=h/2.0;
	if(w<h){
		float t=w;
		w=h;
		h=t;
	}
	vector< pair<float,float> > po;
	vector< pair<float,float> > po1;
	float x,y;
	 x=w;
	 y=h;
	 pair<float,float> t;
	t.first=x;
	t.second=y;
	po.pb(t);
	t.first=-x;
	t.second=y;
	po.pb(t);
	t.first=-x;
	t.second=-y;
	po.pb(t);
	t.first=x;
	t.second=-y;
	po.pb(t);
	for(int i=0;i<sz(po);i++){
		x=po[i].first*cos(dr(a))-po[i].second*sin(dr(a));
	 y=po[i].first*sin(a)+po[i].second*cos(a);
	 t.first=x;
	 t.second=y;
	 cout<<"a:"<<x<<" "<<y<<"\n";
	 cout<<"angle:"<<cos(dr(a))<<" "<<sin(dr(a))<<"\n";
	 po1.pb(t);
	}
for(int i = 0; i<sz(po); i++)cout<<po[i].first<<" "<<po[i].second<<"\n";
sort(po1.rbegin(),po1.rend());
for(int i = 0; i<sz(po); i++)cout<<po1[i].first<<" "<<po1[i].second<<"\n";
	if(a==0 || a==180 || (a==90 && w==h)){
		float area=0;
		for(int i=1;i+1<sz(po);i++){
        float x1 = po[i].first - po[0].first;
        float y1 = po[i].second - po[0].second;
        float x2 = po[i+1].first - po[0].first;
        float y2 = po[i+1].second- po[0].second;
        float cro = x1*y2 - x2*y1;
        area += cro;
		}
printf("%.6f\n",fabs(area/2));
return 0;
		}
	if(a==90){
		float area=0;
	//	for(int i=0;i<sz(po1);i++)cout<<po1[i].first<<" "<<po1[i].second<<"\n";
	//	cout<<"\n";
		vector< pair<float,float> > po2(4);
	po2[0].first=min(po[0].first,po1[3].first);	
	po2[3].first=min(po[3].first,po1[2].first);	
	po2[1].first=max(po[1].first,po1[0].first);	
	po2[2].first=max(po[2].first,po1[1].first);	
	po2[0].second=min(po[0].second,po1[3].second);	
	po2[3].second=max(po[3].second,po1[2].second);	
	po2[1].second=min(po[1].second,po1[0].second);	
	po2[2].second=max(po[2].second,po1[1].second);	
		//for(int i=0;i<sz(po2);i++)cout<<po2[i].first<<" "<<po2[i].second<<"\n";
		for(int i=1;i+1<sz(po2);i++){
        float x1 = po2[i].first - po2[0].first;
        float y1 = po2[i].second - po2[0].second;
        float x2 = po2[i+1].first - po2[0].first;
        float y2 = po2[i+1].second- po2[0].second;
        float cro = x1*y2 - x2*y1;
        area += cro;
		}
printf("%.6f\n",fabs(area/2));
return 0;
	}
	vector< pair<float,float> > ans;
	ans.pb(inter(po1[0],po1[1],po[0],po[1]));
	ans.pb(inter(po1[0],po1[1],po[1],po[2]));
	ans.pb(inter(po1[1],po1[2],po[1],po[2]));
	ans.pb(inter(po1[1],po1[2],po[2],po[3]));
	ans.pb(inter(po1[2],po1[3],po[2],po[3]));
	ans.pb(inter(po1[2],po1[3],po[3],po[0]));
	ans.pb(inter(po1[3],po1[0],po[3],po[0]));
	ans.pb(inter(po1[3],po1[0],po[0],po[1]));
float area = 0;

for(int i = 0; i<sz(ans); i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
for(int i = 1; i+1<sz(ans); i++){
        float x1 = ans[i].first - ans[0].first;
        float y1 = ans[i].second - ans[0].second;
        float x2 = ans[i+1].first - ans[0].first;
        float y2 = ans[i+1].second- ans[0].second;
        float cro = x1*y2 - x2*y1;
        area += cro;
}
printf("%.6f\n",fabs(area/2));
	return 0;
}

/************************************************************************************************************

	AUTHOR : Aman jain

	FILE NAME : rectangle.cpp

	CREATION DATE : Sun 10 Mar 2013 10:03:16 PM IST

	LAST MODIFIED : Mon 11 Mar 2013 12:07:53 AM IST
			
*************************************************************************************************************/


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<typeinfo>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<int>::iterator VII;
typedef vector<vector <int> > VVI;
typedef vector<vector <int> >::iterator VVII;
typedef vector<string> VSTR;
typedef vector<string>::iterator VSTRI;
typedef string STR;
typedef string::iterator STRI;
typedef pair<int,int> PII;
typedef list<int> LI;
typedef list<int>::iterator LII;


#define INF (int)1e9
#define LINF (long long)1e18
#define EPS 1e-9
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int) (x).size())
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORi(i,a,b) for (i=a;i<b;i++)
#define ROF(i,a,b) for(int i=a-1;i>=b;i--)
#define ROFi(i,a,b) for (i=a-1;i>=0;i--)
#define DIS(a)	sort(all(a)); a.erase(unique(all(a)),a.end())
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char c;scanf("%c",&c);c;})
#define SIC ({scanf("%*c");})
#define SMP(a,b,c) printf("%d%s",a,b==c-1?"":"\n");
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define BS(a,x) ({int z=(lower_bound(ALL(a),x)-(a).begin());(z==0&&a[0]!=x)?-1:z;})
#define PI 3.1415926535897932384626433
#define DEBUG 1

/****************************************************************************************************************************/

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000
 
double xmax,xmin,ymax,ymin; 
int Computeint(double x, double y)
{
        int code;
 
        code = INSIDE;          // initialised as being inside of clip window
 
        if (x < xmin)           // to the left of clip window
                code |= LEFT;
        else if (x > xmax)      // to the right of clip window
                code |= RIGHT;
        if (y < ymin)           // below the clip window
                code |= BOTTOM;
        else if (y > ymax)      // above the clip window
                code |= TOP;
 
        return code;
}
bool LineClip(double& x0, double& y0, double& x1, double& y1)
{
        // compute outcodes for P0, P1, and whatever point lies outside the clip rectangle
        int outcode0 = Computeint(x0, y0);
        int outcode1 = Computeint(x1, y1);
        bool accept = false;
 
        while (true) {
                if (!(outcode0 | outcode1)) { // Bitwise OR is 0. Trivially accept and get out of loop
                        accept = true;
                        break;
                } else if (outcode0 & outcode1) { // Bitwise AND is not 0. Trivially reject and get out of loop
                        break;
                } else {
                        // failed both tests, so calculate the line segment to clip
                        // from an outside point to an intersection with clip edge
                        double x, y;
 
                        // At least one endpoint is outside the clip rectangle; pick it.
                        int outcodeOut = outcode0 ? outcode0 : outcode1;
 
                        // Now find the intersection point;
                        // use formulas y = y0 + slope * (x - x0), x = x0 + (1 / slope) * (y - y0)
                        if (outcodeOut & TOP) {           // point is above the clip rectangle
                                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                                y = ymax;
                        } else if (outcodeOut & BOTTOM) { // point is below the clip rectangle
                                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                                y = ymin;
                        } else if (outcodeOut & RIGHT) {  // point is to the right of clip rectangle
                                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                                x = xmax;
                        } else if (outcodeOut & LEFT) {   // point is to the left of clip rectangle
                                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                                x = xmin;
                        }
 
                        // Now we move outside point to intersection point to clip
                        // and get ready for next pass.
                        if (outcodeOut == outcode0) {
                                x0 = x;
                                y0 = y;
                                outcode0 = Computeint(x0, y0);
                        } else {
                                x1 = x;
                                y1 = y;
                                outcode1 = Computeint(x1, y1);
                        }
                }
        }
        return accept;
}

double angle(double a,double b){ 
	    double ans=atan(b/a);
	        if(a<0&&b>=0)
			        ans+=(PI);
		    else if(a<0&&b<0)
			            ans+=(PI);
		        else if(a>=0&&b<0)
				        ans+=(2*PI);
			    return ans;
}

vector<double> ans_x;
vector<double> ans_y;

bool find(double a, double b){
	bool f=false;
	FOR(i,0,SZ(ans_x)){
		if(ans_x[i]==a && ans_y[i]==b){
			f=true;
			break;
		}
	}
	return !f;
}

int main(){

#ifdef DEBUG
  double tmp_start = clock();
  fprintf(stderr, "Start\n");
#endif


int w=SI,h=SI,alpha=SI;
xmax=(double)h/2;
xmin=-xmax;
ymax=(double)w/2;
ymin=-ymax;
double theta = (double)(alpha*PI)/180.0;
ans_x.clear();
ans_y.clear();
//1st edge
double a_x = (double)h/2;
double a_y = (double)w/2;
double b_x = (double)h/2;
double b_y = -(double)w/2;
double c_x = (a_x*cos(theta))-(a_y*sin(theta));
double c_y = (a_x*sin(theta))+(a_y*cos(theta));
double d_x = (b_x*cos(theta))-(b_y*sin(theta));
double d_y = (b_x*sin(theta))+(b_y*cos(theta));
if(LineClip(c_x,c_y,d_x,d_y)){
	double ta=angle(c_x,c_y);
	double tb=angle(d_x,d_y);
	if(fabs(tb-ta)>PI){
		if(tb<ta)
			tb+=(2*PI);
		else
			ta+=(2*PI);
	}
	if(ta<tb){
		if(find(c_x,c_y)){
			ans_x.PB(c_x);
			ans_y.PB(c_y);
		}
		if(find(d_x,d_y)){
		ans_x.PB(d_x);
		ans_y.PB(d_y);
		}
	}
	else{
		if(find(d_x,d_y)){
		ans_x.PB(d_x);
		ans_y.PB(d_y);
		}
		if(find(c_x,c_y)){
		ans_x.PB(c_x);
		ans_y.PB(c_y);
		}
	}
}

	
a_x = (double)h/2;
a_y = (double)w/2;
b_x = -(double)h/2;
b_y = (double)w/2;
c_x = (a_x*cos(theta))-(a_y*sin(theta));
c_y = (a_x*sin(theta))+(a_y*cos(theta));
d_x = (b_x*cos(theta))-(b_y*sin(theta));
d_y = (b_x*sin(theta))+(b_y*cos(theta));
if(LineClip(c_x,c_y,d_x,d_y)){
	double ta=angle(c_x,c_y);
	double tb=angle(d_x,d_y);
	if(fabs(tb-ta)>PI){
		if(tb<ta)
			tb+=(2*PI);
		else
			ta+=(2*PI);
	}
	if(ta<tb){
		if(find(c_x,c_y)){
		ans_x.PB(c_x);
		ans_y.PB(c_y);
		}
		if(find(d_x,d_y)){
		ans_x.PB(d_x);
		ans_y.PB(d_y);
		}
	}
	else{
		if(find(d_x,d_y)){
		ans_x.PB(d_x);
		ans_y.PB(d_y);
		}
		if(find(c_x,c_y)){
		ans_x.PB(c_x);
		ans_y.PB(c_y);
		}
	}
}
a_x = -(double)h/2;
a_y = -(double)w/2;
b_x = -(double)h/2;
b_y = (double)w/2;
c_x = (a_x*cos(theta))-(a_y*sin(theta));
c_y = (a_x*sin(theta))+(a_y*cos(theta));
d_x = (b_x*cos(theta))-(b_y*sin(theta));
d_y = (b_x*sin(theta))+(b_y*cos(theta));
if(LineClip(c_x,c_y,d_x,d_y)){
	double ta=angle(c_x,c_y);
	double tb=angle(d_x,d_y);
	if(fabs(tb-ta)>PI){
		if(tb<ta)
			tb+=(2*PI);
		else
			ta+=(2*PI);
	}
	if(ta<tb){
		if(find(c_x,c_y)){
		ans_x.PB(c_x);
		ans_y.PB(c_y);
		}
		if(find(d_x,d_y)){
		ans_x.PB(d_x);
		ans_y.PB(d_y);
		}
	}
	else{
		if(find(d_x,d_y)){
		ans_x.PB(d_x);
		ans_y.PB(d_y);
		}
		if(find(c_x,c_y)){
		ans_x.PB(c_x);
		ans_y.PB(c_y);
		}
	}
}
a_x = (double)h/2;
a_y = -(double)w/2;
b_x = -(double)h/2;
b_y = -(double)w/2;
c_x = (a_x*cos(theta))-(a_y*sin(theta));
c_y = (a_x*sin(theta))+(a_y*cos(theta));
d_x = (b_x*cos(theta))-(b_y*sin(theta));
d_y = (b_x*sin(theta))+(b_y*cos(theta));
if(LineClip(c_x,c_y,d_x,d_y)){
	double ta=angle(c_x,c_y);
	double tb=angle(d_x,d_y);
	if(fabs(tb-ta)>PI){
		if(tb<ta)
			tb+=(2*PI);
		else
			ta+=(2*PI);
	}
	if(ta<tb){
		if(find(c_x,c_y)){
		ans_x.PB(c_x);
		ans_y.PB(c_y);
		}
		if(find(d_x,d_y)){
		ans_x.PB(d_x);
		ans_y.PB(d_y);
		}
	}
	else{
		if(find(d_x,d_y)){
		ans_x.PB(d_x);
		ans_y.PB(d_y);
		}
		if(find(c_x,c_y)){
		ans_x.PB(c_x);
		ans_y.PB(c_y);
		}
	}
}

double area = 0;
double N = SZ(ans_x);
//We will triangulate the polygon
//into triangles with points p[0],p[i],p[i+1]

for(int i = 0; i<N; i++)cout<<ans_x[i]<<" "<<ans_y[i]<<"\n";
for(int i = 1; i+1<N; i++){
	    double x1 = ans_x[i] - ans_x[0];
	        double y1 = ans_y[i] - ans_y[0];
		    double x2 = ans_x[i+1] - ans_x[0];
		        double y2 = ans_y[i+1] - ans_y[0];
			    double cross = x1*y2 - x2*y1;
			        area += cross;
}

printf("%0.9lf\n",fabs(area/2.0));


#ifdef DEBUG
  fprintf(stderr, "Total time = %.2lf sec\n", (double)(clock() - tmp_start) / CLOCKS_PER_SEC);
#endif

return 0;
}

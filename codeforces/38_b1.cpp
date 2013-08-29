#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:16777216")
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

int n;
int m;

int dist(int x1, int y1, int x2, int y2) {
	re sqr(x1 - x2) + sqr(y1 - y2);
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	int x1, y1, x2, y2;
	cin >> s1 >> s2;
	x1 = s1[0] - 'a';
	y1 = s1[1] - '1';
	x2 = s2[0] - 'a';
	y2 = s2[1] - '1';

	int ans = 0;
	rep(i, 8) rep(j, 8) {
		if (i != x1 && j != y1 && dist(x2, y2, i, j) != 5 /*&& dist(x1, y1, i, j) != 5*/ && dist(x2, y2, i, j) != 0)
			ans++;
	}

	cout << ans;

	re 0;
}

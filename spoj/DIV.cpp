#include <iostream>
using namespace std;

const int MAX = 1000000, LMT = 1000, LEN = 78500;
int small[MAX+10];

void smallest() {
	int i, j, k;
	for(i=2; i<=MAX; i++) small[i] = ((i&1)==0)? 2 : i;
	for(i=3; i<=LMT; i+=2)
		if(small[i]==i)
			for(j=i; j<=MAX; j+=i)
				if(small[j]==j)
					small[j] = i;
}

int dn(int n) {
	int prv=0, count=0, res=1;
	while(n>1) {
		if(small[n]!=prv) {
			res *= (count+1);
			prv = small[n];
			count = 1;
		}
		else count++;
		n /= small[n];
	}
	return res*(count+1);
}

int main() {
	smallest();
	int d, i, p, q, count=0;
	for(i=2; i<=MAX; i++) {
		d = dn(i);
		p = small[d];
		if(p==d) continue;
		q = small[d/p];
		if(q==p || q!=d/p) continue;
		count++;
		if(count%9==0)cout<<i<<"\n";
	}
	return 0;
}

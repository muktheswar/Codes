#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define MAX_NUM 100010 // 200

// array will be initialized to 0 being global
int primes[MAX_NUM];

void gen_sieve_primes(void)
{
	for (int p=2; p<MAX_NUM; p++) // for all elements in array
	{
		if(primes[p] == 0) // it is not multiple of any other prime
			primes[p] = 1; // mark it as prime

		// mark all multiples of prime selected above as non primes
		int c=2;
		int mul = p * c;
		for(; mul < MAX_NUM;)
		{
			primes[mul] = -1;
			c++;
			mul = p*c;
		}
	}
}

/*void print_all_primes()
{
	int c = 0;
	for(int i=0; i<MAX_NUM; i++)
	{
		if(primes[i] == 1)
		{
			c++;

			if(c < 4)
			{
				switch{
					case 1:
						cout << c << "st prime is: " << i << endl;
						break;
					case 2:
						cout << c << "nd prime is: " << i << endl;
						break;
					case 3:
						cout << c << "rd prime is: " << i << endl;
						break;

					default:
						break;
				}
			}

			else
				cout << c << "th prime is: " << i << endl;
		}
	}
}*/

int main()
{
	gen_sieve_primes();
	int i,n,m,j,a,b;
	cin>>n>>m;
	vector<int> rows(n);
	vector<int> cols(m);
	int row=-1;
	int col=-1;
	int mini=MAX_NUM;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>a;
			//cout<<"primes"<<primes[a]<<"\n";
			if(primes[a]!=1){
				while(a<=100009 && primes[a]!=1){
					rows[i]++;cols[j]++;
					a++;
				}
			}
		}
		if(rows[i]<mini){mini=rows[i];row=i;}
		}
	for(i=0;i<m;i++)if(cols[i]<mini){mini=cols[i];col=i;}
	cout<<mini<<"\n";
	//cout<<row<<" "<<col<<"\n";
	return 0;
}
	


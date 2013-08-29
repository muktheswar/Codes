#include <iostream>
#include <cmath>
#include <queue>
#define LL long long int
using namespace std;
struct node
{
	LL data;
	struct node * left;
	struct node * right;
	LL pos;
};

struct node * root = new struct node;
void generateBinary(LL n);
LL findMax(struct node *, struct node *);
LL bits;

int main(void)
{
root->left=NULL;
root->right=NULL;
	LL n;
	cin >> n;
	
	if(n == 1)
	{
		LL num;
		cin >> num;
		cout << "0" << endl;
		return 0;
	}
	
	LL a[n];
	
	root->data = 0;
	
	bits = 0;
	
	for(LL i=0; i<n; i++)
	{
		cin >> a[i];
		if(a[i] > bits)
		  bits = a[i];
	}
	if(bits == 0)
	  bits = 1;
	else
	  bits = log2(bits) + 1;

	for(LL i=0; i<n; i++)
	{
		struct node * p = root;
		generateBinary(a[i]);
		root=p;
	}
		if(root->left==NULL)cout<<"yes\n";
		if(root->right==NULL)cout<<"yes\n";
	cout << findMax(root, root) << endl;
}

void generateBinary(LL n)
{
	LL binary[bits];
	for(LL i=bits-1; i>=0; i--)
	{
		LL k = n >> i;
		
		if(k & 1)
		  binary[bits-i-1] = 1;
		else
		  binary[bits-i-1] = 0;
	}
	
	for(LL i=0; i<bits; i++)
	{
		if(binary[i] == 0)
		{
			if(!root->left)
			{
				struct node * q = new struct node;
				q->data = 0;
				q->pos = bits-i-1;
				root->left = q;
				q->right=NULL;
				q->left=NULL;
			}
			root = root->left;
		}
		else
		{
			if(!root->right)
			{
				struct node * q = new struct node;
				q->data = 1;
				q->pos = bits-i-1;
				root->right = q;
				q->right=NULL;
				q->left=NULL;
			}
			root = root->right;
		}
	}
}

LL findMax(struct node * p, struct node * q)
{
	if(p == root)
	{
		if(p->left && p->right)
		  return (findMax(p->left, p->right));
		if(p->left)
		  return (findMax(p->left, p->left));
		if(p->right)
		  return (findMax(p->right, p->right));
	}
	if(p->pos == 0)
	{
		return (p->data ^ q->data);
	}
	LL x = pow(2, p->pos);
	
	LL value = x * (p->data ^ q->data);
	
	if((p->left && q->right) || (p->right && q->left))
	{
		LL x1 = 0, x2 = 0;
	
		if(p->left && q->right)
		{
			x1 = value + findMax(p->left, q->right);
		}
		if(p->right && q->left)
		{
			x2 = value + findMax(p->right, q->left);
		}
		return (max(x1, x2));
	}
	  
	if(!p->right && !q->right)
	{
		return(value + findMax(p->left, q->left));
	}
	if(!p->left && !q->left)
	{
		return(value + findMax(p->right, q->right));
	}
	return 0;
}

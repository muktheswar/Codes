#!/usr/bin/python
def powi(n,mod):
	if mod==0:return 1
	if mod==1:return n
	ans=powi(n/2,mod);
	ans=(ans*ans)%mod;
	if n%2==1:ans=(ans*n)%mod;
	return ans;
if __name__=="__main__":
	s=raw_input()
	an="";
	sumi=0;
	p=1;
	n=len(s);
	f=0;
	for i in range(len(s)):
		if s[i]=='0':an+='1'
		else : 
			an+='0';
			f=1;
	if f==0: print 0;
	else:
	#	print an;	
		for i in range(len(an)):
			sumi+=p*(ord(an[n-i-1])-48);
			p*=2;
	#	print sumi;	
		p=1;	
		twop=1;
		for i in range(n):
			twop=twop*2;
	#	print twop	
		ans1=(twop-sumi);	
		ans2=sumi;
	
		mod=1000000007
		ans=(((ans1*(ans1-1)/2)%mod)+((ans2*(ans2-1)/2)%mod))%mod;
		print ans;




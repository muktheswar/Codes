#!/usr/bin/python
def powi(a,n):
	if n==0:return 1;
	if n==1:return a;
	ans=pow(a,n/2);
	ans=ans*ans;
	if n%2!=0:ans=ans*a;
	return ans;

if __name__=="__main__":
	while(1):
		s=raw_input();
		s=s.split();
		s[0]=int(s[0]);
		s[1]=int(s[1]);
		if s[0]==0 and s[1]==0:break;
		print powi(s[0],s[1]);

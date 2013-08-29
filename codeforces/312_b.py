#!/usr/bin/python

if __name__=="__main__":
	s=raw_input();
	s=s.split();
	for i in range(len(s)):
		s[i]=float(s[i]);
	ans=s[0]/s[1];
	t=(1-s[0]/s[1])*(1-s[2]/s[3]);
	print ans*(1/(1-t));	



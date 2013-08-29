#!/usr/bin/python
from fractions import Fraction
if __name__=="__main__":
	s=raw_input()
	s=s.split()
	for i in range(len(s)):
		s[i]=int(s[i])
	a=s[0]*1.0/s[1]	
	ans=str(Fraction(a).limit_denominator(s[2]))
	#print ans
	#for i in range(len(ans)):
	#	print ans[i],
	if(ans.find('/')!=-1):
		print ans
	else:
		print ans+'/1'



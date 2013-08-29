#!/usr/bin/python
if __name__=="__main__":
	f1=0;
	f2=1;
	f3=0;
	l=pow(10,9);
	l+=1;
	for i in range(l+1):
		f3=f1+f2;
		f1=f2;
		f2=f3;
	print f3


#!/usr/bin/python
import math
if __name__=="__main__":
	T=input();
	while(T>0):
		n=input();
		k=1;
		x=0;
		y=0;
		while(1):
			ans=1+k*k*n;
			print ans;
			t=int(math.sqrt(ans));
			if t*t==ans:
				x=t;
				break;
			k+=1
		print x,k
		T-=1;	
			

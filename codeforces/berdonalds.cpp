#include <iostream>
using namespace std;
#define infi 10000000  //infi for infinityclass prims
int ROW;
int COL;
int sum;

class prims{
	int graph[200][200];
	int nodes;
	public:
	prims();
	void createGraph();
	void primsAlgo();
};

prims :: prims(){
	for(int i=0;i<ROW;i++)
		for(int j=0;j<ROW;j++)
			graph[i][j]=infi;
}

void prims :: createGraph(){
	int i,j;
	for(i=0;i<COL;i++){
		int a,b;
		cin>>a>>b>>graph[a][b];
	}

}

void prims :: primsAlgo(){
	int selected[ROW],i,j,ne; //ne for no. of edgesintfalse=0,true=1,min,x,y;

	for(i=0;i<nodes;i++)
		selected[i]=false;

	selected[0]=true;
	ne=0;

	while(ne < nodes-1){
		min=infi;

		for(i=0;i<nodes;i++)
		{
			if(selected[i]==true){
				for(j=0;j<nodes;j++){
					if(selected[j]==false){
						if(min > graph[i][j])
						{
							min=graph[i][j];
							x=i;
							y=j;
						}
					}
				}
			}
		}
		selected[y]=true;
		sum+=graph[x+1][y+1];
		ne=ne+1;
	}
}

void main(){
	sum=0;
	prims MST;
	clrscr();
	cin>>ROW>>COL;
	MST.createGraph();
	MST.primsAlgo();
	cout<<((double)sum)/2<<"\n";
	return 0;
}

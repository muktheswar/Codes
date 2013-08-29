#include<iostream>
using namespace std;
int main()
{
    int a,res=1,s=0;
    cin>>a;
    for(int i=1;i<a;i++)
    {
        s+=12;res+=s;
    }
    cout<<res<<"\n";
    return 0;
}

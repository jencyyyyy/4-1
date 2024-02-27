#include <bits/stdc++.h>

using namespace std;
//a=1,b=3,c=0,M=10
//a=2,b=1,c=0.M=10 
int main()
{
    int mul_C,add_C,Seed,mod,iteration;
    //float x=0;
    cout<<"Enter Multiplicative, Additive, Seed and Mod value";
    cin>>mul_C>>add_C>>Seed>>mod;
    int x=Seed;
    cout<<"No of itiration: ";
    cin>>iteration;
    for(int i=0;i<iteration;i++){
        cout<<x<<"\t";
        x =((mul_C*x+add_C) % mod);
    }
}
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define deb(x) cout<<#x<<" "<<x<<endl
#define fo(i,n) for(int i=0;i<n;i++)
#define nl cout<<endl;
#define inputi(a) scanf("%d",&a)
#define inputl(a) scanf("%lld",&a)
#define printi(a) printf("%d ",a)
#define printl(a) printf("%lld ",a)
#define vi vector<int>
const ll Max2=1e9+7;
const int Max1=1e6+1;
 
template<typename... T>
void read(T&&... arg){
    ((cin>>arg),...);
}
 
template<typename... T> 
void write(T&&... arg){ //rvalue reference (new to cpp)
    ((cout<<arg<<" "),...);
    //cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        //vector<ll>v;
        ll minm=0,maxm=0;
        for(int i=0;i<n;++i){
            ll a;
            cin>>a;
            minm=minm+a;
            maxm=ceil(a*1.0/x)+maxm;
        }
        minm=ceil(minm*1.0/x);
        printl(minm);
        printl(maxm);
        cout<<endl;
    }
}
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
        int n;
        cin>>n;
        vector<ll>v;
        //vector<ll>dp(n);
        for(int i=0;i<n;++i){
            ll p;
            cin>>p;
            v.push_back(p);
        }
        ll q=0;
        for(int i=n-1;i>=0;--i){
        	if(i+v[i]<n)
            	v[i]=v[i]+v[i+v[i]];
        }

        for(int i=0;i<n;i++)
        	q=max(q,v[i]);
        //cout<<endl;
        cout<<q<<endl;
    }
}
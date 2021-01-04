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
        //vector<int>v;
        int a=0,b=0;
        int c=0,d=0;
        for(int i=0;i<n;i++){
            int p;
            cin>>p;
            if(p==1) c++;
            else d++;
        }
        if(d%2!=0){
            c=c-2;
        }
        if(c>=0 && c%2==0){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}
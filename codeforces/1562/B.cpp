#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
bool a[105];
string s;
inline bool prime(int p){
    if(p==1)return 1;
    for(register int i=2;i*i<=p;i++)if(p%i==0)return 1;
    return 0;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    for(register int i=1;i<=100;i++)a[i]=prime(i);
    while(t--){
        cin>>n>>s;
        bool flag=1;
        for(register int i=0;i<n&&flag;i++)if(s[i]=='1'||s[i]=='4'||s[i]=='6'||s[i]=='9'||s[i]=='8'){cout<<"1\n"<<s[i]<<endl;flag=0;}
        if(!flag)continue;
        for(register int i=0;i<n&&flag;i++)
        for(register int j=i+1;j<n&&flag;j++)if(a[(s[i]-'0')*10+s[j]-'0']){
            cout<<"2\n"<<s[i]<<s[j]<<endl;
            flag=0;
        }
    }
    return 0;
}
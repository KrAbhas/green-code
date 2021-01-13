#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cout << #x << " " << x << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define nl cout << endl;
#define inputi(a) scanf("%d", &a)
#define inputl(a) scanf("%lld", &a)
#define printi(a) printf("%d ", a)
#define printl(a) printf("%lld ", a)
#define vi vector<int>
#define vl vector<ll>
const ll Max2 = 1e9 + 7;
const int Max1 = 1e6 + 1;

template <typename... T>
void read(T &&... arg)
{
    ((cin >> arg), ...);
}

template <typename... T>
void write(T &&... arg)
{ //rvalue reference (new to cpp)
    ((cout << arg << " "), ...);
    //cout<<endl;
}

int main()
{
    ll t;
    inputl(t);
    while(t--){
        ll n;
        inputl(n);
        vl v;
        ll a;
        for(int i=0;i<n;++i){
            inputl(a);
            v.push_back(a);
        }
        ll k=0;
        sort(v.begin(),v.end(), greater<ll>());
        for(int i=0;i<n;++i){
            if(i%2==0){
                if(v[i]%2==0){
                    k = k + v[i];
                }
            }
            else{
                if(v[i]%2==1)
                    k=k-v[i];
            }
        }
        if(k>0){
            cout<<"Alice\n";
        }
        else if(k<0){
            cout<<"Bob\n";
        }
        else{
            cout<<"Tie\n";
        }
    }
}
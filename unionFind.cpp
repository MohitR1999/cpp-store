#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>

using namespace std;
const int N =1e5+1;
bool is[N]; 

int val[N],n;

int par[N];
void init(){for(int i=1;i<=n;i++) par[i]=i,val[i]=0;}
int root(int a){while(par[a]!=a) a=par[a]=par[par[a]]; return a;}
void join(int a,int b){par[root(a)]=root(b);}

int main() {
    int x,id,cnt;
    cin>>n;
    while(n!=0){
        ll res=0;
        vector<pii> vec;
        for(int i=1;i<=n;i++) {
            cin>>x;
            is[i]=0;
            vec.pb(mp(x,i));
        }
        init();
        sort(vec.rbegin(),vec.rend());
        for(int i=0;i<n;i++){
            x=vec[i].first;
            id=vec[i].second;
            cnt=1;
            if(id>1 && is[id-1]) {
                cnt+=val[root(id-1)];
                join(id,id-1);
            }
            if(id<n && is[id+1]) {
                cnt+=val[root(id+1)];
                join(id,id+1);
            }
            is[id]=1;
            val[root(id)]=cnt;
            res=max(res,1LL*cnt*x);
            // for(int j=1;j<=n;j++) cerr<<par[j]<<" "; cerr<<"\n";
            // for(int j=1;j<=n;j++) cerr<<val[j]<<" "; cerr<<"\n";
        }
        cout<<res<<"\n";
        cin>>n;
    }
    return 0;
}
#include <bits/stdc++.h>
#define long long ll 
using namespace std;

ll fibm(ll n,vector<ll> qb){
    
    if( n < 2 )
    	return n; 
    
    if(qb[n]!=0)
    	return qb[n];
  
    else
    {
      qb[n]=fibm(n-1,qb) +fibm(n-2,qb);
      return qb[n];
    }
}


void main(){
    int n=10;
    ll  res = fibm(n,vector<ll> (n+1,0));
    cout<<res<<" " << endl;
}

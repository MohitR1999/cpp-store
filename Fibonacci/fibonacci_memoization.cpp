#include <bits/stdc++.h>

using namespace std;

long fibm(long n,vector<long> qb){
    
    if(n==1 ||n==0){
    	return n;
    }
    if(qb[n]!=0){
    	return qb[n];
    }
    else{
      int x=fibm(n-1,qb) +fibm(n-2,qb);
      qb[n]=x;
      return x;
    }
}


int main(){
int n=10;
 long  res=fibm(n,vector<long> (n+1,0));
cout<<res<<" ";

cout<<endl;
return 0;
}

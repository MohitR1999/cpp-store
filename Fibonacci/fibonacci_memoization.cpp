#include<iostream.h>
#include<conio.h>

fibo(ll n,vector<ll> qb){
    
    if( n < 2 )
    	return n; 
    
    if(qb[n]!=0)
    	return qb[n];
  
    else
    {
      qb[n]=fibo(n-1,qb) +fibo(n-2,qb);
      return qb[n];
    }
}


void main()
{
clrscr();
    int n=10;
    ll  res = fibo(n,vector<ll> (n+1,0));
    cout<<res<<" " << endl;
getch();
}

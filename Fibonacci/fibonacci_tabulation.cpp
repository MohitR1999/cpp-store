#include <bits/stdc++.h>

using namespace std;


vector<unsigned long long int> fibt(unsigned long long int n){
    vector<unsigned long long int> a(n,0);
    a[0]=0;
    a[1]=1;
    for(unsigned long long int x=2;x<=n;x++){
        a[x]=a[x-1]+a[x-2];
    }
    return a;
}

int main(){
int n=10;
vector<unsigned long long int> res=fibt(n);

for(int i=0;i<res.size();i++)
{
cout<<res[i]<<" ";
}
cout<<endl;
return 0;
}

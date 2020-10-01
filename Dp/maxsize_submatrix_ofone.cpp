#include <bits/stdc++.h>

using namespace std;


void mssm(vector< vector<int>> mat){

    vector< vector<int>> table(mat.size(),vector<int> (mat[0].size(),0));
    int dr= mat.size()-1;
    int dc= mat[0].size()-1;
    int  max=0;
    int orow=-1;
    int ocol=-1;

    for(int r=dr;r>=0;r--){
        for(int c=dc;c>=0;c--){

            if(r==dr && c==dc){
                table[r][c]=mat[r][c];
            }
            else if(r==dr){
                table[r][c]=mat[r][c];
            }
            else if(c==dc){
                table[r][c]=mat[r][c];
            }
            else{
                if(mat[r][c]==0){
                    table[r][c]=0;
                }
                else{
                    table[r][c]= 1+ min(table[r+1][c+1],min(table[r+1][c],table[r][c+1]));
                }
            }
            if(table[r][c]>max){
                max=table[r][c];
                orow=r;
                ocol=c;
            }

        }
    }

cout<< "max size square is:"<<max<<" at ("<<orow<<","<<ocol<<")"<<endl;
}

static int maxi=0;
int mssmm(vector< vector<int>> mat,int sr,int sc,vector< vector<int>> qb){
    int dr= mat.size()-1;
    int dc= mat[0].size()-1;

    if(sr==dr && sc==dc){
        return mat[sr][sc];
    }
    if(qb[sr][sc]!=0){
        return qb[sr][sc];
    }
    if(mat[sr][sc]){
        return 0;
    }

    else {
       int msh =mssmm(mat,sr,sc+1,qb);
       int msv =mssmm(mat,sr+1,sc,qb);
       int msd=mssmm(mat,sr+1,sc+1,qb);

       int res= 1+min(msh,min(msv,msd));

        if(res>maxi){
            maxi=res;
        }
        qb[sr][sc]=res;
        return res;
   }

}
int main(){

    vector< vector<int>> a={
            {1,0,1,0,0,1},
            {1,0,1,1,1,1},
            {1,1,1,1,1,1},
            {1,1,1,1,0,0},
            {1,1,1,1,1,1},
            {0,0,1,1,1,0}
    };
  mssm(a);
    vector< vector<int>> x(a.size(),vector<int> (a[0].size(),0));
  mssmm(a,0,0,x);
  cout<<endl;
  cout<<maxi;
    return 0;
}

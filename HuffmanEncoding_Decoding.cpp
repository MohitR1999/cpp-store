#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char c;
    int val;
    Node* left;
    Node* right;
    Node(char c,int val){
        this->c = c;
        this->val = val;
        left=right=NULL;
    }
};
class mycomp
{  public:
    bool operator() (Node* a, Node* b)
    {
        return a->val>b->val;
    }
};

Node* huffmancode(vector<pair<char,int>> a){
   
    priority_queue<Node*,vector<Node*>,mycomp> q;
    for(int i=0;i<a.size();i++){
        Node* newnode = new Node(a[i].first,a[i].second);
        q.push(newnode);
    }
   
    while(q.size()>1){
        Node* top1 = q.top();
        q.pop();
        Node* top2 = q.top();
        q.pop();
        Node* newnode = new Node('#',top1->val+top2->val);
        newnode->left = top1;
        newnode->right = top2;
        q.push(newnode);
    }
    Node* root = q.top();
    q.pop();
    return root;
}

void encode(Node* root,string s,map<char,string> &m){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        m[root->c] = s;
    }
    encode(root->left,s+"0",m);
    encode(root->right,s+"1",m);
}
int main(){
    string s;
    cin>>s;
    
    int n  = s.size();
    map<char,int> m1;
    for(int i=0;i<n;i++){
        m1[s[i]]++;
    }
    vector<pair<char,int>> a;
    for(auto i:m1){
        a.push_back({i.first,i.second});
    }
    Node* root = huffmancode(a);
    map<char,string> m;
    string t = "";
    encode(root,t,m);
    map<string,char> decode;
    for(auto i:m){
        decode[i.second] = i.first;
        cout<<i.first<<"-->"<<i.second<<endl;
    }
    cout<<"enter binary to code decode this string"<<endl;
    string temp;
    cin>>temp;
    string run = "";
    string ans="";
    for(int i=0;i<temp.size();i++){
        run.push_back(temp[i]);
        if(decode.find(run)!=decode.end())
        {
            ans.push_back(decode[run]);
            run = "";
        }
    }
    cout<<ans<<endl;
    cout<<endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

typedef char data_t;
struct Node                             //creation of linked list
{
    data_t data;
    Node* link;

    Node(data_t ele)
    {
        data=ele;
        link=nullptr;
    }
};

Node* pstart=nullptr;

void insertfront(data_t ele)        //insert at front side  of linked list
{
    //Node *pNewNode=(struct Node *)malloc(sizeof(struct Node));  //create the node
    Node *pNewNode=new Node(ele);

    pNewNode->link=pstart;
    pstart=pNewNode;

    //pNewNode->data=ele;
    //pNewNode->link=nullptr;

}
void insertrear(data_t ele)            //insert at rear side  of linked list
{
    Node *pNewNode=new Node(ele);
    if(pstart=nullptr)
     {
       pstart=pNewNode;
     }
    else
    {

     Node *pTemp=pstart;
     while(pTemp->link!=nullptr)
     {
         pTemp=pTemp->link;
     }
     pTemp->link=pNewNode;
    }


}
void deleteFront()           //Delete at front side  of linked list
{
    if(pstart)
    {
       Node *temp=pstart;
       pstart=pstart->link;
       delete(temp);
    }
    else{
        cout<<"list is empty\n";
    }

}
void deleteRear()           //Delete at rear side  of linked list
{
    Node *temp=pstart;
    if(!pstart)
    {
        cout<<"List is Empty\n";
    }
    else if(!temp->link)
    {
        delete temp;
        pstart = nullptr;
    }
    else
    {
        while(temp->link->link)
        {
            temp=temp->link;
        }
        delete(temp->link);
        temp->link=nullptr;
    }
}
void display()                //Traverse the linked list
{
   Node *pTraverse = pstart;
   if(pTraverse==nullptr)
   {
       cout<<"empty\n";
   }
   else
   {
      while(pTraverse!=nullptr)
       {
           cout<<pTraverse->data<<" ";
           pTraverse=pTraverse->link;
       }


   }
}
void reverselist()             //reverse the list with the help of builtin stack 
{
    stack<Node *> stk;
    Node *temp=pstart;
    while(temp)
    {
        stk.push(temp);
        temp=temp->link;
    }
    while(stk.empty()==false)
    {
        cout<<stk.top()->data<<"  ";
        stk.pop();
    }
}
/*void displayreverse(Node *pTrav)
{
    if(pTrav)
    {
        displayreverse(pTrav->link);
        cout<<pTrav->data<<" ";
    }
}*/
int main()
{
    //insertfront(63);
    insertfront('r');
    insertfront('a');
    insertfront('j');

    //insertfront(10);
    //insertfront(40);
    displayreverse(pstart);
    //display();
    //deleteFront();
    //deleteRear();
    //insertrear("hariom"s);
    //insertrear("Mahadev");
    cout<<endl;
    //display();



}
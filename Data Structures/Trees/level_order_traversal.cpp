/*
 * Level Order traversal for trees
 *
 * similar to BFS in graphs
 *
 */

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node * left;
    node * right;

    node(int val) : data {val} , left { nullptr } , right { nullptr } 
    {}
};

void print_level_order(node * root) {

    if(!root) return; //root == nullptr

    queue<node *> q;
    q.push(root);
    
    cout << "Output: ";

    while(!q.empty()) {

        node * tmp = q.front();
        cout << tmp->data << " ";
        q.pop();
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }

    cout << endl;
}

int main() {

    // Example tree 
    //                  5
    //                /  \
    //                2   6
    //               / \   \
    //              0   4   8
    //                 /
    //                 3
    // Output : 5 2 6 0 4 8 3

    node * five = new node(5);
    node * two = new node(2);
    node * six = new node(6);
    five->left = two;
    five->right = six;
    node * zero = new node(0);
    two->left = zero;
    node * four = new node(4);
    two->right = four;
    node * eight = new node(8);
    six->right = eight;
    node * three = new node(3);
    four->right = three;

    print_level_order(five);

}
    

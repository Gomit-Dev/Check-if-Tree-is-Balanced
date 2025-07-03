#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert() {
    int val;
    cin >> val;
    if (val == -1) 
    {
        return NULL;
    }
    
    Node* root = new Node(val);
    root->left = insert();
    root->right = insert();
    
    return root;
}

int checkHeight(Node* root) {
    if (!root) return 0;
    int lh = checkHeight(root->left);
    if (lh == -1) return -1;
    int rh = checkHeight(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {
    cout << "Enter nodes in preorder (-1 for NULL): ";
    Node* root = insert();
    if (isBalanced(root)) 
        cout << "The tree is Balanced.";
    else 
        cout << "The tree is Not Balanced.";
    return 0;
}

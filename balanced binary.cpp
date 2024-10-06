
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
int isBalRec(Node* root)
{
    if (root == NULL)
        return 0;
    int lh = isBalRec(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalRec(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

bool isBalanced(Node *root) {
  return (isBalRec(root) > 0);
}
int main()
{
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}

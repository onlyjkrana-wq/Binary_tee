#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_Binary_Tree()
{
    int a;
    cin >> a;
    Node *root = new Node(a);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *my_left, *my_right;
        if (l == -1)
        {
            my_left = NULL;
        }
        else
        {
            my_left = new Node(l);
        }
        if (r == -1)
        {
            my_right = NULL;
        }
        else
        {
            my_right = new Node(r);
        }

        front->left = my_left;
        front->right = my_right;

        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
    }
    return root;
}
int cout_node(Node *root)
{
    if (root == NULL)
        return 0;
    int l = cout_node(root->left);
    int r = cout_node(root->right);
    return l+r+1;
}
int main()
{
    Node *root = input_Binary_Tree();
    int coutn = cout_node(root);
    cout << coutn;
    return 0;
}
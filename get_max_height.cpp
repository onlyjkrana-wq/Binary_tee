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

// input Tree //
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

// get max height //
int get_max_height(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    int l = get_max_height(root->left);
    int r = get_max_height(root->right);

    return max(l,r)+1;
}

// main functoin //
int main()
{
    Node *root = input_Binary_Tree();
    int max_height = get_max_height(root);
    cout << max_height;
    return 0;
}
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


Node* input_tee()
{
    int val; 
    cin >> val;
    Node *root = new Node(val);

    queue<Node *> q;
    q.push(root); // push root in que

    while (!q.empty())
    {
        //
        Node *front = q.front();
        q.pop();
        //cout << front->val <<" ";

        // chacking value ant create new node
        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight; // create new Node

        if (l == -1)
        {
            myLeft = NULL;
        }
        else
        {
            myLeft = new Node(l);
        }
        if (r == -1)
        {
            myRight = NULL;
        }
        else
        {
            myRight = new Node(r);
        }

        // link cunnect
        front->left = myLeft;
        front->right = myRight;

        // value push on que
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
    return root;
}


void inorder(Node *a)
{
    queue <Node *> q;
    q.push(a);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        cout << front->val << " ";

        if (front->left != NULL)
        {
            q.push(front->left);
        }

        if (front->right != NULL)
        {
            q.push(front->right);
        }
    }
}
int main()
{
    Node* root = input_tee();
    inorder(root);
    return 0;
}
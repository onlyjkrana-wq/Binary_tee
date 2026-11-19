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
void level_order(Node *a)
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
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);

    a->left = b;
    a->right = c;
    b->left = d;
    c->left = e;
    c->right = f;

    level_order(a);
    return 0;
}
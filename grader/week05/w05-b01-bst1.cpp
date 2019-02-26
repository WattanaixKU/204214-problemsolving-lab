#include <iostream>
using namespace std;
struct node
{
    int value;
    node* l;
    node* r;
    node(int v, node* l = 0, node* r = 0) : value(v), l(l), r(r){}
};
void BSTinsert(node*root, int x)
{
    if(x <= root->value)
        if(root->l == 0)
            root->l = new node(x);
        else
            BSTinsert(root->l, x);
    else
        if(root->r == 0)
            root->r = new node(x);
        else
            BSTinsert(root->r, x);
}
int BSTfind(node* root, int x)
{
    if(root == 0)
        return 0;
    else if(root->value == x)
        return 1;
    else
        if(x <= root->value)
            return BSTfind(root->l, x);
        else
            return BSTfind(root->r, x);
}
int main()
{
    node* root = 0;
    int m,k,x;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> k >> x;
        if(k==1)
            if(root == 0)
                root = new node(x);
            else
                BSTinsert(root,x);
        else
            cout << BSTfind(root,x) << endl;
    }
    return 0;
}
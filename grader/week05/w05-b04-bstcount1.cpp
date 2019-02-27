#include <iostream>
using namespace std;
struct node
{
    int value;
    int lc;
    int rc;
    node* l;
    node* r;
    node(int v, int lc = 0, int rc = 0, node* l = 0, node* r = 0) : value(v), lc(lc), rc(rc), l(l), r(r){}
};
void BSTinsert(node*root, int x)
{
    if(x <= root->value)
    {
        root->lc = root->lc + 1;
        if(root->l == 0)
            root->l = new node(x);
        else
            BSTinsert(root->l, x);
    }
    else
    {
        root->rc = root->rc + 1;
        if(root->r == 0)
            root->r = new node(x);
        else
            BSTinsert(root->r, x);
    }
}
int BSTcountall(node* croot)
{
    if(croot == 0)
        return 0;
    //return croot->child+1;
}
int BSTcount(node* root, int x)
{
    if(root == 0)
        return 0;
    else if(x == root->value)
        return (int)(root->rc);
    else
        if(x < root->value)
            return 1+BSTcount(root->l, x)+(int)(root->rc);
        else
            return BSTcount(root->r, x);
}
int main()
{
    ios::sync_with_stdio(false);
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
            cout << BSTcount(root,x) << endl;
    }
    return 0;
}

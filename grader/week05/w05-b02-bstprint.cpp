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
void BSTprint(node* croot, int hight)
{
    if(croot != 0)
    {
        BSTprint(croot->r, hight+1);
        for(int i=0;i<hight;i++)
            cout << "...";
        cout << "* " << croot->value << endl;
        BSTprint(croot->l, hight+1);
    }
}
int main()
{
    node* root = 0;
    int m,x;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> x;
        if(root == 0)
            root = new node(x);
        else
            BSTinsert(root,x);
    }
    BSTprint(root, 0);
    return 0;
}
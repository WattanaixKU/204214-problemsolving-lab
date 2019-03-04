#include <iostream>
using namespace std;
struct node
{
    int value;
    int rc;
    node* l;
    node* r;
    node(int v, int rc = 0, node* l = 0, node* r = 0) : value(v), rc(rc), l(l), r(r){}
};
int BSTinsert(node*root, int x)
{
    if(x <= root->value)
        if(root->l == 0)
        {
            root->l = new node(x);
            return root->rc + 1;
        }
        else
            return BSTinsert(root->l, x) + root->rc + 1;
    else
    {
        root->rc = root->rc + 1;
        if(root->r == 0)
        {
            root->r = new node(x);
            return 0;
        }
        else
            return BSTinsert(root->r, x);
    }
}

int BSTcount(node* root, int x)
{
    int count = 0;
    if(root == 0)
        return 0;
    else
    {
        while(root!=0 && root->value != x)
        {
            if(x < root->value)
            {
                count += (int)root->rc+1;
                root = root->l;
            }
            else
                root = root->r;
        }
        if(root!=0)
            count += (int)root->rc;
    }
    return count;
}
int main()
{
    ios::sync_with_stdio(false);
    node* root = 0;
    int m,x;
    long long count = 0;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d", &x);
        if(root == 0)
            root = new node(x);
        else
            count += BSTinsert(root,x);
    }
    cout << count << endl;
    return 0;
}

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
void BSTinsert(node*root, int x)
{
    if(x <= root->value)
        if(root->l == 0)
            root->l = new node(x);
        else
            BSTinsert(root->l, x);
    else
    {
        root->rc = root->rc + 1;
        if(root->r == 0)
            root->r = new node(x);
        else
            BSTinsert(root->r, x);
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
    int m,k,x;
    //cin >> m;
    scanf("%d ",&m);
    for(int i=0;i<m;i++)
    {
        //cin >> k >> x;
        scanf("%d %d ",&k, &x);
        if(k==1)
            if(root == 0)
                root = new node(x);
            else
                BSTinsert(root,x);
        else
            //cout << BSTcount(root,x) << endl;
            printf("%d\n",BSTcount(root,x));
    }
    return 0;
}

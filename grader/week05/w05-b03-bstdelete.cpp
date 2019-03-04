#include <iostream>
using namespace std;
struct node
{
    int value;
    node* p;
    node* l;
    node* r;
    node(int v,node* p, node* l = 0, node* r = 0) : value(v),p(p) , l(l), r(r){}
};
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
void BSTinsert(node*root, int x)
{
    if(x <= root->value)
        if(root->l == 0)
            root->l = new node(x,root);
        else
            BSTinsert(root->l, x);
    else
        if(root->r == 0)
            root->r = new node(x,root);
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
int BSTdelete(node* root, int x)
{
    if(root == 0)
        return 0;
    else if(root->value == x)
    {
        if(root->l == 0 && root->r == 0)
            if(root->p->r == root)
                root->p->r = 0;
            else
                root->p->l = 0;
        else if(root->l != 0 && root->r == 0)
        {
            if(root->p->r == root)
                root->p->r = root->l;
            else
                root->p->l = root->l;
            root->l->p = root->p;
        }
        else if(root->r != 0 && root->l == 0)
        {
            if(root->p->r == root)
                root->p->r = root->r;
            else
                root->p->l = root->r;
            root->r->p = root->p;
        }
        else
        {
            node* q = root->r;
            while(q->l!=0)
                q = q->l;
            q->p->l = q->r;
            q->l = root->l;
            q->r = root->r;
            if(root->p->r == root)
                root->p->r = q;
            else
                root->p->l = q;
            if(q!=0)
                q->p = root->p;
        }
        delete root;
        return 1;

    }
    else
        if(x <= root->value)
            return BSTdelete(root->l, x);
        else
            return BSTdelete(root->r, x);
}
int main()
{
    node* root = new node(0,0);
    int m,k,x;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> k >> x;
        if(k==1)
            if(root->r!=0)
                BSTinsert(root->r,x);
            else
                root->r = new node(x,root);
        else if(k==2)
            cout << BSTfind(root->r,x) << endl;
        else
            BSTdelete(root->r,x);
        BSTprint(root->r,0);
    }
    return 0;
}

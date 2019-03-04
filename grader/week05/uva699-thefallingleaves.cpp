#include <iostream>
using namespace std;
struct node
{
    int value;
    node* p;
    node* l;
    node* r;
    node(int value, node* p, node* l=0,node* r=0) : value(value), p(p), l(l), r(r){}
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

void addToBST(node* header)
{
    int inp;
    bool started = 0;
    node* c = header;
    //node* c = new node(inp,header);
    //header->l = c;
    while(header!=c || !started)
    {
        cin >> inp;
        started = 1;
        c->value = inp;
        if(inp == -1)
        {
            c = c->p;
            while(c->r->value != 0)
                c = c->p;
            c = c->r;
        }
        else
        {
            c->l = new node(0,c);
            c->r = new node(0,c);
            c = c->l;
        }
        BSTprint(header, 0);
    }

}
int main()
{
    int t,cases = 1;
    node* header = new node(0,0);
    addToBST(header);

    return 0;
}
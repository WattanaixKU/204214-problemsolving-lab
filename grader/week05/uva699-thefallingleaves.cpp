#include <iostream>
#include <vector>
using namespace std;
vector<int> answer;
int p = 0;
struct node
{
    int value;
    node* l;
    node* r;
    node(int value, node* l=0,node* r=0) : value(value), l(l), r(r){}
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

void BSTCount(node* header)
{
    if(header->value != -1)
    {
        if(p < 0)
        {
            p++;
            answer.insert(answer.begin(),header->value);
        }
        else if(p == answer.size())
            answer.push_back(header->value);
        else
            answer[p]+=header->value;
        p--;
        BSTCount(header->l);
        p+=2;
        BSTCount(header->r);
        p--;
    }
}

bool addToBST(node* header, int inp)
{
    if(header->value == -1)
        return false;
    if(header->value == 0)
    {
        header->value = inp;
        if(inp != -1 && inp != 0)
        {
            header->l = new node(0);
            header->r = new node(0);
        }
        return true;
    }
    if(!addToBST(header->l, inp))
        if(!addToBST(header->r, inp))
            return false;
    return true;
}
int main()
{
    int t, count = 0;
    bool running = false;
    node* header = new node(0);
    while(true)
    {
        cin >> t;
        if(t == -1 && !running)
            break;
        addToBST(header, t);
        if(!addToBST(header, 0))
        {
            //BSTprint(header,0);
            BSTCount(header);
            cout << "Case " << ++count << ":" << endl;
            for(int i=0;i<answer.size()-1;i++)
                cout << answer[i] << " ";
            cout << answer.back() << endl << endl;;
            header = new node(0);
            answer.clear();
            p = 0;
            running = false;
            continue;
        }
        running = true;
    }
    //cout << "done" << endl;
    return 0;
}
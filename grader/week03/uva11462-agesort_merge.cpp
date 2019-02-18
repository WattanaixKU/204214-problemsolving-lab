#include <iostream>
using namespace std;
struct node
{
    int value;
    node* next;
};
typedef pair<node*,int> pln;
pln merge(pln inp)
{
    /*
    node* head = inp.first;
    //print list
    for(int i=0;i<inp.second;i++)
    {
        cout << head -> value << " ";
        head = head -> next;
    }
    cout << "merge\n";
    */
    if(inp.second == 1)
        return inp;
    node* tmp = inp.first;
    for(int i=0;i<inp.second/2;i++)
        tmp = tmp->next;
    pln a = merge(make_pair(inp.first,inp.second/2));
    pln b = merge(make_pair(tmp,inp.second-inp.second/2));
    node* tail = NULL;
    tmp = NULL;
    while(!(a.second == 0 && b.second == 0))
    {
        if(a.second == 0)
        {
            tail -> next = b.first;
            b.second = 0;
            tail = tail -> next;
        }
        else if(b.second == 0)
        {
            tail -> next = a.first;
            a.second = 0;
            tail = tail -> next;
        }
        else
        {
            if(a.first -> value <= b.first -> value)
            {
                if(tail == NULL)
                    tail = a.first;
                else
                {
                    tail -> next = a.first;
                    tail = tail -> next;
                }
                a.first = a.first -> next;
                a.second--;
            }
            else
            {
                if(tail == NULL)
                    tail = b.first;
                else
                {
                    tail -> next = b.first;
                    tail = tail -> next;
                }
                b.first = b.first -> next;
                b.second--;
            }
        }
        if(tmp == NULL)
            tmp = tail;
        else if(tmp != tail && tmp->next == NULL)
            tmp -> next = tail;
    }
    return make_pair(tmp,inp.second);
}
int main()
{
    int n,t;
    cin >> n;
    node* head = NULL;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        node* c = new node();
        c -> value = t;
        c -> next = head;
        head = c;
    }
    pln ans = merge(make_pair(head,n));
    head = ans.first;
    //print list
    for(int i=0;i<n;i++)
    {
        cout << head -> value << " ";
        head = head -> next;
    }
    cout << endl;
    return 0;
}
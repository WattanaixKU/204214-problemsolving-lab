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
    if(inp.second == 1)
        return inp;
    node* tmp = inp.first;
    for(int i=0;i<inp.second/2;i++)
        tmp = tmp->next;
    pln sorted[2];
    sorted[0] = merge(make_pair(inp.first,inp.second/2));
    sorted[1] = merge(make_pair(tmp,inp.second-inp.second/2));
    node* tail = NULL;
    tmp = NULL;
    int lower;
    while(!(sorted[0].second == 0 && sorted[1].second == 0))
    {
        if(sorted[0].second == 0)
        {
            tail -> next = sorted[1].first;
            sorted[1].second = 0;
            tail = tail -> next;
        }
        else if(sorted[1].second == 0)
        {
            tail -> next = sorted[0].first;
            sorted[0].second = 0;
            tail = tail -> next;
        }
        else
        {
            if(sorted[0].first -> value <= sorted[1].first -> value)
                lower = 0;
            else
                lower = 1;
            if(tail == NULL)
                tail = sorted[lower].first;
            else
            {
                tail -> next = sorted[lower].first;
                tail = tail -> next;
            }
            sorted[lower].first = sorted[lower].first -> next;
            sorted[lower].second--;
        }
        if(tmp == NULL)
            tmp = tail;
        else if(tmp->next == NULL)
            tmp -> next = tail;
    }
    return make_pair(tmp,inp.second);
}
int main()
{
    ios::sync_with_stdio(false);
    int n,t;
    cin >> n;
    while(n!=0)
    {
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
        for(int i=0;i<n-1;i++)
        {
            cout << head -> value << " ";
            head = head -> next;
        }
        cout << head -> value << endl;
        cin >> n;
    }
    return 0;
}
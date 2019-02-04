#include <iostream>
#include <list>
using namespace std;
int main()
{
    int n,inp;
    char mode;
    cin >>n;
    list<int> ll;
    for(int i=0;i<n;i++)
    {
        cin >> mode >> inp;
        if(mode == 'I')
            ll.push_front(inp);
        else
        {
            //ll.erase(ll.begin()+inp);
            list<int>::iterator it = ll.begin();
            while(inp!=1 && it!=ll.end())
            {
                it++;
                inp--;
            }
            if(inp==1 && it!=ll.end())
                ll.erase(it);
        }
    }
    for(list<int>::iterator it = ll.begin();it != ll.end();it++)
        cout << *it << endl;
    return 0;
}
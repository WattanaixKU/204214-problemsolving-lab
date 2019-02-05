#include <vector>
#include <map>
#include <iostream>
using namespace std;
struct cargo{
    int num;
    cargo* next;
};
int main()
{
    int n,inp1,inp2;
    char command;
    cin >> n;
    map<int,cargo* > station;
    bool in_use[100000];
    for(int i=0;i<100000;i++)
    {
        station.insert(pair<int,cargo* > (inp2, NULL));
        in_use[i] = 0;
    }
    for(int e=0;e<n;e++)
    {
        cin >> command >> inp1 >> inp2;
        if(in_use[inp2]==0)
        {
            cargo* head = new cargo;
            head->num = -1;
            head->next = NULL;
            in_use[inp2] = 1;
            station.insert(pair<int,cargo* > (inp2, head));
        }
        if(command=='N')
        {
            cargo* newOne = new cargo;
            newOne->num = inp1;
            newOne->next = NULL;
            cargo* cur = station[inp2]; 
            while(cur->next!=NULL)
                cur = cur->next;
            cur->next = newOne;
        }
        else
        {
            if(in_use[inp1]==0)
                continue;
            cargo* cur = station[inp2];
            while(cur->next!=NULL)
                cur = cur->next;
            cur->next = station[inp1]->next;
            station[inp1]->next = NULL;
        }
    }
    for(int i=0;i<100000;i++)
        if(in_use[i])
            while(station[i]->next!=NULL)
            {
                cout << station[i]->next->num << endl;
                station[i]->next = station[i]->next->next;
            }
    return 0;
}
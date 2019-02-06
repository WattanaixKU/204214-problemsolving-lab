//#include <vector>
//#include <map>
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
    cargo* station[100001];
    cargo* tail[100001];
    //bool in_use[100000];
    for(int i=0;i<100001;i++)
    {
        station[i] = NULL;
        tail[i] = NULL;
        //in_use[i] = 0;
    }
    for(int e=0;e<n;e++)
    {
        cin >> command >> inp1 >> inp2;
        if(command=='N')
        {
            cargo* newOne = new cargo;
            newOne->num = inp1;
            newOne->next = NULL;
            if(tail[inp2]!=NULL)
            {
                cargo* cur = tail[inp2];
                /*while(cur->next!=NULL)
                    cur = cur->next;*/
                cur->next = newOne;
            }
            else
                station[inp2] = newOne;
            tail[inp2] = newOne;
        }
        else
        {
            if(station[inp1]==NULL)
                continue;
            if(tail[inp2]!=NULL)
            {
                cargo* cur = tail[inp2];
                /*while(cur->next!=NULL)
                    cur = cur->next;*/
                cur->next = station[inp1];
            }
            else
                station[inp2] = station[inp1];
            station[inp1] = NULL;
            tail[inp2] = tail[inp1];
            tail[inp1] = NULL;
        }
    }
    for(int i=0;i<100001;i++)
        while(station[i]!=NULL)
        {
            cout << station[i]->num << endl;
            station[i] = station[i]->next;
        }
    return 0;
}

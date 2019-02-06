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
    cargo* station[100000];
    cargo* tail[100000];
    for(int i=0;i<100000;i++)
    {
        station[i] = NULL;
        tail[i] = NULL;
    }
    for(int e=0;e<n;e++)
    {
        cin >> command >> inp1 >> inp2;
        inp2--;
        if(command=='N')
        {
            cargo* newOne = new cargo;
            newOne->num = inp1;
            newOne->next = NULL;
            if(tail[inp2]!=NULL)
                tail[inp2]->next = newOne;
            else
                station[inp2] = newOne;
            tail[inp2] = newOne;
        }
        else
        {
            inp1--;
            if(station[inp1]==NULL)
                continue;
            if(tail[inp2]!=NULL)
                tail[inp2]->next = station[inp1];
            else
                station[inp2] = station[inp1];
            station[inp1] = NULL;
            tail[inp2] = tail[inp1];
            tail[inp1] = NULL;
        }
    }
    for(int i=0;i<100000;i++)
        while(station[i]!=NULL)
        {
            cout << station[i]->num << endl;
            station[i] = station[i]->next;
        }
    return 0;
}
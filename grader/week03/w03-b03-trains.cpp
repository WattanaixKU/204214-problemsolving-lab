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
    map<int,vector<int> > station;
    bool in_use[100000];
    for(int i=0;i<100000;i++)
        in_use[i] = 0;
    for(int e=0;e<n;e++)
    {
        cin >> command >> inp1 >> inp2;
        if(command=='N')
        {
            if(in_use[inp2]==0)
            {
                in_use[inp2] = 1;
                vector<int> tmpv;
                tmpv.push_back(inp1);
                //station[inp2].push_back(inp1);
                station.insert(pair<int,vector<int> > (inp2, tmpv));
            }
            else
                station[inp2].push_back(inp1);
        }
        else
        {
            if(in_use[inp2]==0 && station[inp1].size()!=0)
            {
                in_use[inp2] = 1;
                vector<int> tmpv;
                tmpv.push_back(station[inp1][0]);
                station[inp1].erase(station[inp1].begin());
                station.insert(pair<int,vector<int> > (inp2, tmpv));
            }
            //in_use[inp1] = 0;
            int tmp = station[inp1].size();
            for(int i=0;i<tmp;i++)
            {
                station[inp2].push_back(station[inp1][0]);
                station[inp1].erase(station[inp1].begin());
            }
            /*for(int i=0;i<station[inp1].size();i++)
                station[inp2].push_back(station[inp1][i]);
            station[inp1].clear();*/
        }
    }
    for(int i=0;i<100000;i++)
        if(in_use[i])
            for(int j=0;j<station[i].size();j++)
                cout << station[i][j] << endl;
    return 0;
}
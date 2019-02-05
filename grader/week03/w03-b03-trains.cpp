#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n,inp1,inp2;
    char command;
    cin >> n;
    vector<int> station[100000];
    bool in_use[100000];
    for(int i=0;i<100000;i++)
        in_use[i] = 0;
    for(int e=0;e<n;e++)
    {
        cin >> command >> inp1 >> inp2;
        if(command=='N')
        {
            in_use[inp2] = 1;
            station[inp2].push_back(inp1);
        }
        else
        {
            in_use[inp1] = 0;
            in_use[inp2] = 1;
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
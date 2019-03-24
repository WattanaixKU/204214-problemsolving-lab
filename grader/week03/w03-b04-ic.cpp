#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,t;
    char cmd[3];
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> cmd;
        if(cmd[1] == 'i')
        {
            cin >> t;
            if(cmd[0] == 'r')
                v.push_back(t);
            else
                v.insert(v.begin(),t);
        }
        else
        {
            if(!v.empty())
            {
                if(cmd[0] == 'r')
                {
                    v.insert(v.begin(),v.back());
                    v.pop_back();
                }
                else
                {
                    v.push_back(v[0]);
                    v.erase(v.begin());
                }
            }
        }
    }
    for(int i=0;v.begin()+i!=v.end();i++)
        cout << v[i] << endl;
    return 0;
}
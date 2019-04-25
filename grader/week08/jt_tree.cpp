#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > v;
int h;
void print_tree()
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<v[i].size();j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void input_tree()
{
    int inp;
    cin >> h;
    for(int i=1;i<h+1;i++)
    {
        vector<int> tmpv;
        for(int j=0;j<i*2;j++)
        {
            cin >> inp;
            tmpv.push_back(inp);
        }
        v.push_back(tmpv);
    }
}

int find_max_path()
{
    /*
    int layer[(h-1)*2];
    for(int j=0;j<=2*(h-1);j++)
    {
        layer[j] = max(v[h-1][j], v[h-1][j+1]);
        cout << layer[j] << " ";
    }
    cout << endl;
    */
    for(int i=h-2;i--;i>=0)
    {
        for(int j=0;j<v[i].size();j++)
        {
            v[i][j] += max(v[i+1][j], v[i+1][j]);
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    input_tree();
    print_tree();
    find_max_path();
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int n,sm = 0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int inp;
        cin >> inp;
        if(inp>0)
            sm += inp;
    }
    cout << sm << endl;
    return 0;
}
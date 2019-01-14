#include <iostream>
using namespace std;
int main()
{
    int n;
    int inp;
    int count = 1;
    int load = 0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> inp;
        if(inp+load <=1000)
            load += inp;
        else
        {
            load = inp;
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}
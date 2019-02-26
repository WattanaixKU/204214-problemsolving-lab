#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,t;
    cin >> n;
    while(n!=0)
    {
        vector<int> vv;
        for(int i=0;i<n;i++)
        {
            cin >> t;
            vv.push_back(t);
        }
        sort(vv.begin(),vv.end());
        for(int i=0;i<n-1;i++)
            cout << vv[i] << " ";
        cout << vv[n-1] << endl;
        cin >> n;
    }
    return 0;
}
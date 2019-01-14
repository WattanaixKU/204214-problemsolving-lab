#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int l[n];
    for(int i=0;i<n;i++)
        l[i] = i+1;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n+i;j++)
            cout << l[j%n];
        cout << endl;
    }
}
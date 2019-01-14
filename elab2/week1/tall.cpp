#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int l[n];
    for(int i=0;i<n;i++)
        cin >> l[i];
    for(int i=0;i<n;i++)
    {
        int count = 0;
        for(int j=0;j<n;j++)
            if(l[i]<l[j])
                count++;
        cout << count << endl;
    }
}
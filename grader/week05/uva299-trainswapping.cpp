#include <iostream>
using namespace std;
int main()
{
    int t,n,count,tmp;
    cin >> t;
    for(int r=0;r<t;r++)
    {
        count = 0;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    count++;
                    tmp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = tmp;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps." << endl;
        
    }
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string a,b;
    char c[302];
    cin >> a >> b;
    int i=0, j=0, k=0;
    while(a[i+1]!='\0')
        i++;
    while(b[j+1]!='\0')
        j++;
    c[0] = 0;
    while(i>=0 && j>=0)
    {
        c[k+1] = ((a[i]+b[j]+c[k]-96)/10);
        c[k] = ((a[i]+b[j]+c[k]-96)%10);
        k++;
        i--;
        j--;
    }
    while(i>=0)
    {
        c[k+1] = ((a[i]+c[k]-48)/10);
        c[k] = ((a[i]+c[k]-48)%10);
        k++;
        i--;
    }
    while(j>=0)
    {
        c[k+1] = ((b[j]+c[k]-48)/10);
        c[k] = ((b[j]+c[k]-48)%10);
        k++;
        j--;
    }
    if(c[k]!=0)
        cout << (int)c[k];
    for(int i=k-1;i>=0;i--)
        cout << (int)c[i];
    return 0;
}
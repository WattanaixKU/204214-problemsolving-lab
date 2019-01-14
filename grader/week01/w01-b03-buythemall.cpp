#include <iostream>
using namespace std;
int main()
{
    int p[3];
    int all[3] = {0,0,0};
    for(int i=0;i<3;i++)
        cin >> p[i];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        all[tmp-1] += p[tmp-1];
    }
    n = all[0];
    if(n>all[1])
        n = all[1];
    if(n>all[2])
        n = all[2];
    cout << n << endl;
    return 0;
}
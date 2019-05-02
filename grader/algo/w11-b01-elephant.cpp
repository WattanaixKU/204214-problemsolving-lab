#include <iostream>
using namespace std;
int main()
{
    int n, p, oldbest = -1, ans = -1;
    cin >> n;
    int tbl[n];
    cin >> tbl[0] >> tbl[1];
    tbl[0] = 0;
    tbl[1] = 0;
    tbl[2] = 0;
    for(int i=3;i<=n;i++)
    {
        oldbest = max(oldbest, tbl[i-3]);
        cin >> p;
        tbl[i] = p + oldbest;
        ans = max(ans, tbl[i]);
    }
    cout << ans << endl;
    return 0;
}

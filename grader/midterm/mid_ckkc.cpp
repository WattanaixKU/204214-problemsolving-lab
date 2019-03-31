#include <iostream>
using namespace std;
int main()
{
    int q,count = -1,x = -1;
    cin >> q;
    while(x != 0)
    {
        cin >> x;
        count++;
    }
    if((q-2558+count)%2)
        cout << "C" << endl;
    else
        cout << "K" << endl;
    return 0;
}

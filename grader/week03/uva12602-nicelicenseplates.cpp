#include <iostream>
using namespace std;
int main()
{
    int t,n;
    char c[3];
    cin >> t;
    for(int r=0;r<t;r++)
    {
        for(int i=0;i<3;i++)
        {
            cin >> c[i];
            c[i] -= 'A';
        }
        //cout << c[0]*26*26 + c[1]*26 + c[2] << endl;
        cin >> n;
        n *= -1;
        if(abs(n-(c[0]*26*26 + c[1]*26 + c[2])) <= 100)
            cout << "nice" << endl;
        else
            cout << "not nice" << endl;
    }
}
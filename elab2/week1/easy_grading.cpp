#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n>=80)
        cout << "Excellent job." << endl;
    else if(n>=50)
        cout << "Okay." << endl;
    else
        cout << "Please try harder." << endl;
    return 0;
}

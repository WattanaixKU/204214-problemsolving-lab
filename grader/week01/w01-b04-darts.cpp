#include <iostream>
#include <cmath>
using namespace std;
int scorer(double a)
{
    for(int i=2;i<=10;i+=2)
        if(a<=i)
            return 6-i/2;
    return 0;
}
int main()
{
    int n,score = 0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        score += scorer(sqrt(x*x+y*y));
    } 
    cout << score << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n,x,ind = -1;
    cin >> n;
    pair<int,int> candidate[4];
    pair<int,int> ordered[4];
    for(int i=0;i<4;i++)
        candidate[i] = make_pair(0,0);
    for(int i=0;i<4*n;i++)
    {
        if(i%n==0)
            ind++;
        cin >> x;
        if(x>candidate[ind].first)
        {
            candidate[ind].first = x;
            candidate[ind].second = i+1;
        }
    }
    if(candidate[0].first > candidate[1].first)
    {
        ordered[0] = candidate[0];
        ordered[2] = candidate[1];
    }
    else
    {
        ordered[0] = candidate[1];
        ordered[2] = candidate[0];
    }
    if(candidate[2].first > candidate[3].first)
    {
        ordered[1] = candidate[2];
        ordered[3] = candidate[3];
    }
    else
    {
        ordered[1] = candidate[3];
        ordered[3] = candidate[2];
    }
    if(ordered[1].first>ordered[0].first)
    {
        pair<int,int> t = ordered[0];
        ordered[0] = ordered[1];
        ordered[1] = t;
    }
    for(int i=0;i<4;i++)
        cout << ordered[i].second << " ";
    cout << endl;
    return 0;
}

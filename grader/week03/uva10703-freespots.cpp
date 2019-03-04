#include <iostream>
using namespace std;
int main()
{
    int w,h,tmp,n,count;
    pair<int,int> xy[2];
    while(true)
    {
        count = 0;
        cin >> w >> h >> n;
        if(w == h && h == n && n == 0)
            break;
        bool tbl[w][h];
        for(int i=0;i<w;i++)
            for(int j=0;j<h;j++)
                tbl[i][j] = true;
        for(int i=0;i<n;i++)
        {
            cin >> xy[0].first >> xy[0].second >> xy[1].first >> xy[1].second;
            if(xy[0].first>xy[1].first)
            {
                tmp = xy[0].first;
                xy[0].first = xy[1].first;
                xy[1].first = tmp;
            }
            if(xy[0].second>xy[1].second)
            {
                tmp = xy[0].second;
                xy[0].second = xy[1].second;
                xy[1].second = tmp;
            }
            xy[0].first--;
            xy[1].first--;
            xy[0].second--;
            xy[1].second--;
            for(int j=xy[0].first;j<=xy[1].first;j++)
                for(int k=xy[0].second;k<=xy[1].second;k++)
                    tbl[j][k] = false;
        }
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<h;j++)
            {
                if(tbl[i][j])
                    count++;
                //cout << tbl[i][j];
            }
            //cout << endl;
        }
        if(count == 0)
            cout << "There is no empty spots." << endl;
        else if(count == 1)
            cout << "There is one empty spot." << endl;
        else
            cout << "There are " << count << " empty spots." << endl;
    }
    return 0;
}

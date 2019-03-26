#include "probelib.h"
#include <iostream>
using namespace std;
int main()
{
    int i = 0,f,mid;
    f = probe_init()-1;
    while(f-i>1)
    {
        mid = (f+i)/2;
        if(probe_check(mid,f))
            i = mid;
        else
            f = mid;

    }
    if(probe_check(i,i))
        probe_answer(i);
    else
        probe_answer(f);
    return 0;
}
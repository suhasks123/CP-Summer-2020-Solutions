#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, ctr=0;
    cin >> a >> b;
    while((a!=0 && b!=0) && (a>1 || b>1))
    {
        if(a>=b)
        {
            a -= 2;
            b++;
        }
        else
        {
            b -= 2;
            a++;
        }
        ctr++;
    }
    cout << ctr;
    return 0;
}

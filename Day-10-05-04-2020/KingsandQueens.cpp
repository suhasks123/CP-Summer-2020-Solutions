#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, ax, ay, bx, by, cx, cy;
    cin >> n;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    bool x1, x2, x, y1, y2, y;
    x1 = ax>bx && ax<cx;
    x2 = ax>cx && ax<bx;
    x = x1 || x2;
    y1 = ay>by && ay<cy;
    y2 = ay>cy && ay<by;
    y = y1 || y2;

    if(x || y)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}

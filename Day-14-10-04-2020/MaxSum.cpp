#include<bits/stdc++.h>

using namespace std;


int calculateSum(long long n)
{
    int digit, sum=0;
    while(n!=0)
    {
        digit = n%10;
        sum+=digit;
        n/=10;
    }
    return sum;
}


int main()
{
    long long n, i;
    int s1, s2, sum, m=-3343;
    cin >> n;
    for(i=0;i<=n/2;i++)
    {
        cout << i << "\n";
        s1 = calculateSum(i);
        s2 = calculateSum(n-i);
        sum = s1 + s2;
        if(sum>m)
        {
            m=sum;
        }
    }
    cout << m;
    return 0;
}

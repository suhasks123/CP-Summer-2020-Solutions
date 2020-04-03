#include<bits/stdc++.h>

using namespace std;

int calculateTurns(int k, int n, int a, int b)
{
    int i;
    //vector<int> arr;
    long long val = ((long long)n) * b;
    if(val>=k)
    {
        return -1;
    }
    val = ((long long)n) * a;

    if(val<k)
    {
        return n;
    }
    /*for(i=0;i<n+1;i++)
    {
        arr.push_back(i);
    }*/
    long long low, high;
    low = 0;
    high = n;
    long long mid;
    while(high >= low)
    {
        mid = low + ((high-low)/2);
        if(((mid*a)+((n-mid)*b))<k && (((mid+1)*a)+((n-(mid+1))*b))>=k)
        {
            return mid;
        }

        if(((mid*a)+((n-mid)*b))<k && (((mid+1)*a)+((n-(mid+1))*b))<k)
        {
            low = mid + 1;
        }

        if(((mid*a)+((n-mid)*b))>=k)
        {
            high = mid - 1;
        }


    }


}


int main()
{
    int q, i, k, n, a, b, temp;
    cin >> q;
    vector<int> ans;
    for(i=0;i<q;i++)
    {
        cin >> k>>n>>a>>b;
        temp = calculateTurns(k, n, a, b);
        ans.push_back(temp);
    }

    for(i=0;i<q;i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, n, i, temp, a;
    vector<int> C;
    int sum;
    cin >> A >> B >> n;
    a = A;
    for(i=0;i<n;i++)
    {
        cin >> temp;
        C.push_back(temp);
    }
    sum  = accumulate(C.begin(), C.end(), 0);
    //sum *= B;
    int div = sum/A;
    vector<long long> time;
    long long current = 0;
    //int a = 0;
    for(i=0;i<n;i++)
    {
        if((current + (C[i]))>= div)
        {
            if((div-current)>(current + (C[i])-div))
            {
                current += (C[i]);
                time.push_back(B*current);
                current = 0;
                continue;
            }
            else

                time.push_back(B*current);
                current = 0;
        }
        current += (C[i]);
    }
    time.push_back(B*current);
    long long res = *max_element(time.begin(), time.end());
    //long long shit = 1000000000000;
    cout << res%10000003;
    return 0;

}

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
    string s1, s2;
    cin >> n;
    int digit;
    int sum=0;
    int carry=0;
    while(n!=0)
    {
        digit = n%10;
        if(digit==9 && carry==0)
        {
            s1.append(to_string(9));
            s2.append(to_string(0));
            sum += 9;
            carry=0;
            n/=10;
            continue;
        }
        if(n<10)
        {
            s1.append(to_string(n/2));
            s2.append(to_string(n-carry-(n/2)));
            sum+=n-carry;
            break;
        }

        digit+=10;
        s1.append(to_string(9));
        s2.append(to_string(digit-carry-9));
        sum+=digit-carry;
        carry=1;
        //n-=digit;
        n/=10;
    }
    /*while(n!=0)
    {
        digit = n%10;
        if(n<10)
        {
            s1.append(to_string(n/2));
            s2.append(to_string(n-(n/2)));
            sum+=n;
            break;
        }
        digit+=10;
        s1.append(to_string(9));
        s2.append(to_string(digit-9));
        sum+=digit;
        n-=digit;
        n/=10;
    }*/
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    //cout << s1 << "    " << s2 << "\n";
    cout << sum;
    return 0;
}

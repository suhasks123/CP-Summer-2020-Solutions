#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string ans;
    int temp;
    int digit;
    cin >> n;
    cin >> ans;
    if(n==0 && ans == "0")
    {
        cout << "OK";
        return 0;
    }
    vector<int> num;
    int flag = 0;
    while(n)
    {
        digit = n % 10;
        num.push_back(digit);
        n/=10;
    }
    sort(num.begin(), num.end());
    vector<int> s;
    s.push_back(-3343);
    for(int i = 0; i<num.size();i++)
    {

        if(flag==0 && num[i]!=0)
        {
            s[0] = num[i];
            flag=1;
            continue;
        }
        s.push_back(num[i]);
        //cout << s[i] << "\n";
    }
    /*for(vector<int>::iterator i = num.begin();i != num.end();i++)
    {
        if(*i != 0)
        {
            temp = *i;
            num.erase(i);
            num.push_front(temp);
            break;
        }
    }*/
    int d = 1;
    int number = 0;
    for(vector<int>::reverse_iterator i = s.rbegin();i != s.rend();i++)
    {
        number += (d*(*i));
        d *= 10;
    }
    string str = to_string(number);
    //cout << number;
    //cout << str;
    if(str == ans)
        cout << "OK";
    else
        cout << "WRONG_ANSWER";

    return 0;

}

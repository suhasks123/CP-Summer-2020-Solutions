#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str, hour, minute;
    int flag=0, i, h, m, r;
    cin>> str;
    for(i=0;i<str.length();i++)
    {
        if(str[i]==':')
        {
            flag=1;
            continue;
        }
        if(flag==0)
        {
            hour.push_back(str[i]);
            continue;
        }
        else if(flag==1)
        {
            minute.push_back(str[i]);
            continue;
        }
    }
    h = stoi(hour);
    m = stoi(minute);
    reverse(hour.begin(), hour.end());
    r = stoi(hour);


    if(m<r)
    {
        if(r>59)
        {
            if(h<10)
                cout<< "10:01";
            else if(h>10)
                cout << "20:02";
            return 0;
        }
        if(h<10)
            cout << "0";
        cout << h << ":" << r;
        return 0;
    }
    if(h == 23)
    {
        cout << "00:00";
        return 0;
    }
    if(m>=r)
    {
        h++;
        string temp = to_string(h);
        reverse(temp.begin(), temp.end());
        if(h<10)
            temp.push_back('0');
        r = stoi(temp);
        if(r>59)
        {
            if(h<10)
                cout<< "10:01";
            else if(h>10)
                cout << "20:02";
            return 0;
        }
        if(h<10)
            cout << "0";
        cout << h << ":" << temp;
        return 0;
    }
    return 0;

}

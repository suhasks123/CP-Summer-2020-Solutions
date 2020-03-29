#include <bits/stdc++.h>

using namespace std;

int findRev(string str1, string str2)
{
    reverse(str2.begin(), str2.end());
    if(str1 == str2)
        return 1;
    else
        return 0;
}

int findPalin(string str)
{
    //string s;
    //int siz = str.size();
    /*char s1[siz];
    str.copy(s1, siz, 0);
    string s = s1;
    reverse(s.begin(), s.end());
    if(str == s)
        return 1;
    else
        return 0;*/
    if (str == string(str.rbegin(), str.rend()))
        return 1;
    else
        return 0;
}

int main()
{
    int n, k;
    int i, j, p=-1;
    string s;
    vector<string> str;
    cin >> n >> k;
    map<int, int> pairs;
    vector<int> lone;
    map<string, vector<int>> m, mx;
    do
    {
        cin >> s;

        str.push_back(s);
        if(findPalin(s)==1)
        {
            lone.push_back(str.size()-1);
        }
        sort(s.begin(), s.end());
        if(m.count(s)>0)
        {
            map<string,vector<int>>::iterator it;
            it = m.find(s);
            (it->second).push_back(str.size()-1);
        }
        //else if(m.count(s)==0)
        else
        {
            vector<int> v;
            v.push_back(str.size()-1);
            m.insert(pair<string, vector<int>>(s,v));
        }
    } while(str.size()<n);

    /*for(map<string,vector<int>>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if((it->second).size()>0)
        {
            mx.insert(pair<string, vector<int>>(it->first,it->second));
        }
    }*/
    map<string,vector<int>>::iterator it;
    /*for(it=m.begin();it!=m.end();++it)
    {
        cout << it->first<<"\n";
        for(i=0;i<it->second.size();i++)
            cout<< it->second[i] << ",";
        cout << "\n";
    }*/

    for(it = m.begin(); it != m.end(); ++it)
    {
        for(i=0;i<((it->second).size());i++)
        {
            /*if(findPalin(str[(it->second)[i]])==1)
            {
                //cout << str[(it->second)[i]];
                lone.push_back(i);
            }*/
            for(j=i+1;j<((it->second).size());j++)
            {
                if(findRev(str[(it->second)[i]], str[(it->second)[j]])==1)
                {
                    //cout << str[(it->second)[i]] << "\n";
                    //cout << str[(it->second)[j]] << "\n";
                    if(pairs.count((it->second)[i])<1)
                    {
                        pairs.insert(pair<int, int>((it->second)[i],(it->second)[j]));
                    }
                }
            }
        }
    }
    //int k;
    for(i=0;i<lone.size();i++)
    {
        //cout << pairs.count(lone[i]);
        //cout << str[lone[i]];
        if(pairs.count(lone[i])==0)
        {
            //cout << str[p];
            p=lone[i];
            break;
        }
    }
    string final = "";

    map<int, int>::iterator ps;
    for(ps=pairs.begin();ps != pairs.end();++ps)
    {
        final.append(str[(ps->first)]);
        //cout << str[ps->first];
    }
    if(p!=-1)
        final.append(str[p]);

    map<int, int>::reverse_iterator pr;
    for(pr=pairs.rbegin();pr != pairs.rend();++pr)
    {
        final.append(str[(pr->second)]);
        //cout << str[pr->second];
    }

    cout<< final.size() << "\n";
    cout<< final;

    return 0;
}

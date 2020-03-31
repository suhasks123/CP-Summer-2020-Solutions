#include <bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    int i, fact;
    fact = 1;
    for(i=1;i<=n;i++)
    {
        fact *= i;
    }
    return fact;
}

int combination(int n)
{
    int result = factorial(n)/(factorial(n-2)*2);
    return result;
}


// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int total = 0;
    string str, original;
    int i, j;
    for(i=1;i<s.size();i++)
    {
        map<string, int> m;
        for(j=0;j<=(s.size()-i);j++)
        {
            str = s.substr(j,i);
            original = str;
            sort(str.begin(), str.end());
            //cout << "HELLOOOO:" << str << "\n";
            if(m.count(str)>0)
            {
                map<string,int>::iterator it;
                it = m.find(str);
                (it->second)++;
            }
            else
            {
                m.insert(pair<string, int>(str,1));
            }
        }
        map<string,int>::iterator it;
        //cout<< "HELLOOOOOO\n";
        for(it = m.begin();it != m.end();++it)
        {
            //cout<< it->first << "\n";
            if(it->second>1)
            {
                //cout<< it->first << " " << it->second << "\n";
                total += combination(it->second);
            }
        }
    }

    //cout << total << "\n";
    //int pairs = total/2;
    //cout << pairs << "\n";
    return total;

}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

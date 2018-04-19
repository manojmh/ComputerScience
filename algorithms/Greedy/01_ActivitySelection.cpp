#include <bits/stdc++.h>
using namespace std;
//start and finish time
typedef pair<int, int> iPair;

bool comp(iPair a, iPair b)
{
    return(a.second < b.second);
}

int main()
{
    std::vector<iPair> v =  {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    sort(v.begin(), v.end(), comp);
#ifdef DEBUG
    for(auto it=v.begin(); it != v.end(); it++)
        cout << it->first << " " << it->second << endl;
#endif
    int i=0;
    cout << v[i].first << " " << v[i].second << endl;
    for(int j=1; j<v.size(); j++)
    {
        if(v[j].first > v[i].second)
        {
            cout << v[j].first << " " << v[j].second << endl;
            i = j;
        }
    }
    return 0;
}

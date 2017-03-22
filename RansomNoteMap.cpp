#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) 
{
    unordered_map<string, int> magmap;
    for(vector<string>::iterator it=magazine.begin();it!=magazine.end();it++)
    {
        if(magmap.count(*it)>0) //already exists
           {
                unordered_map<string,int>::iterator m = magmap.find(*it);
                m->second++;
           }
        else
            magmap.insert(pair<string,int>(*it,1));    
    }
      
    for(vector<string>::iterator it=ransom.begin();it!=ransom.end();it++)
    {
        unordered_map<string,int>::iterator r = magmap.find(*it);
        if((r!=magmap.end()) && (r->second>0))  //found
            r->second--;
        else
            return false;            
    }  
    
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++)
    {
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++)
    {
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

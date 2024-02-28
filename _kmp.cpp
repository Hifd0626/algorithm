#include<iostream>
#include<vector>
using namespace std;
vector<int> init_pi(string s) 
{
    vector<int> pi(s.size());
    for(int i = 1; i < s.size(); i++) 
    {
        int j = pi[i-1];
        while(j != 0 && s[i] != s[j]) 
            j = pi[j-1];
        if(s[i] == s[j]) 
            j++;
        pi[i] = j;
    }
    return pi;
}
// s是匹配主串、p是匹配模式串
vector<int> _kmp(string s, string p, vector<int> pi)
{
    vector<int> ans;
    int j = 0;
    for(int i = 0; i < s.size(); i++) 
    {
        while(j != 0 && s[i] != p[j]) 
            j = pi[j-1];
        if(s[i] == p[j]) 
            j++;
        if(j == p.size()) 
        {
            ans.push_back(i-j+1);
            j = pi[j-1];
        }
    }
    return ans;
}

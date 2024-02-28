#include<iostream>
#include<vector>
#include<string>//STL封装string类 字符串相关操作 //getline(cin,str1);
using namespace std;
bool check(string test)
{
    string reverse;
    for(int i=test.size()-1;i>=0;--i)
    {
        reverse+=test[i];
    }
    if(test==reverse)
        return true;
    else
        return false;

}
string plus_change(int N,string M)
{
    int c_in=0;
    string final;
    vector<int> initial,reverse;
    vector<int> result(M.size()+1);
    if(N>=2&&N<=10)
    {
        for(int i=0;i<M.size();++i)
        {
            initial.push_back((M[i]-'0'));
            reverse.push_back(M[M.size()-i-1]-'0');
        }
    }
    else if(N==16)
    {
        for(int i=0;i<M.size();++i)
        {
            if((M[i]-'0')<10)
                initial.push_back((M[i]-'0'));
            else if(M[i]>='A')
                initial.push_back((M[i]-'A'+10));
                 
            if(M[M.size()-i-1]-'0'<10)
                reverse.push_back(M[M.size()-i-1]-'0');
            else if(M[M.size()-i-1]>='A')
                reverse.push_back(M[M.size()-i-1]-'A'+10);
        }
    }
    for(int i=M.size()-1;i>=0;--i)
    {
        result[i+1]=((initial[i]+reverse[i]+c_in)%N);
        if(initial[i]+reverse[i]+c_in>=N)
            c_in=1;
        else
            c_in=0;
    }
    if(c_in==1)
        result[0]=c_in;

    else
        result.erase(result.begin());
    if(N>=2&&N<=10)
    {
        for(int i=0;i<result.size();++i)
        {
            final.push_back(result[i]+'0');
        }
    }
    else if(N==16)
    {
        for(int i=0;i<result.size();++i)
        {
            if(result[i]<10)
                final.push_back(result[i]+'0');
            else
                final.push_back(result[i]-10+'A');
        }
    }
    return final;
}
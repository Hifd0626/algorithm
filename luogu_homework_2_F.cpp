#include<iostream>
#include<vector>
#include<string>
using namespace std;
void change(int n,vector<int>& tmp)
{
    int R;

    while(n!=0)
    {
        R=n%2;
        tmp.push_back(R);
        n=n/2;
    }

}
bool check(vector<int> test, int i)
{
    bool flag=true;
    for(int j=i-1;j>=0;j--)
        if(test[j]==1)
            flag=false;
    return flag;
}
void out_put(int n)
{
    vector<int> tmp;
    change(n,tmp);
        
        for(int i=tmp.size()-1;i>=0;--i)
        {
            if(tmp[i]==1)
            {
                if(i>2)
                {
                    cout<<"2(";
                    out_put(i);
                    cout<<')';
                }
                else
                {
                    if(i==2)
                        cout<<"2(2)";
                    else if(i==1)
                        cout<<'2';
                    else if(i==0)
                        cout<<"2(0)";
                }
                if(!check(tmp,i))
                    cout<<'+';
            }
        }
        

}
string func(int n)
{
  vector<string> s;
  string res;
    for(int i=7;i>=0;i--)
    {
       if((1<<i)&n)
       {
        if(i==0)
        {
          s.push_back("2(0)");
          
        }
        else if(i==1)
        {
          s.push_back("2");
         
        }
        else if(i==2)
        {
          s.push_back("2(2)");
       
        }
        else
        {
          s.push_back("2("+func(i)+")");
        }
       
       }
    }
    for(int i=0;i<=int(s.size())-1;i++){
      res+=s[i];
      if(i<int(s.size())-1){
        res+="+";
      }
    }

    return res;
  }
#if 0
int main()
{
    int n=137;
    //cin>>n;
    //out_put(n);
    cout<<func(n)<<endl;
}
#endif






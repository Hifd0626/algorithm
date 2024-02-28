 #include<iostream>
 #include<vector>
 //using namespace std;
 void matrix_input(int n,int m,std::vector<std::vector<int>> &in)
{ 
    for(int i=0;i<n;i++)//矩阵输入
    {
        std::vector<int> tmp;
        int input;
        for(int j=0;j<m;j++)
        {
            std::cin>>input;
            tmp.push_back(input);
        }
        in.push_back(tmp);
    }
}
void matrix_multiple(std::vector<std::vector<int>> A,std::vector<std::vector<int>> B,std::vector<std::vector<int>> &C)
{
    int input;
    int n=A.size(),m=B.size(),k=B[0].size();
    for(int i=0;i<A.size();i++)
    {
     for(int j=0;j<B[0].size();j++)
        {
            for(int x=0;x<m;x++)
            {
                 C[i][j]+=A[i][x]*B[x][j];

            }
        }
    }
}
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int MinEditDistance(std::string s1,std::string s2)
{
    int n1=s1.size()+1;
    int n2=s2.size()+1;
    std::vector < std::vector<int> > myvec (n1,std::vector<int> (n2,0));
    //solve the 0 case
    for (int i=0;i<n1;++i)
        myvec[i][0] = i;
    for (int i=0;i<n2;++i)
        myvec[0][i] = i;
    //solve the rest of the cases
    for (int i=1;i<n1;++i)
    {
        for (int j=1;j<n2;++j)
        {
            if (s1[i-1]==s2[j-1])
                myvec[i][j] = myvec[i-1][j-1];
            else
                myvec[i][j] = std::min({myvec[i-1][j],myvec[i-1][j-1],myvec[i][j-1]})+1; 
        }
    }
    for (auto x:myvec)
    {
        for (int y:x)
            std::cout<<y<<"  ";
        std::cout<<std::endl;
    }
    return myvec.back().back();
}

int main()
{
    std::string s2="abcdef";
    std::string s1="azced";
    int x = MinEditDistance(s1,s2);
    std::cout<<"The Minimum number of edits to go from A to B =  "<< x;
    return 0;
}
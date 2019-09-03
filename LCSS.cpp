#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

int LongestCommonSubsequence(std::string s1, std::string s2, std::string& LCSS)
{
    int rows = s1.size()+1;
    int cols = s2.size()+1;
    std::vector <std::vector <int> > matrix (rows,std::vector <int> (cols,0));
    std::pair <int,int> ptr= {1,1};
    int i,j;
    while (ptr.first<rows)
    {
        i=ptr.first;
        while(ptr.second<cols)
        {
            j=ptr.second;
            if (s1[i-1]==s2[j-1])
            {
                matrix[i][j]=1+matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j]=std::max(matrix[i-1][j],matrix[i][j-1]);
            }
            ++ptr.second;
        }
        ptr.second=1;
        ++ptr.first;
    }
    //travel backward in the matrix to find out the longest common subsequence
    ptr={rows-1,cols-1};
    while (ptr.first+ptr.second>0)
    {
        i=ptr.first;
        j=ptr.second;
        //std::cout<<i<<"  "<<j<<std::endl;
        if (matrix[i][j]>matrix[i-1][j] && matrix[i][j]>matrix[i][j-1])
        {
            LCSS+=s1[i-1];
            --ptr.first;--ptr.second;
        }
        else 
        {
            if (matrix[i][j]==matrix[i-1][j])
            {
                --ptr.first;
            }
            else 
            {
                --ptr.second;
            }
        }
        
    }
    std::reverse(LCSS.begin(),LCSS.end());
    return matrix.back().back();
}

int main()
{
    std::string s1="acbcf";
    std::string s2="abcdaf";
    std::string LCSS ="";
    int answer = LongestCommonSubsequence(s1,s2,LCSS);
    std::cout<<"The longest common subsequence between\""<<s1<<"\" and \""<<s2<<" is: \"";
    std::cout<<LCSS<<"\""<<std::endl;
    std::cout<<"length of LCSS="<<answer<<std::endl;
}
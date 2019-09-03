#include <iostream>
#include <string>
#include <vector>
#include <utility>

bool DoesMatchExist (std::string query, std::string regex)
{
    int rows= query.size()+1;
    int cols= regex.size()+1;
    std::vector <std::vector <bool>> matrix (rows,std::vector <bool> (cols,false));
    //initialize 0,0 , which is the trivial case
    matrix[0][0]=true;
    //intitialize 0th column and 0th row

    //fill in the matrix using dynamic programming
    std::pair <int,int> ptr = {1,1};
    int i,j;
    while (ptr.first<rows)
    {
        i=ptr.first-1;
        while (ptr.second<cols)
        {
            j=ptr.second-1;
            if (query[i]==regex[j] || regex[j]=='.')
            {
                matrix[ptr.first][ptr.second]=matrix[ptr.first-1][ptr.second-1];
            } 
            else if (regex[j]=='*') 
            {
                //0 occurence
                matrix[ptr.first][ptr.second]=matrix[ptr.first][ptr.second-2];
                //multiple occurences (.* case and a* case)
                if (regex[j-1]=='.' || query[i]==regex[j-1])
                {
                    matrix[ptr.first][ptr.second]= matrix[ptr.first-1][j];  
                }
            }
            else 
                matrix[ptr.first][ptr.second]=false;
            ++ptr.second;
        }
        ptr.second=1;
        ++ptr.first;
    }
    for (auto i:matrix)
    {
        for (bool j:i)
            std::cout<<j<<" ";
        std::cout<<std::endl;
    }
    return matrix.back().back();
}


int main()
{
    std::string regex = "xa*b.c";
    std::string query = "xaabyc";
    if (DoesMatchExist(query,regex))
        std::cout<<"The query matches the regular expression!";
    else
        std::cout<<"The query doesn't match the regular expression!";
}
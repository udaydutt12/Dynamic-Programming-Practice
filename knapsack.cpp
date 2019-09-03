#include <iostream>
#include <utility> 
#include <vector>
#include <algorithm>

int Knapsack(std::vector <std::pair<int,int> > items, int totalweight)
{
    int rows = items.size();
    int cols = totalweight+1;
    //1. Create an array of size [items.length()]*[Totalweight+1] all set to 0
    std::vector <std::vector <int> > matrix(rows,std::vector<int> (cols,0));
    std::pair<int,int> item;
    for (int i=0;i<rows;++i)
    {
        item = items[i];
        for (int j=1;j<cols;++j)
        {
            if (j < item.second)
                matrix[i][j] = matrix[i-1][j];
            else
            {
                if (i==0) 
                    matrix[i][j]=item.second;
                else
                    {
                        matrix[i][j] = std::max(item.first+matrix[i-1][j-item.second],matrix[i-1][j]);
                    }
            }
        }
    }
    for (auto x:matrix)
    {
        for (int y:x)
            std::cout<<y<<" ";
        std::cout<<std::endl;
    }
    return matrix.back().back();
}


int main()
{
    std::vector < std::pair<int,int> > items;
    items.push_back(std::make_pair(1,1));
    items.push_back(std::make_pair(4,3));
    items.push_back(std::make_pair(5,4));
    items.push_back(std::make_pair(7,5));
    int totalweight=7;
    int maxval = Knapsack(items,totalweight);
    std::cout<<maxval;
}
#include <iostream>
#include <utility> 
#include <vector>

int Knapsack(std::vector <std::pair<int,int>> items, int totalweight)
{
    int rows = items.size();
    int cols = totalweight+1;
    //1. Create an array of size [items.length()]*[Totalweight+1] all set to 0
    std::vector <std::vector <int>> matrix(rows,std::vector<int> (cols));
    std::pair ptr = {0,0};
    std::pair item;
    int prev = 0;
    while (ptr.first<rows)
    {
        item = items[ptr.first];
        while (ptr.second < cols)
        {
            if (ptr.second < item.second)
            {
                matrix[ptr.first][ptr.second] = prev;
            }
            else
            {
                matrix[ptr.first][ptr.second] = std::max(item.first+matrix[ptr.first-1][ptr.second-item.second],prev);
                prev = matrix[ptr.first][ptr.second];
            }
            ++ptr.second;
        }
        prev=0;
        ++ptr.first;
    }
    return matrix.back().back();
}


int main()
{
    std::vector <std::pair<int,int>> items;
    items.push_back({1,1});
    items.push_back({3,4});
    items.push_back({4,5});
    items.push_back({5,7});
    int totalweight=7;
    int maxval = Knapsack(items,totalweight);
}
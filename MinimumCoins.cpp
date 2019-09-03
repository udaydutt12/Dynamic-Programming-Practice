#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int MinCoins (std::vector<int> coins,int total)
{
    int n = coins.size();
    std::vector<std::vector <int> > myvec (n,std::vector<int> (total+1,0));
    //fill in 1st row
    for (int j=1;j<total+1;++j)
        myvec[0][j] = j;
    //do rest of matrix using DP
    for (int i=1;i<n;++i)
    {
        for (int j=1;j<total+1;++j)
        {
            if (j>=coins[i])
                myvec[i][j]=std::min(myvec[i-1][j],myvec[i][j-coins[i]]+1);
            else
                myvec[i][j]=myvec[i-1][j];
        }
    }
    //use back-propagation through the vector to print the two coins out
    std::pair<int,int> p={n-1,total};
    std::cout<<"Here are the coins that make "<<total<<": ";
    while(myvec[p.first][p.second]>0)
    {
        if (myvec[p.first][p.second]==myvec[p.first-1][p.second])
            --p.first;
        else
        {
            std::cout<<coins[p.first]<<" ";
            p.second-=coins[p.first];
        }
    }
    std::cout<<std::endl;
    return myvec.back().back();
}

int main ()
{
    std::vector<int> coins = {1,5,6,8};
    int total =11;
    int x= MinCoins(coins,total);
    std::cout<<"The minimum number of coins to get "<<total<<" from "<<"1,5,6,8 is: "<<x;
}
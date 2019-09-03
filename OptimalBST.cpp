#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

int OptimalBST(std::vector <std::pair <int,int>> myBST)
{
    int n = myBST.size();
    std::vector <std::vector <int>> matrix (n,std::vector <int> (n,0));
    //do l=0 case
    for (int i = 0; i<n;++i)
    {
        matrix[i][i]=myBST[i].second;
    }
    auto sumfunc = [](int a, std::pair <int,int> b) {
                        return a+b.second;
                     };
    int sum;
    //do l=1 to l=n-1
    for (int l=1;l<n;++l)
    {
        std::vector <int> minvec (l+1,0);
        for (int j=0;j<n-l;++j)
        {
            minvec.clear();
            for (int k=j;k<=j+l;++k)
            {
                sum = 0;
                if (k>j)
                    sum +=matrix[j][k-1];
                if (k<j+l)
                    sum+=matrix[k+1][j+l];
                minvec.push_back(sum);
            }
            auto min=std::min_element(minvec.begin(),minvec.end());
            matrix[j][j+l] = std::accumulate(myBST.begin()+j, myBST.begin()+j+l+1,0,sumfunc)+*min;
        }
    }
    //return the minimum weight of the tree after optimization
    return matrix[0][n-1];
}

int main ()
{
    std::vector <std::pair <int,int> > myBST;
    myBST.push_back({10,4});
    myBST.push_back({12,2});
    myBST.push_back({16,6});
    myBST.push_back({21,3});
    int x = OptimalBST(myBST);
    std::cout<<" The Binary Search Tree Can be Optimized to have a Total Cost of: "<< x << std::endl;
}
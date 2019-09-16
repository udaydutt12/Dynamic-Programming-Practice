#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int MinAttempts(int eggs,int floors)
{
    std::vector<std::vector<int>> matrix(eggs,std::vector<int>(floors,0));
    std::set<int> maxset;
    //give the matrix initial conditions
    for (int j=0;j<floors;++j)
      matrix[0][j]=j+1;
    for (int i=1;i<eggs;++i)
    {
        //number of eggs=i+1
        for (int j=0;j<floors;++j)
        {
          //current floor=j+1
          if (i>=j)
            matrix[i][j]=matrix[i-1][j];
          else 
          {
            maxset.clear();
            for(int k=0;k<=j;++k)
                maxset.insert(1+std::max(matrix[i-1][k-1],matrix[i-1][j-k]));
            for (auto l=maxset.begin();l!=maxset.end();++l)
              std::cout<<*l<<" ";
            std::cout<<std::endl;
            matrix[i][j]=*maxset.begin();
          }
        }
    }
    for (auto x:matrix)
    {
      for (auto y:x)
        std::cout<<y<<" ";
      std::cout<<std::endl;
    }
    return matrix.back().back();
}

int main()
{
    int eggs=2;
    int floors=6;
    int answer=MinAttempts(eggs,floors);
    std::cout<<"the minimum number of attempts it takes to find where "<<eggs<<"\n";
    std::cout<<"eggs crack if there are "<<floors<<" floors is: "<<answer;
}
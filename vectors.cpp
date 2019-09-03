// Example program
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
bool f (int a, int b)
{
  return a>b ? true : false;
}

void vectorDemo()
{
    std::vector<int> myvec = {11,2,3,14};
    
    std::cout << myvec[1] << std::endl;
    
    //Sorting vectors
    //use sort() from algorithms
    sort(myvec.begin(),myvec.end()); //O(NlogN)
    
    //Searching Vectors
    //Binary Search
    bool present = binary_search(myvec.begin(),myvec.end(),3); //true
    present = binary_search(myvec.begin(),myvec.end(),4); //false
    
    myvec.push_back(85); // appends 85 to the end of the vector
    present = binary_search(myvec.begin(),myvec.end(),85); //true
    
    myvec.push_back(85);
    myvec.push_back(85);
    myvec.push_back(85);
    myvec.push_back(253);
    
    //Search the lower bound of the input
    //if the input is 85, the return is the pointer to the first element >=85
    //vector<int>::iterator it = lower_bound(myvec.begin(),myvec.end(),85); 
    auto it = lower_bound(myvec.begin(),myvec.end(),85); //returns the ptr to the 1st 85
    
    //Search the upper bound of the input
    //if the input is 85, the return is the pointer to the first element >85
    //vector<int>::iterator it = upper_bound(myvec.begin(),myvec.end(),85);
    auto it2 = upper_bound(myvec.begin(),myvec.end(),85); //returns the ptr to 253
    
    std::cout << *it << "  " << *it2 << std::endl; //85  253
    std::cout << it2-it << std::endl; //4, because they are 4 pointers apart
    
    //sort in descending order using comparator 'f'
    sort(myvec.begin(),myvec.end(),f); 

    //iterating through a vector
    //for (vector<int>iterator it3=myvec.begin();it!=myvec.end();++it3)
    for (int x:myvec)
    {
        std::cout << x << " ";
    } 
}

int main()
{
    vectorDemo();
}
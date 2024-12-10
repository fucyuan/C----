#include <iostream>
#include "Vector.h" 
class Test
{
private:
    /* data */
public:
     Test();
     ~Test();
};
 Test:: Test()
{
    std::cout<<"Test"<<std::endl;
}
Test::~Test()
{
    std::cout<<"~Test"<<std::endl;
}

int main()
{
    // Vector<Test,Allocator<Test>> v;
    Vector<int> v1(5);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    // for(int i=0;i<v1.size();i++)
    // {
    //     std::cout<<v1[i]<<" ";
    // }
    // while(!v1.empty())
    // {
    //     std::cout<<v1.back()<<" ";
    //     v1.pop_back();
    // }
    // std::cout<<std::endl;
    //  for(int i=0;i<v1.size();i++)
    // {
    //     std::cout<<v1[i]<<" ";
    // }
    // std::cout<<std::endl;
    for(auto it=v1.begin();it!=v1.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
    
// #include <iostream>
// #include "Vector.h" 
// #include<vector> 
// //迭代器为什么失效
// //当容器的元素被删除后，迭代器失效，因为迭代器指向的位置已经不再是容器中的元素。
// //当从插入元素的时候，迭代器也会失效，因为插入元素之后，容器中的元素位置发生了变化。
// //因此，在容器中进行元素的删除、插入操作时，一定要注意迭代器的失效问题。
// //解决方法：   
// //对于insret来说，可以先获取插入位置的迭代器，然后再插入元素。
// //对于erase来说，可以先获取删除位置的迭代器，然后再调用erase函数。
// //但是，对于其他操作，比如遍历容器，或者对容器进行其他操作，都要注意迭代器的失效问题。
// //因此，在容器中进行元素的删除、插入操作时，一定要注意迭代器的失效问题。
// //另外，对于容器的遍历，可以用for循环，也可以用迭代器。
// //对于for循环，可以用range-based for循环，也可以用普通的for循环。
// //对于迭代器，可以用begin()和end()函数，也可以用其他函数。
// //总结：
// //1.对于insret来说，可以先获取插入位置的迭代器，然后再插入元素。
// //2.对于erase来说，可以先获取删除位置的迭代器，然后再调用erase函数。
// //3.对于其他操作，比如遍历容器，或者对容器进行其他操作，都要注意迭代器的失效问题。
// //4.对于容器的遍历，可以用for循环，也可以用迭代器。
// //5.对于for循环，可以用range-based for循环，也可以用普通的for循环。
// //6.对于迭代器，可以用begin()和end()函数，也可以用其他函数。
// class Test
// {
// private:
//     /* data */
// public:
//      Test();
//      ~Test();
// };
//  Test:: Test()
// {
//     std::cout<<"Test"<<std::endl;
// }
// Test::~Test()
// {
//     std::cout<<"~Test"<<std::endl;
// }

// int main()
// {
//     // // Vector<Test,Allocator<Test>> v;
//     // Vector<int> v1(5);
//     // v1.push_back(1);
//     // v1.push_back(2);
//     // v1.push_back(3);
//     // v1.push_back(4);
//     // v1.push_back(5);
//     // // for(int i=0;i<v1.size();i++)
//     // // {
//     // //     std::cout<<v1[i]<<" ";
//     // // }
//     // // while(!v1.empty())
//     // // {
//     // //     std::cout<<v1.back()<<" ";
//     // //     v1.pop_back();
//     // // }
//     // // std::cout<<std::endl;
//     // //  for(int i=0;i<v1.size();i++)
//     // // {
//     // //     std::cout<<v1[i]<<" ";
//     // // }
//     // // std::cout<<std::endl;
//     // for(auto it=v1.begin();it!=v1.end();it++)
//     // {
//     //     std::cout<<*it<<" ";
//     // }
//     // std::cout<<std::endl;
//     // return 0;
//     std::vector<int> v1;
//     for(int i=0;i<20;i++)
//     {
//         v1.push_back(rand()%100+1);
//     }
//     for(auto c:v1)
//     {
//         std::cout<<c<<" ";
//     }
//     std::cout<<std::endl;
//     // //把v1容器中所有偶数删除
//     // for(auto it=v1.begin();it!=v1.end();)
//     // {
//     //     if(*it%2==0)
//     //     {
//     //         //v1.erase(it);第一次调用后迭代器失效
//     //         it=v1.erase(it);
//     //     }
//     //     else
//     //     {
//     //         it++;
//     //     }
//     // }
//     // for(auto it=v1.begin();it!=v1.end();it++)
//     // {
//     //     std::cout<<*it<<" ";
//     // }
//     // std::cout<<std::endl;
//     // 给v1容器中所有偶数前面添加一个小于偶数值1的数
//     // for(auto it=v1.begin();it!=v1.end();)
//     // {
//     //     if(*it%2==0)
//     //     {
//     //         if(*it==2)   //如果偶数为2，则不添加
//     //         {
//     //             it++;
//     //         }
//     //         else
//     //         {
//     //             it=v1.insert(it,1);
//     //             it++;
//     //         }
//     //     }
//     //     else
//     //     {
//     //         it++;
//     //     }
//     // }
//     for(auto it=v1.begin();it!=v1.end();it++)
//     { 
//         if(*it%2==0)
//         {
//             if(*it==2)   //如果偶数为2，则不添加
//             {
               
//             }
//             else
//             {
//                 it=v1.insert(it,1);
//                 it++;
//             }
//         }
           
//     }

//     for(auto it=v1.begin();it!=v1.end();it++)
//     {
//         std::cout<<*it<<" ";
//     }
//     std::cout<<std::endl;
//     return 0;

    
// }
    
#include<iostream>
#include"Vector.h"
using namespace std;
int main()
{
    Vector<int> v1(50);
    for(int i=0;i<5;i++)
    {
        v1.push_back(i);
    }
    for(auto it=v1.begin();it!=v1.end();it++)
    {
        if (*it%2==0)
        {
            v1.insert(it,100);
            it++;
        }
    }
    for(auto it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it=v1.begin();it!=v1.end();)
    {
        if(*it%2==0)
        {
            //v1.erase(it);第一次调用后迭代器失效
            it=v1.erase(it);
        }
        else
        {
            it++;
        }
    }
    for(auto it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}

        

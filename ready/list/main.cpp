#include <iostream>
#include <list>
#include <vector>
#include "arraylist.h"
#include "linkedlist.h"

using namespace std;

#if 0
void sub(char str[])
{
    str = (char*)"world";
}

int main1(int argc, char const *argv[])
{
    int a = 11;
    int &a_l_r = a;
    int &&a_r_r = 10;

    cout << a << endl;
    cout << a_l_r << endl;
    cout << a_r_r << endl;
    return 0;
}
#endif
#if 1
int main(int argc, char const *argv[])
{
    LinkedList<int> local_list;
    for (int i = 0; i < 5; i++)
    {
        local_list.push_back(i + 1);
    }

    cout << "local_list1.size = " << local_list.size() << endl;
    local_list.print_list();

    return 0;
}
#endif
#if 0
int main(int argc, char const *argv[])
{
    ArrayList<int> local_list1(100);
    for (int i = 0; i < 15000000; i++)
    {
        local_list1.push_back(i + 1);
    }

    cout << "local_list1.size = " << local_list1.size() << endl;
    return 0;
}
#endif
#if 0
int main(int argc, char const *argv[])
{
    ArrayList<int> local_list1(100);
    for (int i = 0; i < 15000000; i++)
    {
        local_list1.push_back(i + 1);
    }

    local_list1.traverse();

    ArrayList<int> local_list2(local_list1);
    ArrayList<int> local_list3(std::move(local_list1));

    // cout << local_list1[1] << endl;
    cout << local_list2[1] << endl;
    cout << local_list3[1] << endl;

    return 0;
}
#endif
#if 0
int main2(int argc, char const *argv[])
{
    list<int> l;
    for (int i = 0; i < 150000; i++)
    {
        l.push_back(i + 1);
    }

    cout << l.front() << endl;
    cout << l.back() << endl;

    return 0;
}
#endif
#if 0
int main(int argc, char const *argv[])
{
    vector<int> v;
    for (int i = 0; i < 15000000; i++)
    {
        v.push_back(i + 1);
    }

    cout << v.front() << endl;
    cout << v.back() << endl;

    return 0;
}
#endif
#if 0
int main4(int argc, char const *argv[])
{

    int a = 5;
    int b = 12;
    int const *p = &a;
    p = &b;

    cout << a << endl;
    cout << b << endl;
    cout << *p << endl;

    const string &s = "asd";


    cout << s << endl;

    return 0;
}
#endif

#include <iostream>
#include <vector>
#include <list>

#include "Vector.h"

using namespace std;

// recursive
int fact(int num) {
    if (num == 0)
        return 1;
    return num * fact(num - 1);
}

template <typename Container>
void removeEveryOtherItem( Container & lst ) {
    auto itr = lst.begin();

    while( itr != lst.end() ) {     
        itr = lst.erase( itr );
        if ( itr != lst.end() )
            ++itr;
    }
}

template <typename Container, typename T>
void change( Container & lst, const T & item ) 
{
    typename Container::iterator itr = lst.begin();

    while( itr != lst.end() ) {     
        *itr++ = item;
    }
}

template <typename Container>
auto begin( Container & lst ) -> decltype( lst.begin() )
{
    return lst.begin();
}

template <typename Container>
auto begin( const Container & lst ) -> decltype( lst.begin() )
{
    return lst.begin();
}

int main()
{
    // cout << fact(5) << endl;

    Vector<int> lst;
    lst.push_back(11);
    lst.push_back(2);
    lst.push_back(3);

    // change(lst, 19);

    for( auto itr = lst.begin(); itr != lst.end(); ++itr ) {
        cout << *itr << endl;
    }
    return 0;
}

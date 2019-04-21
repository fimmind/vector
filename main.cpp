#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector<int> vec;
    int num = 0;
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << vec << endl;
        *i = ++num;
    }
    cout << vec.begin() << endl
        << vec << endl;

    return 0;
}

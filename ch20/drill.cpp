#include "../forras/std_lib_facilities.h"

template<class list>
void increment(list& container, int amount){
    for(auto& element : container)
        element += amount;
}

template<class N, class t>
t MyCopy(N start, N end, t target){
    for (N p = start; p != end; ++p)
    {
        *target++ = *p;
    }
    return target;
}


int main()
{
    int arrayNumbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> vectorNumbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    list<int> listNumbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    constexpr int size = sizeof(arrayNumbers)/sizeof(*arrayNumbers);

    //int arrayNumbers2[sizeof(arrayNumbers)/sizeof(*arrayNumbers)];
    //copy(begin(arrayNumbers), end(arrayNumbers), begin(arrayNumbers2));

    int arrayNumbers2[size];
    MyCopy(begin(arrayNumbers), end(arrayNumbers), begin(arrayNumbers2));
    vector<int> vectorNumbers2 = vectorNumbers;
    list<int> listNumbers2 = listNumbers;
    increment(arrayNumbers, 2);
    increment(vectorNumbers, 3);
    increment(listNumbers, 5);


    MyCopy(begin(arrayNumbers), end(arrayNumbers), begin(vectorNumbers2));

    ///*
    for (int& i : arrayNumbers2) cout << i << " ";
    cout << endl;
    for (int& i : vectorNumbers2) cout << i << " ";
    cout << endl;
    for (int& i : listNumbers2) cout << i << " ";
    cout << endl;
    //*/


    vector<int>::iterator vit;
    vit = find(vectorNumbers2.begin(), vectorNumbers2.end(), 3);

    if (vit != vectorNumbers2.end())
    {
        cout << "Found the 3! Its position is " << distance(vectorNumbers2.begin(), vit) << endl;
    } else {
        cout << "Not found the 3!" << endl;
    }

    vit = find(vectorNumbers2.begin(), vectorNumbers2.end(), 27);
    
    if (vit != vectorNumbers2.end())
    {
        cout << "Found the 27! Its position is " << distance(vectorNumbers2.begin(), vit) << endl;
    } else {
        cout << "Not found the 27!" << endl;
    }

    return 0;
}
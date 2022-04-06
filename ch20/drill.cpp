#include "../forras/std_lib_facilities.h"

template<class list>
void increment(list& container, int amount){
    for(auto& element : container)
        element += amount;
}



int main()
{
    int arrayNumbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> vectorNumbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    list<int> listNumbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int* arrayNumbers2 = arrayNumbers;
    vector<int> vectorNumbers2 = vectorNumbers;
    list<int> listNumbers2 = listNumbers;

    for (int i : arrayNumbers)
    {
        arrayNumbers[i] += 2;
        vectorNumbers[i] += 3; 
    }
    increment(listNumbers, 5);


    for (int& i : arrayNumbers) cout << i << " ";
    cout << endl;
    for (int& i : vectorNumbers) cout << i << " ";
    cout << endl;
    for (int& i : listNumbers) cout << i << " ";
    cout << endl;
    
    
}
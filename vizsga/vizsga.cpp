#include "../forras/std_lib_facilities.h"
#include <random>



//poisson eloszlás / poisson distribution
int main(){

    random_device r;
    mt19937 gen(r());
    //default_random_engine el(r());
    //default_random_engine generator;
    poisson_distribution<int> pisson_dis(100);
    //int random = pisson_dis(gen);
    
    vector<int> vektor;

    for (int i = 0; i < 10; i++){
        vektor.push_back(pisson_dis(gen));
    }

    for(auto i: vektor){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
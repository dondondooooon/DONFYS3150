#include <iostream>
#include<armadillo>
using namespace arma;
using namespace std;

int main(){

    int L = 6;
    // for (int i=0; i<10; i++){
    //     srand(time(NULL)); // Seed Generate
    //     int x = randu() * L;
    //     cout << "This: " << x << endl;
    // }

    srand(time(NULL));
    for (int i=0; i<10; i+=4){
        cout << "This: " << i << endl << "LOL: " << rand() % L << endl;
    }

    return 0;
}
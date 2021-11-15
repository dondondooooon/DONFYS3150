#include <iostream>
#include<armadillo>
#include<random>
using namespace arma;
using namespace std;

int main(){

    // int L = 6;
    // for (int i=0; i<10; i++){
    //     // srand(time(NULL)); // Seed Generate
    //     int x = arma::randu() * L;
    //     cout << "This: " << x << endl;
    // }

    // srand(time(NULL));
    // for (int i=0; i<10; i+=4){
    //     cout << "This: " << i << endl << "LOL: " << rand() % L << endl;
    // }

    const double range_from  = 0.;
    const double range_to    = 1.;//000000000000000;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<double>  distr(range_from, range_to);

    for (int i=0; i<20; i++){
        std::cout << distr(generator) << '\n';
        //double x = distr(generator) / 1000000000000000.;
        //cout << "This: " << x << endl;
    }

    // const int s = 31;
    // mt19937_64 mtrand(s);
    // for (int i=0; i<20; i++){
    //     cout << mtrand() << endl;
    // }


    return 0;
}
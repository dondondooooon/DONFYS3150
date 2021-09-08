#include <iostream>
#include<armadillo>

using namespace std;

int main()
{
    double Nnew = 10;
    for (int i = Nnew-1; i>0 ; i--){         
        cout << i << endl;     
    }
     
 return 0;
}

/*
arma::vec x = arma::linspace(1,20,10); // Creates an evenly linearly spaced vector with N elements
    double x_i = x(4); // Extracts a specific index in a vector
    cout<< x;
    cout<< x_i << endl;
    cout<< x.size() << endl;

    double s = 0;
    for (int i = 0; i <= 5; i++) {
    s += i;
    }
    cout << s << endl << endl;

    cout << exp(1) << endl;

    arma::mat A = arma::mat(10,2);
    A.col(1) = x;
    cout << A << endl;

    x = 0
    cout << 1-(1-exp(-10))*x-exp(-10*x);
*/

/*
//arma::vec xn 

//arma::vec y = arma::vec(xn.size()); // creates an empty vector with the same size as x vector

//arma::mat A = arma::mat(100,2);
    //A.col(0) = xn;
    //A.col(1) = y;
    // cout << A << endl; // check print
*/
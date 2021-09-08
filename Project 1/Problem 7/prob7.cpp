#include "head.hpp"

double u(double x);                         // Declaration of Equation 2 Function

int main(){
<<<<<<< HEAD

    //Makes a file.txt for the data points:
    string filename = "prob7.txt";  
    ofstream ofile;                         //Create and open the output file 
    ofile.open(filename);                   //Connect it to filename

=======
    /*
    //Makes a file.txt for the data points:
    //string filename = "prob2.txt";  
    //ofstream ofile;                         //Create and open the output file 
    //ofile.open(filename);                   //Connect it to filename
    */
>>>>>>> origin

    //Parameters for N 
    double N = 100;                          //Number of data points that will be used
    double Nnew = N-2;

    //Vectors for original function
<<<<<<< HEAD
    vec x = linspace(0,1,N);         // Creates N linearly spaced vector from start to end
    vec y = vec(N);                  // Initialize a vector for u(x) or y-values of size N
    vec g = vec(N);                  // (h^2*f_i) g vector
    vec b = vec(Nnew).fill(2.);      // Main-diagonal vector
    vec a = vec(Nnew).fill(-1.);     // Sub-diagonal vector
    vec c = vec(Nnew).fill(-1.);     // Super-diagonal vector
    vec bt = vec(Nnew);              // b-tilde vector
    vec gt = vec(Nnew);              // g-tilde vector
    vec vt = vec(Nnew);              // v-stjerne vector
    double h = x(1)-x(0);                        // Steps

    //Loop for u(x) or y-values and g-values
    for (int i=0; i < x.size(); i++){         // Loop through x vector indexes
        y(i) = u(x(i));                        // Run through function
        g(i) = pow(h,2)*y(i);                  // Fill in indexes in g-vector

=======
    arma::vec x = arma::linspace(0,1,N);       // Creates N linearly spaced vector from start to end
    arma::vec y = arma::vec(N);                // Initialize a vector for u(x) or y-values of size N
    arma::vec g = arma::vec(N);                  // (h^2*f_i) g vector
    arma::vec a = arma::vec(Nnew).fill(-1.);     // Sub-diagonal vector
    arma::vec b = arma::vec(Nnew).fill(2.);      // Main-diagonal vector
    arma::vec c = arma::vec(Nnew).fill(-1.);     // Super-diagonal vector
    arma::vec bt = arma::vec(Nnew);              // b-tilde vector
    arma::vec gt = arma::vec(Nnew);              // g-tilde vector
    arma::vec vt = arma::vec(Nnew);              // v-stjerne vector
    double h = x(1)-x(0);                      // Steps

    //Loop for u(x) or y-values and g-values
    for (int i=0; i < x.size() ; i++){         // Loop through x vector indexes
        y(i) = u(x(i));                        // Run through function
        g(i) = pow(h,2)*y(i);               // Fill in indexes in g-vector
>>>>>>> origin
    }

    //Initialization
    g(0) = g(0) + x(0);                        // g initial
<<<<<<< HEAD
    //g(N-1) = g(N-1) + x(N-1);                     // g end
=======
    g(-1) = g(-1) + x(-1);                     // g end
>>>>>>> origin
    bt(0) = b(0);                              // b-tilde initial
    gt(0) = g(0);                              // g-tilde end

    //Loop for b- and g-tilde vectors
    for (int i=1; i < Nnew ; i++){             // Loop through N-2 indexes starting from 1
        bt(i) = b(i) - (a(i)/bt(i-1))*c(i-1);  // b-tilde vector def
        gt(i) = g(i) - (a(i)/bt(i-1))*gt(i-1); // g-tilde vector def
    }

    //Initialization for vt
<<<<<<< HEAD
    vt(Nnew-1) = gt(Nnew-1)/bt(Nnew-1);
    
    //Loop for v-stjerne vector
    for (int i = Nnew-2; i >= 0 ; i--){         // Loop through N-2 indexes downwards starting from end index
        vt(i) = (gt(i)-c(i)*vt(i+1))/bt(i);    // b-tilde vector def
        
    }

    for (int i=0; i<Nnew; i++){
        ofile << setw(12) << setprecision(2) << scientific << x(i) << ",";
        ofile << setw(12) << setprecision(2) << scientific << vt(i) << endl;
    }

    cout << "it works til here?" << endl;
    cout << gt(7) << endl;
/*
    
=======
    vt(-1) = gt(-1)/bt(-1);

    //Loop for v-stjerne vector
    for (int i=Nnew-1; i < Nnew ; i--){         // Loop through N-2 indexes downwards starting from end index
        vt(i) = (gt(i)-c(i)*vt(i+1))/bt(i);     // b-tilde vector def
    }

    /*
>>>>>>> origin
    {
        //Saving the matrix into a data file
        //ofile << setw(12) << setprecision(2) << scientific << A(i,0) << ",";     //Upload x-values
        //ofile << setw(12) << setprecision(2) << scientific << A(i,1) << endl;     //Upload y-values
    }

    //ofile.close();  //Close output file
    */

<<<<<<< HEAD
    ofile.close(); 
=======
>>>>>>> origin
    return 0;
}

//Calculating the y-values
<<<<<<< HEAD
double u(double x){                                 // Takes in an float element x
        //return ( 1-(1-exp(-10))*x-exp(-10*x) );   //Calculates and spits out the solution using that value
=======
double u(double x){                             // Takes in an float element x
        //return ( 1-(1-exp(-10))*x-exp(-10*x) ); //Calculates and spits out the solution using that value
>>>>>>> origin
        return (100*exp(-10*x));
}

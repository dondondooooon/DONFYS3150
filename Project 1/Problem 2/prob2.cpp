#include "head.hpp"

double u(double x);                         // Declaration of Equation 2 Function

int main(){
    //Makes a file.txt for the data points:
    string filename = "prob2.txt";  
    ofstream ofile;                         //Create and open the output file 
    ofile.open(filename);                   //Connect it to filename

    //Parameters for matrix
    double N = 100;                          //Number of data points that will be used
    arma::mat A = arma::mat(N,2);           // Creates an Nx2 matrix
    A.col(0) = arma::linspace(0,1,N);       // Creates N linearly spaced vector from start to end
    arma::vec sz = A.col(0);                //Used to get the size of one column in the matrix
    
    //The Loop
    for (int i=0; i < sz.size() ; i++){     //Loop through x vector indexes
        A(i,1) = u(A(i,0));                 //Insert the function values into second column in matrix A

        //Saving the matrix into a data file
        ofile << setw(12) << setprecision(2) << scientific << A(i,0) << ",";     //Upload x-values
        ofile << setw(12) << setprecision(2) << scientific << A(i,1) << endl;     //Upload y-values
    }

    ofile.close();  //Close output file

    return 0;
}

//Calculating the y-values
double u(double x){                             // Takes in an float element x
        return ( 1-(1-exp(-10))*x-exp(-10*x) );    //Calculates and spits out the solution using that value
}

#include <iostream>
#include "utils.hpp"
#include "alg.hpp"

int main()
{
    vec n = linspace(2,10,9);

    //Makes a file.txt for the data points:
    string filename = "scaling.txt";  
    ofstream ofile;         //Create and open the output file 
    ofile.open(filename);   //Connect it to filename

    // Loop for N: 
    for (int i=0; i < 9; i++){
        //Initiazlization
        vec arma_eigval;
        mat arma_eigvec; 
        int k,l = 0.0;
        int iter = 0;
        double eps = 1.0e-8;
        bool converged {false};
        double N = double(n(i));
        double maxiter = N*N*N;
        vec anl_eigval = vec(N).fill(0.);
        mat anl_eigvec = mat(N,N).fill(0.);
        vec jaro_eigval = vec(N).fill(0.);
        mat jaro_eigvec = mat(N,N).fill(0.);
        // Sets up R_1 = I matrix
        mat R = mat(N,N,fill::eye);
        // Sets up tridiagonal matrix A for size N
        mat A = create_trimatsym(N);
        // Finds the max off-diagonal element for A
        double max = max_offdiag_symmetric(A,k,l);


        // // Oppgave 3
        // // Armadillo Eigen-solver
        //eig_sym(arma_eigval,arma_eigvec,A);
        // // Analytisk Eigen-solver
        // analytisk_eigen(N,anl_eigval,anl_eigvec);
        // // Normalize
        // anl_eigvec = normalise(anl_eigvec);
    

        // //Oppgave 4
        // //Test Matrix T
        // mat T = mat(4,4,fill::eye);
        // T(1,2) = -0.7;
        // T(2,1) = -0.7;
        // T(0,3) = 0.5;
        // T(3,0) = 0.5;
        // double max = max_offdiag_symmetric(T,k,l);
        // cout << "Matrix: " << endl << T << endl;
        // cout << "The maximum value of all off-diagaonal element is: "
        //     << max << endl;
        // cout << "The index for this maximum off-diagonal element is: "
        //     << k+1 << ".row and " << l+1 << ".column" << endl;


        // //Oppgave 5
        // cout << "Original Matrix: " << endl << A << endl;

        jacobi_eigen(A,R,N,k,l,max,eps,jaro_eigval,jaro_eigvec,
        maxiter,iter,converged);

        // cout << "Arma::Eigenvalues: " << endl << arma_eigval << endl;
        // cout << "Arma::Eigenvectors: " << endl << arma_eigvec << endl;
        // cout << "Analytical Eigenvalues: " << endl << anl_eigval << endl;
        // cout << "Analytical Eigenvectors: " << endl << anl_eigvec << endl;
        // cout << "Egenvalues via Jacobi: " << endl << jaro_eigval << endl;
        // cout << "Rotation Matrix/Egenvectors: " << endl << jaro_eigvec << endl;
        // cout << "Iterations: " << iter << endl;
        // if (converged == 1){
        //     cout << "We've converged enough :) (staaahp)" << endl;
        // }

        //Oppgave 6
        ofile << setw(12) << setprecision(3) << scientific << N;     // N values
        ofile << setw(12) << setprecision(3) << scientific << iter << endl;    // Iterations values
    }
    ofile.close();

    // Done
    return 0;
}
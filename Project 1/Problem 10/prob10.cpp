#include "head.hpp"

//Declaration of Functions
double u(double x);                                 // Analytical Exact Function 
double f(double x);                                 // Original 2nd order derivative function
// Vis hensyn på man øker 10-faktor i tid også... ta log10(tid)(?) i think
int main(){

    // Start measuring time
    auto t1 = chrono::high_resolution_clock::now();

    for(int i = 1; i < 8; i++){                     //Iterate N from 1 to 10^7 

        int N = pow(10,i);                          //Number of data points that will be used
        double Nnew = N-2;                          //Length minus the two boundary points 

        //Makes a file.txt for the data points:
        string filename = "prob8" + to_string(N) + ".txt";  
        ofstream ofile;                             //Create and open the output file 
        ofile.open(filename);                       //Connect it to filename                     
    
        //Initialize vectors
        vec x = linspace(0,1,N);                    // Creates N linearly spaced vector from start to end
        vec y = vec(N);                             // Initialize a vector for y-values of size N
        vec ux = vec(N);                            // Initialize a vector for u(x) of size N
        vec g = vec(N);                             // g vector
        vec b = vec(Nnew).fill(2.);                 // Main-diagonal vector
        vec a = vec(Nnew).fill(-1.);                // Sub-diagonal vector
        vec c = vec(Nnew).fill(-1.);                // Super-diagonal vector
        vec bt = vec(Nnew);                         // b-tilde vector
        vec gt = vec(Nnew);                         // g-tilde vector
        vec vt = vec(N);                            // v-stjerne vector (The last two indexes for this vector will be empty)
        double h = x(1)-x(0);                       // h-Steps

        //Loop for y-values and g-values
        for (int i=0; i < x.size(); i++){           // Loop through x vector indexes
            y(i) = f(x(i));                         // Fill in equation 1
            ux(i) = u(x(i));                         // Fill in equation 2
            g(i) = pow(h,2)*y(i);                   // Fill in indexes in g-vector (h^2*f_i)
        }

        //Initialze Boundaries
        g(0) = g(0) + ux(0);                        // g initial
        g(N-1) = g(N-1) + ux(N-1);                  // g end
        bt(0) = b(0);                               // b-tilde initial
        gt(0) = g(0);                               // g-tilde initial

        //Loop for b- and g-tilde vectors
        for (int i=1; i < Nnew ; i++){              // Loop through N-2 indexes starting from 1
            bt(i) = b(i) - (a(i)/bt(i-1))*c(i-1);   // b-tilde vector def
            gt(i) = g(i) - (a(i)/bt(i-1))*gt(i-1);  // g-tilde vector def
        }

        //Initialize end element for v-tilde vector
        vt(Nnew-1) = gt(Nnew-1)/bt(Nnew-1);
    
        //Loop for v-stjerne vector
        for (int i = Nnew-2; i >= 0 ; i--){         // Loop through N-2 indexes downwards starting from end index
            vt(i) = (gt(i)-c(i)*vt(i+1))/bt(i);     // v-stjerne vector def
        }

        //Shift v-stjerne elements to the right	
        double endbound = vt(N-1);	
	    for (int i = N-1; i > 0; i--){	
	    	vt(i) = vt(i-1);
        }		
	    vt[0] = endbound;
    
        // Writing them into the file
        for (int i=0; i<x.size(); i++){
            ofile << setw(23) << setprecision(15) << scientific << x(i);     // x-values
            ofile << setw(23) << setprecision(15) << scientific << vt(i);    // approx values
            ofile << setw(23) << setprecision(15) << scientific << ux(i) << endl; // exact values
        }

        ofile.close();                              // Close file
    }   
    
    // Stop measuring time
    auto t2 = std::chrono::high_resolution_clock::now();
    // Calculate elapsed time
    double duration_seconds = chrono::duration<double>(t2 - t1).count();
    // Ferdig
    cout << "Done!" << endl;
    return 0;
}

//Function for calculating the y-values
double f(double x){                                 // Takes in input x-element/index
    return (100*exp(-10*x));                        // From equation 1
}

//Function for calculating u(x)
double u(double x){                                 // Takes in input x-element/index
    return ( 1-(1-exp(-10))*x-exp(-10*x) );         // From equation 2
}
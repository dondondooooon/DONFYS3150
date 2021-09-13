#include "head.hpp"

//Declaration of Functions
double u(double x);                   // Analytical Exact Function 
double f(double x);                   // Original 2nd order derivative function

int main(){

for (int j=1; j<11; j++){           // Iterate 10 for reliable results
// Makes a .txt file for time measurements
string filename = to_string(j) +"_timedata.txt";
ofstream ofile;
ofile.open(filename);
    for(int i = 1; i < 7; i++){         //Iterate N from 1 to 10^6 

        int N = pow(10,i);              //Number of data points that will be used
        double Nnew = N-2;              //Length minus the two boundary points                  
        vec x = linspace(0,1,N);        // Creates N linearly spaced vector from start to end
        vec y = vec(N);                 // Initialize a vector for y-values of size N
        vec ux = vec(N);                // Initialize a vector for u(x) of size N
        vec g = vec(N);                 // g vector
        vec bt = vec(Nnew);             // b-tilde vector
        vec gt = vec(Nnew);             // g-tilde vector
        vec vt = vec(N);                // v-stjerne vector 
        vec bt2 = vec(Nnew);             // b-tilde vector
        vec gt2 = vec(Nnew);             // g-tilde vector
        vec vt2 = vec(N);                // v-stjerne vector
        double h = x(1)-x(0);           // h-Steps
        //Loop for y-values, ux-values and g-values
        for (int i=0; i < x.size(); i++){   // Loop for y-values and g-values
            y(i) = f(x(i));                 // Fill in equation 1
            ux(i) = u(x(i));                // Fill in equation 2
            g(i) = pow(h,2)*y(i);           // Fill in indexes in g-vector (h^2*f_i)
        }
        //Initialze Boundaries
        gt(0) = g(0);                    // g-tilde initial
        gt2(0) = g(0);                   // -"-
        g(0) = g(0) + ux(0);             // g initial
        g(N-1) = g(N-1) + ux(N-1);       // g end

        // Start measuring time for GENERAL
        auto gen_t1 = chrono::high_resolution_clock::now();
        //Initialize vectors
        vec b = vec(Nnew).fill(2.);     // Main-diagonal vector
        vec a = vec(Nnew).fill(-1.);    // Sub-diagonal vector
        vec c = vec(Nnew).fill(-1.);    // Super-diagonal vector
        bt(0) = b(0);                   // b-tilde initial
        
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
        // Stop measuring time for general
        auto gen_t2 = std::chrono::high_resolution_clock::now();


        // Start measuring time for SPECIAL
        auto sps_t1 = chrono::high_resolution_clock::now();
        bt2(0) = 2.;                                 // b-tilde initial
        
        //Loop for b- and g-tilde vectors
        for (int i=1; i < Nnew ; i++){                 // Loop through N-2 indexes starting from 1
            bt2(i) = (double(i)+1)/double(i);          // b-tilde vector def
            gt2(i) = g(i) + (1/bt2(i-1))*gt2(i-1);     // g-tilde vector def
        }
        //Initialize end element for v-stjerne vector
        vt2(Nnew-1) = gt2(Nnew-1)/bt2(Nnew-1);
        //Loop for v-stjerne vector
        for (int i = Nnew-2; i >= 0 ; i--){         // Loop through N-2 indexes downwards starting from end index
            vt2(i) = (gt2(i)+vt2(i+1))/bt2(i);      // v-stjerne vector def
        }
        // Stop measuring time for special
        auto sps_t2 = std::chrono::high_resolution_clock::now();

        // Calculate elapsed time
        double duration_seconds1 = chrono::duration<double>(gen_t2 - gen_t1).count();
        double duration_seconds2 = chrono::duration<double>(sps_t2 - sps_t1).count();
        // Write time results into file
        ofile << setw(15) << setprecision(5) << duration_seconds1;         // time taken for gen.
        ofile << setw(15) << setprecision(5) << duration_seconds2 << endl; // time taken for spes.
    }   
ofile.close();                              // Close file
}
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
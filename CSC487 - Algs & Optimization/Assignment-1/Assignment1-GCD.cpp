#include "dynamic_array.h"
#include <time.h>
#include <math.h>
//Logan Sill
//Student ID: 101065203


long Session1alg(long m,  long n){
    long gcd;
    dynamic_array arr1,arr2;   
    for(long walker = 1; walker < m; walker++){
        if( m % walker == 0 ){
            arr1.push(walker);
        }
    }
    for(long walker = 1; walker < n; walker++){
        if ( n % walker == 0){
            arr2.push(walker);
        }
    }
    for (long i = 0; i < arr1.length; i++){
        for (long j = 0; j < arr2.length; j++){
            if (arr1[i] == arr2[j]){
                gcd = arr1[i];
            }
        }
    }
    return gcd;
}

long EuclidRecursive(long m,  long n){
    if (n == 0){
        return m;    
    }else{
        return EuclidRecursive(n, m % n);
    }

}


long EuclidLoop(long m,  long n){
    long r;
    while(n != 0){
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}


long CICA(long m,  long n){
    long t = min(m,n);
    bool stop = false;
    while (stop == false){
        if (m % t == 0 && n % t == 0){
            stop = true;
        }else{
            t-=1;
        }
    }
    return t;
}

int main(){
    time_t ts,te;
    double rt;
    long m, n;
    //read m,n;
    cin >> m >> n;
    //check m,n;
    if (m < 0 || n < 0 || m == 0 && n == 0)
        cout << "Wrong input. m and n must be both non negative not both equal to zero" << endl;
    else{
        time(&ts);
        cout << "gcd(" << m << ", " << n << ") = " << Session1alg(m,n) << endl;
        time(&te);
        rt = double(te - ts); 
        cout << "The time taken by Session1alg is " << rt << endl;
        
        time(&ts);
        cout << "gcd(" << m << ", " << n << ") = " << EuclidRecursive(m,n) << endl;
        time(&te);
        rt = double(te - ts); 
        cout << "The time taken by EuclidRecursive is " << rt << endl;

        time(&ts);
        cout << "gcd(" << m << ", " << n << ") = " << EuclidLoop(m,n) << endl;
        time(&te);
        rt = double(te - ts); 
        cout << "The time taken by EuclidLoop is " << rt << endl;

        time(&ts);
        cout << "gcd(" << m << ", " << n << ") = " << CICA(m,n) << endl;
        time(&te);
        rt = double(te - ts); 
        cout << "The time taken by CICA is " << rt << endl;
    }
    
    return 0;
}
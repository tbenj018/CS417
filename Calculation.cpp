#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

#include "calculation.h"

inline static float sqr(float x) {
    return x*x;
}

//*************************************************************************************************

double Calculation::interpolate( ){
    std::vector<double> &xData;
    std::vector<double> &yData;
    double x;
    bool extrapolate;
    int size = xData.size();

    int i = 0;
    if ( x >= xData[size - 2] ){
      i = size - 2;
    }
    else{
      while ( x > xData[i+1] ) i++;
    }
    double xL = xData[i], yL = yData[i], xR = xData[i+1], yR = yData[i+1];
    if ( !extrapolate ){
      if ( x < xL ) yR = yL;
      if ( x > xR ) yL = yR;
    }
    double dydx = ( yR - yL ) / ( xR - xL );
    return yL + dydx * ( x - xL );

    double m,b,r;
    linreg(n,x,y,&m,&b,&r);
    printf("m=%g b=%g r=%g\n",m,b,r);
    return 0;
}

//*************************************************************************************************


double Calculation::leastSquares(){
    int n;
    const double x[];
    const double y[];
    double* m;
    double* b;
    double* r
    double sumx = 0.0;                      /* sum of x     */
    double sumx2 = 0.0;                     /* sum of x**2  */
    double sumxy = 0.0;                     /* sum of x * y */
    double sumy = 0.0;                      /* sum of y     */
    double sumy2 = 0.0;                     /* sum of y**2  */

    for (int i=0;i<n;i++){
        sumx  += x[i];
        sumx2 += sqr(x[i]);
        sumxy += x[i] * y[i];
        sumy  += y[i];
        sumy2 += sqr(y[i]);
    }

    REAL denom = (n * sumx2 - sqr(sumx));
    if (denom == 0) {
        // singular matrix. can't solve the problem.
        *m = 0;
        *b = 0;
        if (r) *r = 0;
            return 1;
    }

    *m = (n * sumxy  -  sumx * sumy) / denom;
    *b = (sumy * sumx2  -  sumx * sumxy) / denom;
    if (r!=NULL) {
        *r = (sumxy - sumx * sumy / n) /    /* compute correlation coeff */
              sqr((sumx2 - sqr(sumx)/n) *
              (sumy2 - sqr(sumy)/n));
    }

    return 0;
}

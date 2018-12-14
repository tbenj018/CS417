#ifndef __CALCULATION_H__
#define __CALCULATION_H__

#include <iostream>
#include <vector>
#include <cmath>

class Calculation
{
public:

  Calculation() : x_Points(0.0), y_Points(0.0){}
  double GetX_Points() const;
  double GetY_Points() const;
  double interpolate( vector<double> &xData, vector<double> &yData, double x, bool extrapolate );
  double leastSquares(int n, const float x[], const float y[], float* m, float* b, float* r);

  friend std::istream& operator>>(std::istream& is, points& p);
  friend inline static REAL sqr(REAL x);

};

std::istream& operator>>(std::istream& is, Calculation& p)
{
	is >> p.x_Points >> p.y_Points;
	return is;
}

inline static REAL sqr(REAL x) {
    return x*x;
}

#endif // __CALCULATION_H__

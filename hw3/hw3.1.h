#if !defined HW_3_1_H
#define HW_3_1_H
#include <complex>
#include <cmath>



class Derivable
{
public:
  virtual std::complex<double> eval(const std::complex<double> coord) const = 0;
};

double firstDerivative(Derivable&, const double where);
#endif

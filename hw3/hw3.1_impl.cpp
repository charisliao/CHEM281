#include "hw3.1.h"
#include "MyCosine.h"
#include "MyPotential.h"
#include <cmath>

std::complex<double> MyPotential::eval(const std::complex<double> r) const
{
  /* implement */
  return 1.0/pow(r, 2.0) - 1.0/pow(r, 6.0);
}

std::complex<double> MyCosine::eval(const std::complex<double> r) const
{
  /* implement */
  return cos(r);
}


/********************************/
#include <stdio.h>
#include <float.h>
#include <hw3.1.h>


double firstDerivative(Derivable& d, const double r)
{
  /* implement */
  
  // //estimate stepsize h 
  double h = sqrt(DBL_EPSILON);
  // Classical Approach (Central Difference)
  double dfdr_classical = (d.eval(r + h).real() - d.eval(r).real()) / h;

  // Complex Step Approach
  std::complex<double> dfdr_complex = imag(d.eval(r + h * std::complex<double>(0, 1))) / h;

  return std::real(dfdr_complex);


}

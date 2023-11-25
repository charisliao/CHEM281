#if !defined MYPOTENTIAL_H
#define MYPOTENTIAL_H
#include <hw3.1.h>
// #pragma once
class MyPotential : public Derivable {
  public:
    virtual std::complex<double> eval(const std::complex<double> coord) const;
};

#endif

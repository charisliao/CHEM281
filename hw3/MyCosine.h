#if !defined MYCOSINE_H
#define MYCOSINE_H
#include <hw3.1.h>


//create my cosine class that inherits from derivable
class MyCosine : public Derivable {
  public:
    virtual std::complex<double> eval(const std::complex<double> coord) const;
};

#endif

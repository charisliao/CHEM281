/**
 * @file problem4a.cpp
 * @author Charis Liao (charisliao@berkeley.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <math.h>

using namespace std;



double func(const double x) {
    return sqrt(1 - pow(sqrt(2) / 2, 2) * pow(sin(x), 2));
}

// 
double evalfunc(const double stepsize, const unsigned int step) {
    return func(step * stepsize);
}

double trinteg(const unsigned int stepsize, const unsigned int nsteps) {
    double sum = 0.0;
    for (int i = 0; i < nsteps; i++) {
        sum += evalfunc(stepsize, i);
    }
    
    return (sum * stepsize - 0.5 * (evalfunc(stepsize, 0) + evalfunc(stepsize, nsteps - 1)) * stepsize) * sqrt(2);
}


int main(int argc, char* argv[])
{
  const unsigned int default_nsteps = 1000000;
  unsigned int nsteps_param = 0;
  
  
  for (unsigned int k=1; k<argc; )
    {
    if (strcmp(argv[k], "--steps") == 0)
      {
      if (argc<k+2)
	{
        printf("error: --steps has to be followed by a number\n");
	exit(1);
	}
      else
        {
	nsteps_param = atoi(argv[k+1]);
        }
      k+=2;
      continue;
      }
    if (strcmp(argv[k], "--threads") == 0)
      {
      if (argc<k+2)
	{
        printf("error: --threads has to be followed by a number\n");
	exit(1);
	}
    
      k+=2;
      continue;
      }
    {
    printf("error: %s unrecognized keyword\n", argv[k]);
    exit(1);
    }
    }
  std::cout.precision(std::numeric_limits<double>::max_digits10-1);
  // call cei to get the reference value


  double lower_limit = 0.e+00;
  double upper_limit = M_PI/2.e+00;

  const unsigned int nsteps = nsteps_param ? nsteps_param : default_nsteps;

  double step_size = (upper_limit-lower_limit)/(nsteps-1);
  auto start = std::chrono::high_resolution_clock::now();
  double intval = trinteg(step_size, nsteps);
  auto end = std::chrono::high_resolution_clock::now();
  const std::chrono::duration<double> elapsed_seconds{end - start};
  cout << "Integration uses " << nsteps << " steps" << endl;
  cout << "integ: " << intval << endl;
    cout << "time: " << elapsed_seconds.count() << "s" << endl;


  cout<<endl;
  cout<< "Observation: The integ result is 0 because of the 'const unsigned int' I was required to use." << endl;
  cout << "Since I think the purpose of assigning specific datatypes for the variables is to teach us a leason of the importance of datatype," << endl;
  cout << "I decided to keep the 'const unsigned int'." << endl;
  return 0;
}

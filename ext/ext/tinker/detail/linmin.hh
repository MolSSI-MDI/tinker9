#ifndef TINKER_MOD_LINMIN_HH_
#define TINKER_MOD_LINMIN_HH_

#include "util/macro.h"

TINKER_NAMESPACE_BEGIN namespace linmin {
extern int& intmax;
extern double& stpmin;
extern double& stpmax;
extern double& cappa;
extern double& slpmax;
extern double& angmax;

#ifdef TINKER_MOD_CPP_
extern "C" int TINKER_MOD(linmin, intmax);
extern "C" double TINKER_MOD(linmin, stpmin);
extern "C" double TINKER_MOD(linmin, stpmax);
extern "C" double TINKER_MOD(linmin, cappa);
extern "C" double TINKER_MOD(linmin, slpmax);
extern "C" double TINKER_MOD(linmin, angmax);

int& intmax = TINKER_MOD(linmin, intmax);
double& stpmin = TINKER_MOD(linmin, stpmin);
double& stpmax = TINKER_MOD(linmin, stpmax);
double& cappa = TINKER_MOD(linmin, cappa);
double& slpmax = TINKER_MOD(linmin, slpmax);
double& angmax = TINKER_MOD(linmin, angmax);
#endif
} TINKER_NAMESPACE_END

#endif

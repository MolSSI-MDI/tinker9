#include "ff/hippo/empole.h"
#include "ff/nblist.h"
#include "tool/externfunc.h"

namespace tinker {
TINKER_FVOID2(cu, 1, acc, 1, empoleAplusEwaldRealSelf, int, int);
static void empoleAplusEwaldRealSelf(int vers, int useCF)
{
   TINKER_FCALL2(cu, 1, acc, 1, empoleAplusEwaldRealSelf, vers, useCF);
}

static void empoleAplusEwaldRecip(int vers, int useCF)
{
   empoleChgpenEwaldRecip(vers, useCF);
}

void empoleAplusEwald(int vers, int useCF)
{
   empoleAplusEwaldRealSelf(vers, useCF);
   empoleAplusEwaldRecip(vers, useCF);
}
}

namespace tinker {
TINKER_FVOID2(cu, 1, acc, 1, empoleAplusNonEwald, int, int);
void empoleAplusNonEwald(int vers, int useCF)
{
   TINKER_FCALL2(cu, 1, acc, 1, empoleAplusNonEwald, vers, useCF);
}
}

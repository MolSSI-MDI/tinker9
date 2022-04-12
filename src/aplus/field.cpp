#include "ff/elec.h"
#include "ff/hippo/induce.h"
#include "ff/nblist.h"
#include "tool/externfunc.h"

namespace tinker {
TINKER_FVOID2(cu, 0, acc, 1, dfieldEwaldRecipSelf, real (*)[3]);
static void dfieldAplusEwaldRecipSelf(real (*field)[3])
{
   TINKER_FCALL2(cu, 0, acc, 1, dfieldEwaldRecipSelf, field);
}

TINKER_FVOID2(cu, 1, acc, 1, dfieldAplusEwaldReal, real (*)[3]);
static void dfieldAplusEwaldReal(real (*field)[3])
{
   TINKER_FCALL2(cu, 1, acc, 1, dfieldAplusEwaldReal, field);
}

static void dfieldAplusEwald(real (*field)[3])
{
   dfieldAplusEwaldRecipSelf(field);
   dfieldAplusEwaldReal(field);
}
}

namespace tinker {
TINKER_FVOID2(cu, 1, acc, 1, dfieldAplusNonEwald, real (*)[3]);
static void dfieldAplusNonEwald(real (*field)[3])
{
   TINKER_FCALL2(cu, 1, acc, 1, dfieldAplusNonEwald, field);
}

void dfieldAplus(real (*field)[3])
{
   if (useEwald())
      dfieldAplusEwald(field);
   else
      dfieldAplusNonEwald(field);
}
}

namespace tinker {
static void ufieldAplusEwaldRecipSelf(const real (*uind)[3], real (*field)[3])
{
   ufieldChgpenEwaldRecipSelf(uind, field);
}

TINKER_FVOID2(cu, 1, acc, 1, ufieldAplusEwaldReal, const real (*)[3], real (*)[3]);
static void ufieldAplusEwaldReal(const real (*uind)[3], real (*field)[3])
{
   TINKER_FCALL2(cu, 1, acc, 1, ufieldAplusEwaldReal, uind, field);
}

static void ufieldAplusEwald(const real (*uind)[3], real (*field)[3])
{
   ufieldAplusEwaldRecipSelf(uind, field);
   ufieldAplusEwaldReal(uind, field);
}
}

namespace tinker {
TINKER_FVOID2(cu, 1, acc, 1, ufieldAplusNonEwald, const real (*)[3], real (*)[3]);
static void ufieldAplusNonEwald(const real (*uind)[3], real (*field)[3])
{
   TINKER_FCALL2(cu, 1, acc, 1, ufieldAplusNonEwald, uind, field);
}

void ufieldAplus(const real (*uind)[3], real (*field)[3])
{
   if (useEwald())
      ufieldAplusEwald(uind, field);
   else
      ufieldAplusNonEwald(uind, field);
}
}

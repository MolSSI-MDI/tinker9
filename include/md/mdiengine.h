#pragma once
#include "tool/error.h"
#include "tool/ioprint.h"
#include "ff/precision.h"
#include <tinker/detail/inform.hh>
#include <tinker/detail/mdstuf.hh>
#include <tinker/detail/units.hh>
#include "mdi.h"

namespace tinker {

class MDIEngine
{
protected:
   // MDI communicator with the driver
   static MDI_Comm mdi_comm;
   static int nrespa_mdi;
public:
   static void initialize(int* argc_ptr, char*** argv_ptr);
   static void update_nsteps(int istep, int* nsteps);
   static void set_nrespa(int nrespa);
   static void run_mdi(int node_id);

   // node id's
   static int next_node_id;
   static int default_node_id;
   static int initmd_node_id;
   static int forces_node_id;
   static int coords_node_id;

   // ID of the node that MDI is currently supposed to reach
   static int target_node_id;

   // flag to stop listening at the current MDI node
   static bool terminate_node;

   // flag to terminate execution of MDI
   static bool exit_mdi;

   // temporary function for MDI testing purposes
   template <class F, class... Ts>
   static void mdiprint(const F& f, Ts&&... args){
       print(stdout, f, args...);
   };

   // converts a fixed-point value \c g to floating-point value on host.
   template <class F>
   static inline fixed toFixedPoint(F f);
};

}

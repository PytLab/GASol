/*! \file  mpih.h
 *  \brief Common MPI header wrapper for serial or parallel builds.
 */


#ifndef __MPIH__
#define __MPIH__


// NOTE: The RUNMPI flag is set from CMake. It is defined in the
//       CMake generated file mpiflag.h
#include "mpiflag.h"


#if RUNMPI == true
#include <mpi.h>
#else
// Redefine namespace of MPI.
namespace MPI
{
    typedef int Intracomm;
    static int COMM_WORLD;
}
#endif // RUNMPI

#endif // __MPIH__


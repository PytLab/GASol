/*! \file  mpiutils.cpp
 *  \brief File for the implementation code of the common MPI routines.
 */


#include "mpiutils.h"
#include <vector>

namespace gasol {

// -----------------------------------------------------------------------------
//
void MPIUtils::init()
{
   if (initialized())
    {
        return;
    }

#if RUNMPI == true
    MPI::Init();
#endif
}


// -----------------------------------------------------------------------------
//
bool MPIUtils::finalized()
{
#if RUNMPI == true
    return MPI::Is_finalized();
#else
    return false;
#endif
}


// -----------------------------------------------------------------------------
//
bool MPIUtils::initialized()
{
#if RUNMPI == true
    return MPI::Is_initialized();
#else
    return false;
#endif
}


// -----------------------------------------------------------------------------
//
void MPIUtils::finalize()
{
    if (finalized())
    {
        return;
    }

#if RUNMPI == true
    MPI::Finalize();
#endif
}


// -----------------------------------------------------------------------------
//
int MPIUtils::myRank(MPI::Intracomm & comm)
{
#if RUNMPI == true
    return comm.Get_rank();
#else
    return comm = 0;
#endif
}


// -----------------------------------------------------------------------------
//
int MPIUtils::size(MPI::Intracomm & comm)
{
#if RUNMPI == true
    return comm.Get_size();
#else
    return comm = 1;
#endif
}


// -----------------------------------------------------------------------------
//
void MPIUtils::barrier(MPI::Intracomm & comm)
{
#if RUNMPI == true
    MPI_Barrier(comm);
#else
    comm = 0;
#endif
}


// -----------------------------------------------------------------------------
//
std::pair<int, int> MPIUtils::splitSize(int n, MPI::Intracomm & comm)
{
    int start = 0, end = n;

#if RUNMPI == true
    int nprocs = size(comm);
    int rank = myRank(comm);
    int residual = n % nprocs;
    std::vector<int> chunk_sizes(nprocs, n/nprocs);

    for (int i = 0; i < residual; i++)
    {
        chunk_sizes[i] += 1;
    }

    for (int i = 0; i < rank; i++)
    {
        start += chunk_sizes[i];
    }
    end = start + chunk_sizes[rank];
#else
    comm = 0;
#endif

    return std::pair<int, int>(start, end);
}

}


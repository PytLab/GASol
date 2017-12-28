/*! \file  mpiutils.h
 *  \brief Intrerfaces of the common MPI routines.
 */


#ifndef __MPIUTILS__
#define __MPIUTILS__

#include "mpih.h"

#include <utility>

namespace gasol {
/// Struct for handling MPI functions to be wrapped.
struct MPIUtils {

    /*! \brief Wrapps MPI_INIT
     */
    static void init();

    /*! \brief Wrap MPI::Is_initialized
     */
    static bool initialized();

    /*! \brief Wrapps MPI_FINALIZE
     */
    static void finalize();

    /*! \brief Wrap MPI::Is_finialized
     */
    static bool finalized();

    /*! \brief Wrapps MPI_COMM_RANK
     *  \param comm: The communicator to use.
     *  \return: The rank of this process withing the given communicator.
     */
    static int myRank(const MPI::Intracomm & comm=MPI::COMM_WORLD);

    /*! \brief Wrapps MPI_COMM_SIZE
     *  \param comm: The communicator to use.
     *  \return: The sise of the communicator (the total number of processes).
     */
    static int size(const MPI::Intracomm & comm=MPI::COMM_WORLD);

    /*! \brief Wrapps MPI_BARRIER, syncronizing processes.
     *  \param comm: The communicator to use.
     */
    static void barrier(const MPI::Intracomm & comm=MPI::COMM_WORLD);

    /*! \brief Returns true if the calling process is the master.
     */
    static bool isMaster(const MPI::Intracomm & comm=MPI::COMM_WORLD)
    { return (myRank(comm) == 0); }

    /*! \brief Split a size to different chunks.
     */
    static std::pair<int, int> splitSize(int size, const MPI::Intracomm & comm=MPI::COMM_WORLD);

};

};

#endif // __MPIUTILS__


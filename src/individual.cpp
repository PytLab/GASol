/*! \file individual.cpp
 *  \brief File for implementations of GAIndividual class.
 */

#include "individual.h"

namespace gasol {
    //--------------------------------------------------------------------------
    //
    Individual::Individual(std::vector<double> & solution_candidate,
                           const std::vector<std::pair<double, double>> & ranges,
                           const std::vector<double> & precisions) :
        solution_candidate_(solution_candidate),
        ranges_(ranges),
        precisions_(precisions)
    {}

    //--------------------------------------------------------------------------
    //
    Individual::Individual(std::vector<double> & solution_candidate,
                           const std::pair<double, double> & range,
                           const double precision) :
        solution_candidate_(solution_candidate),
        ranges_(solution_candidate.size(), range),
        precisions_(solution_candidate.size(), precision)
    {}
}


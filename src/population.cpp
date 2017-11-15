/*! \file population.cpp
 *  \brief File for implementation of Population class.
 */

#include "population.h"
#include "individual.h"

namespace gasol {

    //--------------------------------------------------------------------------
    //
    Population::Population(const std::vector<Individual> & individuals) :
        indvs_(individuals),
        size_(indvs_.size())
    {
        // Initialize individual pointers.
        for (auto & indv: indvs_)
        {
            indv_ptrs_.push_back(&indv);
        }
    }

}  // namespace gasol


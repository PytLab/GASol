/*! \file population.cpp
 *  \brief File for implementation of Population class.
 */

#include "population.h"
#include "individual.h"

#include <algorithm>

namespace gasol {

    //--------------------------------------------------------------------------
    //
    Population::Population(const std::vector<Individual> & individuals, Fitness *pfit) :
        indvs_(individuals),
        pfit_(pfit),
        size_(indvs_.size())
    {
        // Initialize individual pointers.
        for (auto & indv: indvs_)
        {
            indv_ptrs_.push_back(&indv);
        }
    }

    //--------------------------------------------------------------------------
    //
    const Individual & Population::bestIndv()
    {
        if (best_indv_ == nullptr)
        {
            // Comparation function.
            auto comp = [this](Individual *indv_ptr1, Individual *indv_ptr2)
                        { return (*pfit_)(*indv_ptr1) < (*pfit_)(*indv_ptr2); };

            best_indv_ = *std::max_element(indv_ptrs_.begin(),
                                           indv_ptrs_.end(),
                                           comp);
        }

        return *best_indv_;
    }

    //--------------------------------------------------------------------------
    //
    std::vector<double> Population::allFitVals() const
    {
        std::vector<double> all_fits;

        for (auto indv_it = indvs_.begin(); indv_it != indvs_.end(); indv_it++)
        {
            all_fits.push_back((*pfit_)(*indv_it));
        }

        return all_fits;
    }

}  // namespace gasol


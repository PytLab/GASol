/*! \file population.cpp
 *  \brief File for implementation of Population class.
 */

#include "population.h"
#include "individual.h"

#include <algorithm>
#include <utility>

namespace gasol {

    //--------------------------------------------------------------------------
    //
    Population::Population(std::vector<Individual> & individuals, Fitness *pfit) :
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
    void Population::updateIndividuals(const std::vector<Individual> & indvs)
    {
        auto it1 = indvs_.begin();
        auto it2 = indvs.begin();
        for ( ; it1 != indvs_.cend(); it1++, it2++)
        {
            *it1 = *it2;
        }
    }

    //--------------------------------------------------------------------------
    //
    const Individual & Population::bestIndv()
    {
        if (best_indv_ == nullptr)
        {
            // comparation function.
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
    const Individual & Population::worstIndv()
    {
        if (worst_indv_ == nullptr)
        {
            // Comparation function.
            auto comp = [this](Individual *indv_ptr1, Individual *indv_ptr2)
                        { return (*pfit_)(*indv_ptr1) < (*pfit_)(*indv_ptr2); };

            worst_indv_ = *std::min_element(indv_ptrs_.begin(),
                                            indv_ptrs_.end(),
                                            comp);
        }

        return *worst_indv_;
    }

    //--------------------------------------------------------------------------
    //
    std::vector<double> Population::allFitVals() const
    {
        std::vector<double> all_fits;

        for (auto it = indv_ptrs_.begin(); it != indv_ptrs_.end(); it++)
        {
            all_fits.push_back((*pfit_)(**it));
        }

        return all_fits;
    }

}  // namespace gasol


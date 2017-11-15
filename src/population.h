/*! \file  population.h
 *  \brief File for Population class definition.
 */

#ifndef __POPULATION__
#define __POPULATION__


#include <vector>

namespace gasol {

    // Forward declaration.
    class Individual;

    /*! \brief Class for population iterated in genetic algorithm engine.
     */
    class Population {

    public:
        /*! \brief Constructor for population with multiple individuals.
         */
        Population(const std::vector<Individual> & individuals);

        /*! \brief Query function for population size.
         */
        int size() const { return size_; }

        /*! \brief Const query function for individual pointers.
         */
        const std::vector<Individual *> & indvPtrs() const { return indv_ptrs_; }

        /*! \brief Query function for individual pointers.
         */
        std::vector<Individual *> & indvPtrs() { return indv_ptrs_; }

    private:

        /// Individuals in population.
        std::vector<Individual> indvs_;

        /// Pointers pointing to all individuals.
        std::vector<Individual *> indv_ptrs_;

        /// Population size.
        size_t size_;
    };
}

#endif  // __POPULATION__


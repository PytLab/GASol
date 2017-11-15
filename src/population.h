/*! \file  population.h
 *  \brief File for Population class definition.
 */

#ifndef __POPULATION__
#define __POPULATION__


#include <vector>

namespace gasol {

    // Forward declaration.
    class Individual;

    // Type alias of a fitness function.
    using Fitness = double (Individual &);

    /*! \brief Class for population iterated in genetic algorithm engine.
     */
    class Population {

    public:
        /*! \brief Constructor for population with multiple individuals.
         */
        Population(const std::vector<Individual> & individuals, Fitness *pfit);

        /*! \brief Return reference of the individual with max fitness value.
         */
        const Individual & bestIndv() const;

        /*! \brief Query function for population size.
         */
        int size() const { return size_; }

        /*! \brief Query function for fitness function.
         */
        Fitness *fitness() const { return pfit_; }

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

        /// Fitness function pointer.
        Fitness *pfit_ = nullptr;

        /// Population size.
        size_t size_;

        /// Pointer of best individual.
        const Individual *best_indv_ = nullptr;
    };
}

#endif  // __POPULATION__


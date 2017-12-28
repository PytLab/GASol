/*! \file engine.cpp
 *  \brief Implementations for genetic algorithm engine.
 */

#include "mpiutils.h"
#include "engine.h"

namespace gasol {

    //--------------------------------------------------------------------------
    //
    void Engine::run(int ng)
    {
        // Individuals collector in genetic algorithm generation.
        std::vector<Individual> individuals(population_.size(), population_.indvs()[0]);

        for (int g = 0; g < ng; g++)
        {
            int start = 0, end = population_.size()/2;
            #pragma omp parallel for schedule(static)
            for (int idx = start; idx < end; idx++)
            {
                // Indices for individuals in new individual list.
                int i = 2*idx, j = 2*idx + 1;

                // Select father and mother.
                Parents parents = selection_.select(population_);

                // Crossover.
                std::pair<Individual, Individual> && children = crossover_.cross(parents);

                // Mutation.
                mutation_.mutate(children.first);
                mutation_.mutate(children.second);

                // Add to individuals.
                individuals[i] = children.first;
                individuals[j] = children.second;
            }

            // Reserve the best indv.
            individuals[0] = population_.bestIndv();

            // Update population.
            population_.updateIndividuals(individuals);
        }
    }
}


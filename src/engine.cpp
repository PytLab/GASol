/*! \file engine.cpp
 *  \brief Implementations for genetic algorithm engine.
 */

#include "engine.h"

namespace gasol {

    //--------------------------------------------------------------------------
    //
    void Engine::run(int ng)
    {
        for (int g = 0; g < ng; g++)
        {
            // Individuals in next generation population.
            std::vector<Individual> individuals(population_.size(), population_.indvs()[0]);

#pragma omp parallel for schedule(static)
            for (int i = 0; i < population_.size() - 1; i++)
            {
                int j = i + 1;
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


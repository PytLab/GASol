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
            std::vector<Individual> individuals;

            for (int i = 0; i < population_.size()/2; i++)
            {
                // Select father and mother.
                Parents parents = selection_.select(population_);

                // Crossover.
                std::pair<Individual, Individual> && children = crossover_.cross(parents);

                // Mutation.
                mutation_.mutate(children.first);
                mutation_.mutate(children.second);

                // Add to individuals.
                individuals.push_back(children.first);
                individuals.push_back(children.second);
            }

            // Reserve the best indv.
            individuals[0] = population_.bestIndv();

            // Update population.
            population_.updateIndividuals(individuals);
        }
    }
}


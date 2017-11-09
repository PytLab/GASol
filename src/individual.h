/*! \file  individual.hpp
 *  \brief File for the GAIndividual class definition
 */

#ifndef __INDIVIDUAL__
#define __INDIVIDUAL__

#include <vector>
#include <utility>

namespace gasol {

    /*! \brief Class for defining an individual in genetic algorithm engine.
     */
    class Individual {

    public:
        /*! \brief Constructor for the genetic algorithm individual.
         * 
         *  \param solution_candiate: A possible solution vector in the solution
         *                            space where genetic algorithm runs.
         *  \param ranges: The value ranges for all components in solution candidate vector.
         *  \param precisions: The discrete precisions for all components in solution 
         *                     candidate vector
         */
        Individual(std::vector<double> & solution_candidate,
                   const std::vector<std::pair<double, double>> & ranges,
                   const std::vector<double> & precisions);

        /*! \brief Another constructor for the genetic algorithm individual.
         * 
         *  \param solution_candiate: A possible solution vector in the solution
         *                            space where genetic algorithm runs.
         *  \param range: The value range for all components in solution candidate vector.
         *  \param precision: The discrete precision for all components in solution 
         *                    candidate vector
         */
        Individual(std::vector<double> & solution_candidate,
                   const std::pair<double, double> & range,
                   const double precision);

        /*! \brief Query function for solution candidate.
         */
        const std::vector<double> & solutionCandidate() const
        { return solution_candidate_; }

        /*! \brief Query function for ranges.
         */
        const std::vector<std::pair<double, double>> & ranges() const
        { return ranges_; }

        /*! \brief Query function for discrete precisions.
         */
        const std::vector<double> & precisions() const
        { return precisions_; }

    protected:

    private:
        /// Solution candidate vector.
        std::vector<double> solution_candidate_;
        /// Ranges for all components in solution vector.
        std::vector<std::pair<double, double>> ranges_;
        /// Discrete precision.
        std::vector<double> precisions_;
    };

}

#endif  // __INDIVIDUAL__


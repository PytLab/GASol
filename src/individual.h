/*! \file  individual.hpp
 *  \brief File for the GAIndividual class definition
 */

#ifndef __INDIVIDUAL__
#define __INDIVIDUAL__

#include <vector>
#include <utility>

namespace gasol {

    // Type alias.
    using RangePairs = std::vector<std::pair<double, double>>;
    using GeneBreakPts = std::vector<std::pair<int, int>>;

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
                   const RangePairs & ranges,
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
        const RangePairs & ranges() const
        { return ranges_; }

        /*! \brief Query function for original discrete precisions.
         */
        const std::vector<double> & originalPrecisions() const
        { return ori_precisions_; }

        /*! \brief Query function for precision loss flag.
         */
        bool precisionLoss() const
        { return precision_loss_; }

        /*! \brief Query function for gene lengths.
         */
        const std::vector<int> & geneLengths() const
        { return gene_lengths_; }

        /*! \brief Query function for discrete precisions.
         */
        const std::vector<double> & precisions() const
        { return precisions_; }

    protected:

    private:
        /// Solution candidate vector.
        std::vector<double> solution_candidate_;
        /// Ranges for all components in solution vector.
        RangePairs ranges_;
        /// Original discrete precisions for all components in solution.
        std::vector<double> ori_precisions_;
        /// Actual dsicrete precisions used in GA engine.
        std::vector<double> precisions_;
        /// Lengths of gene fragments.
        std::vector<int> gene_lengths_;
        /// The break points in gene sequence.
        GeneBreakPts gene_break_pts_;
        /// The chromsome contains gene sequence.
        std::vector<bool> chromsome_;
        /// Flag for precision loss.
        bool precision_loss_ = false;
    };

}

#endif  // __INDIVIDUAL__


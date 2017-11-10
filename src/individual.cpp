/*! \file individual.cpp
 *  \brief File for implementations of GAIndividual class.
 */

#include <cmath>
#include <iostream>

#include "individual.h"

namespace gasol {
    //--------------------------------------------------------------------------
    //
    Individual::Individual(std::vector<double> & solution_candidate,
                           const RangePairs & ranges,
                           const std::vector<double> & precisions) :
        solution_candidate_(solution_candidate),
        ranges_(ranges),
        ori_precisions_(precisions)
    {
        // Function to check an integer is the power of 2.
        auto power_of_2 = [](int n) { return !(n & (n - 1)); };

        // Calculate gene fragment lengths for all component in solution.
        auto range_it = ranges_.cbegin();
        auto prec_it = ori_precisions_.cbegin();

        for (; range_it != ranges_.end() && prec_it != ori_precisions_.end();
                range_it++, prec_it++)
        {
            double span = range_it->second - range_it->first;

            // The number of possible values for this component.
            // *****************************************************************
            // NOTE: EXCEPT the start point. For example, if precision is 0.2
            //       and range is [0.0, 1.0], then the n_info equals to 5 (5 numbers):
            //       0.2, 0.4, 0.6, 0.8, 1.0 not include 0.0
            // *****************************************************************
            int n_info = (int)(span/(*prec_it));

            if (!power_of_2(n_info))
            {
                precision_loss_ = true;
            }

            int length = (int)(std::log2(n_info));
            gene_lengths_.push_back(length);
        }

        // Calculate adjusted discrete precisions.
        if (precision_loss_)
        {
            range_it = ranges_.cbegin();
            auto len_it = gene_lengths_.cbegin();

            for (; range_it != ranges_.end() && len_it != gene_lengths_.end();
                    range_it++, len_it++)
            {
                // Ajusted precision.
                double precision = (range_it->second - range_it->first)/std::pow(2, *len_it);
                precisions_.push_back(precision);
            }
        }
        else
        {
            precisions_ = ori_precisions_;
        }
    }

    //--------------------------------------------------------------------------
    //
    Individual::Individual(std::vector<double> & solution_candidate,
                           const std::pair<double, double> & range,
                           const double precision) :
        solution_candidate_(solution_candidate),
        ranges_(solution_candidate.size(), range),
        ori_precisions_(solution_candidate.size(), precision)
    {}
}


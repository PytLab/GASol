/*! \brief File unittest for Individual class
 */

#include "individual.hpp"
#include "gtest/gtest.h"

namespace {

TEST(IndividualTest, Construction) {
    // Construct an individual.
    std::vector<double> solution_candidate {1.0, 2.0};
    std::vector<std::pair<double, double>> ranges {{0.0, 2.0}, {1.0, 2.0}};
    std::vector<double> precisions {0.001, 0.001};
    gasol::Individual indv(solution_candidate, ranges, precisions);

    // Check solution candidate.
    for (size_t i = 0; i < indv.solutionCandidate().size(); ++i)
    {
        double ref_component = solution_candidate[i];
        double ret_component = indv.solutionCandidate()[i];
        EXPECT_DOUBLE_EQ(ref_component, ret_component);
    }

    // Check ranges.
    for (size_t i = 0; i < indv.ranges().size(); i++)
    {
        double ref_floor = ranges[i].first;
        double ref_ceiling = ranges[i].second;
        double ret_floor = indv.ranges()[i].first;
        double ret_ceiling = indv.ranges()[i].second;
        EXPECT_DOUBLE_EQ(ref_floor, ret_floor);
        EXPECT_DOUBLE_EQ(ref_ceiling, ret_ceiling);
    }

    // Check precisions.
    for (size_t i = 0; i < indv.precisions().size(); i++)
    {
        double ref_prec = precisions[i];
        double ret_prec = precisions[i];
        EXPECT_DOUBLE_EQ(ref_prec, ret_prec);
    }
}

} // namespace


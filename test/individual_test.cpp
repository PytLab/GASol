/*! \brief File unittest for Individual class
 */

#include "individual.h"
#include "gtest/gtest.h"

namespace {

TEST(IndividualTest, ConstructionWithMultiVals)
{
    // Construct an individual.
    std::vector<double> solution_candidate {1.0, 1.75};
    std::vector<std::pair<double, double>> ranges {{0.0, 1.0}, {1.0, 2.0}};
    std::vector<double> precisions {0.1, 0.2};
    gasol::Individual indv(solution_candidate, ranges, precisions);

    // Check solution candidate.
    for (size_t i = 0; i < solution_candidate.size(); ++i)
    {
        double ref_component = solution_candidate[i];
        double ret_component = indv.oriSolutionCandidate()[i];
        EXPECT_DOUBLE_EQ(ref_component, ret_component);
    }

    // Check ranges.
    for (size_t i = 0; i < ranges.size(); i++)
    {
        double ref_floor = ranges[i].first;
        double ref_ceiling = ranges[i].second;
        double ret_floor = indv.ranges()[i].first;
        double ret_ceiling = indv.ranges()[i].second;
        EXPECT_DOUBLE_EQ(ref_floor, ret_floor);
        EXPECT_DOUBLE_EQ(ref_ceiling, ret_ceiling);
    }

    // Check original precisions.
    for (size_t i = 0; i < precisions.size(); i++)
    {
        double ref_prec = precisions[i];
        double ret_prec = indv.originalPrecisions()[i];
        EXPECT_DOUBLE_EQ(ref_prec, ret_prec);
    }

    // Check gene fragment lengths.
    std::vector<int> ref_lengths = {3, 2};
    for (size_t i = 0; i < ref_lengths.size(); i++)
    {
        EXPECT_EQ(ref_lengths[i], indv.geneLengths()[i]);
    }

    // Check precision loss.
    EXPECT_TRUE(indv.precisionLoss());

    // Check actual precisions.
    std::vector<double> ref_precisions = {0.125, 0.25};
    for (size_t i = 0; i < ref_precisions.size(); i++)
    {
        EXPECT_DOUBLE_EQ(ref_precisions[i], indv.precisions()[i]);
    }

    // Check chromsome.
    std::vector<bool> ref_chromsome {1, 1, 1, 1, 0};
    for (size_t i = 0; i < ref_chromsome.size(); i++)
    {
        EXPECT_EQ(ref_chromsome[i], indv.chromsome()[i]);
    }

    // Check gene fragment break points.
    gasol::GeneBreakPts ref_break_pts = {{0, 2}, {3, 4}};
    for (size_t i = 0; i < ref_break_pts.size(); i++)
    {
        EXPECT_EQ(ref_break_pts[i].first, indv.geneBreakPts()[i].first);
        EXPECT_EQ(ref_break_pts[i].second, indv.geneBreakPts()[i].second);
    }

    // Check adjusted solution vector.
    std::vector<double> ref_solution_candidate {1.0, 1.75};
    for (size_t i = 0; i < ref_solution_candidate.size(); i++)
    {
        EXPECT_DOUBLE_EQ(ref_solution_candidate[i], indv.solutionCandidate()[i]);
    }
}

TEST(IndividualTest, ConstructionWithSingleVal)
{
    // Construct an individual.
    std::vector<double> solution_candidate {1.0, 2.0};
    std::vector<std::pair<double, double>> ref_ranges {{0.0, 2.0}, {0.0, 2.0}};
    std::vector<double> ref_precisions {0.001, 0.001};
    std::pair<double, double> range {0.0, 2.0};
    double precision = 0.001;
    gasol::Individual indv(solution_candidate, range, precision);

    // Check solution candidate.
    for (size_t i = 0; i < solution_candidate.size(); ++i)
    {
        double ref_component = solution_candidate[i];
        double ret_component = indv.oriSolutionCandidate()[i];
        EXPECT_DOUBLE_EQ(ref_component, ret_component);
    }

    // Check ranges.
    for (size_t i = 0; i < ref_ranges.size(); i++)
    {
        double ref_floor = ref_ranges[i].first;
        double ref_ceiling = ref_ranges[i].second;
        double ret_floor = indv.ranges()[i].first;
        double ret_ceiling = indv.ranges()[i].second;
        EXPECT_DOUBLE_EQ(ref_floor, ret_floor);
        EXPECT_DOUBLE_EQ(ref_ceiling, ret_ceiling);
    }

    // Check precisions.
    for (size_t i = 0; i < ref_precisions.size(); i++)
    {
        double ref_prec = ref_precisions[i];
        double ret_prec = indv.originalPrecisions()[i];
        EXPECT_DOUBLE_EQ(ref_prec, ret_prec);
    }
}

} // namespace


/*! \brief File unittest for Individual class
 *  \author zjshao <shaozhengjiang@gmail.com>
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

    // Check attributes.
    EXPECT_DOUBLE_EQ(indv.solutionCandidate()[0], 1.0);
}

} // namespace


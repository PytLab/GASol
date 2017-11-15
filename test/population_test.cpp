/*! \brief Unittest for Population class
 */ 
#include "population.h"
#include "individual.h"
#include "gtest/gtest.h"

namespace {

class PopulationTest : public ::testing::Test {

protected:
    virtual void SetUp() {}

    virtual void TearDown() {}

    // Individuals used in tests.
    gasol::RangePairs ranges_ {{0.0, 1.0}, {1.0, 2.0}};
    std::vector<double> precisions_ {0.125, 0.25};

    std::vector<double> solution1_ {1.0, 1.75};
    gasol::Individual indv1_ = gasol::Individual(solution1_, ranges_, precisions_);

    std::vector<double> solution2_ {0.875, 1.5};
    gasol::Individual indv2_ = gasol::Individual(solution2_, ranges_, precisions_);

    std::vector<double> solution3_ {0.5, 2.0};
    gasol::Individual indv3_ = gasol::Individual(solution3_, ranges_, precisions_);
};

TEST_F(PopulationTest, Construction)
{
    std::vector<gasol::Individual> indvs {indv1_, indv2_, indv3_};
    gasol::Population population(indvs);

    // Check size.
    EXPECT_EQ(population.size(), 3);

    // Check one pointer.
    const auto indv_ptr = population.indvPtrs()[0];
    std::vector<bool> ref_chromsome {1, 1, 1, 1, 0};
    for (size_t i = 0; i < ref_chromsome.size(); i++)
    {
        EXPECT_EQ(ref_chromsome[i], indv_ptr->chromsome()[i]);
    }
}

} // namespace


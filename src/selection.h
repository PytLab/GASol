/*! brief File for selection operator classes definitions.
*/

#ifndef __SELECTION__
#define __SELECTION__

#include <utility>

namespace gasol {

    // Forward declaration.
    class Individual;
    class Population;

    // Type alias.
    using Parents = std::pair<const Individual *, const Individual *>;

    /*! \brief Abstract base class for selection operator.
     */
    class SelectionBase {

    public:
        /* \brief Constructor.
         */
        SelectionBase(int seed = -1) : seed_(seed) {}

        /*! \brief Pure virtual function for selection operation on populaiton.
         *  \param population: Population from which parents are choosen.
         */
        virtual Parents select(Population & population) = 0;

        /* \brief Query function for random seed.
         */
        int seed() const { return seed_; }

    protected:

    private:
        /// Random number seed.
        int seed_;
    };

    
    /*! \brief Selection operator implementation using roulette wheel.
     */
    class RouletteWheelSelection : public SelectionBase {

    public:
        /*! \brief Constructor for roulette wheel selection operator.
         *  \param seed: Seed for random number generator, if seed < 0, then time
         *               function would be used to generate seed.
         */
        RouletteWheelSelection(int seed=-1) : SelectionBase(seed) {}

        /*! \brief Selection operation.
         */
        Parents select(Population & population);

    private:
    };
}

#endif  // __SELECTION__


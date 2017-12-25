/*! \brief File for mutation operators definition.
 */

#ifndef __MUTATION__
#define __MUTATION__

#include <ctime>

namespace gasol {

    // Forward declarations.
    class Individual;

    /*! brief Abstract base class for mutation operator.
     */
    class MutationBase {

    public:
        /*! \brief Constructor.
         *  \param pm: The mutation probability.
         *  \param seed: Random seed for the crossover operator. If seed < 0, then
         *               the time() would be used to generate a seed.
         */
        MutationBase(double pm, int seed = -1) : pm_(pm)
        {
            if (seed < 0)
            {
                seed_ = time(NULL);
            }
            else
            {
                seed_ = seed;
            }
        }

        /*! \brief A pure virtual function to mutate an individual.
         *  \param indv: An individual to be mutated.
         */
        virtual void mutate(Individual & indv) const = 0;

        /*! \brief Query function for random seed.
         */
        int seed() const { return seed_; }

        /*! \brief Query function for mutation probability.
         */
        int pm() const { return pm_; }

    protected:

    private:
        /// Ranom seed.
        int seed_;

        /// Mutation probability.
        double pm_;
    };


    /*! \brief Mutation operator with flip bit mutation implementation.
     */
    class FlipBitMutation : public MutationBase {

    public:
        /*! \brief Constructor.
         */
        FlipBitMutation(double pm, int seed = -1) : MutationBase(pm, seed) {}

        /*! \brief Mutate an individual with flip bit method.
         */
        void mutate(Individual & indv) const;

    protected:

    private:

    };
}

#endif


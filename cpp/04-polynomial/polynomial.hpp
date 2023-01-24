#include "arrRational.hpp"
#include "cmath"
#include "algorithm"

namespace poly
{
class Polynomial
{
    public:
        explicit Polynomial();
        explicit Polynomial(size_t degree);
        explicit Polynomial(size_t degree , const Rational* const arr);

        Polynomial operator+( const Polynomial& other) const;
        Polynomial operator-( const Polynomial& other) const;
        Polynomial operator*( const Polynomial& other) const;
        Polynomial operator/( const Polynomial& other) const;

        // Rational& at(size_t i) const;
        Rational& at(size_t i);
        float valueAt(double x) const;
        Rational valueAt(Rational x) const;
        Polynomial ppp() const;
        void displye() const;

    private:
        void reSize();

    private:
        size_t m_degree;
        ds::ArrRational m_coeff;
};
}
#ifndef DEF_POLYNOMIAL_HPP
#define DEF_POLYNOMIAL_HPP

#include <vector>

#include "./Monomial.hpp"

class Polynomial {

    public:

    Polynomial() = default;

    Polynomial(const Polynomial&) = default;
    Polynomial(Polynomial&&) noexcept = default;

    Polynomial(std::string);
    Polynomial(Monomial);

    ~Polynomial() = default;

    template <typename Lambda> void ForEach(Lambda function) const {

        for (Monomial m : terms) {

            if (!m.Null()) function(m);

        }

    }

    template <typename Lambda> void ForEach(Lambda function) {

        for (Monomial &m : terms) {

            if (!m.Null()) function(m);

        }

    }

    bool Null() const;
    bool IsMonomial() const;
    bool IsBinomial() const;
    bool IsTrinomial() const;
    bool IsQuadrinomial() const;

    int CalculateFor(int) const;
    unsigned int Degree() const;
    std::size_t Count() const;

    friend std::string ToString(const Polynomial&);

    friend Polynomial Factor(const Polynomial&, const Polynomial&);
    friend std::pair<Polynomial, Polynomial> Develop(const Polynomial&);

    friend std::vector<unsigned int> GetDegrees(const Polynomial&);

    friend Polynomial operator+(const Polynomial&, const Polynomial&);
    friend Polynomial operator-(const Polynomial&, const Polynomial&);
    friend Polynomial operator*(const Polynomial&, const Polynomial&);
    friend Polynomial operator/(const Polynomial&, const Polynomial&);
    friend Polynomial operator%(const Polynomial&, const Polynomial&);

    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);
    Polynomial& operator*=(const Polynomial&);
    Polynomial& operator/=(const Polynomial&);
    Polynomial& operator%=(const Polynomial&);

    friend bool operator==(const Polynomial&, const Polynomial&);
    friend bool operator!=(const Polynomial&, const Polynomial&);

    friend bool operator<(const Polynomial&, const Polynomial&);
    friend bool operator<=(const Polynomial&, const Polynomial&);

    friend bool operator>(const Polynomial&, const Polynomial&);
    friend bool operator>=(const Polynomial&, const Polynomial&);

    Monomial operator[](std::size_t) const;
    Monomial& operator[](std::size_t);

    Polynomial& operator=(const Polynomial&) = default;
    Polynomial& operator=(Polynomial&&) noexcept = default;

    operator std::string();

    friend std::ostream& operator<<(std::ostream&, const Polynomial&);

    private:

    std::vector<Monomial> terms;

};

template <std::size_t Size> class Static_Polynomial {

    public:

    private:

};

using Binomial = Static_Polynomial<2>;
using Trinomial = Static_Polynomial<3>;
using Quadrinomial = Static_Polynomial<4>;

#endif // DEF_POLYNOMIAL_HPP
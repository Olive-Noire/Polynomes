#ifndef DEF_POLYNOMIAL_HPP
#define DEF_POLYNOMIAL_HPP

#include <vector>

#include "./Monomial.hpp"

class Polynomial {

    public:

    Polynomial();

    Polynomial(const Polynomial&) = default;
    Polynomial(Polynomial&&) noexcept = default;

    Polynomial(const std::string&);
    Polynomial(Monomial);

    ~Polynomial() = default;

    bool Null() const;
    bool IsMonomial() const;
    bool IsBinomial() const;
    bool IsTrinomial() const;

    int CalculateFor(int);
    std::size_t Count() const;
    std::size_t Degree() const;

    friend std::string ToString(const Polynomial&);

    friend Polynomial Factor(const Polynomial&, const Polynomial&);
    friend std::pair<Polynomial, Polynomial> Develop(const Polynomial&);

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

#endif // DEF_POLYNOMIAL_HPP
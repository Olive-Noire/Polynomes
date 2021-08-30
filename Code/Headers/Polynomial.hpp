#ifndef DEF_POLYNOMIAL_HPP
#define DEF_POLYNOMIAL_HPP

#include <utility>
#include <iosfwd>
#include <string>
#include <vector>

class Monomial {

    public:

    Monomial();

    Monomial(const Monomial&) = default;
    Monomial(Monomial&&) noexcept = default;

    Monomial(const std::string&);
    Monomial(int v, unsigned int p = 1);

    ~Monomial() = default;

    bool Null() const;

    int CalculateFor(int);

    friend std::string ToString(Monomial);

    friend Polynomial Factor(const Polynomial&, const Polynomial&);
    friend std::pair<Polynomial, Polynomial> Develop(const Polynomial&);

    friend Monomial operator+(const Monomial&, const Monomial&);
    friend Monomial operator-(const Monomial&, const Monomial&);
    friend Monomial operator*(const Monomial&, const Monomial&);
    friend Monomial operator/(const Monomial&, const Monomial&);

    Monomial& operator+=(const Monomial&);
    Monomial& operator-=(const Monomial&);
    Monomial& operator*=(const Monomial&);
    Monomial& operator/=(const Monomial&);

    friend bool operator==(const Monomial&, const Monomial&);
    friend bool operator!=(const Monomial&, const Monomial&);

    friend bool operator<(const Monomial&, const Monomial&);
    friend bool operator<=(const Monomial&, const Monomial&);

    friend bool operator>(const Monomial&, const Monomial&);
    friend bool operator>=(const Monomial&, const Monomial&);

    Monomial& operator=(const Monomial&) = default;
    Monomial& operator=(Monomial&&) noexcept = default;

    friend std::ostream& operator<<(std::ostream&, const Monomial&);

    private:

    int value;
    unsigned int power;

};

class Polynomial {

    public:

    Polynomial();

    Polynomial(const Polynomial&) = default;
    Polynomial(Polynomial&&) noexcept = default;

    Polynomial(Monomial);

    ~Polynomial() = default;

    bool Null() const;
    bool IsMonomial() const;
    bool IsBinomial() const;
    bool IsTrinomial() const;

    int CalculateFor(int);
    std::size_t Count() const;

    friend std::string ToString(const Polynomial&);

    friend Polynomial Factor(const Polynomial&, const Polynomial&);
    friend std::pair<Polynomial, Polynomial> Develop(const Polynomial&);

    friend Polynomial operator+(const Polynomial&, const Polynomial&);
    friend Polynomial operator-(const Polynomial&, const Polynomial&);
    friend Polynomial operator*(const Polynomial&, const Polynomial&);
    friend Polynomial operator/(const Polynomial&, const Polynomial&);

    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);
    Polynomial& operator*=(const Polynomial&);
    Polynomial& operator/=(const Polynomial&);

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

    friend std::ostream& operator<<(std::ostream&, const Polynomial&);

    private:

    std::vector<Monomial> terms;

};

#endif // DEF_POLYNOMIAL_HPP
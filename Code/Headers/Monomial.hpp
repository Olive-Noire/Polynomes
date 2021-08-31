#ifndef DEF_MONOMIAL_HPP
#define DEF_MONOMIAL_HPP

#include <string>

class Monomial {

    public:

    Monomial();

    Monomial(const Monomial&) = default;
    Monomial(Monomial&&) noexcept = default;

    Monomial(std::string);
    Monomial(int, unsigned int = 1);

    ~Monomial() = default;

    void SetNull();

    bool Null() const;

    int CalculateFor(int) const;

    friend bool CanDivide(const Monomial&, const Monomial&);

    friend std::string ToString(Monomial);
    friend std::string ToStringFor(Monomial, int);

    friend Monomial Factor(const Monomial&, const Monomial&);
    friend std::pair<Monomial, Monomial> Develop(const Monomial&);

    friend Monomial operator+(const Monomial&, const Monomial&);
    friend Monomial operator-(const Monomial&, const Monomial&);
    friend Monomial operator*(const Monomial&, const Monomial&);
    friend Monomial operator/(const Monomial&, const Monomial&);
    friend Monomial operator%(const Monomial&, const Monomial&);

    Monomial& operator+=(const Monomial&);
    Monomial& operator-=(const Monomial&);
    Monomial& operator*=(const Monomial&);
    Monomial& operator/=(const Monomial&);
    Monomial& operator%=(const Monomial&);

    friend bool operator==(const Monomial&, const Monomial&);
    friend bool operator!=(const Monomial&, const Monomial&);

    friend bool operator<(const Monomial&, const Monomial&);
    friend bool operator<=(const Monomial&, const Monomial&);

    friend bool operator>(const Monomial&, const Monomial&);
    friend bool operator>=(const Monomial&, const Monomial&);

    Monomial& operator=(const Monomial&) = default;
    Monomial& operator=(Monomial&&) noexcept = default;

    operator std::string();

    friend std::ostream& operator<<(std::ostream&, const Monomial&);

    int coefficient;
    unsigned int exposant;

};

#endif // DEF_MONOMIAL_HPP
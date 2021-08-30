#ifndef DEF_MONOMIAL_HPP
#define DEF_MONOMIAL_HPP

#include <string>

class Monomial {

    public:

    Monomial();

    Monomial(const Monomial&) = default;
    Monomial(Monomial&&) noexcept = default;

    Monomial(const std::string&);
    Monomial(int, unsigned int = 1);

    ~Monomial() = default;

    bool Null() const;

    int CalculateFor(int);

    friend std::string ToString(Monomial);

    friend Monomial Factor(const Monomial&, const Monomial&);
    friend std::pair<Monomial, Monomial> Develop(const Monomial&);

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

    operator std::string();

    friend std::ostream& operator<<(std::ostream&, const Monomial&);

    private:

    int value;
    unsigned int power;

};

#endif // DEF_MONOMIAL_HPP
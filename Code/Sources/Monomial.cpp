#include "../Headers/Monomial.hpp"

#include <sstream>
#include <cassert>
#include <cctype>
#include <cmath>

Monomial::Monomial() : coefficient{0}, exposant{0} {}

Monomial::Monomial(std::string s) {

    for (std::size_t i{0}; i < s.size(); i++) {

        if (std::isspace(s[i])) {

            s.erase(s.begin()+i);
            i--;

        }

    }

    bool negatif{false};

    if (!s.empty() && !std::isdigit(s[0]) && s[0] != '-') {

        coefficient = exposant = 0;

    } else {

        if (!s.empty() && s[0] == '-') {

            negatif = true;
            s.erase(s.begin());

        }

        std::pair<bool, bool> verifications{false, false};
        std::pair<std::string, std::string> extracts;

        for (char c : s) {

            if (std::isdigit(c)) {

                if (verifications.second) {

                    extracts.second.push_back(c);

                } else {

                    extracts.first.push_back(c);

                }

            } else {

                if (c == 'x' && !verifications.first) {
                
                    verifications.first = true;

                } else if (c == '^' && verifications.first && !verifications.second) {

                    verifications.second = true;

                } else {

                    if (verifications.second) {

                        extracts.second.clear();

                    } else {

                        extracts = {};

                    }

                    break;

                }

            }

        }

        if (extracts == std::pair<std::string, std::string>{}) {

            coefficient = exposant = 0;

        } else if (extracts.second.empty()) {

            std::istringstream{extracts.first} >> coefficient;
            exposant = verifications.first;

            if (negatif) coefficient = -coefficient;

        } else {

            std::istringstream{extracts.first} >> coefficient;
            std::istringstream{extracts.second} >> exposant;

            if (negatif) coefficient = -coefficient;

        }

    }

}

Monomial::Monomial(int v, unsigned int e) : coefficient{v}, exposant{e} {}

void Monomial::SetNull() {
    
    coefficient = 0;
    exposant = 0;

}

bool Monomial::Null() const { return coefficient == 0 && exposant == 0; }
int Monomial::CalculateFor(int x) const { return coefficient*std::pow(x, exposant); }

std::string ToString(Monomial m) {

    if (m.exposant == 0) {

        return std::to_string(m.coefficient);

    } else if (m.exposant == 1) {

        return std::to_string(m.coefficient)+'x'; 

    } else {
    
        return std::to_string(m.coefficient)+"x^"+std::to_string(m.exposant);

    }
    
}

std::string ToStringFor(Monomial m, int i) {

    if (m.exposant == 0) {

        return std::to_string(m.coefficient);

    } else if (m.exposant == 1) {

        return std::to_string(m.coefficient)+'*'+std::to_string(i); 

    } else {

        if (i >= 0) {
    
            return std::to_string(m.coefficient)+'*'+std::to_string(i)+'^'+std::to_string(m.exposant);

        } else {

            return std::to_string(m.coefficient)+"*("+std::to_string(i)+")^"+std::to_string(m.exposant);;

        }

    }
    
}

Monomial Factor(const Monomial &a, const Monomial &b) {

    Monomial f;
    return f;

}

std::pair<Monomial, Monomial> Develop(const Monomial &m) {

    std::pair<Monomial, Monomial> d;
    return d;

}

Monomial operator+(const Monomial &l, const Monomial &r) {

    assert(l.exposant == r.exposant);
    return Monomial{l.coefficient+r.coefficient, l.exposant};

}

Monomial operator-(const Monomial &l, const Monomial &r) {

    assert(l.exposant == r.exposant);
    return Monomial{l.coefficient-r.coefficient, l.exposant};

}

Monomial operator*(const Monomial &l, const Monomial &r) {

    return Monomial{l.coefficient*r.coefficient, l.exposant+r.exposant};

}

Monomial operator/(const Monomial &l, const Monomial &r) {

    assert(l.coefficient%r.coefficient == 0 && l.exposant >= r.exposant);
    return Monomial{l.coefficient/r.coefficient, l.exposant-r.exposant};

}


Monomial operator%(const Monomial &l, const Monomial &r) { return l-l/r*r; }

Monomial& Monomial::operator+=(const Monomial &m) { return *this = *this+m; }
Monomial& Monomial::operator-=(const Monomial &m) { return *this = *this-m; }
Monomial& Monomial::operator*=(const Monomial &m) { return *this = *this*m; }
Monomial& Monomial::operator/=(const Monomial &m) { return *this = *this/m; }
Monomial& Monomial::operator%=(const Monomial &m) { return *this = *this%m; }
 
bool operator==(const Monomial &l, const Monomial &r) { return l.coefficient == r.coefficient && l.exposant == r.exposant; }
bool operator!=(const Monomial &l, const Monomial &r) { return !(l == r); }

bool operator<(const Monomial &l, const Monomial &r) { return l.CalculateFor(2) < r.CalculateFor(2); }
bool operator<=(const Monomial &l, const Monomial &r) { return l < r || l == r; }

bool operator>(const Monomial &l, const Monomial &r) { return !(l <= r); }
bool operator>=(const Monomial &l, const Monomial &r) { return l > r || l == r; }

Monomial::operator std::string() { return ToString(*this); }

std::ostream& operator<<(std::ostream &flux, const Monomial &m) {

    flux << ToString(m);
    return flux;

}
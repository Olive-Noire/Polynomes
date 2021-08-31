#include "../Headers/Polynomial.hpp"

Polynomial::Polynomial(std::string s) {

    for (std::size_t i{0}; i < s.size(); i++) {

        if (std::isspace(s[i])) {

            s.erase(s.begin()+i);
            i--;

        }

    }

    bool sign{!s.empty() && s[0] != '-'};
    if (!sign) s.erase(s.begin());

    std::string temp;

    while (!s.empty()) {

        if (s[0] == '+' || s[0] == '-' || s.size() == 1) {

            if (s.size() == 1) temp.push_back(s[0]);

            Monomial m{temp};

            if (m.exposant >= terms.size()) {

                while (m.exposant > terms.size()) {
                    
                    terms.push_back(Monomial{0, terms.size()});

                }

                if (sign) {

                    terms.push_back(m);

                }   else {

                    terms.push_back(-m);

                }

            } else {

                if (sign) {

                    terms[m.exposant] += m;

                }   else {

                    terms[m.exposant] -= m;

                }

            }

            sign = (s[0] != '-');

            s.erase(s.begin());
            temp.clear();

            continue;

        }

        temp.push_back(s[0]);
        s.erase(s.begin());

    }

}

Polynomial::Polynomial(Monomial m) : terms{m} {

    for (std::size_t i{0}; i < m.exposant; i++) {

        terms.insert(terms.begin()+i, Monomial{0, i});

    }

}

bool Polynomial::Polynomial::Null() const {

    bool n{true};
    for (Monomial m : terms) {

        if (!m.Null()) {

            n = false;
            break;

        }

    }

    return n;

}

bool Polynomial::IsMonomial() const { return Count() == 1; }
bool Polynomial::IsBinomial() const { return Count() == 2; }
bool Polynomial::IsTrinomial() const { return Count() == 3; }
bool Polynomial::IsQuadrinomial() const { return Count() == 4; }

int Polynomial::CalculateFor(int x) const {

    int result{0};
    for (Monomial m : terms) result += m.CalculateFor(x);

    return result;

}

unsigned int Polynomial::Degree() const {

    unsigned int max{0};
    ForEach([&max](Monomial m) -> void {

        if (m.exposant > max) max = m.exposant;

    });

    return max;

}

std::size_t Polynomial::Count() const {

    std::size_t count{0};
    for (Monomial m : terms) count += !m.Null();

    return count;

}

std::string ToString(const Polynomial &p) {

    if (p.Null()) {

        return "0";

    } else {

        std::string s;
        for (std::size_t i{0}; i < p.terms.size(); i++) {

            if (!p.terms[p.terms.size()-1-i].Null()) {

                if (i != 0 && p.terms[p.terms.size()-1-i].coefficient >= 0) s.push_back('+');
                s += ToString(p.terms[p.terms.size()-1-i]);

            }

        }

        return s;

    }

}

Polynomial Factor(const Polynomial &a, const Polynomial &b) {



}

std::pair<Polynomial, Polynomial> Develop(const Polynomial &p) {



}

std::vector<unsigned int> GetDegrees(const Polynomial &p) {

    std::vector<unsigned int> degrees;
    p.ForEach([&degrees](Monomial m) -> void { degrees.push_back(m.exposant); });

    return degrees;

}

Polynomial operator+(const Polynomial &l, const Polynomial &r) {

    if (r.terms.size() > l.terms.size()) {

        return r+l;

    } else {

        Polynomial result{l};
        for (std::size_t i{0}; i < r.terms.size(); i++) {

            result.terms[i] += r[i];

        }

        return result;

    }

}

Polynomial operator-(const Polynomial &l, const Polynomial &r) {

    Polynomial result{l};

    for (std::size_t i{0}; i < r.terms.size(); i++) {
            
        if (i < l.terms.size()) {

            result.terms[i] -= r[i];

        } else {

            result.terms.push_back(-r[i]);

        }

    }

    return result;

}

Polynomial operator*(const Polynomial &l, const Polynomial &r) {

    Polynomial result;
    for (std::size_t i{0}; i < r.terms.size(); i++) {

        for (std::size_t j{0}; j < l.terms.size(); j++) {

            result += r[i]*l[j];

        }

    }

    return result;

}

Polynomial operator/(const Polynomial &l, const Polynomial &r) {

    return l+r;

}

Polynomial operator%(const Polynomial &l, const Polynomial &r) { return l-l/r*r; }

Polynomial& Polynomial::operator+=(const Polynomial &p) { return *this = *this+p; }
Polynomial& Polynomial::operator-=(const Polynomial &p) { return *this = *this-p; }
Polynomial& Polynomial::operator*=(const Polynomial &p) { return *this = *this*p; }
Polynomial& Polynomial::operator/=(const Polynomial &p) { return *this = *this/p; }
Polynomial& Polynomial::operator%=(const Polynomial &p) { return *this = *this%p; }

bool operator==(const Polynomial &l, const Polynomial &r) { return l.terms == r.terms; }
bool operator!=(const Polynomial &l, const Polynomial &r) { return !(l == r); }

bool operator<(const Polynomial &l, const Polynomial &r) { return l.CalculateFor(2) < r.CalculateFor(2); }
bool operator<=(const Polynomial &l, const Polynomial &r) { return l < r || l == r; }

bool operator>(const Polynomial &l, const Polynomial &r) { return !(l <= r); }
bool operator>=(const Polynomial &l, const Polynomial &r) { return l > r || l == r; }

Monomial Polynomial::operator[](std::size_t index) const { return terms[index]; }
Monomial& Polynomial::operator[](std::size_t index) { return terms[index]; }

Polynomial::operator std::string() { return ToString(*this); }

std::ostream& operator<<(std::ostream &flux, const Polynomial &p) {

    flux << ToString(p);
    return flux;

}
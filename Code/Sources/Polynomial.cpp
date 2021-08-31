#include "../Headers/Polynomial.hpp"

Polynomial::Polynomial() {



}

Polynomial::Polynomial(const std::string &s) {

    
    
}

Polynomial::Polynomial(Monomial m) {

    

}

bool Polynomial::Polynomial::Null() const {



}

bool Polynomial::IsMonomial() const {



}

bool Polynomial::IsBinomial() const {



}

bool Polynomial::IsTrinomial() const {



}

int Polynomial::CalculateFor(int x) {



}

std::size_t Polynomial::Count() const {



}

std::size_t Polynomial::Degree() const {



}

std::string ToString(const Polynomial &p) {



}

Polynomial Factor(const Polynomial &a, const Polynomial &b) {



}

std::pair<Polynomial, Polynomial> Develop(const Polynomial &p) {



}

Polynomial operator+(const Polynomial &l, const Polynomial &r) {



}

Polynomial operator-(const Polynomial &l, const Polynomial &r) {



}

Polynomial operator*(const Polynomial &l, const Polynomial &r) {



}

Polynomial operator/(const Polynomial &l, const Polynomial &r) {



}

Polynomial& Polynomial::operator+=(const Polynomial &p) {



}

Polynomial& Polynomial::operator-=(const Polynomial &p) {



}

Polynomial& Polynomial::operator*=(const Polynomial &p) {



}

Polynomial& Polynomial::operator/=(const Polynomial &p) {



}

bool operator==(const Polynomial &l, const Polynomial &r) {



}

bool operator!=(const Polynomial &l, const Polynomial &r) {



}

bool operator<(const Polynomial &l, const Polynomial &r) {



}

bool operator<=(const Polynomial &l, const Polynomial &r) {



}

bool operator>(const Polynomial &l, const Polynomial &r) {



}

bool operator>=(const Polynomial &l, const Polynomial &r) {



}

Monomial Polynomial::operator[](std::size_t index) const {



}

Monomial& Polynomial::operator[](std::size_t index) {



}

Polynomial::operator std::string() {



}

std::ostream& operator<<(std::ostream &flux, const Polynomial &p) {



}
#include <iostream>

int GreatestCommonDivisor(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GreatestCommonDivisor(b, a % b);
	}
}

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int new_numerator, int new_denominator) { 
		const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
		numerator = new_numerator / gcd;
		denominator = new_denominator / gcd;
		if (denominator < 0) {
			denominator = -denominator;
			numerator = -numerator;
		}
	}

	int Numerator() const {
		return numerator;
	}

	int Denominator() const {
		return denominator;
	}

private:
	int numerator;
	int denominator;
};

bool operator==(const Rational &lhs, const Rational &rhs) {
	return lhs.Numerator() == rhs.Numerator() &&
		   lhs.Denominator() == rhs.Denominator();
}


Rational operator+(const Rational &lhs, const Rational &rhs) {
	return {
		lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()};
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
	return {
		lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()};
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
	return {
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

std::istream &operator>>(std::istream &is, Rational &r) {
	int n, d;
	char c;

	if (is) {
		is >> n >> c >> d;
		if (is) {
			if (c == '/') {
				r = Rational(n, d);
			}
			else {
				is.setstate(std::ios_base::failbit);
			}
		}
	}

	return is;
}

std::ostream &operator<<(std::ostream &os, const Rational &r) {
	return os << r.Numerator() << '/' << r.Denominator();
}

bool operator<(const Rational &lhs, const Rational &rhs) {
	return (lhs - rhs).Numerator() < 0;
}

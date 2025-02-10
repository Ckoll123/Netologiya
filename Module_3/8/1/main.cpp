#include <iostream>
#include <limits>

class Fraction
{
private:
	int numerator_;
	int denominator_;

    void fractionConversion(Fraction f1);

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

    bool operator==(const Fraction & other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(8, 6);
    
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}

bool Fraction::operator==(const Fraction& other) const 
{ 
    bool result {(numerator_ * other.denominator_ == other.numerator_ * denominator_) ? true : false};
    return result;
}

bool Fraction::operator!=(const Fraction& other) const 
{ 
    bool result {*this == other};
    return !result;
}

bool Fraction::operator<(const Fraction& other) const 
{ 
    bool result {(numerator_ * other.denominator_ < other.numerator_ * denominator_) ? true : false};
    return result;
}

bool Fraction::operator>(const Fraction& other) const 
{ 
    // bool result {(numerator_ * other.denominator_ > other.numerator_ * denominator_) ? true : false};
    // return result;
    
    double a = numerator_ / denominator_;
    double b = other.numerator_ / other.denominator_;
    bool result {(abs(a-b) > std::numeric_limits<double>::epsilon()) ? true : false};
    return result;
}

bool Fraction::operator<=(const Fraction& other) const 
{ 
    bool result {*this > other};
    return !result;
}

bool Fraction::operator>=(const Fraction& other) const 
{ 
    bool result {*this < other};
    return !result;
}
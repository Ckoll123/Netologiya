#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

    int gcdCalc(int num, int den);

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

    std::string printValue();

    // bool operator==(const Fraction & other) const;
    // bool operator!=(const Fraction& other) const;
    // bool operator<(const Fraction& other) const;
    // bool operator>(const Fraction& other) const;
    // bool operator<=(const Fraction& other) const;
    // bool operator>=(const Fraction& other) const;

    Fraction operator+(Fraction other);
    Fraction operator-(Fraction other);
    Fraction operator*(Fraction other);
    Fraction operator/(Fraction other);

    Fraction operator-();
    Fraction& operator++();
    Fraction& operator--();
    Fraction operator++(int);
    Fraction operator--(int);
};

int main()
{
	Fraction f1(3, 4);
	Fraction f2(4, 5);
	Fraction temp(0, 0);

	// std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	// std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	// std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	// std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	// std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	// std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

    
    temp = f1 + f2;
	std::cout << "f1 + f2 = " << temp.printValue() << '\n';
    temp = f1 - f2;
	std::cout << "f1 - f2 = " << temp.printValue() << '\n';
    temp = f1 * f2;
	std::cout << "f1 * f2 = " << temp.printValue() << '\n';
    temp = f1 / f2;
	std::cout << "f1 / f2 = " << temp.printValue() << '\n';

    temp = ++f1 * f2;
	std::cout << "++f1 * f2 = " << temp.printValue() << '\n';
    std::cout << "Значение дроби 1 = " << f1.printValue() << '\n';

    temp = f1-- * f2;
	std::cout << "f1-- * f2 = " << temp.printValue() << '\n';
    std::cout << "Значение дроби 1 = " << f1.printValue() << '\n';

	std::cout << "f1 = " << f1.printValue() << '\n';
    f1 = -f1;
	std::cout << "-f1 = " << f1.printValue() << '\n';

	return 0;
}


std::string Fraction::printValue(){
    return std::to_string(numerator_) + "/" + std::to_string(denominator_);
}

int Fraction::gcdCalc(int num, int den)
{
    if(num < 0) num *= -1;
    if(den < 0) den *= -1;

    if (!(num % den)){
        return den;
    }
    
    if (!(den % num)){
        return num;
    }

    if (num > den)
    { return gcdCalc(num % den, den); }
    else
    { return gcdCalc(num, den % num); }
}

//---------------------------------------------------------------------------------------------------

Fraction Fraction::operator+(Fraction other){
    Fraction temp{*this};
    if (temp.denominator_ == other.denominator_)
    { 
        temp.numerator_ += other.numerator_;
        return temp;
    }
    else
    {
        int commonDen = temp.denominator_ * other.denominator_;
        temp.numerator_ *= other.denominator_;
        other.numerator_ *= temp.denominator_;

        temp.numerator_ += other.numerator_;
        temp.denominator_ = commonDen;
        
        int gcd{};
        gcd = gcdCalc(temp.numerator_, temp.denominator_);
        temp.numerator_ /= gcd;
        temp.denominator_ /= gcd;
        return temp;
    }
}

Fraction Fraction::operator-(Fraction other){
    Fraction temp{*this};
    if (temp.denominator_ == other.denominator_)
    { 
        temp.numerator_ += other.numerator_;
        return temp;
    }
    else
    {
        int commonDen = temp.denominator_ * other.denominator_;
        temp.numerator_ *= other.denominator_;
        other.numerator_ *= temp.denominator_;

        temp.numerator_ -= other.numerator_;
        temp.denominator_ = commonDen;
        
        int gcd{};
        gcd = gcdCalc(temp.numerator_, temp.denominator_);
        temp.numerator_ /= gcd;
        temp.denominator_ /= gcd;
        return temp;
    }
}

Fraction Fraction::operator*(Fraction other){
    Fraction temp{*this};
    temp.numerator_ *= other.numerator_;
    temp.denominator_ *= other.denominator_;

    int gcd{};
    gcd = gcdCalc(temp.numerator_, temp.denominator_);
    temp.numerator_ /= gcd;
    temp.denominator_ /= gcd;
    return temp;
}

Fraction Fraction::operator/(Fraction other){
    Fraction temp{*this};
    temp.numerator_ *= other.denominator_;
    temp.denominator_ *= other.numerator_;

    int gcd{};
    gcd = gcdCalc(temp.numerator_, temp.denominator_);
    temp.numerator_ /= gcd;
    temp.denominator_ /= gcd;
    return temp;
}

Fraction Fraction::operator-() {
    Fraction temp(-this->numerator_, this->denominator_);
    return temp;
}

Fraction& Fraction::operator++(){
    numerator_ += denominator_;

    int gcd{};
    gcd = gcdCalc(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
    return *this;
}

Fraction& Fraction::operator--(){
    numerator_ -=denominator_;

    int gcd{};
    gcd = gcdCalc(numerator_, denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction temp{*this};
    ++(*this);

    return temp;
}

Fraction Fraction::operator--(int){
    Fraction temp{*this};
    --(*this);

    return temp;
}

//-------------------------------------------------------------------------------------------------------

// bool Fraction::operator==(const Fraction& other) const 
// { 
//     bool result {(numerator_ * other.denominator_ == other.numerator_ * denominator_) ? true : false};
//     return result;
// }

// bool Fraction::operator!=(const Fraction& other) const 
// { 
//     bool result {*this == other};
//     return !result;
// }

// bool Fraction::operator<(const Fraction& other) const 
// { 
//     bool result {(numerator_ * other.denominator_ < other.numerator_ * denominator_) ? true : false};
//     return result;
// }

// bool Fraction::operator>(const Fraction& other) const 
// { 
//     // bool result {(numerator_ * other.denominator_ > other.numerator_ * denominator_) ? true : false};
//     // return result;
    
//     double a = numerator_ / denominator_;
//     double b = other.numerator_ / other.denominator_;
//     bool result {(abs(a-b) > std::numeric_limits<double>::epsilon()) ? true : false};
//     return result;
// }

// bool Fraction::operator<=(const Fraction& other) const 
// { 
//     bool result {*this > other};
//     return !result;
// }

// bool Fraction::operator>=(const Fraction& other) const 
// { 
//     bool result {*this < other};
//     return !result;
// }
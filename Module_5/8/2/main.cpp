#include <iostream>
#include <vector>
#include <utility>

class big_integer{
public:
    big_integer() :
        _digits{}
    {}

    big_integer(const std::string& sting_number){
        if (sting_number.empty()){
            _digits = {};
            return;
        }

        for (size_t i = sting_number.size(); i > 0; i--){
            if (isdigit(sting_number[i - 1])) {
                _digits.push_back(sting_number[i - 1] - '0');
            }
        }

        if (_digits.empty()){
            _digits = {0};
        }

    }

    big_integer(big_integer&& other) noexcept :
        _digits(std::move(other._digits))
    { other._digits = {0}; }
    
    big_integer& operator=(big_integer&& other) noexcept {
        if (this != &other) {
            _digits = std::move(other._digits);
            other._digits = {0};
        }
        return *this;
    }
    
    big_integer operator+(const big_integer& other) const{
        big_integer result;

        size_t max_len = std::max(_digits.size(), other.getSize());
        int carry = 0;

        for (size_t i = 0; i < max_len || static_cast<size_t>(carry); ++i) {
            int sum = carry;
            if (i < _digits.size()) sum += _digits[i];
            if (i < other.getSize()) sum += other.getDigitElement(i);
            
            result._digits.push_back(sum % 10);
            carry = sum / 10;
        }

        return result;
    }
    
    big_integer operator*(int num){
        if (num < 0) {
            throw std::invalid_argument("Работа с отрицательными числами не предусмотрена");
        }

        big_integer result;

        int carry = 0;
        for (size_t i = 0; i < _digits.size() || static_cast<size_t>(carry); ++i) {
            int product = carry;
            if (i < _digits.size()) {
                product += _digits.at(i) * num;
            }
            
            result._digits.push_back(product % 10);
            carry = product / 10;
        }

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        for (auto it = num._digits.rbegin(); it != num._digits.rend(); it++) {
            os << *it;
        }
        return os;
    }

    size_t getSize() const{
        return _digits.size();
    };

    int getDigitElement(int elementNumber) const{
        return _digits.at(elementNumber);
    }

private:
    std::vector<int> _digits;
};

int main(){
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099

    return 0;
}

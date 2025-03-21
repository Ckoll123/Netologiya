#include <iostream>

int fibonachi(int n, int prev2, int prev1);

int main() {
    int n = 6;

    std::cout << fibonachi(n, 0, 1);
    return 0;
}

int fibonachi(int n, int prev2, int prev1) {
  
    if (n == 0) {
        return prev2;
    }
  
    if (n == 1) {
        return prev1;
    }
    
    return fibonachi(n - 1, prev1, prev2 + prev1);
}

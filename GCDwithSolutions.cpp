#include <iostream>

int GCD(int a, int b, int &x, int &y);
std::string f(int &a);

int main() {

    int a, b, x, y, gcd;

    a = 126;
    b = 10101;
    gcd = GCD(a, b, x, y);

    std::cout << f(a) << " * " << f(x) << " + " << f(b) << " * " << f(y) << " = " << gcd << std::endl;

    std::cout << a * x + b * y << " = " << gcd << std::endl;

    return 0;
}

//this function is based on the logic of Euclid's algorithm and it returns a GCD of a and b
//and 1 solution set (the equation is a * x + b * y = GCD) as its arguments
int GCD(int a, int b, int &x, int &y) {

    int r1, r2, rn, t, q, c, d;

    //1st case
    x = 0; y = 1;

    //0 cases
    if (a == 0) {if (b == 0) y = 0; return b;}
    if (b == 0) {y = 0; x = 1; return a;}

    //q is num1 / num2 and rn is a remainder of num1 and num2
    q = a / b; r1 = a - q * b;
    
    //1st case
    if (r1 == 0) return b;

    //c and d are former coeficients
    c = x; d = y;
    
    //2nd case
    x = 1; y = -q;

    q = b / r1; r2 = b - q * r1;

    //2nd case
    if (r2 == 0) return r1;

    //other cases
    do {

        //t is for "remembering" x
        t = x;
        //finds new x
        x = c - q * x;
        //sets c (which is a former x)
        c = t;

        //same goes for y and d
        t = y;
        y = d - q * y;
        d = t;

        q = r1 / r2; rn = r1 - q * r2;

        //now r1 and r2 are former remainders
        r1 = r2;
        r2 = rn;

    } while(rn != 0);

    return r1;
}

//puts parentheses if number a is negative
std::string f(int &a) {

    return (a < 0) ? "(" + std::to_string(a) + ")" : std::to_string(a);
}

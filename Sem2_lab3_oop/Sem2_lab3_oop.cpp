#include <iostream>
#include <list>
#include <math.h>

using namespace std;

class Function {
public:
    double x;
    double y;
    float result;

    virtual double calculate() {
        return result;
    }
    virtual void getResult() {
        cout << "Result: " << result << endl;
    }
};

class Multiplication : public Function {
public:
    Multiplication() {
        x = 7;
        y = 3.5;
    }
    Multiplication(const Multiplication& sum) {
        x = sum.x;
        y = sum.y;

    }
    Multiplication(double x_input, double y_input) {
        x = x_input;
        y = y_input;
    }

    virtual double calculate() {
        result = x * y;
        return result;
    }
};

class Sum : public Function {
public:
    Sum() {
        x = 7;
        y = 2;
    }
    virtual double calculate() {
        result = x + y;
        return result;
    }
};

class Menos : public Function {
public:
    Menos() {
        x = 19;
        y = 4;
    }
    virtual double calculate() {
        result = x - y;
        return result;
    }
};
class ReverseMenos : public Function {
public:
    ReverseMenos() {
        x = 3;
        y = 2;
    }
    virtual double calculate() {
        result = y-x;
        return result;
    }
};

class Division : public Function {
public:
    Division() {
        x = 4;
        y = 5;
    }
    virtual double calculate() {
        result = x/y;
        return result;
    }
};
class ReverseDivision : public Function {
public:
    ReverseDivision() {
        x = 13.75;
        y = 79;
    }
    virtual double calculate() {
        result = y/ x;
        return result;
    }
};
class Container {
    list<Function*> functions;

public:
    void add(Multiplication* Multiplication_res) {
        functions.push_back(Multiplication_res);
    }

    void add(Sum* suma) {
        functions.push_back(suma);
    }

    void add(Menos* Menos_res) {
        functions.push_back(Menos_res);
    }

    void add(ReverseMenos* ReverseMenos_res) {
        functions.push_back(ReverseMenos_res);
    }

    void add(Division* Divisions_res) {
        functions.push_back(Divisions_res);
    }

    void add(ReverseDivision* ReverseDivision_res) {
        functions.push_back(ReverseDivision_res);
    }

    void calculate() {
        float res = 1;
        for (auto it = functions.begin(); it != functions.end(); ++it) {
            res *= (*it)->calculate();
            res = abs(res);
            (*it)->getResult();
        }
        cout << "The result of multiplying all functions: " << res;
    }
};

int main()
{
    Container cont;
    cont.add(new Multiplication(7, 4));
    cont.add(new Sum());
    cont.add(new Multiplication());

    cont.add(new Menos());
    cont.add(new ReverseMenos());

    cont.add(new Division());
    cont.add(new ReverseDivision());
    cont.calculate();
    return 0;
}


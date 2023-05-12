#include <iostream>
#include <list>
#include <math.h>

using namespace std;

class Function {
protected:
    double x;
    double y;

public:
    Function() {
        this->x = 0;
        this->y = 0;
    };
    virtual double calculate() = 0;
};

class Multiplication : public Function {
public:
    Multiplication() : Function() {
        x = 7;
        y = 3.5;
    }
    double calculate() override {
        return x * y;
    }
};

class Sum : public Function {
public:
    Sum() : Function() {
        x = 7;
        y = 2;
    }
    double calculate() override {
        return x + y;
    }
};

class Menos : public Function {
public:
    Menos() : Function() {
        x = 19;
        y = 4;
    }
    double calculate() override {
        return x - y;
    }
};
class ReverseMenos : public Function {
public:
    ReverseMenos() : Function() {
        x = 3;
        y = 2;
    }
    double calculate() override {
        return y - x;
    }
};

class Division : public Function {
public:
    Division() : Function() {
        x = 4;
        y = 5;
    }
    double calculate() override {
        return x / y;
    }
};

class ReverseDivision : public Function {
public:
    ReverseDivision() : Function() {
        x = 13.75;
        y = 79;
    }
    double calculate() override {
        return y / x;
    }
};
class Container {
    list<Function*> functions;

public:
    void add(Function* res) {
        functions.push_back(res);
    }

    double calculate() {
        double res = 1;
        for (Function* function : functions) {
            res *= abs(function->calculate());
        }
        return res;
    }
};

int main()
{
    Container cont;
    cont.add(new Sum());
    cont.add(new Multiplication());
    cont.add(new Menos());
    cont.add(new ReverseMenos());
    cont.add(new Division());
    cont.add(new ReverseDivision());
    cout << cont.calculate();

    return 0;
}


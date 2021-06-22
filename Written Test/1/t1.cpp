/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-19 09:44:42
 * @LastEditTime: 2021-06-19 10:23:02
 * @FilePath: \Leetcode\Written Test\模版\t1.cpp
 */
# include <iostream>
using namespace std;

class Base{
    public:
        virtual ~Base() {}
    public:
        virtual void Print() {
            cout << "Base::Print()" << endl;
        }
        void Hello() {
            cout << "Base::Hello()" << endl;
            Print();
        }
};

class Deriv1: public Base {
    public:
        void Print() {
            cout << "Deriv1::Print()" << endl;
        }
        void Hello() {
            cout << "Deriv1::Hello()" << endl;
            Print();
        }
};

class Deriv2: public Deriv1 {
    public:
        void Print() {
            cout << "Deriv2::Print()" << endl;
        }
        void Hello() {
            cout << "Deriv2::Hello()" << endl;
            Print();
        }
};


int main() {
    Base* p1 = new Base();
    Base* p2 = new Deriv1();
    Base* p3 = new Deriv2();

    p1->Print();
    p1->Hello();
        p2->Print();
    p2->Hello();
        p3->Print();
    p3->Hello();

    return 0;
}

#include <iostream>
#include <sstream>

using namespace std;

class Punkt
{
protected:
    double x;
    double y;

public:
    Punkt() : x(0), y(0) {}
    Punkt(double X, double Y) : x(X), y(Y) {}
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getX() { return x; }
    double getY() { return y; }
    string info()
    {
        stringstream s;
        s << "(" << x << ";" << y << ") ";
        return s.str();
    }
    void przesun(double dx, double dy)
    {
        x += dx;
        y += dy;
    }
};
//------------------------------------------------------------------------------//

class Prostokat : public Punkt
{

protected:
    double a;
    double b;

public:
    Prostokat() : Punkt(), a(0), b(0) {}
    Prostokat(double X, double Y, double A, double B) : Punkt(X, Y), a(A), b(B) {}
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    double getA() { return a; }
    double getB() { return b; }
    double getPole()
    {
        return a * b;
    }
    string info()
    {
        stringstream s;
        s << Punkt::info() << " a=" << a << " b=" << b << " pole=" << getPole();
        return s.str();
    }
};
//---------------------------------------------------------------------------------------//

class Prostopadloscian : public Prostokat
{
protected:
    double z;
    double h;

public:
    Prostopadloscian() : Prostokat(), z(0), h(0) {}
    Prostopadloscian(double X, double Y, double Z, double A, double B, double H)
        : Prostokat(X, Y, A, B), z(Z), h(H) {}
    double getPole()
    {
        return 2 * Prostokat::getPole() + 2 * a * h + 2 * b * h;
    }
    double getObjetosc()
    {
        return Prostokat::getPole() * h;
    }
};
double main()
{
    Punkt *p1 = new Punkt(20, 30);
    cout << p1->info();
    delete p1;
    return 0;
}
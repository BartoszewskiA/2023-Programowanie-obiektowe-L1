#include <iostream>

using namespace std;

class Figura
{
public:
    double virtual getPole() = 0;
    double virtual getObwod() = 0;
};

class Kolo : public Figura
{
protected:
    double r;

public:
    Kolo(double R) : r(R) {}
    double getPole() { return 3.14 * r * r; }
    double getObwod() { return 2 * 3.14 * r; }
};

class Kwadrat : public Figura
{
protected:
    double a;

public:
    Kwadrat(double A) : a(A) {}
    double getPole() { return a * a; }
    double getObwod() { return 4 * a; }
};

class Prostokat : public Figura
{
protected:
    double a;
    double b;

public:
    Prostokat(double A, double B) : a(A), b(B) {}
    double getPole() { return a * b; }
    double getObwod() { return 2 * a + 2 * b; }
};
// tak nie dzila!
Figura *tab[] = {new Kolo(20),
                 new Kwadrat(30),
                 new Prostokat(10, 30),
                 new Kwadrat(50)};
int main()
{
    for (int i = 0; i < 4; i++)
        cout << tab[i]->getPole() << " " << tab[i]->getObwod() << endl;
    
    for (int i = 0; i < 4; i++)
        delete tab[i];

    return 0;
}
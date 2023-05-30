#include <iostream>

using namespace std;

class Lz
{
private:
    double a;
    double b;

public:
    Lz(double cz_rzeczywista, double cz_urojona) : a(cz_rzeczywista), b(cz_urojona) {}
    Lz operator-(Lz l2)
    {
        Lz wynik(this->a - l2.a, this->b - l2.b);
        return wynik;
    }
    Lz operator*(double s)
    {
        // double a = l1.a * s;
        // double b = l1.b * s;
        // return Lz(a, b);
        return Lz(a * s, b * s);
    }

    friend ostream &operator<<(ostream &str, Lz liczba);
    friend Lz operator+(Lz l1, Lz l2);
    // friend Lz operator*(Lz l1, double s);
    friend Lz operator*(double s, Lz l2);
    // friend Lz operator-(Lz l1, Lz l2);
};

ostream &operator<<(ostream &str, Lz liczba)
{
    if (liczba.a == 0 && liczba.b == 0)
        cout << "0";
    if (liczba.a != 0)
        str << liczba.a;
    if (liczba.a != 0 && liczba.b > 0)
        str << "+";
    if (liczba.b != 0)
        str << liczba.b << "i";
    return str;
}

Lz operator+(Lz l1, Lz l2)
{
    double a = l1.a + l2.a;
    double b = l1.b + l2.b;
    Lz wynik(a, b);
    return wynik;
}

// Lz operator-(Lz l1, Lz l2)
// {
//     double a = l1.a - l2.a;
//     double b = l1.b - l2.b;
//     Lz wynik(a, b);
//     return wynik;
// }

// Lz operator*(Lz l1, double s)
// {
//     // double a = l1.a * s;
//     // double b = l1.b * s;
//     // return Lz(a, b);
//     return Lz(l1.a * s, l1.b * s);
// }

Lz operator*(double s, Lz l2);
{
    // double a = l1.a * s;
    // double b = l1.b * s;
    // return Lz(a, b);
    return Lz(s * l2.a, s * l2.b);
}

Lz tab[9] = {Lz(10, 20), Lz(-10, 20), Lz(10, -20), Lz(-10, -20),
             Lz(0, 20), Lz(0, -20), Lz(10, 0), Lz(-10, 0), Lz(0, 0)};

int main()
{
    // for (int i = 0; i < 9; i++)
    //     cout << tab[i] << endl;
    Lz liczba1(10, -45);
    Lz liczba2(-5, 30);
    // Lz wynik = liczba1 - liczba2;
    // cout << liczba1 << " + " << liczba2 << " = " << wynik;
    // cout << liczba1 << " - " << liczba2 << " = " << liczba1 - liczba2;

    Lz wynik = 3 * liczba1;
    cout << wynik;
    return 0;
}
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
    friend istream &operator>>(istream &str, Lz &ob);
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

Lz operator*(double s, Lz l2)
{
    // double a = l1.a * s;
    // double b = l1.b * s;
    // return Lz(a, b);
    return Lz(s * l2.a, s * l2.b);
}

istream &operator>>(istream &str, Lz &ob)
{
    string s;
    double a = 0;
    double b = 0;
    str >> s;
    int poz_i = s.find('i');
    if (poz_i < 0) // nie ma czesci urojonej
    {
        a = atof(s.c_str());
    }
    else // liczba ma czesc urojona
    {
        s = s.substr(0, s.length() - 1); // usuwam litere "i"
        int poz_plus = s.find('+');
        int poz_minus = s.find('-');
        int poz_2_min = s.find('-', 1);
        if (poz_plus <= 0 && poz_minus <= 0 && poz_2_min < 0) // jest tylko czesc urojona
        {
            b = atof(s.c_str());
        }
        else // obie czesci
        {
            if (poz_plus > 0) // a+bi lub -a+bi
            {
                a = atof(s.substr(0, poz_plus).c_str());
                b = atof(s.substr(poz_plus, s.length() - poz_plus).c_str());
            }
            else if(poz_minus >0) //a-bi
            {
                a = atof(s.substr(0, poz_minus).c_str());
                b = atof(s.substr(poz_minus, s.length() - poz_minus).c_str());
            }
            else //-a-bi
            {
                a = atof(s.substr(0, poz_2_min).c_str());
                b = atof(s.substr(poz_2_min, s.length() - poz_2_min).c_str());
            }
        }
    }

    ob.a = a;
    ob.b = b;
    return str;
}

Lz tab[9] = {Lz(10, 20), Lz(-10, 20), Lz(10, -20), Lz(-10, -20),
             Lz(0, 20), Lz(0, -20), Lz(10, 0), Lz(-10, 0), Lz(0, 0)};

int main()
{
    // for (int i = 0; i < 9; i++)
    //     cout << tab[i] << endl;
    Lz test(101, 101);
    Lz l2(20, -10);
    cout << "podaj liczbe zespolona: ";
    cin >> test;
    cout << "podales: " << test << endl;
    test = test + l2;
    cout << "wynik= " << test;
    return 0;
}
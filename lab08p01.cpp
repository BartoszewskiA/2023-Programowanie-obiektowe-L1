#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class RGB
{
private:
    int R;
    int G;
    int B;

public:
    RGB() : R(255), G(255), B(255)
    {
        // cout << "zadziala konstruktor RGB bez parametrow\n";
    }
    RGB(int r, int g, int b) : R(r), G(g), B(b)
    {
        cout << "zadziala konstruktor RGB z parametrami\n";
    }
    ~RGB()
    {
        cout << "zadziala destruktor RGB\n";
    }
    string toString()
    {
        stringstream s;
        s << "R=" << R << " G=" << G << " B=" << B;
        return s.str();
    }
    friend RGB dodaj(RGB &k1, RGB &k2);
    friend RGB *dodaj(RGB *k1, RGB *k2);
    friend RGB wzmoc(RGB &k, double w);
};

RGB dodaj(RGB &k1, RGB &k2)
{
    int r = k1.R + k2.R;
    int g = k1.G + k2.G;
    int b = k1.B + k2.B;
    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;
    RGB wynik(r, g, b);
    return wynik;
}

RGB wzmoc(RGB &k, double w)
{
    int r = k.R + w*k.R;
    int g = k.G + w * k.G;
    int b = k.B + w * k.B;
    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;
    RGB wynik(r, g, b);
    return wynik;
}

RGB *dodaj(RGB *k1, RGB *k2)
{
    int r = k1->R + k2->R;
    int g = k1->G + k2->G;
    int b = k1->B + k2->B;
    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;
    RGB *wynik = new RGB(r, g, b);
    return wynik;
}

int main()
{
    // RGB kolorA(200, 30, 50), kolorB(100, 255, 0);
    // RGB wynik = dodaj(kolorA, kolorB);
    // cout << wynik.toString() << endl;

    RGB *kolorA = new RGB(200, 30, 60);
    RGB *kolorB = new RGB(200, 100, 0);

    RGB *wynik = dodaj(kolorA, kolorB);
    cout << wynik->toString()<<endl;
    delete kolorA;
    delete kolorB;
    delete wynik;
    return 0;
}
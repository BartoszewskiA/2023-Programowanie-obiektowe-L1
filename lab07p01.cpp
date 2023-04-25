#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

class RGB
{
protected:
    int R;
    int G;
    int B;

public:
    RGB() : R(255), G(255), B(255)
    {
        cout << "zadziala konstruktor RGB bez parametrow\n";
    }
    RGB(int r, int g, int b) : R(r), G(g), B(b)
    {
        cout << "zadziala konstruktor RGB z parametrami\n";
    }
    void setR(int R) { this->R = R; }
    void setG(int G) { this->G = G; }
    void setB(int B) { this->B = B; }
    int getR() { return R; }
    int getG() { return G; }
    int getB() { return B; }
    int getJasnosc() { return round((R + G + B) / 3.0); }
    string toString()
    {
        stringstream s;
        s << "R=" << R << " G=" << G << " B=" << B;
        return s.str();
    }
};

//---------------------------------------------------------------

class aRGB : public RGB
{
protected:
    int A;

public:
    aRGB() : RGB(), A(255)
    {
        cout << "zadziala konstruktor aRGB bez parametrow\n";
    }
    aRGB(int a, int r, int g, int b) : RGB(r, g, b), A(a)
    {
        cout << "zadziala konstruktor aRGB z parametrami\n";
    }

    void setA(int A) { this->A = A; }
    int getA() { return A; }
    string toString()
    {
        stringstream s;
        // s << "A=" << A << " R=" << R << " G=" << G << " B=" << B;
        s << "A=" << A << " " << RGB::toString();
        return s.str();
    }
};

RGB kolory_podstawowe[] = {
    RGB(255, 0, 0),
    RGB(0, 255, 0),
    RGB(0, 0, 255)};

int main()
{
    // RGB piksek01(30,40,60);
    // cout << piksek01.toString();

    // aRGB piksel02(100, 30, 50, 80);
    // cout << piksel02.toString();
    // cout << " A=" << piksel02.getA();

    return 0;
}
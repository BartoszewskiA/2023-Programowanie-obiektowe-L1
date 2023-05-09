#include <iostream>

using namespace std;

class liczba
{
private:
    int x;
    static int ile;
    static int suma;

public:
    liczba(int dana) : x(dana)
    {
        ile++;
        suma += x;
    }
    ~liczba()
    {
        ile--;
        suma -= x;
    }
    void setX(int x)
    {
        suma -= x;
        this->x = x;
        suma += x;
    }
    int getX() { return x; }
    int getIle() { return ile; }
    int getSuma() { return suma; }
    double getSrednia() { return (double)suma / ile; }
};

int liczba::ile = 0;
int liczba::suma = 0;

int main()
{

    return 0;
}
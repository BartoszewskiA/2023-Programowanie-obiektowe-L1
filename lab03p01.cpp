#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const int ILE = 100;

class punkt
{
private:
    double x;
    double y;

public:
    void setX(double px) { x = px; }
    void setY(double py) { y = py; }
    double getX() { return x; }
    double getY() { return y; }
    double getR()
    {
        return sqrt(x * x + y * y);
    }
    void losuj(int a, int b); // losowanie z przedzialu <a;b>
};

void punkt::losuj(int a, int b)
{
    x = rand() % (b - a + 1) + a;
    y = rand() % (b - a + 1) + a;
}

int main()
{
    srand(time(NULL));
    punkt tab[ILE];
    // for (int i = 0; i < ILE; i++)
    // {
    //     tab[i].setX(rand() % 201 - 100);
    //     tab[i].setY(rand() % 201 - 100);
    // }
    for (int i = 0; i < ILE; i++)
        tab[i].losuj(-100, 100);

    for (int i = 0; i < ILE; i++)
        cout << "(" << tab[i].getX() << ";" << tab[i].getY() << ") ";

    double r_min = tab[0].getR();
    double r_max = tab[0].getR();

    for (int i = 0; i < ILE; i++)
    {
        if (tab[i].getR() < r_min)
            r_min = tab[i].getR();
        if (tab[i].getR() > r_max)
            r_max = tab[i].getR();
    }
    cout << endl
         << "minimalna odleglosc od srodka ukladu wspolrzednych: " << r_min
         << "\nmaksymalna odleglosc od srodka ukladu wspolrzednych: " << r_max;

    return 0;
}
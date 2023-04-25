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
    punkt(int a, int b)
    {
        x = rand() % (b - a + 1) + a;
        y = rand() % (b - a + 1) + a;
    }
    void setX(double px) { x = px; }
    void setY(double py) { y = py; }
    double getX() { return x; }
    double getY() { return y; }
    double getR()
    {
        return sqrt(x * x + y * y);
    }
};

int main()
{
    srand(time(NULL));
    punkt *tab[ILE];
    for (int i = 0; i < ILE; i++)
    {
        tab[i] = new punkt(-100, 100);
    }

    for (int i = 0; i < ILE; i++)
        cout << "(" << tab[i]->getX() << ";" << tab[i]->getY() << ") ";
    return 0;
}
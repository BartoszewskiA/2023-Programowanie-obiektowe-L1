#include <iostream>
#include <ctime>

using namespace std;

class Random
{
public:
    Random() { srand(time(NULL)); }
    int nextInt() { return rand(); }
    int nextInt(int b) { return rand() % b; }
    int nextInt(int a, int b) { return rand() % (b - a) + a; }
    double nextDouble() { return rand() % 10000 / 10000.0; }
    bool nextBool()
    {
        if (rand() % 2 == 0)
            return false;
        else
            return true;
    }
};

int main()
{
    Random random01;
    for (int i = 0; i < 50; i++)
    {
        cout << random01.nextDouble() << " ";
    }
    return 0;
}
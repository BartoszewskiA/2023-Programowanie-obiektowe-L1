#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <string>

using namespace std;

class czas_pracy
{
private:
public:
    czas_pracy()
    {
        dopisz_czas();
    }
    ~czas_pracy()
    {
        dopisz_czas();
        cout << endl
             << "pracowales juz: " << zlicz_czas_pracy() << endl;
    }
    void dopisz_czas()
    {
        int czas = time(NULL);
        fstream plik;
        plik.open("log.txt", ios::app);
        plik << czas;
        plik << endl;
        plik.close();
    }
    int zlicz_czas_pracy()
    {
        fstream plik;
        plik.open("log.txt", ios::in);
        string s1, s2;
        int p, k, odstep, czas_calkoity = 0;
        if (!plik.good())
            return 0;
        while (!plik.eof())
        {
            getline(plik, s1);
            getline(plik, s2);
            if (s1.length() > 0 && s2.length() > 0)
            {
                p = atoi(s1.c_str());
                k = atoi(s2.c_str());
                odstep = k - p;
                // cout << s1 << " " << s2 << " " << odstep << endl;
                czas_calkoity += odstep;
            }
        }
        plik.close();
        return czas_calkoity;
    }
};

int main()
{
    czas_pracy p1;
    // p1.zlicz_czas_pracy();
    cout << "Nacisnij dowolny klawisz ";
    getch();
    return 0;
}
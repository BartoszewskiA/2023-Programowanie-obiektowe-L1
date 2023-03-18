#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct osoba
{
    int id;
    string imie;
    string nazwisko;
};

osoba *baza[1000];
int n = 0; // liczba rekordow

void odczyt_pliku();
void dodaj_rekord();
void wyswietl_baze();
void zapisz_do_pliku();
void usun();

int main()
{
    int wybor = -1;
    while (true)
    {
        cout << "1 - odczytaj z pliku" << endl
             << "2 - dodaj rekord" << endl
             << "3 - wyswietl baze " << endl
             << "4 - zapisz do pliku" << endl
             << "5 - usun baze" << endl
             << "0 - wyjdz z programu" << endl
             << "WYBOR: ";
        cin >> wybor;
        cin.clear();
        cin.ignore(10, '\n');
        switch (wybor)
        {
        case 1:
            odczyt_pliku();
            break;
        case 2:
            dodaj_rekord();
            break;
        case 3:
            wyswietl_baze();
            break;
        case 4:
            zapisz_do_pliku();
            break;
        case 5:
            usun();
            break;
        case 0:
            usun();
            return 0;
            break;
        default:
            cout << "Nie ma takiej opcji";
        }
    }

    return 0;
}

void odczyt_pliku()
{
    fstream plik;
    plik.open("baza.txt", ios::in);
    string s, im, nazw;
    getline(plik, s);
    int ile = atoi(s.c_str());
    for (int i = 0; i < ile; i++)
    {
        getline(plik, im);
        getline(plik, nazw);
        baza[n] = new osoba;
        baza[n]->imie = im;
        baza[n]->nazwisko = nazw;
        baza[n]->id = n + 1;
        n++;
    }
    plik.close();
}
void dodaj_rekord()
{
    string im, nazw;
    system("cls");
    cout << "Podaj imie: ";
    getline(cin, im);
    cout << "Podaj nazwisko: ";
    getline(cin, nazw);
    baza[n] = new osoba;
    baza[n]->imie = im;
    baza[n]->nazwisko = nazw;
    baza[n]->id = n + 1;
    n++;
}
void wyswietl_baze()
{
    system("cls");
    for (int i = 0; i < n; i++)
    {
        cout << "\n------------------------------------------\n"
             << "ID:\t\t" << baza[i]->id << endl
             << "Imie:\t\t" << baza[i]->imie << endl
             << "Nazwisko:\t" << baza[i]->nazwisko
             << "\n------------------------------------------\n";
    }
}
void zapisz_do_pliku()
{
    fstream plik;
    plik.open("baza.txt", ios::out);
    plik << n << endl;
    for (int i = 0; i < n; i++)
    {
        plik << baza[i]->imie << endl;
        plik << baza[i]->nazwisko << endl;
    }
    plik.close();
}
void usun()
{
    for (int i = 0; i < n; i++)
        delete baza[i];
    n = 0;
}
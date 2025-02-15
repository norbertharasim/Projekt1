
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include<chrono>
#include<cstring>

using namespace std;
using namespace chrono;

const int rozmiar_tablicy = 5;

void wyswietlanie_gracza(char imie_gracza[50]) {
    cout << "\t" << imie_gracza << endl;
}
void wyswietlanie_bota(char imie_bota[50]) {
    cout << endl << "\t" << imie_bota << endl;
}
void plansza(char tablica[rozmiar_tablicy][rozmiar_tablicy]) { //jednorazowa inicjalizacja i przypisanie 4 wierszowi znaku pionka c i 1 wierszowi znaku pionka b
    char c = 'c';
    char b = 'b';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tablica[i][j] = 0;
        
}
    
}
    for (int i = 4; i > 0; i--) {
        tablica[4][i] = c;
    
}
    for (int i = 1; i <= 4; i++) {
        tablica[1][i] = b;
    
}
}
void wyswietlenie(char tablica[rozmiar_tablicy][rozmiar_tablicy], char imie_gracza[50], char imie_bota[50], char abcd[5]) { //rysowania planszy i wyuswietlenie kto czym gra

    wyswietlanie_gracza(imie_gracza);
    cout << " " << char(201) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(187) << "\n";
    for (int i = 4; i > 0; i--) {
        for (int j = 0; j <= 4; j++) {
            if (j == 0 && i > 0)
                cout << i << char(186);
            else if (i > 0 && tablica[i][j] != 0)
            {
                cout << " " << tablica[i][j] << " " << char(186);
            
}
            else if (i > 0 && tablica[i][j] == 0)
                cout << "   " << char(186);
        
}
        cout << endl;
        if (i > 1)
            cout << " " << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << endl;

    
}
    cout << " " << char(200) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(188) << endl;
    for (int i = 0; i <= 4; i++)
        cout << "   " << abcd[i];
    wyswietlanie_bota(imie_bota);
    cout << endl << imie_gracza << " GRA PIONAMI c " << endl;
    cout << imie_bota << " GRA PIONAMI b " << endl << endl;
}

void ile_pionk(char znak, int& ile_pionkow, char tablica[rozmiar_tablicy][rozmiar_tablicy]) { //funkcja liczaca ile jest pionkow graczy
    ile_pionkow = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (tablica[i][j] == znak) {
                ile_pionkow++;
            
}
        
}
    
}
}
void opcje_gracza(char tablica[rozmiar_tablicy][rozmiar_tablicy], char imie_gracza[50]) { //to tylko pokazuje dostepne pionki zeby program byl przyjemniejszy dla uzytkownika

    cout << "RUCH GRACZA: " << imie_gracza << " (PIONKI CZARNE)" << endl << endl;
    cout << "Legalny jest ruch pionkiem o indeksie(ksach)" << endl;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (tablica[i][j] == 'c') {
                if (j == 1) {
                    cout << "A" << i << " ";
                
}
                else if (j == 2) {
                    cout << "B" << i << " ";
                
}
                else if (j == 3) {
                    cout << "C" << i << " ";
                
}
                else if (j == 4) {
                    cout << "D" << i << " ";
                
}
            
}
        
}
    
}
}

void wybor_pionka(char tablica[rozmiar_tablicy][rozmiar_tablicy], char imie_gracza[50], int& kolumna, int& w) { //wybor pionka przez gracza z przeliczeniem kodu asci

    opcje_gracza(tablica, imie_gracza);
    cout << endl;

    w = 0;
    char k = 0;
    kolumna = 0;
    char wybor[4] = { 0 
};

    bool czy_podal_dobry_pionek = false;
    while (czy_podal_dobry_pionek == false) {
        cout << "Podaj ktorym pionkiem chcesz ruszyc: ";
        cin >> wybor;
        k = wybor[0];
        w = wybor[1] - '0';
        kolumna = k - 'A' + 1;
        if ((tablica[w][kolumna] == 'c') &&
            ((tablica[w + 1][kolumna] == 0 && (w + 1) <= 4) ||
                (tablica[w - 1][kolumna] == 0 && w - 1 >= 1) ||
                (tablica[w][kolumna + 1] == 0 && kolumna + 1 <= 4) ||
                (tablica[w][kolumna - 1] == 0 && kolumna - 1 >= 1) ||
                (kolumna + 3 <= 4 && tablica[w][kolumna + 3] == 'b' && tablica[w][kolumna + 2] == 0 && tablica[w][kolumna + 1] == 'c')
                || (kolumna - 3 >= 1 && tablica[w][kolumna - 3] == 'b' && tablica[w][kolumna - 2] == 0 && tablica[w][kolumna - 1] == 'c')
                || (w + 3 <= 4 && tablica[w + 3][kolumna] == 'b' && tablica[w + 2][kolumna] == 0 && tablica[w + 1][kolumna] == 'c')
                || (w - 3 >= 1 && tablica[w - 3][kolumna] == 'b' && tablica[w - 2][kolumna] == 0 && tablica[w - 1][kolumna] == 'c')))
        {
            czy_podal_dobry_pionek = true;
        
}
        else
            cout << "PODALES NIEPOPRAWNY PIONEK LUB PIONEK KTORY NIE MA DOSTEPNYCH RUCHOW!" << endl;
    
}
    cout << " GRACZ WYBRAL PIONEK " << k << wybor[1] << endl;
}
void ruch_gracza(char tablica[rozmiar_tablicy][rozmiar_tablicy], char imie_gracza[50], double& czas_gracza) { //funkcja pyta gracza gdzie ruszyc i sprawdza czy ten ruch jest zgodny

    int kolumna = 0;
    int w = 0;

    double start, koniec, czas;
    start = time(NULL);
    wybor_pionka(tablica, imie_gracza, kolumna, w);

    int wiersz = 0;
    char kolumna_ruchu = 0;
    int kolumna_liczba = 0;

    while (true) {
        char wiersz_walidujacy[5];
        while (true) {

            cout << "Podaj wiersz na ktory chcesz ruszyc tym pionkiem(1-4): ";
            cin >> wiersz_walidujacy;
            if (strlen(wiersz_walidujacy) == 1 && wiersz_walidujacy[0] >= '1' && wiersz_walidujacy[0] <= '4') {
                wiersz = wiersz_walidujacy[0] - '0';
                break;
            
}
            else if (wiersz != 1 && wiersz != 2 && wiersz != 3 && wiersz != 4) {
                cout << "PODALES NIEPOPRAWNY WIERSZ SPROBUJ PONOWNIE " << endl;
            
}
        
}

        while (true) {
            cout << "Podaj kolumne na ktora chcesz ruszyc tym pionkiem(A-D): ";
            cin >> kolumna_ruchu;
            if (kolumna_ruchu >= 'A' && kolumna_ruchu <= 'D') {
                break;
            
}
            else {
                cout << "PODALES NIEPOPRAWNA KOLUMNE SPROBUJ PONOWNIE " << endl;
            
}
        
}

        kolumna_liczba = kolumna_ruchu - 'A' + 1;

        if (((kolumna_liczba == kolumna + 1
            || kolumna_liczba == kolumna - 1) && (wiersz == w)
            || (kolumna_liczba == kolumna) && (wiersz == w + 1
                || wiersz == w - 1)) && tablica[wiersz][kolumna_liczba] == 0
            ) {

            tablica[w][kolumna] = 0;
            tablica[wiersz][kolumna_liczba] = 'c';
            break;
        
}
        else if (kolumna_liczba == kolumna + 3 && tablica[w][kolumna + 1] == 'c' && tablica[w][kolumna + 2] == 0 && tablica[wiersz][kolumna_liczba] == 'b')
        {
            tablica[w][kolumna] = 0;
            tablica[wiersz][kolumna_liczba] = 'c';
            break;
        
}
        else if (wiersz == w + 3 && tablica[w + 1][kolumna] == 'c' && tablica[w + 2][kolumna] == 0 && tablica[wiersz][kolumna_liczba] == 'b')
        {
            tablica[w][kolumna] = 0;
            tablica[wiersz][kolumna_liczba] = 'c';
            break;
        
}

        else if (wiersz == w - 3 && tablica[w - 1][kolumna] == 'c' && tablica[w - 2][kolumna] == 0 && tablica[wiersz][kolumna_liczba] == 'b')
        {
            tablica[w][kolumna] = 0;
            tablica[wiersz][kolumna_liczba] = 'c';
            break;
        
}
        else if (kolumna_liczba == kolumna - 3 && tablica[w][kolumna - 1] == 'c' && tablica[w][kolumna - 2] == 0 && tablica[wiersz][kolumna_liczba] == 'b')
        {
            tablica[w][kolumna] = 0;
            tablica[wiersz][kolumna_liczba] = 'c';
            break;
        
}
        else
        {
            cout << "PODALES RUCH NIEZGDONY Z ZASADMI " << endl;
        
}
    
}

    koniec = time(NULL);

    czas = koniec - start;
    cout << czas << " TYLE CZASU MINELO " << endl;
    czas_gracza = czas_gracza - czas;
    cout << "TYLE CZASU POZOSTALO NA KOLEJNE RUCHY GRACZOWI " << czas_gracza << endl;


}

void pionek_bota(int& w_pionka, int& k_pionka, char tablica[rozmiar_tablicy][rozmiar_tablicy]) { //losuje pionka ktorym bedzie ruszac bot 10000 razy dla pewnosci

    w_pionka = 0;
    k_pionka = 0;
    char b = 'b';
    int ile_pionkow = 0;
    ile_pionk(b, ile_pionkow, tablica);
    if (ile_pionkow == 0)
    {
        cout << "BRAK DOSTEPNYCH PIONKOW BOTA " << endl;
        return;
    
}

    int proby_max = 10000;

    bool odpowiedni_pionek = false;

    while (odpowiedni_pionek == false && proby_max > 0) {
        w_pionka = rand() % 4 + 1;
        k_pionka = rand() % 4 + 1;

        if (tablica[w_pionka][k_pionka] == 'b') {
            odpowiedni_pionek = true;
        
}
        proby_max--;
    
}
    if (odpowiedni_pionek == false) {
        cout << "NIE ZNALEZIONO PIONKA DLA BOTA " << endl;
        return;
    
}
}

void czy_mozna_zbic(char tablica[rozmiar_tablicy][rozmiar_tablicy], bool& czy_mozna_bic) { //sprawdzenie czy bot moze bic jesli tak to prioritetowo bije
    int w_pionka = 0;
    int k_pionka = 0;

    int k = 0;
    int w = 0;

    czy_mozna_bic = false;
    int proby_max = 2000;

    char b = 'b';


    while (czy_mozna_bic == false && proby_max > 0) {
        pionek_bota(w_pionka, k_pionka, tablica);
        k = rand() % 4 + 1;
        w = rand() % 4 + 1;
        if ((k == k_pionka + 3 && tablica[w][k_pionka + 1] == 'b' && tablica[w][k_pionka + 2] == 0 && tablica[w][k] == 'c' && k_pionka + 3 <= 4) && w == w_pionka)
        {
            tablica[w_pionka][k_pionka] = 0;
            tablica[w][k] = 'b';
            czy_mozna_bic = true;
            break;
        
}
        else if ((w == w_pionka + 3 && tablica[w_pionka + 1][k] == 'b' && tablica[w_pionka + 2][k] == 0 && tablica[w][k] == 'c' && w_pionka + 3 <= 4) && k == k_pionka)
        {
            tablica[w_pionka][k_pionka] = 0;
            tablica[w][k] = 'b';
            czy_mozna_bic = true;
            break;
        
}

        else if ((w == w_pionka - 3 && tablica[w_pionka - 1][k] == 'b' && tablica[w_pionka - 2][k] == 0 && tablica[w][k] == 'c' && w_pionka - 3 >= 1) && k == k_pionka)
        {
            tablica[w_pionka][k_pionka] = 0;
            tablica[w][k] = 'b';
            czy_mozna_bic = true;
            break;
        
}

        else if ((k == k_pionka - 3 && tablica[w][k_pionka - 1] == 'b' && tablica[w][k_pionka - 2] == 0 && tablica[w][k] == 'c' && k_pionka - 3 >= 1) && w == w_pionka)
        {
            tablica[w_pionka][k_pionka] = 0;
            tablica[w][k] = 'b';
            czy_mozna_bic = true;
            break;
        
}
        else
            proby_max--;
    
}
}
void ruch_bota(char tablica[rozmiar_tablicy][rozmiar_tablicy]) { //tutaj generuje ruch pionkiem jesli nie ma bicia dostepnego i sprawdza czy ruch jest zgodny

    int w_pionka = 0;
    int k_pionka = 0;

    bool czy_mozna_bic = false;

    srand(time(NULL));
    czy_mozna_zbic(tablica, czy_mozna_bic);
    if (czy_mozna_bic == true) {
        cout << "Bot zbil pionek" << endl;
        return;
    
}

    //pionek_bota(w_pionka, k_pionka, tablica);
    int k = 0;
    int w = 0;

    bool czy_znaleziono_miejsce = false;
    int proby_max = 1000000;
    while (czy_znaleziono_miejsce == false && proby_max > 0) {
        pionek_bota(w_pionka, k_pionka, tablica);
        k = rand() % 4 + 1;
        w = rand() % 4 + 1;
        if ((
            ((k == k_pionka + 1 || k == k_pionka - 1) && (w == w_pionka)) ||
            ((k == k_pionka) && (w == w_pionka + 1 || w == w_pionka - 1))) &&
            tablica[w][k] == 0) {
            czy_znaleziono_miejsce = true;
            tablica[w_pionka][k_pionka] = 0;
            tablica[w][k] = 'b';

        
}
        proby_max--;
    
}
    if (!czy_znaleziono_miejsce) {
        cout << "BOT NIE ZNALAZL RUCHU PO 1000000 PROBACH! " << endl;
    
}
}
int prototyp_ruchu_bota(char tablica[5][5], char imie_bota[50], char abcd[5], char imie_gracza[50], double& czas_bota) { //tutaj sprawdza ile czasu to zajelo

    cout << "RUCH GRACZA: " << imie_bota << " PIONKI BIALE" << endl;

    auto start = high_resolution_clock::now();

    ruch_bota(tablica);
    wyswietlenie(tablica, imie_gracza, imie_bota, abcd);

    auto koniec = high_resolution_clock::now();

    auto czas_w_mikrosekundach = duration_cast<microseconds>(koniec - start).count();
    double czas_w_sekundach = czas_w_mikrosekundach / 1000000.0;

    cout << czas_w_sekundach << " RUCH ZAJAL TYLE SEKUND" << endl;
    czas_bota = czas_bota - czas_w_sekundach;

    cout << "TYLE CZASU POZOSTALO NA KOLEJNE RUCHY BOTOWI " << czas_bota << endl;
    return 1;
}

bool czy_gracz_ma_ruchy(char tablica[rozmiar_tablicy][rozmiar_tablicy]) { //tutaj sprawdza czy gracz ma jakies ruchy zeby sprawdzac czy przypadkiem nie ma konca gry

    int ile_pionkow = 0;
    char c = 'c';
    ile_pionk(c, ile_pionkow, tablica);
    if (ile_pionkow != 0) {
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                if (tablica[i][j] == 'c') {
                    if ((j + 1 <= rozmiar_tablicy && tablica[i][j + 1] == 0)
                        || (j - 1 >= 1 && tablica[i][j - 1] == 0)
                        || (i + 1 <= rozmiar_tablicy && tablica[i + 1][j] == 0)
                        || (i - 1 >= 1 && tablica[i - 1][j] == 0)
                        || (j + 3 <= 4 && tablica[i][j + 3] == 'b' && tablica[i][j + 2] == 0 && tablica[i][j + 1] == 'c')
                        || (j - 3 >= 1 && tablica[i][j - 3] == 'b' && tablica[i][j - 2] == 0 && tablica[i][j - 1] == 'c')
                        || (i + 3 <= 4 && tablica[i + 3][j] == 'b' && tablica[i + 2][j] == 0 && tablica[i + 1][j] == 'c')
                        || (i - 3 >= 1 && tablica[i - 3][j] == 'b' && tablica[i - 2][j] == 0 && tablica[i - 1][j] == 'c')
                        )
                    {
                        return true;
                    
}
                
}
            
}
        
}
    
}

    else
        return false;
    return false;
}
bool czy_bot_ma_ruchy(char tablica[rozmiar_tablicy][rozmiar_tablicy]) {// tutaj tak samo sprawdza z botem

    int ile_pionkow = 0;
    char b = 'b';
    ile_pionk(b, ile_pionkow, tablica);

    if (ile_pionkow == 0) {
        cout << "BOTOWI SKONCYZYLY SIE PIONKI, KONIEC GRY " << endl;
        return false;
    
}

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (tablica[i][j] == 'b') {
                if (((j + 1) <= 4 && tablica[i][j + 1] == 0)
                    || ((j - 1) >= 1 && tablica[i][j - 1] == 0)
                    || ((i + 1) <= 4 && tablica[i + 1][j] == 0)
                    || ((i - 1) >= 1 && tablica[i - 1][j] == 0)
                    || ((j + 3) <= 4 && tablica[i][j + 3] == 'c' && tablica[i][j + 2] == 0 && tablica[i][j + 1] == 'b')
                    || ((j - 3) >= 1 && tablica[i][j - 3] == 'c' && tablica[i][j - 2] == 0 && tablica[i][j - 1] == 'b')
                    || ((i + 3) <= 4 && tablica[i + 3][j] == 'c' && tablica[i + 2][j] == 0 && tablica[i + 1][j] == 'b')
                    || ((i - 3) >= 1 && tablica[i - 3][j] == 'c' && tablica[i - 2][j] == 0 && tablica[i - 1][j] == 'b')
                    )
                {

                    return true;
                
}
            
}
        
}

    
}
    cout << "BOT NIE MA DOSTEPNCYH RUCHOW! KONIEC " << endl;
    return false;
}

void rozgrywka(char imie_gracza[50], char tablica[5][5], char abcd[5], char imie_bota[50], double czas) { // tutaj jest po kolei rozgrywka najpierw sprawdzenie czy nie ma konca potem bot i sprawdzenie potem gracz i sprawdzenie i tak petli

    double czas_gracza = 0;
    double czas_bota = 0;
    czas_bota = czas_gracza = czas;
    wyswietlenie(tablica, imie_gracza, imie_bota, abcd);

    while (true) {
        if (!czy_bot_ma_ruchy(tablica))
        {
            cout << " WYGRAL GRACZ !!! ";
            break;
        
}
        if (!czy_gracz_ma_ruchy(tablica))
        {
            cout << "WYGRAL BOT !!!";
            break;
        
}
        prototyp_ruchu_bota(tablica, imie_bota, abcd, imie_gracza, czas_bota);

        if (!czy_gracz_ma_ruchy(tablica))
        {
            cout << " WYGRAL BOT !!! ";
            break;
        
}
        if (czas_bota <= 0)
        {
            cout << "WYGRAL GRACZ BO BOTOWI SKONCZYL SIE CZAS !!!" << endl;
            break;
        
}

        ruch_gracza(tablica, imie_gracza, czas_gracza);
        wyswietlenie(tablica, imie_gracza, imie_bota, abcd);

        if (!czy_bot_ma_ruchy(tablica))
        {
            cout << " WYGRAL GRACZ";
            break;
        
}

        if (czas_gracza <= 0)
        {
            cout << "WYGRAL BOT BO GRACZOWI SKONCZYL SIE CZAS !!!" << endl;
            break;
        
}
    
}
}
int main() {
    char tablica[5][5];
    char abcd[5] = "ABCD";
    char wybor;
    char imie_gracza[50];
    char imie_bota[50];
    bool prawidlowe_wejscie = false;

    while (!prawidlowe_wejscie) {
        cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<
            char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);
        cout << endl;
        cout << char(186) << "\t\tGRA KONO  \t\t " << char(186) << endl;
        cout << char(186) << "  kliknij[s] aby rozpoczac rozgrywke \t " << char(186) << endl << char(186) << "   kliknij[e] aby oposcic program. \t " << char(186) << "\t\t\n" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<
            char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) <<
            char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
        cin >> wybor;

        switch (wybor) {
        case 's':
        {
            cout << "Podaj swoje imie: ";
            cin >> imie_gracza;

            cout << "Podaj imie przeciwnika: ";
            cin >> imie_bota;
            cout << endl;

            double czas;
            cout << "PODAJ ILE CZASU MAJA MIEC GRACZE ( W SEKUNDACH) : ";
            cin >> czas;
            if (czas <= 0) {
                cout << "CZAS NIE MOZE BYC UJEMNY ANI ZEROWY " << endl;
                break;
            
}
            plansza(tablica);
            rozgrywka(imie_gracza, tablica, abcd, imie_bota, czas);

            cout << endl;
            prawidlowe_wejscie = true;
            break;
        
}
        case 'e':
        {
            prawidlowe_wejscie = true;
            break;
        
}
        default:
            cout << "ZLY PRZYCISK SPROBUJ JESZCZE RAZ: " << endl;
            break;
        
}
    
}
    return 0;
}

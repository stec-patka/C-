#include <iostream>
#include <vector>

//Zadanie 1 - Funkcja minimum, maksimum
//Napisz szablon funkcji `minimum`, która znajduje najmniejszą wartość w tablicy (wektorze) i zwraca ją

template<typename T>
T minimum(std::vector<T>& tab){
T minimum = tab[0];
for(size_t i=0;i<tab.size();i++){
    if(minimum>tab[i]){
        minimum=tab[i];
    }
}
return minimum;
}

template<typename T>
T maks(std::vector<T>& tab){
T maks=tab[0];
for(size_t i=0; i<tab.size();i++){
    if(maks<tab[i]){
        maks=tab[i];
    }
}
return maks;
}

//Zadanie 2 - Funkcja szukaj_auta
//Obiekty klasy Auto posiadają trzy publiczne pola typu string: marka, model i kolor.
//Napisz funkcję szukaj auta() z trzema parametrami:
//pierwszym jest vector obiektów klasy Auto, drugim string
//a trzecim wskaźnik na pole składowe typu string klasy Auto.
//Funkcja ma wyszukać w wektorze pierwsze wystąpienie obiektu, który we wskazywanym polu zawiera podany string.
//Funkcja ma zwracać indeks znalezionego obiektu.

int szukaj_auta(std::vector<Auto>& Auta,std::string& watosc, std::string Auto::* pole){
for (size_t i=0;i<Auta.size();i++){
    if(Auta[i]. *pole==wartosc){
        return static_cast<int>(i);
    }
}
return -1;
}

//zadanie 3
//Dane są klasy Koło i Kwadrat, które posiadają publiczną metodę pole() zwracającą pole danej figury jako
//liczba rzeczywista typu double (klasy są już zdefiniowane łącznie z metodami pole).

//Zadaniem jest napisanie klasy Figura (będącej interfejsem), z której dziedziczą klasy Koło i Kwadrat.
//Klasa ma posiadać czysto abstrakcyjną metodę pole(), która jest nadpisywana w klasach pochodnych

class Figura{
    public:
virtual double pole()=0;
virtual ~Figura()=default;
};

//zadanie4 Napisz dwie funkcje.
//Pierwsza niech dostaje dwie liczby typu double i zwraca wynik dzielenia drugiej przez pierwszą.
//Jeśli pierwsza liczba wynosi zero, funkcja ma rzucić wyjątek std::runtime_error z komunikatem "Dzielenie przez zero".
//Druga funkcja ma nazywać się serwis i ma mieć takie same parametry jak pierwsza, ale nie ma nic zwracać.
//Ma wywołać pierwszą funkcję i wypisać jej wynik oraz obsłużyć rzucony wyjątek.
//Obsługa wyjątku ma polegać na wypisaniu komunikatu z obiektu wyjątku.

double dzielnie(double a, double b){
if (a==0){
    throw std::runtime_error("dzielenie przr zero");
}
else {
    return b/a;
}
}

void serwis(double a, double b){
try{
double wynik=dzielnie(0,4);
std::cout <<"wynik:"<<wynik<<std::endl;
}
catch(const std::runtime_error& e){
std::cout<<"blad: "<<e.what()<<std::endl;
}
}

//zadanie5
//Stwórz klasę Temperatura, która będzie posiadała pole prywatne stopnie typu double do przechowywania temperatury w skali Kelvina.
//W klasie stwórz konstruktor, który otrzymuje wartość double traktując jako temperatura w skali Celsjusza i konwertuje ją do Kelvinów zapisując po konwersji w prywatnym polu stopnie.
//Dodaj do klasy operator double, konwertujący obiekt Temperatura na wartość double będącą wartością temperatury w Celsjuszach.
//Dla przypomnienia: 0 K = -273,15ºC.
//Dla celów testowych dodaj do klasy metodę print, która wypisze na ekran wartość pola stopnie (samą wartość, bez żadnych dodatkowych tekstów).



class Temperatura{
    private:
    double stopnie;
    public:
        Temperatura(double C){
        stopnie=C+273.15;
        }

        operator double()const {
        return stopnie-273.15;
        }

        void print()const{
        std::cout<<stopnie<<std::endl;
        }
};


//Zadanie 1 - Klasa Transport i dziedziczenie
//Stwórz klasę Transport posiadającą metodę wypisz()  wypisującą komunikat "Jestem środkiem transportu".
//Następnie stwórz dwie klasy: Samochód i Statek dziedziczące z Transport. Klasa Samochód niech posiada metodę wypisz()
//wypisującą komunikat "Jestem samochodem" , a klasa Statek metodę wypisz()  wypisującą komunikat "Jestem statkiem". Jako czwartą stwórz klasę
//Amfibia dziedziczącą po klasach Samochód i Statek. Ta klasa nie ma posiadać "własnej" metody wypisz,
//jedynie dziedziczy ją po 'przodkach'. Na koniec napisz funkcję transport(), w której utwórz obiekt klasy Amfibia i za jego pomocą, używając
//jedynie metod wypisz() spowoduj wypisanie komunikatów (każdy w osobnej linii):    "Jestem samochodem", "Jestem statkiem", "Jestem środkiem transportu".

class Transport{
    public:
    void wypisz(){
        std::cout<<"Jestem środkiem transportu"<<std::endl;
    }
    virtual ~Transport() = default;
};
class Samochod: virtual public Transport{
    public:
    void wypisz()const {
        std::cout<<"Jestem samochodem"<<std::endl;
    }
};
class Statek: virtual public Transport{
    public:
    void wypisz()const {
        std::cout<<"Jestem statkiem"<<std::endl;
    }
};
class Amfibia:public Samochod, public Statek{
};

void transport(){
Amfibia obj;
obj.Samochod::wypisz();
obj.Statek::wypisz();
obj.Transport::wypisz();

}

//Zadanie 2 - Szablon klasy Stos
//Napisz szablon klasy Stos z metodą push() na wektorze

template<typename T>
class Stos
{
private:
    std::vector<T> tab;
public:
    void push(const T& element)
    {
        tab.push_back(element);
    }

};

Dana jest klasa, której niekompletna deklaracja znajduje się poniżej :
class Tablica {
    int *tab;
    int size;
public:
    Tablica (const std::initializerlist<int>& lista)
        {
        tab = new int[lista.size()];
        size = lista.size();
        int i=0;
        for(auto el: lista)
              tab[i++] = el;
        }
};
//zadanie3
Dana jest klasa, której niekompletna deklaracja znajduje się poniżej :
class Tablica {
    int *tab;
    int size;
public:
    Tablica (const std::initializerlist<int>& lista)
        {
        tab = new int[lista.size()];
        size = lista.size();
        int i=0;
        for(auto el: lista)
              tab[i++] = el;
        }
Dopisz konstruktor przenoszący  tej klasy.
UWAGA: Klasa jest już napisana, zawiera deklarację  konstruktora przenoszącego, brakuje tylko definicji tego konstruktora i tu należy ją napisać.
metody pop() proszę zaimplementować metodę get_vector() zwracającą  tablicę tab.


// KONSTRUKTOR PRZENOSZĄCY (definicja poniżej)
    Tablica(Tablica&& other) noexcept {
        tab = other.tab;
        size = other.size;
        other.tab = nullptr;
        other.size = 0;
    }

    // get_vector(): zwraca zawartość tab jako std::vector<int>
    std::vector<int> get_vector() const {
        std::vector<int> vec;
        for (int i = 0; i < size; ++i)
            vec.push_back(tab[i]);
        return vec;
    }

//4. Napisz własną klasę wyjątków, która ma dziedziczyć z std::exception. W konstruktorze, oprócz napisu wyjątek powinien dostawać i zapamiętywać
//liczbę całkowitą. Napis i liczba powinny być prywatne, napis ma być zwracany przez metodę what() (tak jak to jest w standardowych wyjątkach),
//a liczbę całkowitą przez inną metodę. Napisz funkcję, która otrzymuje  vector liczb typu double i zwraca vector pierwiastków tych liczb.
//Jeśli miałoby nastąpić liczenie pierwiastka z liczby ujemnej funkcja ma rzucić wyjątek typu zdefiniowanego powyżej z komunikatem
//"Pierwiastek z wartości ujemnej" oraz z indeksem pozycji na której ta wartość wystąpiła. Napisz drugą funkcję, która ma nazywać się serwis i
//ma mieć taki sam parametr jak pierwsza, ale nie ma nic zwracać. Ma wywołać pierwszą funkcję i wypisać jej wynik oraz obsłużyć  rzucony wyjątek.
//Obsługa wyjątku ma polegać na wypisaniu komunikatu z obiektu wyjątku oraz pozycji na której wystąpiła wartość ujemna (wszystko w tej samej linii).

// Definicja klasy wyjątku
class NegativeSqrtException : public std::exception {
private:
    std::string message;
    int index;

public:
    NegativeSqrtException(const std::string& msg, int idx)
        : message(msg), index(idx) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    int getIndex() const {
        return index;
    }
};

// Funkcja do liczenia pierwiastków
std::vector<double> obliczPierwiastki(const std::vector<double>& liczby) {
    std::vector<double> wyniki;
    for (size_t i = 0; i < liczby.size(); ++i) {
        if (liczby[i] < 0) {
            throw NegativeSqrtException("Pierwiastek z wartości ujemnej", i);
        }
        wyniki.push_back(std::sqrt(liczby[i]));
    }
    return wyniki;
}

// Funkcja serwis
void serwis(const std::vector<double>& liczby) {
    try {
        std::vector<double> wyniki = obliczPierwiastki(liczby);
        std::cout << "Wyniki pierwiastkowania: ";
        for (double wynik : wyniki) {
            std::cout << wynik << " ";
        }
        std::cout << std::endl;
    } catch (const NegativeSqrtException& e) {
        std::cout << e.what() << " " << e.getIndex() << std::endl;
    }
}

//5. Stwórz klasę Zwierze posiadającą metodę wypisz()  wypisującą komunikat "Jestem zwierzęciem". Następnie stwórz dwie klasy: Ssak i Ryba dziedziczące z
//Zwierze. Klasa Ssak niech posiada metodę wypisz()  wypisującą komunikat "Ssę" , a klasa Ryba metodę wypisz()  wypisującą komunikat "Pływam".
//Jako czwartą stwórz klasę Delfin dziedziczącą po klasach Ssak i Ryba. Ta klasa nie ma posiadać "własnej" metody wypisz, jedynie dziedziczy ją po 'przodkach'.

//Na koniec napisz funkcję zwierzak(), w której utwórz obiekt klasy Delfin i za jego pomocą, używając jedynie metod wypisz() spowoduj wypisanie komunikatów
//(każdy w osobnej linii):    "Ssę", "Pływam", "Jestem zwierzęciem".

class Zwierze
{
public:
    void wypisz(){
        std::cout<<"Jestem zwierzęciem"<<std::endl;
    }
    virtual ~Zwierze()=default;
};

class Ssak:  virtual public Zwierze{
public:
    void wypisz(){
        std::cout<<"sse"<<std::endl;
    }
};
class Ryba:virtual public Zwierze{
public:
     void wypisz(){
        std::cout<<"plywam"<<std::endl;
    }
};
class Delfin: public Ssak, public Ryba{
};

void zwierzak(){
Delfin d;
d.Ssak::wypisz();
d.Ryba::wypisz();
d.Zwierze::wypisz();
}
int main()
{
    return 0;
}

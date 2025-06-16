#include <iostream>

//szablony
//1. Napisz szablon klasy Stos implementujacej stos na prywatnej tablicy tab typu vector.
// W klasie wystarczy zaimplementowac metode push() wstawiajaca na stos.

template<typename T>
class Stos{
private:
    std::vector<T>tab;

public:
    void push(const T& element){
    tab.push_back(element);
    }
};

//2.Napisz szablon klasy Stos implementujący stos na prywatnej 100-elementowej tablicy tab. Oprócz tablicy potrzebna
// będzie zmienna wskazująca wierzchołek stosu. W klasie należy zaimplementować metodę push() wstawiającą na stos,
//metodę pop() pobierającą ze stosu (zwracającą wartość) oraz metodę isEmpty() zwracającą true, jeśli stos jest pusty.

template<typename T>
class Stos{
private:
    T tab[100];
    int wierzcholek;
public:
    Stos() : wierzcholek(-1){}
    void push(const T& element){
        if(top<99){
            tab[++wierzcholek]=element;
        }
    }

    T pop(){
        if(!isEmpty()){
            return tab[wierzcholek--];
        }
        throw std::out_of_range("Stos jest pusty");
    }

    bool isEmpty()const {
    return wierzcholek == -1;
    }
};

//3.Napisz szablon funkcji minimum, która znajduje najmniejszą wartość w tablicy (wektorze) i zwraca ją.
template<typename T>
T minimum(std::vector<T>& tab){
    T mini=tab[0];
    for(size_t i=0;i<tab.size();i++){
        if(tab[i]<mini){
            mini=tab[i];
        }
    }
    return mini;
}

//4. Napisz szablon funkcji o nazwie maksimum, która znajduje największą wartość w tablicy.
// Funkcja otrzymuje tablicę w postaci wskaźnika oraz jej rozmiar i zwraca znalezioną wartość.

template<typename T>
T maksimum(T* tab, int rozmiar){
    T maks=tab[0];
    for (int i=0;i<rozmiar;i++){
        if(tab[i]>maks){
            maks=tab[i];
        }
    }
    return maks;

}

//5. napisz szablon funkcji srednia. Funkcja przyjmuje wskaznik tablicy i jej rozmiar, zwraca srednia z liczb
template<typename T>
T srednia(T* tab, int rozmiar){
    T suma=0;
    for(int i=0; i<rozmiar;i++){
        suma+=tab[i];
    }
    return static_cast<double>(suma)/rozmiar;

}

//Konstruktor przenoszacy i metoda get_vector()
//Dopisz do klasy Tablica konstruktor przenoszacy i metode get_vector()

Tablica(Tablica&& other) noexcept : tab(other.tab), size(other.size){
    other.tab=nullptr;
    other.size=0;

}
std::vector<int> get_vector() const{
return std::vector<int>(tab, tab+size);
}

//Dodaj do klasy Tablica przenoszacy operator =. Opisz dokladnie co robi i jak nalezy go napisac

Tablica& operator=(Tablica&& other) noexcept{
    if(this!= &other){
        delete[] tab_;//zwolni stara pamiec
        tab_=other.tab_;
        size_=other.size_;
        other.tab_=nullptr;
        other.size=0;
    }
    return *this;
}
~Tablica(){
    delete[] tab_;
}

//szukajace funkcje

//1.Jest sobie klasa Auto z polami marka, model, kolor.
//Utwórz funkcję przyjmującą wektor wskaźników na Auto, string oraz wskaźnik na string i zwracającą wskaźnik na string.
//Funkcja ma wyszukać wartość stringa z pola obiektu wektora, zwrócić wskaźnik na ten string?
//zwraca wskaznik
std::string* szukaj_auto(std::vector<Auto*>& auta, const std::string& wartosc, std::string Auto::*pole){
    for(Auto* a : auta){
        if(a->*pole == wartosc){
            return &(a->*pole);
        }
    }
    return nullptr;
}

//1.2 - Funkcja szukaj_auta
//Obiekty klasy Auto posiadają trzy publiczne pola typu string: marka, model i kolor.
//Napisz funkcję szukaj auta() z trzema parametrami:
//pierwszym jest vector obiektów klasy Auto, drugim string
//a trzecim wskaźnik na pole składowe typu string klasy Auto.
//Funkcja ma wyszukać w wektorze pierwsze wystąpienie obiektu, który we wskazywanym polu zawiera podany string.
//Funkcja ma zwracać indeks znalezionego obiektu.
 int szukaj_auto1(std::vector<Auto>& auta, std::string& wartosc, std::string Auto::* pole){
    for(size_t i=0;i<auta.size();i++){
        if(auta[i].*pole==wartosc){
            return static_cast<int>(i);
        }
    }
    return -1;
 }

 //2.Napisz funkcję szukaj(), która przyjmuje trzy parametry: pierwszy jest vector obiektów klasy Książka,
 //drugi string, a trzeci wskaźnik na pole składowe klasy Książka. Funkcja ma wyszukać w tablicy pierwsze wystąpienie obiektu,
 // którego wskazanym polem zawiera podany string. Funkcja ma zwracać indeksy znalezionego obiektu.

std::vector<int> szukaj_ksiazke(std::vector<Ksiazka>& ksiazki, const std::string& wartosc, std::string Ksiazka::* pole) {
    std::vector<int> indeksy;
    for (size_t i = 0; i < ksiazki.size(); ++i) {
        if (ksiazki[i].*pole == wartosc) {
            indeksy.push_back(static_cast<int>(i));
        }
    }
    return indeksy;
}

//klasy
//1. Stwórz klasę Transport posiadającą metodę wypisz()  wypisującą komunikat "Jestem środkiem transportu". Następnie stwórz dwie
//klasy: Samochód i Statek dziedziczące z Transport. Klasa Samochód niech posiada metodę wypisz()  wypisującą komunikat
 //"Jestem samochodem" , a klasa Statek metodę wypisz()  wypisującą komunikat "Jestem statkiem". Jako czwartą stwórz klasę Amfibia
//dziedziczącą po klasach Samochód i Statek. Ta klasa nie ma posiadać "własnej" metody wypisz, jedynie dziedziczy ją po 'przodkach'.
 //Na koniec napisz funkcję transport(), w której utwórz obiekt klasy Amfibia i za jego pomocą, używając jedynie metod wypisz()
//spowoduj wypisanie komunikatów (każdy w osobnej linii):    "Jestem samochodem", "Jestem statkiem", "Jestem środkiem transportu"
class Transport{
public:
    void wypisz(){
        std::cout<<"jestem srodkiem transportu"<<std::endl;
    }
};
class Samochod:virtual public Transport{
public:
    void wypisz(){
        std::cout<<"jestem samochodem"<<std::endl;
    }

};
class Statek:virtual public Transport{
public:
    void wypisz(){
        std::cout<<"jestem statkiem"<<std::endl;
    }

};
class Amfibia: public Statek, public Samochod{

};
void transport(){
    Amfibia p;
    p.Samochod::wypisz();
    p.Statek::wypisz();
    p.Transport::wypisz();

}

//2.Napisz klasę Zwierzę posiadającą metodę wypisz() wypisującą komunikat "Jestem zwierzęciem". Następnie stwórz dwie klasy: Ssak i Ryba dziedziczące po Zwierzę.
//Klasa Ssak niech posiada metodę wypisz() wypisującą komunikat "Ssę", a klasa Ryba metodę wypisz() wypisującą komunikat "Plywam".
// Jako czwartą stwórz klasę Delfin dziedziczącą po klasach Ssak i Ryba. Ta klasa nie ma posiadać własnej metody wypisz, jedynie
//dziedziczy ją po przodkach. Na koniec napisz funkcję zwierzak(), w której utworzysz obiekt klasy Delfin i za jego pomocą używając
//jedynie metody wypisz() spowodujesz wypisanie komunikatów (każdy w osobnej linii): "Ssę", "Plywam", "Jestem zwierzęciem".

class Zwierze{
public:
    void wypisz(){
        std::cout<<"jestem zwierzeciem"<<std::endl;
    }
};
class Ssak:virtual public Zwierze{
public:
    void wypisz(){
        std::cout<<"sse"<<std::endl;
    }
};
class Ryba:virtual public Zwierze{
public:
    void wypisz(){
        std::cout<<"plwam"<<std::endl;
    }
};
class Delfin:public Ssak, public Ryba{
};
void zwierzak(){
    Delfin d;
    d.Ssak::wypisz();
    d.Ryba::wypisz();
    d.Zwierze::wypisz();
}

//3.Napisz interfejs (klasę Figury) zawierający metodę pole() zwracającą liczbę rzeczywistą typu double.
//Następnie zdefiniuj klasy Kolo i Kwadrat, które mają dziedziczyć z klasy Figury. Jako wartość stałej pi należy przyjąć 3.14.
 //Napisz funkcję figury(), która nie ma parametrów i nie zwraca wartości. W funkcji:
//Utwórz tablicę (w postaci vector) inteligentnych, unikalnych wskaźników na klasę Figura.Dodaj do tablicy kwadrat o boku 4 oraz
//koło o promieniu 3. Wypisz (po jednej w linii) pole obu figur przechodząc w pętli po tablicy figur.
class Figury{
public:
    virtual double pole()const=0;
    virtual ~Figury(){}
};
class Kolo: public Figury{
private:
    double r;
public:
    Kolo(double promien):r(promien){}
    double pole()const override{
    return 3.14*r*r;
    }
};
class Kwadrat: public Figury{
private:
    double a;
public:
    Kwadrat(double bok):a(bok){}
    double pole()const override{
    return a*a;
    }
};
void figury(){
std::vector<std::unique_ptr<Figury>>tab;
tab.push_back(std::make_unique<Kwadrat>(4));
tab.push_back(std::make_unique<Kolo>(3));

for(const auto& f : tab){
    std::cout<<f->pole()<<"\n";
}

}

//4.Utwórz klasę Osoba z prywatnymi polami string imię i nazwisko, a publicznym konstruktorem oraz funkcją wypisz().
//Utwórz klasę Pracownicy z polem prywatnym stanowisko i publicznym konstruktorem z polami wcześniejszej klasy + stanowisko
//oraz swoją funkcję wypisz() z polami klasy Osoba i stanowiskiem. Dodatkowo funkcja void, która dodaje do wektora
//wskaźników Osoba obiekty: "Jan" "Kowalski" oraz "Jakub" "Nowak" "Dyrektor" i potem w pętli wypisuje.
class Osoba{
private:
    std::string imie;
    std::string nazwisko;
public:
    Osoba(std::string i,std::string n):imie(i), nazwisko(n){}
    virtual void wypisz(){
    std::cout<<imie<<" "<<nazwisko;
    }
    virtual ~Osoba(){}

};
class Pracownicy:public Osoba{
private:
    std::string stanowisko;
public:
    Pracownicy(std::string i, std::string n, std::string s):Osoba(i,n), stanowisko(s){}
    virtual void wypisz(){
        Osoba::wypisz();
    std::cout<<", "<<stanowisko<<std::endl;
    }
};
void dodajWpis(){
    std::vector<Osoba*> osoby;
    osoby.push_back(new Osoba("Jan","Kowalski"));
    osoby.push_back(new Pracownicy("Jakub","Nowak", "Dyrektor"));
    for(Osoba* o : osoby){
        o->wypisz();
    }
    for(Osoba* o : osoby){
        delete o;
    }
}

//wyjatki
//1.Funkcje dzielenia i serwis - Napisz dwie funkcje: jedną zwracającą wynik dzielenia dwóch liczb typu `double`
 //(z wyjątkiem dla dzielenia przez zero) oraz drugą, `serwis`, która wywołuje pierwszą i obsługuje wyjątek

double dzielenie(double a, double b){
    if(a==0){
        throw std::runtime_error("dzielenie przez 0")
    }
    else{
        return b/a;
    }
}
void serwis(double a, double b){
    try{
        double wynik=dzielenie(a,b);
        std::cout<<"wynik wynosi:"<<wynik<<std::endl;
    }
    catch(const std::runtime_error& e){
        std::cout<<e.what();
    }

}
//2.Funkcja przyjmująca dwa wektory double, zwraca wektor sum odpowiadającym sobie pól.
//Jeśli rozmiary wektorów się różnią należało rzucić wyjątkiem std::runtime_error.
//Druga funkcja serwis przyjmuje wektor i nic nie zwraca, wywołuje pierwszą funkcję i obsługuje wyjątek.
std::vector<double> suma(std::vector<double>& vec1, std::vector<double>& vec2){
    std::vector<double> sum;
    if(vec1.size()!=vec2.size()){
        throw std::runtime_error("rozny rozmiar");
    }
    else{
        for(size_t i=0;i<vec1.size();i++){
            sum.push_back(vec1[i]+vec2[i]);
        }
    }
    return sum;
}
void serwis(std::vector<double>& vec1, std::vector<double>& vec2){
    try{
    std::vector<double> wynik=suma(vec1, vec2);
    for(double& val : wynik){
        std::cout<<"wynik: " <<val;
    }
    }
    catch(std::runtime_error& e){
        std::cout<<e.what();
    }
}

//3.Funkcja przyjmująca dwa wektory double, zwraca iloczyn skalarny tych wektorow.
//Jeśli rozmiary wektorów się różnią należało rzucić wyjątkiem std::runtime_error.
//Druga funkcja serwis przyjmuje wektor i nic nie zwraca, wywołuje pierwszą funkcję i obsługuje wyjątek.
double iloczyn(std::vector<double>& vec1, std::vector<double>& vec2){
    double iloczyn=0.0;
    if(vec1.size()!=vec2.size()){
        throw std::runtime_error("rozne rozmiary");
    }
    else{
        for(size_t i=0;i<vec1.size();i++){
            iloczyn+=vec1[i]*vec2[i];
        }
    }
    return iloczyn;
}
void serwis(std::vector<double>& vec1, std::vector<double>& vec2){
    try{
        double wynik=iloczyn(vec1,vec2);
        std::cout<<"wynik: "<<wynik<<std::endl;
    }
    catch(std::runtime_error& e){
        std::cout<<e.what();
    }
}











#include <iostream>
#include <math.h>
#include <stdexcept>
#include <vector>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//dziedziczenie
class Punkt{
float x,y;
std::string nazwa;

public:
    Punkt(std::string n="S", float a=0, float b=0){
    nazwa=n;
    x=a;
    y=b;
    }
    void wyswietl(){
    std::cout<<nazwa<<"("<<x<<","<<y<<")"<<std::endl;
    }
};

class Kolo: public Punkt{
    protected:
float r;
std::string nazwa;

public:
    Kolo(std::string np="S", std::string nk="kolko", float rk=0, float a=0, float b=0)
    :Punkt(np,a,b){
    nazwa =nk;
    r=rk;
    }

    void wypisz(){
        std::cout<<"kolo o nazwie: "<<nazwa<<std::endl;
        std::cout<<"srodek kola:" <<std::endl;
        Punkt::wyswietl();
        std::cout<<"promien"<<r<<std::endl;

    }
};

class Kula:public Kolo{
std::string nazwa;

public:
    Kula(std::string np="S", std::string nkk="kulaa",std::string nk="kolko", float rk=0, float a=0, float b=0)
    :Kolo(np,nk,rk,a,b){
    nazwa=nkk;
    }

    void wyswietl(){
    Kolo::wypisz();
    std::cout<<nazwa<<std::endl;
    std::cout<<"objetos kuli wynosi: "<<(4.0/3.0*M_PI*r*r*r)<<std::endl;
    }
};


//polimorfizm
class Ksztalt{
public:
    virtual void oblicz_pole()=0;
};

class Koloo: public Ksztalt{
float r;
public:
    Koloo(float x){
    r=x;
    }
    void oblicz_pole(){
    std::cout<<"pole kola:"<<M_PI*r*r<<std::endl;
    }
};

class Kwadrat:public Ksztalt{
float a;
public:
Kwadrat(float x){
a=x;
}

void oblicz_pole(){
std::cout<<"pole kwadratu: "<<a*a<<std::endl;
}
};


void obliczenia(Ksztalt *x){
x->oblicz_pole();
}


//szablony
template<typename T>
T sum(T a, T b){
    return a+b;
}

//int sum(int a, int b){
//return a+b;
//}

//double sum(double a, double b){
//return a+b;
//}

template<typename T>
class Test
{
private:
    T x;
    T y;
public:
    Test(T a, T b): x(a), y(b){
    std::cout<<x+y<<std::endl;
    }
};


template<>
class Test <std::string>
{
private:
    std::string x;
    std::string y;
public:
    Test(std::string a, std::string b): x(a), y(b){
    std::cout<<"Tekst: " << x+y<<std::endl;
    }
};

//wyjatki
double dziel(double a, double b) {
    if (b == 0) {
        throw "Blad: dzielenie przez zero!";
    }
    return a / b;
}

int pobierzElement(const std::vector<int>& dane, int indeks) {
    if (indeks < 0 || indeks >= dane.size()) {
        throw std::runtime_error("Nieprawidlowy indeks!");
    } else {
        return dane[indeks];
    }
}


int main()
{
    std::cout << "Hello world!" << std::endl;
//dziedziczenie
    Kolo k1;
    //k1.wypisz();

    Kula k2;
    k2.wyswietl();


//polimorfizm
    Koloo k(1);
    Kwadrat kw(2);

    Ksztalt *wsk;
    wsk=&k;
    wsk ->oblicz_pole();

    wsk=&kw;
    wsk->oblicz_pole();


//szablony
    std::cout<<sum(4,7)<<std::endl;
    std::cout<<sum(3.5,7.0)<<std::endl;

    Test<int> obj1(5,10);
    Test<float> obj2(5.25,7.25);
    Test<std::string> obj3("ale"," gowno");


//wyjatki
 double x = 10;
    double y = 0;

    try {
        double wynik = dziel(x, y);
        std::cout << "Wynik: " << wynik << std::endl;
    } catch (const char* e) {
        std::cout << "Wyjatek zlapany: " << e << std::endl;
    }

    std::cout << "wektor" << std::endl;
     std::vector<int> liczby = {10, 20, 30};

    try {
        int wynik = pobierzElement(liczby, 5);
        std::cout << "Element: " << wynik << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Wyjatek zlapany: " << e.what() << std::endl;
    }

    return 0;
}

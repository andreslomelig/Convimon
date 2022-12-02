#include<string>
using namespace std;

void clearConsole() {
    system("pause");
    system("cls");
}

class Pokemon
{
private:
    string nombre;
    string nivel;
    int vida;
    int pa1 = 25;
    int pa2 = 20;
    int pa3 = 20;
    int pa4 = 20;
public:
    Pokemon() {};
    Pokemon(string _nombre, string _nivel, int _vida)
    {
        nombre = _nombre;
        vida = _vida;
        nivel = _nivel;
    }

    int Getvida() { return vida; }
    void Setvida(int val) { vida = val; }
    string Getnombre() { return nombre; }
    void Setnombre(string val) { nombre = val; }
    string Getnivel() { return nivel; }
    void Setnivel(string val) { nivel = val; }
    int Getpa1() { return pa1; }
    void Setpa1(int val) { pa1 = val; }
    int Getpa2() { return pa2; }
    void Setpa2(int val) { pa2 = val; }
    int Getpa3() { return pa3; }
    void Setpa3(int val) { pa3 = val; }
    int Getpa4() { return pa4; }
    void Setpa4(int val) { pa4 = val; }
};



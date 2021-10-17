#include <iostream>
#include <random>
using namespace std;

struct Particula{
    double X;
    double Y;
    double z;
    double mass;
};


int main(int argc, char* argv[]) {

    cout << "Has introducido " << argc << " Parametros" << endl;
    //[----------------Control de Parámetros---------------------]
    if(argc != 6){
        cerr << "Número de parámetros Inválido" << endl;
        return -1;
    }else if(atoi(argv[1]) <= 0){
        cerr << "Número de partículas Inválido" << endl;
        cerr << "El número de partículas debe ser Mayor que 0" << endl;
        return -1;
    }else if(atoi(argv[2]) <= 0){
        cerr << "Número de iteraciones de tiempo Inválido" << endl;
        cerr << "El número de iteraciones de tiempo debe ser Mayor que 0" << endl;
        return -1;
    }else if(atoi(argv[3]) <= 0){
        cerr << "Seed Inválida" << endl;
        cerr << "Seed debe ser Mayor que 0" << endl;
        return -1;
    }else if(atof(argv[4]) <= 0){
        cerr << "Tamaño del cubo Inválido" << endl;
        cerr << "El tamaño del cubo debe ser Mayor que 0" << endl;
        return -1;
    }else if(atof(argv[5]) <= 0){
        cerr << "Intervalo de Tiempo Inválido" << endl;
        cerr << "El Intervalo de Tiempo debe ser Mayor que 0" << endl;
        return -1;
    }else{
        //[-------------------Creación de Arrays-------------------]
        if(isdigit(atoi(argv[1]))){

        }
        int NumParticulas = atoi(argv[1]);
        Particula list[NumParticulas];

        //[---------------------Generador de números------------------------]
        //int seed = ;
        mt19937_64 generator(atoi(argv[3]));




        //cout << "Hello, World!" << endl;
        return 0;
    }











}

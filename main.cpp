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
    }
    //definir los parametros
    int num_objects = atoi(argv[1]);
    int num_iteration = atoi(argv[2]);
    int random_seed =atoi(argv[3]);
    double size_enclosure = atof(argv[4]);
    double time_step =atof(argv[5]);


    if(num_objects <= 0){
        cerr << "Número de partículas Inválido" << endl;
        cerr << "El número de partículas debe ser Mayor que 0" << endl;
        return -1;
    }else if(num_iteration <= 0){
        cerr << "Número de iteraciones de tiempo Inválido" << endl;
        cerr << "El número de iteraciones de tiempo debe ser Mayor que 0" << endl;
        return -1;
    }else if(random_seed <= 0){
        cerr << "Seed Inválida" << endl;
        cerr << "Seed debe ser Mayor que 0" << endl;
        return -1;
    }else if( size_enclosure<= 0){
        cerr << "Tamaño del cubo Inválido" << endl;
        cerr << "El tamaño del cubo debe ser Mayor que 0" << endl;
        return -1;
    }else if(time_step <= 0){
        cerr << "Intervalo de Tiempo Inválido" << endl;
        cerr << "El Intervalo de Tiempo debe ser Mayor que 0" << endl;
        return -1;
    }else{
        //[-------------------Creación de Arrays-------------------]
        if(isdigit(num_objects)){

        }

        struct Particula particulas[num_objects];

        //[---------------------Generador de números------------------------]
        //int seed = ;
        mt19937_64 generator(random_seed);
        std::uniform_real_distribution<double> dis(0.0, size_enclosure);



        //cout << "Hello, World!" << endl;
        return 0;
    }











}

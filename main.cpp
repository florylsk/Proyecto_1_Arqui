#include <iostream>
#include <random>
#include <cmath>
#include <fstream>
using namespace std;

struct Particula{
    double X;
    double Y;
    double Z;
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
    /*PARA DEBUG
    int num_objects = 5;
    int num_iteration = 3;
    int random_seed = 3;
    double size_enclosure = 20.0;
    double time_step = 0.3;
    cout << argv[0] << endl;*/


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

        ofstream file;
        file.open("/home/carlos/CLionProjects/Proyecto_1_Arqui/init_config.txt");


        //[-------------------Creación de Arrays-------------------]

        std::vector<Particula> particulas(num_objects);

        //[---------------------Generador de números------------------------]
        //Esto podriamos meterlo en una función, Iteramos con un for y hacemos esto para cada particula
        mt19937_64 generator(random_seed);
        std::uniform_real_distribution<double> dis{0.0, size_enclosure};
        std::normal_distribution<double> d{pow(10.0,21.0), pow(10.0, 15.0)};
        //uso para generar un valor: double val1 = dis(generator);
        int i;
        for(i = 0; i < num_objects ; i++){
            particulas[i].X = dis(generator);
            particulas[i].Y = dis(generator);
            particulas[i].Z = dis(generator);
            particulas[i].mass = d(generator);
        }
        //cout << "Terminado" << endl;












        return 0;
    }











}

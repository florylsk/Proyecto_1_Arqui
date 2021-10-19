#include <iostream>
#include <random>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Particula{
    double X; //posicion X
    double Y; //posicion Y
    double Z; //posicion Z
    double Vx; //Velocidad en X
    double Vy; //Velocidad en Y
    double Vz; //Velocidad en Z
    double mass; //Masa de la particula
};



//global variables before init
int num_objects;
int num_iteration;
int random_seed;
double size_enclosure;
double time_step;

//global variables after init



int init_config(vector<Particula> &particulas){
    //crea el archivo en cmake-buiild-debug
    fstream file;
    file.open("init_config.txt",fstream::in | fstream::out | fstream::trunc);
    file << setprecision(3) << size_enclosure << " " << setprecision(3) << time_step << " " << setprecision(3) << num_objects << endl;
    int i;
    for(i = 0; i < num_objects; i++){
        file<<fixed<<showpoint;
        file<<setprecision(3);
        file<<particulas[i].X<<" "<<particulas[i].Y<<" "<<particulas[i].Z<<" ";
        file<<particulas[i].Vx<<" "<<particulas[i].Vy<<" "<<particulas[i].Vz<<" ";
        file<<particulas[i].mass<<endl;

    }
    file.close();
    return 0;
}
void colision_particulas(Particula A, Particula B, int posB, vector<Particula> &particulas){
    A.mass = A.mass + B.mass;
    A.Vx = A.Vx + B.Vx;
    A.Vy = A.Vy + B.Vy;
    A.Vz = A.Vz + B.Vz;
    vector<Particula>::iterator ptr;
    advance(ptr,posB);
    particulas.erase(ptr);
    return;

}

int generar_particulas(vector<Particula> &particulas,vector<int> &modulos,mt19937_64 &generator,uniform_real_distribution<double> &dis,normal_distribution<double> &d){
    for(int i = 0; i < num_objects ; i++){
        particulas[i].X = dis(generator);
        particulas[i].Y = dis(generator);
        particulas[i].Z = dis(generator);
        particulas[i].Vx=0;
        particulas[i].Vy=0;
        particulas[i].Vz=0;
        particulas[i].mass = d(generator);


    }
    //comprobar que no hay 2 con el mismo módulo(misma posicion)
    //modulo = sqrt((pow(particulas[i].X,2))+pow(particulas[i].Y,2)+pow(particulas[i].Z,2));
    for (int j=0;j<num_objects;j++){
        modulos[j] = sqrt((pow(particulas[j].X,2))+pow(particulas[j].Y,2)+pow(particulas[j].Z,2));
    }
    for (int i=0;i<num_objects;i++){
        for (int j=0;j<num_objects;j++){
            if (modulos[i]==modulos[j] && i!=j){
                //hacer algo
            }
        }
    }

    return 0;

}

int main(int argc, char* argv[]) {
    cout << "Has introducido " << argc-1 << " Parametros" << endl;
    //[----------------Control de Parámetros---------------------]
    if(argc != 6){
        cerr << "Número de parámetros Inválido" << endl;
        return -1;
    }
    //dar valor a los paremetros
    num_objects = atoi(argv[1]);
    num_iteration = atoi(argv[2]);
    random_seed =atoi(argv[3]);
    size_enclosure = atof(argv[4]);
    time_step =atof(argv[5]);
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
    }
    cout<<"Argumentos:\n"<<"num_objects: "<<num_objects<<"\nnum_iterations: "<<num_iteration<<"\nrandom_seed: "<<random_seed<<"\nsize_enclosure: "<<size_enclosure<<"\ntime_step: "<<time_step<<endl;
    mt19937_64 generator(random_seed);
    uniform_real_distribution<double> dis{0.0, size_enclosure};
    normal_distribution<double> d{pow(10.0,21.0), pow(10.0, 15.0)};

    vector<Particula> particulas(num_objects);
    vector<int> modulos(num_objects);

    if(generar_particulas(particulas,modulos,generator,dis,d)==-1){
        cerr<<"fallo al generar las particulas";
    }

    if(init_config(particulas)==-1){
        cerr<<"fallo en el init config";
    }










    return 0;
}

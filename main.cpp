#include <iostream>
#include <random>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Particula{
    double posicion[3];
    double velocidad[3];
    double fuerza[3];
    double mass;

};

const double G= 6.674*(pow(10,-11));

//global variables
int num_objects;
int num_iteration;
int random_seed;
double size_enclosure;
double time_step;





int init_config(vector<Particula> &particulas){
    //crea el archivo en cmake-buiild-debug
    fstream file;
    file.open("init_config.txt",fstream::in | fstream::out | fstream::trunc);
    file<<fixed<<showpoint;
    file<<setprecision(3);
    file << size_enclosure<<" "<<time_step<<" "<<num_objects<<endl;
    for(int i = 0; i < num_objects; i++){

        file<<particulas[i].posicion[0]<<" "<<particulas[i].posicion[1]<<" "<<particulas[i].posicion[2]<<" ";
        file<<particulas[i].velocidad[0]<<" "<<particulas[i].velocidad[1]<<" "<<particulas[i].velocidad[2]<<" ";
        file<<particulas[i].mass<<endl;

    }
    file.close();
    return 0;
}
void colision_particulas(Particula A, Particula B, int posB, vector<Particula> &particulas){
    A.mass = A.mass + B.mass;
    A.velocidad[0] = A.velocidad[0] + B.velocidad[0];
    A.velocidad[1] = A.velocidad[1] + B.velocidad[1];
    A.velocidad[2] = A.velocidad[2] + B.velocidad[2];
    vector<Particula>::iterator ptr;
    advance(ptr,posB);
    particulas.erase(ptr);
    return;

}

int generar_particulas(vector<Particula> &particulas,mt19937_64 &generator,uniform_real_distribution<double> &dis,normal_distribution<double> &d){
    for(int i = 0; i < num_objects ; i++){
        particulas[i].posicion[0] = dis(generator);
        particulas[i].posicion[1] = dis(generator);
        particulas[i].posicion[2] = dis(generator);
        particulas[i].velocidad[0]=0;
        particulas[i].velocidad[1]=0;
        particulas[i].velocidad[2]=0;
        particulas[i].fuerza[0]=0;
        particulas[i].fuerza[1]=0;
        particulas[i].fuerza[2]=0;
        particulas[i].mass = d(generator);


    }

    return 0;

}

int fuerza_gravitatoria(Particula &p, vector<Particula> &particulas){
    for(int i=0;i<num_objects;i++){
        if(&p != &particulas[i] ){
            if((particulas[i].posicion[0]-p.posicion[0])==0){
                continue;
            }
            else if((particulas[i].posicion[1]-p.posicion[1])==0){
                continue;
            }
            else if ((particulas[i].posicion[2]-p.posicion[2])==0){
                continue;
            }
            else {
                p.fuerza[0] += (G * p.mass * particulas[i].mass * (particulas[i].posicion[0] - p.posicion[0])) /
                               (pow((fabs(particulas[i].posicion[0] - p.posicion[0])), 3));
                p.fuerza[1] += (G * p.mass * particulas[i].mass * (particulas[i].posicion[1] - p.posicion[1])) /
                               (pow((fabs(particulas[i].posicion[1] - p.posicion[1])), 3));
                p.fuerza[2] += (G * p.mass * particulas[i].mass * (particulas[i].posicion[2] - p.posicion[2])) /
                               (pow((fabs(particulas[i].posicion[2] - p.posicion[2])), 3));
            }
        }
    }
    return 0;
}


void aceleracion_y_velocidad(Particula &p){
    double accX = (1/p.mass)*p.fuerza[0];
    double accY = (1/p.mass)*p.fuerza[1];
    double accZ = (1/p.mass)*p.fuerza[2];
    p.velocidad[0]+= accX*time_step;
    p.velocidad[1]+= accY*time_step;
    p.velocidad[2]+= accZ*time_step;
}


void actualizar_posicion(Particula &p){
    p.posicion[0]+= p.velocidad[0]*time_step;
    p.posicion[1]+= p.velocidad[1]*time_step;
    p.posicion[2]+= p.velocidad[2]*time_step;
    if (p.posicion[0]<=0){
        p.posicion[0]=0;
        p.velocidad[0]=-p.velocidad[0];
    }
    if (p.posicion[1]<=0){
        p.posicion[1]=0;
        p.velocidad[1]=-p.velocidad[1];
    }
    if (p.posicion[2]<=0){
        p.posicion[2]=0;
        p.velocidad[2]=-p.velocidad[2];
    }
    if (p.posicion[0]>=size_enclosure){
        p.posicion[0]=size_enclosure;
        p.velocidad[0]=-p.velocidad[0];
    }
     if (p.posicion[1]>=size_enclosure){
        p.posicion[1]=size_enclosure;
        p.velocidad[1]=-p.velocidad[1];
    }
    if (p.posicion[2]>=size_enclosure){
        p.posicion[2]=size_enclosure;
        p.velocidad[2]=-p.velocidad[2];
    }


    p.fuerza[0]=0;
    p.fuerza[1]=0;
    p.fuerza[2]=0;

}
void final_config(vector<Particula> &particulas){
    fstream file;
    file.open("final_config.txt",fstream::in | fstream::out | fstream::trunc);
    file<<fixed<<showpoint;
    file<<setprecision(3);
    file << size_enclosure<<" "<<time_step<<" "<<num_objects<<endl;
    for(int i = 0; i < num_objects; i++){

        file<<particulas[i].posicion[0]<<" "<<particulas[i].posicion[1]<<" "<<particulas[i].posicion[2]<<" ";
        file<<particulas[i].velocidad[0]<<" "<<particulas[i].velocidad[1]<<" "<<particulas[i].velocidad[2]<<" ";
        file<<particulas[i].mass<<endl;

    }
    file.close();
    return;


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

    if(generar_particulas(particulas,generator,dis,d)==-1){
        cerr<<"fallo al generar las particulas";
    }
    if(init_config(particulas)==-1){
        cerr<<"fallo en el init config";
    }

    for (int i=0;i<num_iteration;i++){
        for(int j=0;j<num_objects;j++){
            fuerza_gravitatoria(particulas[j],particulas);
            aceleracion_y_velocidad(particulas[j]);
            actualizar_posicion(particulas[j]);
        }
    }
    final_config(particulas);
    cout<<"terminado :)"<<endl;


    return 0;
}

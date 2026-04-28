#ifndef SENSOR_H
#define SENSOR_H

#include <string>
using namespace std;

class Sensor{
    private:
        int id;
        std::string tipo;
        std::string localizacao;
        float ultimaLeitura;
    
    public:
        Sensor();
        Sensor(int i, std::string t, std::string l);

        int getId();

        std::string getLocalizacao();
        
        std::string getTipo();
        float getUltimaLeitura();
        void setUltimaLeitura(float leitura);

};

#endif
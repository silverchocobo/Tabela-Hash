#include "Sensor.h"
#include <string>
using namespace std;

    Sensor::Sensor(){
        ultimaLeitura = -1.0;
    };
    Sensor::Sensor(int i, std::string t, std::string l){
        id = i;
        tipo = t;
        localizacao = l;
        ultimaLeitura = -1.0;
    }

    int Sensor::getId() {
        return id;
    }

    std::string Sensor::getLocalizacao() {
            return localizacao;
    }
            
    std::string Sensor::getTipo() {
            return tipo;
    }

    float Sensor::getUltimaLeitura() {
        return ultimaLeitura;
    }

    void Sensor::setUltimaLeitura(float leitura) {
        ultimaLeitura = leitura;
    }

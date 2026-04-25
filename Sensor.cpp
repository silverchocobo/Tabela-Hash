#include "Sensor.h"
#include <string>
using namespace std;

    Sensor::Sensor(){
    };
    Sensor::Sensor(int i, std::string t, std::string l){
        id = i;
        tipo = t;
        localizacao = l;
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

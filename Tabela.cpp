#include <iostream>
#include "Tabela.h"
using namespace std;

Tabela::Tabela() {
    tamanho = std::size(sensores);
}

void Tabela::cadastarSensor(Sensor sensor) {
    int idSensor = sensor.getId();
    int h1 = idSensor % tamanho;
    int h2 = 97 - (idSensor % 97);
    int h;
    int i = 0;

    while(true){
        h = (h1 + i * h2) % tamanho;
         std::cout << h;
        if (!sensores[h]){
            sensores[h] = sensor;
            break;
        }
        i++; 
    }   
}

void Tabela::exibirSensores(){
    for (const auto& opt_sensor : sensores) {
        if(opt_sensor.has_value()){
            Sensor sensor = opt_sensor.value(); 
            std::cout << "----------------------" << "\n";
            std::cout << "Id: " << sensor.getId() << "\n";
            std::cout << "Tipo: " << sensor.getTipo() << "\n";
            std::cout << "Localização: " << sensor.getLocalizacao() << "\n";
        }
    }
}


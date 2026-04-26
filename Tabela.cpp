#include <iostream>
#include "Tabela.h"
using namespace std;

Tabela::Tabela() {
    tamanho = std::size(sensores);
}

void Tabela::cadastarSensor(Sensor sensor) {
    int idSensor = sensor.getId();
    int h1 = idSensor % tamanho;
    int h2 = 7 - (idSensor % 7);
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

void Tabela::exibirSensores() {
    for (int i = 0; i < tamanho; i++) {
        if (sensores[i].has_value()) {
            Sensor sensor = sensores[i].value();
            std::cout << "--- [ POSICAO " << i << " ] ---" << "\n";
            std::cout << "Id: " << sensor.getId() << "\n";
            std::cout << "Tipo: " << sensor.getTipo() << "\n";
            std::cout << "Localização: " << sensor.getLocalizacao() << "\n\n";
        } else {
            std::cout << "--- [ POSICAO " << i << " ] VAZIA ---\n\n"; 
        }
    }
}


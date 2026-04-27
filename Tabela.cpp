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
        if (!sensores[h] || sensores[h]->getId() == -1){
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
            if (sensor.getId() == -1) {
                std::cout << "--- [ POSICAO " << i << " ] VAZIA ---\n\n";
                continue;
            }
            std::cout << "--- [ POSICAO " << i << " ] ---" << "\n";
            std::cout << "Id: " << sensor.getId() << "\n";
            std::cout << "Tipo: " << sensor.getTipo() << "\n";
            std::cout << "Localização: " << sensor.getLocalizacao() << "\n\n";
        } else {
            std::cout << "--- [ POSICAO " << i << " ] VAZIA ---\n\n"; 
        }
    }
}

std::optional<Sensor> Tabela::getSensor(int id) {
    int h1 = id % tamanho;
    int h2 = 7 - (id % 7);
    int h;
    int i = 0;

    while(i < tamanho) {
        h = (h1 + i * h2) % tamanho;
        if (!sensores[h]) {
            return std::nullopt;
        } else if (sensores[h]->getId() == id) {
            return sensores[h];
        }
        i++;
    }
    return std::nullopt;
}

bool Tabela::atualizarLeitura(int id, float valor) {
    int h1 = id % tamanho;
    int h2 = 7 - (id % 7);
    int h;
    int i = 0;

    while(i < tamanho) {
        h = (h1 + i * h2) % tamanho;
        if (!sensores[h]) {
            return false;
        } else if (sensores[h]->getId() == id) {
            sensores[h]->setUltimaLeitura(valor); 
            return true;
        }
        i++;
    }
    return false;
}

bool Tabela::removerSensor(int id) {
    int h1 = id % tamanho;
    int h2 = 7 - (id % 7);
    int h;
    int i = 0;

    while(i < tamanho) {
        h = (h1 + i * h2) % tamanho;
        if (!sensores[h]) {
            return false;
        } else if (sensores[h]->getId() == id) {
            sensores[h] = Sensor(-1, "", ""); // tombstone
            return true;
        }
        i++;
    }
    return false;
}

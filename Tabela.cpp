#include <iostream>
#include "Tabela.h"
#include <chrono>
using namespace std;

Tabela::Tabela() {
    tamanho = std::size(sensores);
}

int Tabela::cadastarSensor(Sensor sensor) {
    int idSensor = sensor.getId();
    int i = 0;

    while(i < tamanho){
        int h = funcaoHash(i,idSensor);
        if (!sensores[h] || sensores[h]->getId() == -1){
            sensores[h] = sensor;
            return i;;
        }
        i++; 
    }
    return -1;
    
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
    int i = 0;
    auto inicio = std::chrono::steady_clock::now();

    while(i < tamanho) {
        int h = funcaoHash(i,id);
        if (!sensores[h]) {
            return std::nullopt;
        } else if (sensores[h]->getId() == id) {
            auto fim = std::chrono::steady_clock::now();   
            auto duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio);
            std::cout << "Tempo de busca: " << duracao.count() << " nanossegundos" << std::endl;
            return sensores[h];
        }
        i++;
    }
    auto fim = std::chrono::steady_clock::now();   
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    std::cout << "Tempo de busca: " << duracao.count() << " ms" << std::endl;
    return std::nullopt;
}

bool Tabela::atualizarLeitura(int id, float valor) {
    int i = 0;

    while(i < tamanho) {
        int h = funcaoHash(i,id);
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

void Tabela::testeDesempenho() {
    
    cout << "\n-- Iniciando Teste de Desempenho (1000 Sensores) --" << endl;
    
    auto inicio = chrono::high_resolution_clock::now();

    int inseridos = 0;
    int colisoes = 0;
    for (int i = 0; i < 1000; i++) {
        int id_gerado = rand() % 5000;
        string tipo_gerado = "Tipo_" + to_string(i);
        string local_gerado = "Setor_" + to_string(i);
        
        Sensor s(id_gerado, tipo_gerado, local_gerado);
        colisoes += cadastarSensor(s);
        inseridos++;
    }

    auto fim = chrono::high_resolution_clock::now();
    
    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);

    cout << "\n" << inseridos << " sensores foram gerados e inseridos." << endl;
    cout << "Tempo de execucao da insercao: " << duracao.count() << " microssegundos." << endl;
    std::cout << "Colisoes: " << colisoes <<std::endl;  
}

bool Tabela::removerSensor(int id) {
    int i = 0;

    while(i < tamanho) {
        int h = funcaoHash(i,id);
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

int Tabela::funcaoHash(int i, int id){
    int h1 = id % tamanho;
    int h2 = 997 - (id % 977);
    return (h1 + i * h2) % tamanho;
}

#ifndef TABELA_H
#define TABELA_H

#include <vector>
#include <array>
#include <optional>
#include "Sensor.h"

class Tabela{
    private:
        std::array<std::optional<Sensor>, 10> sensores;
        int tamanho;
    public:
        Tabela();
        void cadastarSensor(Sensor sensor);
        void atualizarLeitura(int id);
        Sensor getSensor(int id);
        void removerSensor(int id);
        void exibirSensores();
};

//POSSIBILIDADE DE FUNÇÃO HASHING:
//Double hashing: H(k, i) = (h1(k) + i * h2(k)) % m

//h1(k) = k % m

//h2(k) = primo menor que m - (k % primo menor que m)

#endif
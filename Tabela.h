#define TABELA_H

#include <vector>
#include <array>
#include <optional>
#include "Sensor.h"

class Tabela{
    private:
        std::array<std::optional<Sensor>, 1000> sensores;
        int tamanho;
    public:
        Tabela();
        int cadastarSensor(Sensor sensor);
        bool atualizarLeitura(int id, float valor);
        std::optional<Sensor> getSensor(int id);
        void removerSensor(int id);
        void exibirSensores();
        void testeDesempenho();
};

//POSSIBILIDADE DE FUNÇÃO HASHING:
//Double hashing: H(k, i) = (h1(k) + i * h2(k)) % m

//h1(k) = k % m

//h2(k) = primo menor que m - (k % primo menor que m)
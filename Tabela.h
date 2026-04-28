#define TABELA_H

#include <vector>
#include <array>
#include <optional>
#include "Sensor.h"

class Tabela{
    private:
        std::array<std::optional<Sensor>, 11> sensores;
        int tamanho;
    public:
        Tabela();
        int cadastarSensor(Sensor sensor);
        bool atualizarLeitura(int id, float valor);
        std::optional<Sensor> getSensor(int id);
        bool removerSensor(int id);
        void exibirSensores();
        void testeDesempenho();
        int funcaoHash(int i, int id);
};

//POSSIBILIDADE DE FUNÇÃO HASHING:
//Double hashing: H(k, i) = (h1(k) + i * h2(k)) % m

//h1(k) = k % m

//h2(k) = primo menor que m - (k % primo menor que m)
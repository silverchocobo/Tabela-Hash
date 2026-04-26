#include "Sensor.h"
#include "Tabela.h"

int main(){

    Tabela tabela;

    // 1. Inserções normais (Sem colisão)
    Sensor s1(15, "Temperatura", "Sala 1");   // Vai para Pos 5
    Sensor s2(23, "Umidade", "Estufa");       // Vai para Pos 3
    tabela.cadastarSensor(s1);
    tabela.cadastarSensor(s2);

    // 2. Primeira Colisão (ID 35 bate no 15)
    Sensor s3(35, "Pressao", "Laboratorio");  // Vai para Pos 7
    tabela.cadastarSensor(s3);

    // 3. Colisões em Cadeia (ID 45 e 5 batem no 15, 35 e entre si)
    Sensor s4(45, "Luz", "Jardim");           // Vai para Pos 9
    Sensor s5(5,  "Movimento", "Corredor");   // Vai para Pos 1
    tabela.cadastarSensor(s4);
    tabela.cadastarSensor(s5);

    // 4. Mais inserções e nova colisão
    Sensor s6(10, "Fumaca", "Cozinha");       // Vai para Pos 0
    Sensor s7(20, "Gas", "Porão");            // Vai para Pos 4 (Colide com 10)
    tabela.cadastarSensor(s6);
    tabela.cadastarSensor(s7);

    // 5. Preenchendo os ultimos espaços vazios
    Sensor s8(12, "Agua", "Caixa D'Agua");    // Vai para Pos 2
    Sensor s9(18, "Vento", "Telhado");        // Vai para Pos 8
    Sensor s10(16, "Ruido", "Rua");           // Vai para Pos 6
    tabela.cadastarSensor(s8);
    tabela.cadastarSensor(s9);
    tabela.cadastarSensor(s10);

    tabela.exibirSensores();
}
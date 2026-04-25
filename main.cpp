#include "Sensor.h"
#include "Tabela.h"

int main(){

    Tabela tabela;
    Sensor sensor1(1,"Batata","Porto Alegre");
    tabela.cadastarSensor(sensor1);
    tabela.exibirSensores();
}
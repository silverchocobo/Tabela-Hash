#include <iostream>
#include <string>
#include <chrono>
#include "Sensor.h"
#include "Tabela.h"
#include <thread>

using namespace std;

void exibirMenu() {
    cout << "\n=-=-=-=-=-= SISTEMA DE MONITORAMENTO AGRICOLA =-=-=-=-=-=" << endl;
    cout << "1) Cadastrar sensor" << endl;
    cout << "2) Atualizar leitura" << endl;
    cout << "3) Buscar sensor" << endl;
    cout << "4) Remover sensor TODO" << endl;
    cout << "5) Exibir sensores" << endl;
    cout << "6) Teste de desempenho" << endl;
    cout << "0) Sair do sistema" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    Tabela tabela;
    int opcao;

    do {
        exibirMenu();

        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore('\n');
            opcao = -1;
        }

        switch(opcao) {
            case 1: {
                int id;
                string tipo, localizacao;
                cout << "Digite o ID do sensor (numero inteiro): ";
                cin >> id;
                
                cout << "Digite o Tipo do sensor: ";
                cin >> ws; 
                getline(cin, tipo);
                
                cout << "Digite a Localizacao do sensor: ";
                getline(cin, localizacao);
                
                Sensor novoSensor(id, tipo, localizacao);
                tabela.cadastarSensor(novoSensor);
                cout << "Sensor cadastrado com sucesso!" << endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
                break;
            }
            case 2: {
                int idBusca;
                float novaLeitura;
                cout << "Digite o ID do sensor: ";
                cin >> idBusca;
                cout << "Digite o valor da nova leitura: ";
                cin >> novaLeitura;
                
                if (tabela.atualizarLeitura(idBusca, novaLeitura)) {
                    cout << "Leitura atualizada com sucesso!" << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                } else {
                    cout << "Sensor com ID " << idBusca << " nao encontrado." << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                }
                break;
            }
            case 3: {
                int idBusca;
                cout << "\n-- Buscar Sensor --" << endl;
                cout << "Digite o ID do sensor: ";
                cin >> idBusca;
                
                std::optional<Sensor> encontrado = tabela.getSensor(idBusca);
                if (encontrado) {
                    cout << "Sensor encontrado!" << endl;
                    cout << "Tipo: " << encontrado->getTipo() << " | Local: " << encontrado->getLocalizacao() << " | Ultima Leitura: " << encontrado->getUltimaLeitura() << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                } else {
                    cout << "Sensor com ID " << idBusca << " nao encontrado." << endl;
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                }
                break;
            }
            case 4:
                // TODO remocao
                cout << "\nTODO" << endl;
                break;
            case 5:
                cout << "\n-- Lista de Sensores --" << endl;
                tabela.exibirSensores();
                std::this_thread::sleep_for(std::chrono::seconds(5));
                break;
            case 6:
                tabela.testeDesempenho();
                std::this_thread::sleep_for(std::chrono::seconds(5));
                break;
            case 0:
                cout << "\nSaindo do sistema" << endl;
                break;
            default:
                cout << "\nOpcao invalida." << endl;
        }
    } while (opcao != 0);

    return 0;
}
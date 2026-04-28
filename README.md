# Tabela Hash - Sistema de Monitoramento Agrícola
Trabalho do Grau A de Algoritmos e Programação Estruturas Avançadas de Dados. Simula um sistema para sensores distribuídos em uma propriedade rural. Cada sensor tem ID único usado como chave, e a tabela faz inserção, busca, atualização e remoção.
## Como rodar
Compilar:
```
g++ -std=c++17 main.cpp Sensor.cpp Tabela.cpp -o main
```
Executar:
```
./main
```

## Visão geral
O programa apresenta um menu interativo onde o usuário cadastra sensores informando ID, tipo e localização. A tabela hash recebe esses sensores e usa o ID como chave para calcular a posição de armazenamento. Quando duas chaves caem no mesmo índice, o duplo hashing recalcula uma nova posição usando uma segunda função hash, evitando o clustering que aconteceria com sondagem linear. Além do cadastro, o usuário pode atualizar a leitura de um sensor existente, buscar um sensor pelo ID, remover um sensor (tombstone) e listar todos os sensores.
## Função hash
Foi adotado o **duplo hashing**, definido por:
```
H(k, i) = (h1(k) + i * h2(k)) % m
```
Onde:
- `k` é o ID do sensor
- `i` é o número da tentativa
- `m` é o tamanho da tabela
- `j` é um número primo pouco menor que m
- `h1(k) = k % m` é a função hash primária
- `h2(k) = j - (k % j)` é a função hash secundária

A primeira função define a posição inicial. Se houver colisão, a segunda função define o passo de sondagem, que varia conforme a chave. Isso evita o agrupamento primário da sondagem linear e o agrupamento secundário da sondagem quadrática, distribuindo as chaves de forma mais uniforme pela tabela.

## Métodos
### Sensor(int, string, string)
Construtores da classe Sensor. O construtor padrão inicializa `ultimaLeitura` em -1.0 (indicando que ainda não obteve nenhuma leitura). Recebe ID, tipo e localização.
### Sensor::getId() / getTipo() / getLocalizacao() / getUltimaLeitura()
Getters do sensor. Retornam respectivamente o ID, o tipo, a localização e o valor da última leitura armazenada.
### Sensor::setUltimaLeitura(float)
Setter que atualiza o valor da última leitura do sensor.
### Tabela::Tabela()
Construtor da tabela. Inicializa o atributo `tamanho` com o tamanho do array interno. As posições começam vazias (`std::nullopt`).
### Tabela::funcaoHash(int i, int id)
Implementa a função de duplo hashing descrita acima. Recebe o número da tentativa `i` e o ID do sensor, e retorna o índice na tabela.
### Tabela::cadastarSensor(Sensor)
Insere um novo sensor na tabela. Em um laço, calcula a posição via `funcaoHash` para tentativas crescentes (i = 0, 1, 2, ...) até encontrar um slot vazio ou um tombstone (sensor com ID -1). Retorna o número de tentativas até inserir, ou -1 se a tabela estiver cheia.
### Tabela::getSensor(int id)
Busca um sensor pelo ID. Aplica o duplo hashing percorrendo a sequência de sondagem até achar o sensor com ID correspondente ou bater num slot vazio (que indica que o sensor não existe). Retorna `std::optional<Sensor>`.
### Tabela::atualizarLeitura(int id, float valor)
Localiza o sensor pelo ID seguindo a mesma sequência de sondagem da busca, e atualiza o valor da última leitura. Retorna `true` se encontrou e atualizou, `false` se o sensor não existe.
### Tabela::removerSensor(int id)
Remove um sensor pelo ID. Substitui o sensor por um tombstone (sensor com id -1). Retorna `true` se removeu, `false` se não encontrou.
### Tabela::exibirSensores()
Percorre todas as posições da tabela e imprime ID, tipo e localização dos sensores presentes. Posições vazias e tombstones são marcadas como "VAZIA".
### main()
Loop principal do menu interativo. Apresenta as opções (cadastrar, atualizar leitura, buscar, remover, exibir, teste de desempenho, sair), lê a entrada do usuário e chama o método correspondente da tabela.
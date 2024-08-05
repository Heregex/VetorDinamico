## README.md

# Definição e implementação de um vetor dinâmico

Este repositório contém a implementação de vetores dinâmicos em C++, utilizando duas abordagens: alocação dinâmica de arrays e listas duplamente ligadas. O objetivo é comparar o desempenho dessas implementações em diferentes cenários, avaliando suas vantagens e desvantagens em termos de eficiência, uso de memória e complexidade de código.

## Relatório

O relatório detalhado da implementação e análise de desempenho está disponível no arquivo `relatorio.pdf`. O relatório aborda os seguintes tópicos:

* Introdução aos vetores dinâmicos.
* Descrição das duas abordagens de implementação.
* Detalhes da implementação de cada classe, incluindo os métodos e suas complexidades.
* Análise comparativa do desempenho das duas implementações, com base em testes e resultados.

## Arquivos

* **`array_list.hpp`:**  Declaração da classe `array_list` (implementação com array dinâmico).
* **`linked_list.hpp`:** Declaração da classe `linked_list` (implementação com lista duplamente ligada).
* **`gera_num.cpp`:**  Programa que gera um .txt com números aleatórios para os testes.
* **`test-pushfront-array-list-01.cpp`:** Teste de inserção no início para `array_list`.
* **`test-pushfront-linked-list-01.cpp`:** Teste de inserção no início para `linked_list`.
* **`test-removeat-array-list-01.cpp`:** Teste de remoção por índice para `array_list`.
* **`test-removeat-linked-list-01.cpp`:** Teste de remoção por índice para `linked_list`.
* **`/push/e[1-5].txt`:** Arquivos de entrada para os testes de inserção.
* **`/remove_at/e[1-2].txt`:** Arquivos de entrada para os testes de remoção.

## Como Compilar e Executar os Testes

**1. Compilar o Gerador de Números:**

```bash
g++ gera_num.cpp -o gera_num
```

**2. Gerar Arquivos de Entrada:**

```bash
./gera_num <qtd_números> nome_arquivo.txt
```

**3. Compilar os Testes:**

```bash
g++ <arquivo_de_teste>.cpp -o <nome_do_executavel>.exe
```

**4. Executar os Testes:**

```bash
./<nome_do_executavel>.exe < <arquivo_de_teste>.txt
# <arquivo_de_teste>.txt localizados em /push e /remove_at
```
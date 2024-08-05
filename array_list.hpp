#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

#include <iostream>

class array_list {
private:
    int *data;
    unsigned int size_;
    unsigned int capacity_;

    // Aumenta a capacidade do vetor
    void increase_capacity() {
        unsigned int new_capacity = capacity_;

        // 4.1.1. Aumentar em 100:
        new_capacity += 100; 

        // 4.1.2. Aumentar em 1000:
        // new_capacity += 1000;

        // 4.1.3. Duplicar a capacidade (definir tamanho inicial 8 no construtor):
        // new_capacity *= 2;

        int *new_data = new int[new_capacity];

        // Copia os elementos para o novo vetor
        for (unsigned int i = 0; i < size_; ++i) {
            new_data[i] = data[i]; 
        }

        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    array_list() {
        // Para usar com implementação 4.1.3:
        // data = new int[8];
        capacity_ = 8;
        size_ = 0;
        // Para usar com implementações 4.1.1/2:
        data = new int[capacity_];
    }

    ~array_list() {
        delete[] data;
    }

    // Recupera a quantidade de elementos do vetor.
    // Complexidade Big-O: O(1)
    unsigned int size() {
        return size_;
    }

    // Recupera a capacidade atual do vetor. 
    // Complexidade Big-O: O(1)
    unsigned int capacity() {
        return capacity_;
    }

    // Recupera a porcentagem de ocupação do vetor. 
    // Complexidade Big-O: O(1)
    double percent_occupied() {
        return static_cast<double>(size_) / capacity_;
    }

    // Insere um elemento value na posição index.
    // Complexidade Big-O: O(n)
    bool insert_at(unsigned int index, int value) {
        if (index > size_) {
            return false; // index inválido
        }

        if (size_ == capacity_) {
            increase_capacity(); // aumenta a capacidade, se necessário
        }

        // Desloca os elementos para a direita a partir do índice
        for (unsigned int i = size_; i > index; --i) {
            data[i] = data[i - 1];
        }

        data[index] = value; // Insere o valor na posição index
        ++size_;

        return true;
    }

    // Remove um elemento na posição index. 
    // Complexidade Big-O: O(n)
    bool remove_at(unsigned int index) {
        if (index >= size_) {
            return false; // index inválido
        }

        // Desloca os elementos para a esquerda a partir do índice
        for (unsigned int i = index; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }

        --size_;

        return true;
    }

    // Recupera o elemento na posição index. 
    // Complexidade Big-O: O(1)
    int get_at(unsigned int index) {
        if (index >= size_) {
            return -1; // -1 se index for inválido.
        }
        
        return data[index];
    }

    // Remove todos os elementos do vetor.
    // Complexidade Big-O: O(1)
    void clear() {
        delete[] data;             // Libera a memória do array antigo
        data = new int[capacity_]; // Realoca um novo array vazio com a mesma capacidade
        size_ = 0;                 // Redefine o tamanho
    }

    // Adiciona um elemento value no final do vetor. 
    // Complexidade Big-O: O(1)
    void push_back(int value) {
        if (size_ == capacity_) {
            increase_capacity(); // Aumenta a capacidade se necessário
        }

        data[size_++] = value;
    }

    // Adiciona um elemento value no início do vetor.
    // Complexidade Big-O: O(n)
    void push_front(int value) {
        if (size_ == capacity_) {
            increase_capacity(); // Aumenta a capacidade se necessário
        }

        // Desloca todos os elementos uma posição para a direita
        for (unsigned int i = size_; i > 0; --i) {
            data[i] = data[i - 1];
        }

        data[0] = value; // Insere o novo valor no início
        ++size_;         // Aumenta o tamanho do vetor
    }

    // Remove o último elemento do vetor. 
    // Complexidade Big-O: O(1)
    bool pop_back() {
        if (size_ == 0) {
            return false; // vetor vazio
        }

        --size_; // Reduz o tamanho do vetor
        data[size_] = 0;

        return true;
    }

    // Remove o primeiro elemento do vetor. 
    // Complexidade Big-O: O(n)
    bool pop_front() {
        if (size_ == 0) {
            return false; // vetor vazio
        }

        // Desloca todos os elementos uma posição para a esquerda
        for (unsigned int i = 1; i < size_; ++i) {
            data[i - 1] = data[i];
        }

        --size_; // Reduz o tamanho do vetor

        return true;
    }

    // Recupera o último elemento do vetor.
    // Complexidade Big-O: O(1)
    int back() {
        if (size_ == 0) {
            return -1; // vetor vazio, retorna -1
        }

        return data[size_ - 1];
    }

    // Retorna o primeiro elemento do vetor.
    // Complexidade Big-O: O(1)
    int front() {
        if (size_ == 0) {
            return -1; // vetor vazio, retorna -1
        }

        return data[0];
    }

    // Remove o valor informado para value.
    // Complexidade Big-O: O(n)
    bool remove(int value) {
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) {
                return remove_at(i);
            }
        }

        return false;
    }

    // Recupera o índice de value.
    // Complexidade Big-O: O(n)
    int find(int value) {
        // Percorre o vetor até achar value
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) {
                return i;
            }
        }

        return -1; // value não encontrado, retorna -1
    }

    // Recupera a quantidade de vezes que o elemento value aparece no vetor.
    // Complexidade Big-O: O(n)
    int count(int value) {
        int count = 0; // contador

        // Percorre o vetor contando as ocorrências de value
        for (unsigned int i = 0; i < size_; ++i) {
            if (data[i] == value) {
                ++count; // incrementa contador
            }
        }

        return count;
    }

    // Retorna a soma dos elementos do vetor.
    // Complexidade Big-O: O(n)
    int sum() {
        int sum = 0;
        
        // Percorre o vetor somando os elementos
        for (unsigned int i = 0; i < size_; ++i) {
            sum += data[i];
        }

        return sum;
    }
};

#endif // __ARRAY_LIST_IFRN__
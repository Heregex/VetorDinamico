#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
#include <iostream>

class linked_list {
private:
    struct int_node {
        int value;
        int_node *next, *prev;
    };

    int_node *head, *tail;
    unsigned int size_;

public:
    linked_list() {
        head = nullptr;
        tail = nullptr;
        size_ = 0;
    }

    ~linked_list() {
        int_node* current = this->head;

        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;

            delete to_remove;
        }
    }

    // Recupera a quantidade de elementos da lista.
    // Complexidade Big-O: O(1)
    unsigned int size() {
        return size_;
    }

    // Recupera a capacidade atual da lista. 
    // Complexidade Big-O: O(1)
    unsigned int capacity() {
        return size_;
    }

    // Recupera a porcentagem de ocupação da lista.
    // Complexidade Big-O: O(1)
    double percent_occupied() {
        return 100.0; // 100.0: a lista está sempre 100% preenchida
    }

    // Insere um elemento value na posição index.
    // Complexidade Big-O: O(n)
    bool insert_at(unsigned int index, int value) {
        if (index > size_) {
            return false; // index inválido
        }

        // Usa push_front() em caso de
        // inserção no início
        if (index == 0) {
            push_front(value);
            return true;
        }

        // Usa push_back() em caso de
        // inserção no final
        if (index == size_) {
            push_back(value);
            return true;
        }

        // Cria novo nó
        int_node *new_node = new int_node;
        new_node->value = value;

        int_node *current = head;

        for (unsigned int i = 0; i < index - 1; ++i) {
            current = current->next;
        }

        // Reorganiza ponteiros
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;

        ++size_;

        return true;
    }

    // Remove um elemento da posição index. 
    // Complexidade Big-O: O(n)
    bool remove_at(unsigned int index) {
        if (index >= size_) {
            return false; // index inválido
        }

        int_node *current = head;

        // Encontra o nó a ser removido
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }


        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next; // Nó a ser removido é o HEAD
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev; // Nó a ser removido é o TAIL
        }

        delete current; // Libera memória do nó removido
        --size_;

        return true;
    }

    // Recupera o elemento na posição index.
    // Complexidade Big-O: O(n)
    int get_at(unsigned int index) {
        if (index >= size_) {
            return -1; // index inválido, retorna -1
        }

        int_node *current = head;

        // Encontra o nó para index
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->value;
    }

    // Remove todos os elementos da lista.
    // Complexidade Big-O: O(n)
    void clear() {
        // Remove o primeiro elemento da lista até que 
        // não sobre nenhum (head->nullptr)
        while (head != nullptr) {
            pop_front();
        }
    }

    // Adiciona um elemento value no final da lista. 
    // Complexidade Big-O: O(1)
    void push_back(int value) {
        // Cria novo nó
        int_node *new_node = new int_node;

        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = tail;

        if (tail != nullptr) {
            // lista vazia: HEAD->new_node
            tail->next = new_node;
        } else {
            head = new_node;
        }

        tail = new_node; // TAIL->new_node
        ++size_;
    }

    // Adiciona um elemento value no início da lista.
    // Complexidade Big-O: O(1)
    void push_front(int value) {
        // Cria novo nó
        int_node *new_node = new int_node;
        new_node->value = value;
        new_node->next = head;
        new_node->prev = nullptr;

        if (head != nullptr) {
            head->prev = new_node;
        } else {
            // lista vazia: TAIL->new_node
            tail = new_node;
        }

        head = new_node; // HEAD->new_node
        ++size_;
    }

    // Remove o último elemento da lista.
    // Complexidade Big-O: O(1)
    bool pop_back() {
        if (tail == nullptr) {
            return false; // lista vazia
        }

        int_node *temp = tail; // ponteiro temporário
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // lista vazia
        }

        delete temp; // libera memória do nó removido
        --size_;

        return true;
    }

    // Remove o primeiro elemento da lista.
    // Complexidade Big-O: O(1)
    bool pop_front() {
        if (head == nullptr) {
            return false; // lista vazia
        }

        int_node *temp = head; // ponteiro temporário
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // lista vazia
        }

        delete temp; // libera memória do nó removido
        --size_;

        return true;
    }

    // Recupera o último elemento da lista.
    // Complexidade Big-O: O(1)
    int back() {
        if (tail == nullptr) {
            return -1; // lista vazia, retorna -1
        }

        return tail->value;
    }

    // Retorna o primeiro elemento da lista.
    // Complexidade Big-O: O(1)
    int front() {
        if (head == nullptr) {
            return -1; // lista vazia, retorna -1
        }

        return head->value;
    }

    // Remove o valor informado para value.
    // Complexidade Big-O: O(n)
    bool remove(int value) {
        int_node *current = head;

        // Percorre a lista procurando por value
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    // Nó a ser removido é o HEAD
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    // Nó a ser removido é o TAIL
                    tail = current->prev;
                }

                delete current; // Libera memória do nó removido
                --size_;

                return true;
            }

            current = current->next;
        }

        return false;
    }

    // Recupera o índice de value.
    // -1 se não for encontrado.
    // Complexidade Big-O: O(n)
    int find(int value) {
        int_node *current = head;
        unsigned int index = 0;
        
        // Percorre a lista procurando por value
        while (current != nullptr) {
            if (current->value == value) {
                return index;
            }

            ++index;
            current = current->next; // próximo nó
        }

        return -1;
    }

    // Recupera a quantidade de vezes que o elemento value aparece na lista. 
    // Complexidade Big-O: O(n)
    int count(int value) {
        int count = 0;
        int_node *current = head;

        // Percorre a lista contando as ocorrências de value
        while (current != nullptr) {
            if (current->value == value) {
                ++count;
            }
            
            current = current->next;
        }

        return count;
    }

    // Retorna a soma dos elementos da lista.
    // Complexidade Big-O: O(n)
    int sum() {
        int sum = 0;
        int_node *current = head;

        // Percorre a lista somando os valores dos nós
        while (current != nullptr) {
            sum += current->value;
            current = current->next;
        }
        
        return sum;
    }
};

#endif // __LINKED_LIST_IFRN__
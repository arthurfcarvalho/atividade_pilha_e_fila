#include <stdio.h>

struct No{

    int valor;
    No *prox;

    No(){
        valor = NULL;
        prox = NULL;
    }

    No(int _valor){
        valor = _valor;
        prox = NULL;
    }

};

struct Pilha {

    No *topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (topo == NULL);
    }

    void inserir(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = topo;
                topo = NULL;
                delete(aux);
            } else {
                No *aux = topo;
                topo = topo->prox;
                delete(aux);
            }
            n--;
        }
    }

    int topoPilha() {
        if (vazia()) {
            return NULL;
        }
        return topo->valor;
    }

};

struct Fila {
    No *cabeca, *cauda;
    int n;

    Fila() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserir(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    int frente() {
        if (vazia()) {
            return NULL;
        }
        return cabeca->valor;
    }

    void inverter(){

        No *aux = cabeca;
        Pilha p;

        while(aux != NULL){

            p.inserir(aux->valor);
            aux = aux->prox;
        }

        aux = cabeca;

        while(aux != NULL){

            remover();
            aux = cabeca;
        }

        aux = p.topo;

        while(aux != NULL){
            inserir(aux->valor);
            aux = aux->prox;
        }

        aux = cabeca;

        while(aux != NULL){

            printf("%d -> ", aux->valor);
            aux = aux->prox;
        }
    }
};




int main(){

    Fila f;

    f.inserir(1);
    f.inserir(2);
    f.inserir(3);
    f.inserir(4);
    f.inserir(5);

    f.inverter();

    return 0;
}

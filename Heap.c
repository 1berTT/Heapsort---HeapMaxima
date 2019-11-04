#include <stdio.h>
#include <stdlib.h>

void subir(int i, int* vetor, int tamanho){
    int pai = i/2;
    if(pai >= 1){
        if(vetor[i] > vetor[pai]){
            int aux = vetor[i];
            vetor[i] = vetor[pai];
            vetor[pai] = aux;
            subir(pai, vetor, tamanho);
        }
    }
}

void descer(int i, int* vetor, int tamanho){
    int filhoEsq = 2*i;
    int filhoDir = filhoEsq + 1;


    if(filhoDir <= tamanho){

        if(vetor[i] < vetor[filhoEsq] || vetor[i] < vetor[filhoDir]){
            if(vetor[filhoEsq] >= vetor[filhoDir]){
                int aux = vetor[i];
                vetor[i] = vetor[filhoEsq];
                vetor[filhoEsq] = aux;
                descer(filhoEsq, vetor, tamanho);
            }else{
                int aux = vetor[i];
                vetor[i] = vetor[filhoDir];
                vetor[filhoDir] = aux;
                descer(filhoDir, vetor, tamanho);
            }
        }
    }else if(filhoEsq <= tamanho && filhoDir > tamanho){
        if(vetor[filhoEsq] >= vetor[i]){
            int aux = vetor[i];
            vetor[i] = vetor[filhoEsq];
            vetor[filhoEsq] = aux;
            descer(filhoEsq, vetor, tamanho);
        }
    }
}

void constroiHeap(int* vetor, int tamanho){
    for(int i=(tamanho/2); i>=1; i--){
        descer(i,vetor,tamanho);
    }
}

void inserir(int novo, int* vetor, int tamanho){
    vetor[tamanho+1] = novo;
    tamanho = tamanho + 1;
    subir(tamanho, vetor, tamanho);
}

void remover(int* vetor, int tamanho){
    if(tamanho != 0){
        vetor[1] = vetor[tamanho];
        tamanho = tamanho - 1;
        descer(1, vetor, tamanho);
    }else{
        printf("ja ta vazio...");
    }
}

void heapSort(int* vetor, int tam){
    constroiHeap(vetor, tam);
    for(int i=1; i<=tam; i++){
        printf("%i ", vetor[i]);
    }
    printf("\n");

    for(int i=tam; i>=2; i--){
        int aux = vetor[i];
        vetor[i] = vetor[1];
        vetor[1] = aux;
        descer(1, vetor, i-1);
    }

    for(int i=1; i<=tam; i++){
        printf("%i ", vetor[i]);
    }
}


void main(){
    int opcao;
    int *vetor;
    int tamanho;
    int incremento = 0;
    printf("Informe o numero de componentes do vetor\n");
    scanf("%i", &tamanho);
    vetor = (int *) malloc(tamanho * sizeof(int));
    printf("\n");
    while(opcao != 5){
        printf("\n--------------------------------------------------------------------------\n");
        printf("--------------------------------------------------------------------------\n");
        printf("---0 para ver Heap, 1 para add, 2 para remover, 4 para rodar heapsort:----\n");
        printf("--------------------------------------------------------------------------\n");
        printf("--------------------------------------------------------------------------\n");
        scanf("%i", &opcao);
        printf("\n");
        if(opcao == 1){
            if(incremento < tamanho){
                int add;
                printf("Digite o valor a ser inserido: ");
                scanf("%i", &add);
                inserir(add, vetor, incremento);
                incremento++;
            }else{
                printf("Vetor ta cheio... \n");
            }

        }else if(opcao == 2){
            remover(vetor, incremento);
            incremento--;
        }else if(opcao == 0){
            if(incremento == 0){
                printf("Ta vazio...");
            }
            for(int i=1; i<=incremento; i++){
                printf(" %i ", vetor[i]);
            }
        }else if(opcao == 4){
            heapSort(vetor, incremento);
            exit(0);
        }else{
            exit(0);
        }
    }
}

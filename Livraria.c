
#include "Livraria.h"

// Funcao para criar um novo livro
Livro* criarLivro(char* titulo, char* autor, char* ISBN, int status) {
    Livro* novoLivro = (Livro*)malloc(sizeof(Livro));
    if (novoLivro == NULL) {
        printf("Erro ao alocar memoria para o novo livro.\n");
        return NULL;
    }
    strcpy(novoLivro->titulo, titulo);
    strcpy(novoLivro->autor, autor);
    strcpy(novoLivro->ISBN, ISBN);
    novoLivro->status = status;
    novoLivro->prox = NULL;
    return novoLivro;
}

// Funcao printar opcao invalida
void printOpcaoInvalida() {
    printf("\nOpcao invalida! Tente novamente.\n");
}

// Funcao printar lista vazia
void printListaVazia() {
    printf("Nenhum livro na lista.\n");
}

// Funcao para adicionar um livro a lista
void adicionarLivro(Livro** lista, Livro* novoLivro) {
    if (*lista == NULL) {
        *lista = novoLivro;
    } else {
        Livro* temp = *lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoLivro;
    }
    printf("Livro adicionado com sucesso!\n");
}

// Funcao para listar todos os livros
void listarLivros(Livro* lista) {
    if (lista == NULL) {
        printListaVazia();
        return;
    }
    Livro* temp = lista;
    while (temp != NULL) {
        printf("\nTitulo: %s\n", temp->titulo);
        printf("Autor: %s\n", temp->autor);
        printf("ISBN: %s\n", temp->ISBN);
        printf("Status: %s\n", temp->status == 0 ? "Disponivel" : "Emprestado");
        printf("--------------------------\n");
        temp = temp->prox;
    }
}

// Funcao para listar os livros Disponiveis
void listarLivrosDisponiveis(Livro* lista) {
    if (lista == NULL) {
        printListaVazia();
        return;
    }
    Livro* temp = lista;
    while (temp != NULL) {
        if(temp->status == 0) {
            printf("\nTitulo: %s\n", temp->titulo);
            printf("Autor: %s\n", temp->autor);
            printf("ISBN: %s\n", temp->ISBN);
            printf("Status: %s\n", temp->status == 0 ? "Disponivel" : "Emprestado");
            printf("--------------------------\n");
        }
        temp = temp->prox;
    }
}

// Funcao para listar os livros Emprestados
void listarLivrosEmprestados(Livro* lista) {
    if (lista == NULL) {
        printListaVazia();
        return;
    }
    Livro* temp = lista;
    while (temp != NULL) {
        if(temp->status == 1) {
            printf("\nTitulo: %s\n", temp->titulo);
            printf("Autor: %s\n", temp->autor);
            printf("ISBN: %s\n", temp->ISBN);
            printf("Status: %s\n", temp->status == 0 ? "Disponivel" : "Emprestado");
            printf("--------------------------\n");
        }
        temp = temp->prox;
    }
}

// Funcao para atualizar um livro pelo ISBN
void atualizarLivro(Livro* lista, char* ISBN) {
    if (lista == NULL) {
        printListaVazia();
        return;
    }
    Livro* temp = lista;
    while (temp != NULL) {
        if (strcmp(temp->ISBN, ISBN) == 0) {
            printf("Atualizando livro: %s\n", temp->titulo);
            printf("Digite o novo titulo:");
            getchar();
            fgets(temp->titulo, sizeof(temp->titulo), stdin);
            temp->titulo[strcspn(temp->titulo, "\n")] = '\0';
            printf("Digite o novo autor:");
            fgets(temp->autor, sizeof(temp->autor), stdin);
            temp->autor[strcspn(temp->autor, "\n")] = '\0';
            printf("Digite o novo status (0 para disponivel, 1 para emprestado):");
            scanf("%d", &temp->status);
            getchar(); // Limpar o buffer
            printf("Livro atualizado com sucesso!\n");
            return;
        }
        temp = temp->prox;
    }
    printf("Livro com ISBN %s nao encontrado.\n", ISBN);
}

// Funcao para deletar um livro pelo ISBN
void deletarLivro(Livro** lista, char* ISBN) {
    if (*lista == NULL) {
        printListaVazia();
        return;
    }
    Livro* temp = *lista;
    Livro* anterior = NULL;

    while (temp != NULL) {
        if (strcmp(temp->ISBN, ISBN) == 0) {
            if (anterior == NULL) {
                *lista = temp->prox;
            } else {
                anterior->prox = temp->prox;
            }
            free(temp);
            printf("Livro deletado com sucesso!\n");
            return;
        }
        anterior = temp;
        temp = temp->prox;
    }
    printf("Livro com ISBN %s nao encontrado.\n", ISBN);
}

// Funcao Bubble Sort para ordenar livros por titulo
void bubbleSort(Livro** lista) {
    if (*lista == NULL) {
        printListaVazia();
        return;
    }

    int trocado;
    Livro *ptr1;
    Livro *lptr = NULL;

    do {
        trocado = 0;
        ptr1 = *lista;

        while (ptr1->prox != lptr) {
            if (strcmp(ptr1->titulo, ptr1->prox->titulo) > 0) {
                // Troca os dados dos livros
                char tempTitulo[100], tempAutor[50], tempISBN[13];
                int tempStatus;

                strcpy(tempTitulo, ptr1->titulo);
                strcpy(tempAutor, ptr1->autor);
                strcpy(tempISBN, ptr1->ISBN);
                tempStatus = ptr1->status;

                strcpy(ptr1->titulo, ptr1->prox->titulo);
                strcpy(ptr1->autor, ptr1->prox->autor);
                strcpy(ptr1->ISBN, ptr1->prox->ISBN);
                ptr1->status = ptr1->prox->status;

                strcpy(ptr1->prox->titulo, tempTitulo);
                strcpy(ptr1->prox->autor, tempAutor);
                strcpy(ptr1->prox->ISBN, tempISBN);
                ptr1->prox->status = tempStatus;

                trocado = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (trocado);
    printf("Livros ordenados por titulo.\n");
}

// Funcao para imprimir o Menu na tela
void interfaceMenu(int* opcao) {
    printf("\nMenu:\n");
    printf("1. Adicionar livro\n");
    printf("2. Listar livros\n");
    printf("3. Atualizar livro\n");
    printf("4. Deletar livro\n");
    printf("5. Ordenar livros por titulo\n");
    printf("6. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", opcao);
    getchar();
}

// Funcao para inserir um livro na lista
void inputDadosLivro(Livro** lista) {
    char titulo[100], autor[50], ISBN[13];
    int status = 99;

    printf("\nDigite o titulo do livro: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';
    printf("Digite o autor do livro: ");
    fgets(autor, sizeof(autor), stdin);
    autor[strcspn(autor, "\n")] = '\0';
    printf("Digite o ISBN do livro: ");
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';
    printf("Digite o status do livro (0 para disponivel, 1 para emprestado): \n");
    scanf("%d", &status);
    getchar();
    while(status != 1 && 0 != status) {
        printOpcaoInvalida();
        scanf("%d", &status);
        getchar();
    }

    Livro* novoLivro = criarLivro(titulo, autor, ISBN, status);
    if (novoLivro != NULL) {
        adicionarLivro(lista, novoLivro);
    }

}

// Funcao para pegar uma input de string
char* pegarString(char string[15]) {
    char *ISBN = malloc(sizeof(char) * 13);
    printf("Digite o ISBN do livro a ser %s: ", string);
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strcspn(ISBN, "\n")] = '\0';

    return ISBN;
}

// Funcao para liberar a memoria da lista
void liberarMemoriaLista(Livro* lista) {
    Livro* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

// Funcao para listar as listagens de livros
void interfaceListarLivros(Livro* lista) {

    int opcao;
    do {
        printf("\nListar:\n");
        printf("1. Todos\n");
        printf("2. Disponiveis\n");
        printf("3. Emprestados\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                listarLivros(lista);
                break;
            case 2:
                listarLivrosDisponiveis(lista);
                break;
            case 3:
                listarLivrosEmprestados(lista);
                break;
            case 4:
                break;
            default:
                printOpcaoInvalida();
        }
    }while(opcao != 4);

}
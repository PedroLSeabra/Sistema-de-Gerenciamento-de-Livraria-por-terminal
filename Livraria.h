#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif

typedef struct Livro {
    char titulo[100];
    char autor[50];
    char ISBN[13];
    int status; 
    struct Livro *prox;
} Livro;

Livro* criarLivro(char* titulo, char* autor, char* ISBN, int status);

// Função printar opcao invalida
void printOpcaoInvalida();

// Função printar lista vazia
void printListaVazia();

// Função para adicionar um livro à lista
void adicionarLivro(Livro** lista, Livro* novoLivro);

// Função para listar todos os livros
void listarLivros(Livro* lista);

// Função para listar os livros Disponiveis
void listarLivrosDisponiveis(Livro* lista);

// Função para listar os livros Emprestados
void listarLivrosEmprestados(Livro* lista);

// Função para atualizar um livro pelo ISBN
void atualizarLivro(Livro* lista, char* ISBN);

// Função para deletar um livro pelo ISBN
void deletarLivro(Livro** lista, char* ISBN);

// Função Bubble Sort para ordenar livros por título
void bubbleSort(Livro** lista);

// Função para imprimir o Menu na tela
void interfaceMenu(int* opcao);

// Função para inserir um livro na lista
void inputDadosLivro(Livro** lista);

// Função para pegar uma input de string
char* pegarString(char string[15]);

// Função para liberar a memoria da list
void liberarMemoriaLista(Livro* lista);

// Função para listar as listagens de livros
void interfaceListarLivros(Livro* lista);


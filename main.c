#include "Livraria.c"

// Função principal
int main() {
    Livro* listaLivros = NULL;
    int opcao;

    do {

        interfaceMenu(&opcao);

        switch (opcao) {
            case 1:
                inputDadosLivro(&listaLivros);
            break;

            case 2:
                interfaceListarLivros(listaLivros);
            break;

            case 3:
                atualizarLivro(listaLivros, pegarString("atualizado"));
            break;

            case 4:
                deletarLivro(&listaLivros, pegarString("deletado"));
            break;

            case 5:
                bubbleSort(&listaLivros);
            break;

            case 6:
                printf("Saindo do programa...\n");
            break;

            default:
                printOpcaoInvalida();
        }
    } while (opcao != 6);

    liberarMemoriaLista(listaLivros);

    return 0;
}

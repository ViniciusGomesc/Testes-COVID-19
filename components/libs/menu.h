#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Função que limpa a tela do terminal, nome abreviado de clearScreen (Limpa Tela) */
void clscr() {

    // Comando da lib stdlib.h que executa varios comandos dos prompts (Linux, Mac, Windows ...)
    system("cls || clear");

}

/* Função que imprime o menu e retorna a opção escolhida */
int menu() {

    int opcao;

    do {

        clscr();
    
        // Imprimindo linha decorativa 
        printf("-----------------------------------------------------------\n");

        // Imprimindo Menu de Opções
        printf("\t\t#### TESTES COVID-19 ####\n\n");

        printf("Menu de Opcoes:\n\n");

        printf("1 - Cadastrar novos testes\n");
        printf("2 - Consultar teste\n");
        printf("3 - Cancelar teste\n");
        printf("4 - Salvar informacoes em arquivo\n");
        printf("5 - Visualizar informacoes de testes realizados\n");
        printf("6 - Relatorio de testes realizados\n");
        printf("0 - Sair\n");

        // Imprimindo linha decorativa 
        printf("-----------------------------------------------------------\n");

        printf("Digite a opcao: ");
        scanf("%d", &opcao);

    } while(!((opcao >= 0) && (opcao <= 6)));

    return opcao;
}

/* Função de encerramento do programa, endProg (Fim do Programa) */
void endProg() {

    printf("Pressione \"Enter\" para finalizar o programa");
    
    getchar();
    clscr();

}
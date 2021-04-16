#include "menu.h"

/* 
===============================================
            DEFINIÇÃO DE STRUCTS
===============================================
*/

/* Definindo os campos dados para o struct Pessoa */
typedef struct rotuloPessoa {

    char fullName[100], cpf[20];
    int dia, mes, ano;
    char sexo;
    char bairro[100], resultadoTeste;
    int idade;

} Pessoa;

/* 
===============================================
            DEFINIÇÃO DE FUNÇÕES
===============================================
*/


/* Função que retorna o primeiro nome(firstName) ex: Pedro Emanuel => Pedro */
void firstName(char nomeCompleto[], char name[]) {

    int i;

    /* Pegando o primeiro nome */
    for(i = 0; !(nomeCompleto[i] == ' ' || nomeCompleto[i] == '\0'); i++) {

        name[i] = nomeCompleto[i];
        
    }

    /* Evita de imprimir lixo depois do '\0 */
    name[i] = '\0'; 


}

/* Função que cadastra novos testes, regNewTests => Registrar novos testes */
Pessoa regNewTests() {

    Pessoa pessoa;
    char name[15];

    printf("Digite o seu nome: ");
    gets(pessoa.fullName);

    clscr();

    firstName(pessoa.fullName, name);

    printf("%s, digite o seu CPF: ", name);
    gets(pessoa.cpf);

    clscr();

    /* Avisando ao usuário que agora a data de nascime nto terá que ser armazenada */
    printf("%s, agora e preciso ser armazendo sua data de nascimento: \n\n", name);

    /* Pegando o dia */
    printf("Dia: ");
    scanf("%d", &pessoa.dia);


    /* Pegando o Mês */
    printf("Mes: ");
    scanf("%d", &pessoa.mes);


    /* Pegando o Ano */
    printf("Ano: ");
    scanf("%d", &pessoa.ano);

    getchar(); // Limpa o buffer
    clscr();

    /* Pegando o sexo M para masculino e F para feminino */
    printf("Digite o seu sexo \"M\" para masculino e \"F\" feminino: ");
    scanf("%c", &pessoa.sexo);

    getchar();
    clscr();

    /* Pegando o bairro do usuário */
    printf("%s, informe o bairro: ", name);
    gets(pessoa.bairro);

    clscr();

    /* Informando ao usuário que agora será armazenado os resultados dos testes */
    printf("%s, agora sera armazenado os resultados dos testes da COVID-19: \n\n", name);

    printf("Digite \"P\" para positivo e \"N\" para negativo: ");
    scanf("%c", &pessoa.resultadoTeste);

    getchar();
    clscr();
    
    return pessoa;

}

/* Função que calcula a idade da pessoa através da data de nascimento informações de aprendizado retirado do site [https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/]
   e do site [https://www.vivaolinux.com.br/dica/Funcoes-de-data-usando-time.h] - Ambos artigos pesquisados afim de aprendizagem de uso da lib
*/
int yearsOld(Pessoa dataDeNascimento) {

    /* Pegando data atual em segundos */
    time_t tm = time(NULL);
    char *dataAtual = asctime(localtime(&tm)); // Convertendo segundos para string
    int dia, mes, ano; // variaveis para armazenar a conversão de strings para inteiro
    int i, j, resultado; // resultado armazena o calculo
    char month[5]; // Armazena o mes ex: Apr
    char day[3]; // Armazena o dia ex: 15
    char year[6]; // Armazena o ano: 2021 

    j = 0; // auxiliar para o month

    // Pegando o mes atual como string
    for(i = 4; dataAtual[i] != ' '; i++) {

        
        month[j] = dataAtual[i];

        j++;

    }

    month[j] = '\0';

    j = 0;

    // Pegando o dia atual como string
    for(i = 8; dataAtual[i] != ' '; i++) {

        day[j] = dataAtual[i];

        j++;

    }

    day[j] = '\0';

    j = 0;

    // Pegando o ano atual como string
    for(i = 20; dataAtual[i] != '\0'; i++) {

        year[j] = dataAtual[i];

        j++;

    }

    day[j] = '\0';

    /* Convertendo dia e ano de string para inteiro */
    dia = atoi(day);
    ano = atoi(year);

    // Converte mês de string por extenso para inteiro ex: Apr => 4
    if(strcmp(month, "Jan") == 0) {

        mes = 1;

    } else if(strcmp(month, "Feb") == 0) {

        mes = 2;

    } else if(strcmp(month, "Mar") == 0) {

        mes = 3;

    } else if(strcmp(month, "Apr") == 0) {

        mes = 4;

    } else if(strcmp(month, "May") == 0) {

        mes = 5;

    } else if(strcmp(month, "Jun") == 0) {
        
        mes = 6;

    } else if(strcmp(month, "Jul") == 0) {

        mes = 7;

    } else if(strcmp(month, "Aug") == 0) {

        mes = 8;

    } else if(strcmp(month, "Sep") == 0) {

        mes = 9;

    } else if(strcmp(month, "Oct") == 0) {

        mes = 10;

    } else if(strcmp(month, "Nov") == 0) {

        mes = 11;

    } else if(strcmp(month, "Dec") == 0) {

        mes = 12;

    }

    // pegando a idade da pessoa
    resultado = ano - dataDeNascimento.ano;

    // Avalia se o aniversário da pessoa já passou
    if(mes < dataDeNascimento.mes) {

        resultado -= 1;

    } else if(mes == dataDeNascimento.mes) {

        if(!(dia >= dataDeNascimento.dia)) {

            resultado -= 1;

        }

    }

    return resultado;

}

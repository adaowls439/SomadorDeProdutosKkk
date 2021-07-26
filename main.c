#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "funcoes.h"

typedef struct DadosFuncionarios {
    char nome[50];

    int cFuradeira;
    int cMochila;
    int cSerra;

    int eFuradeira;
    int eMochila;
    int eSerra;

    int Total;
}funcionario;

funcionario Funcionarios[100];

int NUMFUNCIONARIOS = 0;

void clear_key(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

void BuscarFuncionario(int tipo){
    char nome[50];
    bool coletandoDados = true;
    printf("\n* Mande \"0\" no lugar do nome para voltar ao MENU.\n");

    do{
        printf("\n\nFuncionario: ");
        fflush(stdin);
        fgets(nome, 50, stdin);
        convMaiusculo(nome);
        removeSalto(nome);

        if(!strcmp(nome, "0")){
            coletandoDados = false;
        } else {
            int i=0;
            while(i < NUMFUNCIONARIOS+1){
                if(!strcmp(nome,Funcionarios[i].nome)){
                    RegistrarItem(tipo,i);
                    i++;
                } else if(i == NUMFUNCIONARIOS){
                    strcpy(Funcionarios[i].nome,nome);
                    RegistrarItem(tipo,i);
                    NUMFUNCIONARIOS++;
                    i++;
                }
                i++;
            }
        }
    }while(coletandoDados == true);
}

void RegistrarItem(int tipo, int numeroDoFuncionario){
    char item;
    bool certo = false;
    do{
        printf("Item (F = Furadeira, M = Mochila e S = Serra): ");
        fflush(stdin);
        scanf("%c",&item);
        switch (item) {
            case 'f':
                if(tipo == 1){
                    Funcionarios[numeroDoFuncionario].cFuradeira = Funcionarios[numeroDoFuncionario].cFuradeira+1;
                    printf("Funcionário %s coletou Furadeira!",Funcionarios[numeroDoFuncionario].nome);
                } else if(tipo == 2){
                    Funcionarios[numeroDoFuncionario].eFuradeira = Funcionarios[numeroDoFuncionario].eFuradeira+1;
                    printf("Funcionário %s entregou Furadeira!",Funcionarios[numeroDoFuncionario].nome);
                }

                certo = true;

                break;
            case 'm':
                if(tipo == 1){
                    Funcionarios[numeroDoFuncionario].cMochila = Funcionarios[numeroDoFuncionario].cMochila+1;
                    printf("Funcionário %s coletou Mochila!",Funcionarios[numeroDoFuncionario].nome);
                } else if(tipo == 2){
                    Funcionarios[numeroDoFuncionario].eMochila = Funcionarios[numeroDoFuncionario].eMochila+1;
                    printf("Funcionário %s entregou Mochila!",Funcionarios[numeroDoFuncionario].nome);
                }

                certo = true;

                break;
            case 's':
                if(tipo == 1){
                    Funcionarios[numeroDoFuncionario].cSerra = Funcionarios[numeroDoFuncionario].cSerra+1;
                    printf("Funcionário %s coletou Serra!",Funcionarios[numeroDoFuncionario].nome);

                } else if(tipo == 2){
                    Funcionarios[numeroDoFuncionario].eSerra = Funcionarios[numeroDoFuncionario].eSerra+1;
                    printf("Funcionário %s entregou Serra!",Funcionarios[numeroDoFuncionario].nome);
                }

                certo = true;

                break;
            default: printf("\nEste item está errado!");
        }
    }while(certo == false);
}

void Exibir(){
    printf("\n");
    printf("Coletas e Entregas Gerais: \n");
    printf("cFuradeira\tcMochila\tcSerra\t|Coletas Totais|\teFuradeira\teMochila\teSerra\t|Entregas Totais|\tNome");
    int i = 0;
    while(i < NUMFUNCIONARIOS){
        int coletasTotais = Funcionarios[i].cFuradeira + Funcionarios[i].cMochila + Funcionarios[i].cSerra;
        int entregasTotais = Funcionarios[i].eFuradeira + Funcionarios[i].eMochila +Funcionarios[i].eSerra;
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%s",Funcionarios[i].cFuradeira,Funcionarios[i].cMochila,Funcionarios[i].cSerra,coletasTotais,Funcionarios[i].eFuradeira,Funcionarios[i].eMochila,Funcionarios[i].eSerra,entregasTotais,Funcionarios[i].nome);
        i++;
    }
}

void Menu(){
    int op;

    printf("\n\n***** Registrador de Coletas e Entregas *****");
    printf("\n1 - Para começar a registrar as coletas;");
    printf("\n2 - Para começar a registrar as Entregas;");
    printf("\n3 - Exibir dados dos funcionários.\n");

    scanf("%d",&op);
    switch (op) {
        case 1: BuscarFuncionario(1); break;
        case 2: BuscarFuncionario(2); break;
        case 3: Exibir(); break;
        default: printf("\n* Esta opção não existe!\n");
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    bool op = true;
    do{
        Menu();
    }while(op == true);

    return 0;
}

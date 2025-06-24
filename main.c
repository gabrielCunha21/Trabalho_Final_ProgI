#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menuInicial(){

    setlocale(LC_ALL, "Portuguese");

    int opcao=0;

    printf("\n-------------------------------------\n");
    printf("| 1 -> Cadastro de Presos;          |\n");
    printf("| 2 -> Gerenciar Transferencia;     |\n");
    printf("| 3 -> Gerenciar Saida (Liberacao); |\n");
    printf("| 4 -> Consulta/Listagem;           |\n");      
    printf("| 5 -> Relatorios;                  |\n");
    printf("| 6 -> Sair.                        |");
    printf("\n-------------------------------------\n");

    printf("Digite a opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case  1:
        /* code */
        break;
    
    case  2:
        /* code */
        break;

    case  3:
        /* code */
        break;

    case  4:
        /* code */
        break;

    case  5:
        /* code */
        break;

    case  6:
        /* code */
        break;

    default:
        break;
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    menuInicial();
    
    return 0;
}


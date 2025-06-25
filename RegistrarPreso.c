#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fichaCriminal
{
    char codigoPenal[4];
    char dataCrime[11];
    char descricao[200];
};

struct Preso
{
    char nome[20];
    char cpf[15];
    char idade[3];
    char cela[4];
    char dataEntrada[11];
    struct fichaCriminal FichaCriminal;

};


void gravarArquivo(struct Preso preso1);
void lerArquivo();
// void adicionarAoArquivo();

int main() {

    int opcao;

    struct Preso preso;

    FILE *arquivo;

    if((arquivo = fopen("../dados.txt", "w+"))){
        puts("Arquivo criado com sucesso");
        fclose(arquivo);
    }

    do {
        printf("\n=== MENU ===\n");
        printf("1. Registrar Preso\n");
        printf("2. Listar Presos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch(opcao) {
            case 1:
                printf("Digite o nome do preso: ");
                scanf("%s", preso.nome);
                printf("Digite o cpf do preso: ");
                scanf("%s", preso.cpf);
                printf("Digite a idade do preso: ");
                scanf("%s", preso.idade);
                printf("Digite a cela do preso: ");
                scanf("%s", preso.cela);
                printf("Digite a data: (DD/MM/AAAA): ");
                scanf("%s", preso.dataEntrada);
                gravarArquivo(preso);
                break;
            case 2:
                lerArquivo();
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while(opcao != 4);

    return 0;
}

void gravarArquivo(struct Preso preso1) {

    FILE *arquivo;

    if((arquivo = fopen("../dados.txt", "a")) == NULL){
        puts("Erro");
    }

    if(fprintf(arquivo, "%s - %s - %s - %s - %s;\n", preso1.nome, preso1.cpf, preso1.idade, preso1.cela, preso1.dataEntrada)){
        fclose(arquivo);
        puts("ERRO");
    }

    fclose(arquivo);
    printf("Dados gravados com sucesso!\n");
}

void lerArquivo() {
    FILE *arquivo;
    char linha[1000];
    char *registro;
    int numeroRegistro = 1;

    arquivo = fopen("../dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura! Verifique se o arquivo existe.\n");
        return;
    }

    printf("\nConteudo do arquivo:\n");
    printf("--------------------\n");

    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = 0;

        registro = strtok(linha, ";");

        while (registro != NULL) {
            printf("Linha %d: %s\n", numeroRegistro, registro);
            numeroRegistro++;
            registro = strtok(NULL, ";");
        }
    }

    printf("--------------------\n");

    // Fecha o arquivo
    fclose(arquivo);
}

// void adicionarAoArquivo() {
//     FILE *arquivo;
//     char registro1[100], registro2[100];

//     // Abre o arquivo para adicionar conteúdo (append)
//     arquivo = fopen("dados.txt", "a");

//     if (arquivo == NULL) {
//         printf("Erro ao abrir o arquivo para adicionar dados!\n");
//         return;
//     }

//     printf("Digite o primeiro registro: ");
//     fgets(registro1, sizeof(registro1), stdin);
//     // Remove a quebra de linha do fgets
//     registro1[strcspn(registro1, "\n")] = 0;

//     printf("Digite o segundo registro: ");
//     fgets(registro2, sizeof(registro2), stdin);
//     // Remove a quebra de linha do fgets
//     registro2[strcspn(registro2, "\n")] = 0;

//     // Adiciona os dois registros separados por ; no final do arquivo
//     fprintf(arquivo, "%s;%s\n", registro1, registro2);

//     // Fecha o arquivo
//     fclose(arquivo);

//     printf("Dados adicionados com sucesso!\n");
// }
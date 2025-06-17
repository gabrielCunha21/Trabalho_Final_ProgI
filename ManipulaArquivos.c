#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gravarArquivo() {
    FILE *arquivo;
    char registro1[100], registro2[100];

    // Abre o arquivo para escrita (cria se não existir)
    arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    printf("Digite o primeiro registro: ");
    fgets(registro1, sizeof(registro1), stdin);
    // Remove a quebra de linha do fgets
    registro1[strcspn(registro1, "\n")] = 0;

    printf("Digite o segundo registro: ");
    fgets(registro2, sizeof(registro2), stdin);
    // Remove a quebra de linha do fgets
    registro2[strcspn(registro2, "\n")] = 0;

    // Escreve os dois registros separados por ; na mesma linha
    fprintf(arquivo, "%s;%s\n", registro1, registro2);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Dados gravados com sucesso!\n");
}

void lerArquivo() {
    FILE *arquivo;
    char linha[200];
    char *registro1, *registro2;
    int numeroLinha = 1;

    // Abre o arquivo para leitura
    arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura! Verifique se o arquivo existe.\n");
        return;
    }

    printf("\nConteúdo do arquivo:\n");
    printf("--------------------\n");

    // Lê linha por linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Remove a quebra de linha
        linha[strcspn(linha, "\n")] = 0;

        // Separa os registros usando strtok
        registro1 = strtok(linha, ";");
        registro2 = strtok(NULL, ";"); // continua de onde parou o ponteiro

        if (registro1 != NULL && registro2 != NULL) {
            printf("Linha %d:\n", numeroLinha);
            printf("  Registro 1: %s\n", registro1);
            printf("  Registro 2: %s\n", registro2);
        } else {
            printf("Linha %d: %s (formato inválido)\n", numeroLinha, linha);
        }
        numeroLinha++;
    }

    printf("--------------------\n");

    // Fecha o arquivo
    fclose(arquivo);
}

void adicionarAoArquivo() {
    FILE *arquivo;
    char registro1[100], registro2[100];

    // Abre o arquivo para adicionar conteúdo (append)
    arquivo = fopen("dados.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para adicionar dados!\n");
        return;
    }

    printf("Digite o primeiro registro: ");
    fgets(registro1, sizeof(registro1), stdin);
    // Remove a quebra de linha do fgets
    registro1[strcspn(registro1, "\n")] = 0;

    printf("Digite o segundo registro: ");
    fgets(registro2, sizeof(registro2), stdin);
    // Remove a quebra de linha do fgets
    registro2[strcspn(registro2, "\n")] = 0;

    // Adiciona os dois registros separados por ; no final do arquivo
    fprintf(arquivo, "%s;%s\n", registro1, registro2);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Dados adicionados com sucesso!\n");
}

int main() {
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Gravar dados no arquivo\n");
        printf("2. Ler dados do arquivo\n");
        printf("3. Adicionar dados ao arquivo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch(opcao) {
            case 1:
                gravarArquivo();
                break;
            case 2:
                lerArquivo();
                break;
            case 3:
                adicionarAoArquivo();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while(opcao != 4);

    return 0;
}
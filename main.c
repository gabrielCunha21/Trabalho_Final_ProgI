#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Preso
{
    char nome[20];
    char cpf[15];
    char idade[3];
    char cela[4];
    char dataEntrada[11];

};

void gravarArquivo(struct Preso preso1);
void lerArquivo();

void menuInicial() {
    setlocale(LC_ALL, "Portuguese");

    struct Preso preso;
    // FILE *arquivo;

    // if ((arquivo = fopen("../dados.txt", "w+"))) {
    //     puts("Arquivo criado com sucesso");
    //     fclose(arquivo);
    // }

    int opcao = 0, opcao1 = 0;

    do
        {
        
        printf("\n-------------------------------------\n");
        printf("| 1 -> Cadastro de Presos;          |\n");
        printf("| 2 -> Gerenciar Transferencia;     |\n");
        printf("| 3 -> Gerenciar Saida (Liberacao); |\n");
        printf("| 4 -> Consulta/Listagem;           |\n");      
        printf("| 5 -> Relatorios;                  |\n");
        printf("| 6 -> Sair.                        |\n");
        printf("-------------------------------------\n");

        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                do {
                    printf("\n---------------------------\n");
                    printf("| 1 -> Registrar Preso    |\n");
                    printf("| 2 -> Listar Presos      |\n");
                    printf("| 3 -> Voltar             |\n");
                    printf("---------------------------\n");
                    printf("Digite a opcao: ");
                    scanf("%d", &opcao1);
                    getchar(); // Limpa o buffer do teclado

                    switch (opcao1) {
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
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                            break;
                    }
                } while (opcao1 != 3);

            case 2:
                // Código para transferência
                break;

            case 3:
                // Código para saída/liberação
                break;

            case 4:
                // Código para consulta/listagem
                break;

            case 5:
                // Código para relatórios
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

}

int main() {

    setlocale(LC_ALL, "Portuguese");

    menuInicial();
    
    return 0;
}

void gravarArquivo(struct Preso preso1) {

    FILE *arquivo;

    if((arquivo = fopen("../dados.txt", "a")) == NULL){
        puts("Erro");
    }

    if(fprintf(arquivo, "%s - %s - %s - %s - %s;", preso1.nome, preso1.cpf, preso1.idade, preso1.cela, preso1.dataEntrada)){
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
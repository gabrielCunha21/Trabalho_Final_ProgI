#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct fichaCriminal
{
    char codigoPenal[4];
    char dataCrime[11];
    char descricao[100];
};

struct Preso
{
    char nome[40];
    char cpf[15];
    char idade[3];
    char cela[4];
    char dataEntrada[11];
    struct fichaCriminal FichaCriminal;

};

void editarCela(const char *celaAntiga, const char *novaCela);
void editarPresoPorLinha(int linhaEditar, struct Preso novoPreso);
struct Preso obterPresoPorLinha(int numeroDesejado);
void gravarArquivo(struct Preso preso1);
void liberarPresoPorLinha(int linhaParaLiberar);
void buscarPresoPorNome(const char *nomeBusca);
void imprimirRelatorioPreso(struct Preso preso);
void limparEspacos(char *str);
void lerArquivo();
void lerArquivoLiberados();

void menuInicial() {
    setlocale(LC_ALL, "Portuguese");

    struct Preso preso;
    struct fichaCriminal Fcriminal;
    // FILE *arquivo;

    // if ((arquivo = fopen("../dados.txt", "w+"))) {
    //     puts("Arquivo criado com sucesso");
    //     fclose(arquivo);
    // }

    int opcao = 0, opcao1 = 0, opcao2 = 0;
    char resposta;

    do
        {
        
        printf("\n-------------------------------------\n");
        printf("| 1 -> Gerenciar Presos;            |\n");
        printf("| 2 -> Gerenciar Transferencia;     |\n");
        printf("| 3 -> Gerenciar Saida (Liberacao); |\n");
        printf("| 4 -> Consulta e Relatorios;       |\n");      
        printf("| 5 -> Ficha Criminal;              |\n");
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
                            printf("Digite o cpf do preso: ");
                            scanf("%s", preso.cpf);
                            printf("Digite o nome do preso: ");
                            getchar(); // <- adiciona aqui
                            fgets(preso.nome, sizeof(preso.nome), stdin);
                            preso.nome[strcspn(preso.nome, "\n")] = '\0';
                            
                            printf("Digite a idade do preso: ");
                            scanf("%s", preso.idade);
                            printf("Digite a cela do preso: ");
                            scanf("%s", preso.cela);
                            printf("Digite a data: (DD/MM/AAAA): ");
                            scanf("%s", preso.dataEntrada);
                            printf("Deseja inserir a ficha criminal agora? (s/n): ");
                            scanf( " %c", &resposta);
                            if (resposta == 'S' || resposta == 's')
                            {
                                printf("Digite o codigo penal: ");
                                scanf("%s", Fcriminal.codigoPenal);
                                printf("Digite a data do crime: ");
                                scanf("%s", Fcriminal.dataCrime);
                                printf("Digite a descricao do crime: ");
                                getchar();
                                fgets(Fcriminal.descricao, sizeof(Fcriminal.descricao), stdin);
                                Fcriminal.descricao[strcspn(Fcriminal.descricao, "\n")] = '\0';


                                preso.FichaCriminal = Fcriminal;
                            }
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

                break;

            case 2:

                int escolha;
                char novaCela[4];

                lerArquivo();

                printf("Digite o numero da linha: ");
                scanf("%d", &escolha);

                struct Preso presoSelecionado = obterPresoPorLinha(escolha);

                printf("Digite a nova cela: ");
                scanf("%s", novaCela);
                strcpy(presoSelecionado.cela, novaCela);

                editarPresoPorLinha(escolha, presoSelecionado);

                break;

            case 3:

                int opcao4=0;

                 do {
                    printf("\n-------------------------------\n");
                    printf("| 1 -> Liberar Preso            |\n");
                    printf("| 2 -> Mostrar Presos Liberados |\n");
                    printf("| 3 -> Voltar                   |\n");
                    printf("---------------------------------\n");
                    printf("Digite a opcao: ");
                    scanf("%d", &opcao4);
                    getchar(); 

                    switch (opcao4) {
                        case 1:
                            int linha;

                            lerArquivo(); 
                            printf("Digite o numero da linha do preso a ser liberado: ");
                            scanf("%d", &linha);
                            liberarPresoPorLinha(linha);
                            break;
                        case 2:
                            lerArquivoLiberados();
                            break;
                        case 3:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                            break;
                    }
                } while (opcao4 != 3);

                break;

            case 4:

                 int opcao5=0;

                 do {
                    printf("\n-------------------------------\n");
                    printf("| 1 -> Consultar presos         |\n");
                    printf("| 2 -> Enviar Relatorio         |\n");
                    printf("| 3 -> Voltar                   |\n");
                    printf("---------------------------------\n");
                    printf("Digite a opcao: ");
                    scanf("%d", &opcao5);
                    getchar(); 

                    switch (opcao5) {
                        case 1:
                            char nome[40];
                            printf("Digite o nome a ser buscado: ");
                            getchar(); 
                            fgets(nome, sizeof(nome), stdin);
                            nome[strcspn(nome, "\n")] = '\0'; 

                            buscarPresoPorNome(nome);
                        case 2:

                            int num=0;

                            lerArquivo();

                            printf("Digite a linha do preso que deseja enviar o relatorio: ");
                            scanf("%d", &num);

                            struct Preso p = obterPresoPorLinha(num);
                            imprimirRelatorioPreso(p);

                            break;
                        case 3:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                            break;
                    }
                } while (opcao5 != 3);

                break;

            case 5:

                int opcao6=0;

                do {
                    printf("\n--------------------------------------\n");
                    printf("| 1 -> Adicionar crime                |\n");
                    printf("| 2 -> Remover crime                  |\n");
                    printf("| 3 -> Consultar ficha criminal       |\n");
                    printf("| 4 -> Voltar                         |\n");    
                    printf("----------------------------------------\n");
                    printf("Digite a opcao: ");
                    scanf("%d", &opcao6);
                    getchar(); 

                    switch (opcao6) {
                        case 1:

                            break;
                            
                        case 2:

                            break;
                            
                        case 3:
                        
                            break;

                        case 4:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                            break;
                    }
                } while (opcao6 != 4);

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
    FILE *arquivo = fopen("../dados.txt", "a");
    if (arquivo == NULL) {
        puts("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "%s - %s - %s - %s - %s - %s - %s - %s;\n", preso1.nome, preso1.cpf, preso1.idade, preso1.cela, preso1.dataEntrada, preso1.FichaCriminal.codigoPenal, preso1.FichaCriminal.dataCrime, preso1.FichaCriminal.descricao);

    fclose(arquivo);
    printf("Dados gravados com sucesso!\n");
}

void lerArquivo() {
    FILE *arquivo = fopen("../dados.txt", "r");
    char linha[1024];
    int linhaN = 1;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("\nPresos cadastrados:\n");
    printf("--------------------\n");

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';
        printf("Linha %d: %s\n", linhaN++, linha);
    }

    printf("--------------------\n");

    fclose(arquivo);
}

void lerArquivoLiberados() {
    FILE *arquivo = fopen("../liberados.txt", "r");
    char linha[1024];
    int linhaN = 1;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("\nPresos liberados:\n");
    printf("--------------------\n");

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';
        printf("Linha %d: %s\n", linhaN++, linha);
    }

    printf("--------------------\n");

    fclose(arquivo);
}

void editarPresoPorLinha(int linhaEditar, struct Preso novoPreso) {
    FILE *arquivo = fopen("../dados.txt", "r");
    FILE *temp = fopen("../temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    char linha[1024];
    int linhaAtual = 1;

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';

        if (linhaAtual == linhaEditar) {
            fprintf(temp, "%s - %s - %s - %s - %s - %s - %s - %s;\n",
                    novoPreso.nome,
                    novoPreso.cpf,
                    novoPreso.idade,
                    novoPreso.cela,
                    novoPreso.dataEntrada,
                    novoPreso.FichaCriminal.codigoPenal,
                    novoPreso.FichaCriminal.dataCrime,
                    novoPreso.FichaCriminal.descricao);
        } else {
            fprintf(temp, "%s\n", linha);
        }

        linhaAtual++;
    }

    fclose(arquivo);
    fclose(temp);

    remove("../dados.txt");
    rename("../temp.txt", "../dados.txt");

    printf("Registro da linha %d editado com sucesso.\n", linhaEditar);
}

struct Preso obterPresoPorLinha(int numeroDesejado) {
    FILE *arquivo = fopen("../dados.txt", "r");
    struct Preso p = {0}; 

    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return p;
    }

    char linha[1024];
    int linhaAtual = 1;

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';  
        size_t len = strlen(linha);
        if (linha[len - 1] == ';') linha[len - 1] = '\0'; 

        if (linhaAtual == numeroDesejado) {
            char *campos[8];
            int i = 0;

            char *token = strtok(linha, "-");
            while (token != NULL && i < 8) {
                while (*token == ' ') token++;

                char *fim = token + strlen(token) - 1;
                while (fim > token && *fim == ' ') {
                    *fim = '\0';
                    fim--;
                }

                campos[i++] = strdup(token);
                token = strtok(NULL, "-");
            }

            if (i == 8) {
                strncpy(p.nome, campos[0], sizeof(p.nome));
                strncpy(p.cpf, campos[1], sizeof(p.cpf));
                strncpy(p.idade, campos[2], sizeof(p.idade));
                strncpy(p.cela, campos[3], sizeof(p.cela));
                strncpy(p.dataEntrada, campos[4], sizeof(p.dataEntrada));
                strncpy(p.FichaCriminal.codigoPenal, campos[5], sizeof(p.FichaCriminal.codigoPenal));
                strncpy(p.FichaCriminal.dataCrime, campos[6], sizeof(p.FichaCriminal.dataCrime));
                strncpy(p.FichaCriminal.descricao, campos[7], sizeof(p.FichaCriminal.descricao));
            } else {
                printf("Erro ao interpretar a linha %d (campos insuficientes).\n", numeroDesejado);
            }

            for (int j = 0; j < i; j++) {
                free(campos[j]); 
            }

            break;
        }

        linhaAtual++;
    }

    fclose(arquivo);
    return p;
}

void liberarPresoPorLinha(int linhaParaLiberar) {
    FILE *arquivo = fopen("../dados.txt", "r");
    FILE *temp = fopen("../temp.txt", "w");
    FILE *liberados = fopen("../liberados.txt", "a");

    if (arquivo == NULL || temp == NULL || liberados == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    char linha[1024];
    int linhaAtual = 1;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (linhaAtual == linhaParaLiberar) {
            linha[strcspn(linha, "\n")] = '\0';
            fprintf(liberados, "%s\n", linha);
            printf("Preso da linha %d liberado e movido para 'liberados.txt'.\n", linhaParaLiberar);
        } else {
            fprintf(temp, "%s", linha); 
        }
        linhaAtual++;
    }

    fclose(arquivo);
    fclose(temp);
    fclose(liberados);

    remove("../dados.txt");
    rename("../temp.txt", "../dados.txt");
}

void limparEspacos(char *str) {
    while (*str == ' ') str++; 

    char *end = str + strlen(str) - 1;
    while (end > str && *end == ' ') *end-- = '\0'; 
}

void buscarPresoPorNome(const char *nomeBusca) {
    FILE *arquivo = fopen("../dados.txt", "r");
    char linha[1024];
    int encontrado = 0;
    int linhaAtual = 1;

    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';
        size_t len = strlen(linha);
        if (linha[len - 1] == ';') linha[len - 1] = '\0';

        char copia[1024];
        strcpy(copia, linha);

        char *campos[8];
        int i = 0;
        char *token = strtok(copia, "-");
        while (token != NULL && i < 8) {
            while (*token == ' ') token++;
            campos[i] = token;

            char *fim = campos[i] + strlen(campos[i]) - 1;
            while (fim > campos[i] && *fim == ' ') {
                *fim = '\0';
                fim--;
            }

            token = strtok(NULL, "-");
            i++;
        }

        if (i == 8 && strstr(campos[0], nomeBusca) != NULL) {
            printf("\nPreso encontrado na linha %d:\n", linhaAtual);
            printf("Nome: %s\n", campos[0]);
            printf("CPF: %s\n", campos[1]);
            printf("Idade: %s\n", campos[2]);
            printf("Cela: %s\n", campos[3]);
            printf("Data de Entrada: %s\n", campos[4]);
            printf("Codigo Penal: %s\n", campos[5]);
            printf("Data do Crime: %s\n", campos[6]);
            printf("Descricao do Crime: %s\n", campos[7]);
            encontrado = 1;
        }

        linhaAtual++;
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Nenhum preso com nome contendo \"%s\" foi encontrado.\n", nomeBusca);
    }
}

void imprimirRelatorioPreso(struct Preso preso) {
    printf("\n-----------------------------------------------\n");
    printf("           RELATORIO DO PRESO\n");
    printf("-------------------------------------------------\n");
    printf("Nome completo     : %s\n", preso.nome);
    printf("CPF               : %s\n", preso.cpf);
    printf("Idade             : %s anos\n", preso.idade);
    printf("Cela atual        : %s\n", preso.cela);
    printf("Data de entrada   : %s\n", preso.dataEntrada);
    printf("\n--- Ficha Criminal ---\n");
    printf("Codigo Penal      : %s\n", preso.FichaCriminal.codigoPenal[0] ? preso.FichaCriminal.codigoPenal : "N/A");
    printf("Data do crime     : %s\n", preso.FichaCriminal.dataCrime[0] ? preso.FichaCriminal.dataCrime : "N/A");
    printf("Descricao do crime: %s\n", preso.FichaCriminal.descricao[0] ? preso.FichaCriminal.descricao : "N/A");
    printf("-------------------------------------------------\n");

    printf("\nResumo:\n");
    printf("%s, CPF %s, tem %s anos e esta atualmente na cela %s. "
           "Foi preso em %s. ", preso.nome, preso.cpf, preso.idade, preso.cela, preso.dataEntrada
    );

    if (preso.FichaCriminal.codigoPenal[0]) {
        printf("Esta registrado sob o codigo penal %s, por um crime ocorrido em %s, descrito como: \"%s\".\n", preso.FichaCriminal.codigoPenal, preso.FichaCriminal.dataCrime, preso.FichaCriminal.descricao);
    } else {
        printf("Ainda não ha ficha criminal registrada.\n");
    }
}


#include <stdio.h>

/**
1 – Entrada de dados.
2 – Lista todos os dados na tela.
3 – Pesquisar um medico pelo nome completo e mostra na tela
4 – Pesquisar um celular pelo nome completo
5 – Pesquisar pela data da consulta.
6 – Altera dados. Pesquisa pelo nome completo.
7 – Exclui dados. Pesquisa pelo nome completo.
8 – Saída pelo usuário
*/

struct medico
{
    char nome[50];
    char celular[16];
    char data_consulta[11];
};

void entrada(struct medico *pm);

void lista(struct medico *pm);

void pesquisa(struct medico *pm);

void celular(struct medico *pm);

void consulta(struct medico *pm);

void altera(struct medico *pm);

void remover(struct medico *pm);

int main(void)
{
    struct medico dados;
    struct medico *pm;
    pm = &dados;

    int sair=1;
    char opcao;

    while(sair == 1){
        system("cls");
        printf("Escolha uma das opcoes abaixo:\n");
        printf("\n1 - Entrada de dados\n2 - Listar dados\n3 - Pesquisar um medico\n4 - Pesquisar um celular pelo nome\n5 - Pesquisar medico pela data da consulta\n6 - Alterar dados\n7 - Excluir dados\n8 - Sair\n-> ");
		scanf(" %c", &opcao);
		getchar();
        switch(opcao)
        {
            case '1':
                entrada(pm);
                break;
            case '2':
                lista(pm);
                break;
            case '3':
                pesquisa(pm);
                break;
            case '4':
                celular(pm);
                break;
            case '5':
                consulta(pm);
                break;
            case '6':
                altera(pm);
                break;
            case '7':
                remover(pm);
                break;
            case '8':
                saida(&sair);
                break;
            default:
                printf("A opcao nao e' valida!\n\n");
                scanf(" %c", &opcao);
                break;
        }
    }
    printf("\n\n");
    printf("Volte Sempre! :)\n");
    return 0;
}

void entrada(struct medico *pm)
{
    printf("\n\n");
    FILE *desafio;
    desafio = fopen("desafio.txt", "a");
    printf("\n\nDigite o nome completo do medico: ");
	scanf(" ");
    fgets(pm->nome, 50, stdin);
    printf("\nDigite o celular dele: ");
	scanf(" ");
    fgets(pm->celular, 16, stdin);
    printf("\nDigite a data da consulta que ele ira fazer (dd/mm/aaaa): ");
	scanf(" ");
    fgets(pm->data_consulta, 11, stdin);

    printf("\n\n");

    fprintf(desafio, "%s;%s;%s\n", pm->nome, pm->celular, pm->data_consulta);

    fclose(desafio);
    printf("\n\n");printf("\n\n");printf("\n\n");printf("\n\n");
}

void lista(struct medico *pm)
{
    printf("\n\n");
    FILE *desafio;
    desafio = fopen("desafio.txt", "r");

    if (desafio == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        getchar();
        return;
    }

    printf("Aqui estao os registros encontrados dos medicos:\n\n");
    while (fscanf(desafio, "%[^;];%[^;];%s\n", pm->nome, pm->celular, &pm->data_consulta) != EOF) {
        printf("Nome: %s", pm->nome);
        printf("Celular: %s", pm->celular);
        printf("Data da proxima consulta: %s\n\n", pm->data_consulta);
        printf("\n\n");
    }

    fclose(desafio);
    getchar();
}

void pesquisa(struct medico *pm)
{
    printf("\n\n");
    FILE *desafio;
    char p[40];
    desafio = fopen("desafio.txt", "r");

    if (desafio == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        getchar();
        return;
    }

    printf("Digite o nome completo do medico que deseja encontrar: ");
    fgets(p, 40, stdin);

    int achou = 0;
    while (fscanf(desafio, "%[^;];%[^;];%s\n", pm->nome, pm->celular, &pm->data_consulta) != EOF) {
        int i;
        for (i = 0; p[i] != '\0' && pm->nome[i] != '\0'; i++) {
            if (p[i] != pm->nome[i]) {
                break;
            }
        }

        if (p[i] == '\0' && pm->nome[i] == '\0') {
            achou = 1;
            break;
        }
    }

    fclose(desafio);

    if (achou) {
        printf("\n\n");
        printf("Nome: %s", pm->nome);
        printf("Celular: %s", pm->celular);
        printf("Data da proxima consulta: %s\n\n", pm->data_consulta);
        getchar();
    } else {
        printf("Medico nao encontrado!");
        getchar();
    }
}

void celular(struct medico *pm)
{
    printf("\n\n");
    FILE *desafio;
    char c[50];
    desafio = fopen("desafio.txt", "r");

    printf("Digite o nome completo do medico que deseja saber o celular: ");
	scanf(" ");
    fgets(c, 50, stdin);

    int achou = 0;
    while (fscanf(desafio, "%[^;];%[^;];%s\n", pm->nome, pm->celular, &pm->data_consulta) != EOF) {
        int i;
        for (i = 0; c[i] != '\0' && pm->nome[i] != '\0'; i++) {
            if (c[i] != pm->nome[i]) {
                break;
            }
        }

        if (c[i] == '\0' && pm->nome[i] == '\0') {
            achou = 1;
            break;
        }
    }

    fclose(desafio);

    if (achou) {
        printf("\n\n");
        printf("O celular deste medico e': %s", pm->celular);
        getchar();
    } else {
        printf("Medico nao encontrado!");
        getchar();
    }
}

void consulta(struct medico *pm)
{
    printf("\n\n");
    FILE *desafio;
    char s[11];
    desafio = fopen("desafio.txt", "r");

    printf("Digite a data da consulta para saber o medico responsavel: ");
	scanf(" ");
    fgets(s, 11, stdin);

    int achou = 0;
    while (fscanf(desafio, "%[^;];%[^;];%s\n", pm->nome, pm->celular, &pm->data_consulta) != EOF) {
        int i;
        for (i = 0; s[i] != '\0' && pm->data_consulta[i] != '\0'; i++) {
            if (s[i] != pm->data_consulta[i]) {
                break;
            }
        }

        if (s[i] == '\0' && pm->data_consulta[i] == '\0') {
            achou = 1;
            break;
        }
    }

    fclose(desafio);

    if (achou) {
        printf("\n\n");
        printf("O medico responsavel por essa consulta e' o(a): %s", pm->nome);
        getchar();getchar();
    } else {
        printf("Medico nao encontrado!");
        getchar();
    }
}

void altera(struct medico *pm) {
    printf("\n\n");
    FILE *desafio, *temp; //arquivo temporario criado para copiar os dados do outro
    char a[50];
    desafio = fopen("desafio.txt", "r");
    temp = fopen("temp.txt", "w");

    if (desafio == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        getchar();
        return;
    }

    printf("Digite o nome completo do medico que deseja alterar os dados: ");

	scanf(" ");
    fgets(a, 50, stdin);
    int al = 0;
    while (a[al] != '\0' && a[al] != '\n') {
        al++;
    }

    int achou = 0;
    int fl = 0;

    while (fscanf(desafio, "%[^;];%[^;];%s\n", pm->nome, pm->celular, pm->data_consulta) != EOF) {
        fl = 0;
        while (pm->nome[fl] != '\n') {
            fl++;
        }

        int i = 0;
        int match = 1;
        while (i < al && a[i] != '\n') {
            if (a[i] != pm->nome[i]) {
                match = 0;
                break;
            }
            i++;
        }

        if (match && pm->nome[i] == '\n') {
            achou = 1;
            printf("\n\nDigite os novos dados: ");
            printf("\nNome: ");
			scanf(" ");
            fgets(pm->nome, 50, stdin);
			scanf(" ");
            printf("\nCelular: ");
			scanf(" ");
            fgets(pm->celular, 16, stdin);
            printf("\nData da consulta: ");
			scanf(" ");
            fgets(pm->data_consulta, 11, stdin);
        }

        fprintf(temp, "%s;%s;%s\n", pm->nome, pm->celular, pm->data_consulta);
    }

    if (!achou) {
        printf("Medico nao encontrado!");
        getchar();
        fclose(desafio);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    fclose(desafio);
    fclose(temp);
    remove("desafio.txt");
    rename("temp.txt", "desafio.txt");
}

void remover(struct medico *pm) {
    printf("\n\n");
    FILE *desafio, *temp;
    char r[50];
    desafio = fopen("desafio.txt", "r");
    temp = fopen("temp.txt", "w");

    if (desafio == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        getchar();
        return;
    }

    printf("Digite o nome completo do medico que deseja excluir: ");
	scanf(" ");
    fgets(r, 50, stdin);
    int rl = 0;
    while (r[rl] != '\0' && r[rl] != '\n') {
        rl++;
    }

    int achou = 0;
    int fl = 0;

    while (fscanf(desafio, "%[^;];%[^;];%s\n", pm->nome, pm->celular, pm->data_consulta) != EOF) {
        fl = 0;
        while (pm->nome[fl] != '\n') {
            fl++;
        }

        int i = 0;
        int match = 1;
        while (i < rl && r[i] != '\n') {
            if (r[i] != pm->nome[i]) {
                match = 0;
                break;
            }
            i++;
        }

        if (match && pm->nome[i] == '\n') {
            achou = 1;
            continue; // Se encontrado, pule para o próximo registro, ignorando a escrita do registro atual para removê-lo
        }

        fprintf(temp, "%s;%s;%s\n", pm->nome, pm->celular, pm->data_consulta);
    }

    if (!achou) {
        printf("Medico nao encontrado!");
        getchar();
        fclose(desafio);
        fclose(temp);
        remove("temp.txt");
        return;
    }
    printf("\n\nExcluido com sucesso!!");
    getchar();

    fclose(desafio);
    fclose(temp);
    remove("desafio.txt");
    rename("temp.txt", "desafio.txt");
}


void saida(int *psair)
{
    *psair = 0;
    printf("\n\nEntendido! Ate' Logo!\n");
    return 0;
}

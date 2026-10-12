#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char titular[100];
    char cpf[15];
    float saldo;
    int status;
} Conta;

void cadastrarConta() {
    FILE *arquivo = fopen("contas.dat", "ab+");
    Conta c, temp;
    int existe = 0;

    printf("Numero da conta: ");
    scanf("%d", &c.numero);

    rewind(arquivo);
    while(fread(&temp, sizeof(Conta), 1, arquivo)) {
        if(temp.numero == c.numero) {
            existe = 1;
            break;
        }
    }

    if(existe == 1) {
        printf("Conta ja existe!\n");
    } else {
        printf("Nome do titular: ");
        scanf(" %[^\n]s", c.titular);
        printf("CPF: ");
        scanf("%s", c.cpf);
        printf("Saldo inicial: ");
        scanf("%f", &c.saldo);
        c.status = 1;

        fseek(arquivo, 0, SEEK_END);
        fwrite(&c, sizeof(Conta), 1, arquivo);
        printf("Conta cadastrada com sucesso!\n");
    }
    fclose(arquivo);
}

void consultarConta() {
    FILE *arquivo = fopen("contas.dat", "rb");
    if(arquivo == NULL) {
        printf("Nenhuma conta cadastrada!\n");
        return;
    }
    
    int num, achou = 0;
    Conta c;
    
    printf("Digite o numero da conta: ");
    scanf("%d", &num);

    while(fread(&c, sizeof(Conta), 1, arquivo)) {
        if(c.numero == num) {
            printf("=======================\n");
            printf("CONTA\n");
            printf("=======================\n");
            printf("Numero: %d\n", c.numero);
            printf("Titular: %s\n", c.titular);
            printf("CPF: %s\n", c.cpf);
            printf("Saldo: R$ %.2f\n", c.saldo);
            if(c.status == 1) {
                printf("Status: ATIVA\n");
            } else {
                printf("Status: INATIVA\n");
            }
            achou = 1;
            break;
        }
    }
    
    if(achou == 0) {
        printf("Conta nao encontrada!\n");
    }
    fclose(arquivo);
}

void depositar() {
    FILE *arquivo = fopen("contas.dat", "rb+");
    if(arquivo == NULL) {
        printf("Nenhuma conta cadastrada!\n");
        return;
    }
    
    int num, achou = 0;
    float valor;
    Conta c;
    
    printf("Numero da conta: ");
    scanf("%d", &num);
    printf("Valor do deposito: ");
    scanf("%f", &valor);

    if(valor < 0) {
        printf("Nao e permitido depositar valores negativos!\n");
        fclose(arquivo);
        return;
    }

    while(fread(&c, sizeof(Conta), 1, arquivo)) {
        if(c.numero == num) {
            achou = 1;
            if(c.status == 0) {
                printf("Conta inativa!\n");
            } else {
                c.saldo = c.saldo + valor;
                fseek(arquivo, -sizeof(Conta), SEEK_CUR);
                fwrite(&c, sizeof(Conta), 1, arquivo);
                printf("Deposito realizado com sucesso!\n");
                printf("Saldo atual: R$ %.2f\n", c.saldo);
            }
            break;
        }
    }
    
    if(achou == 0) {
        printf("Conta nao encontrada!\n");
    }
    fclose(arquivo);
}

void sacar() {
    FILE *arquivo = fopen("contas.dat", "rb+");
    if(arquivo == NULL) {
        printf("Nenhuma conta cadastrada!\n");
        return;
    }
    
    int num, achou = 0;
    float valor;
    Conta c;
    
    printf("Numero da conta: ");
    scanf("%d", &num);
    printf("Valor do saque: ");
    scanf("%f", &valor);

    if(valor < 0) {
        printf("Nao e permitido sacar valores negativos!\n");
        fclose(arquivo);
        return;
    }

    while(fread(&c, sizeof(Conta), 1, arquivo)) {
        if(c.numero == num) {
            achou = 1;
            if(c.status == 0) {
                printf("Conta inativa!\n");
            } else {
                if(c.saldo >= valor) {
                    c.saldo = c.saldo - valor;
                    fseek(arquivo, -sizeof(Conta), SEEK_CUR);
                    fwrite(&c, sizeof(Conta), 1, arquivo);
                    printf("Saque realizado com sucesso!\n");
                    printf("Saldo atual: R$ %.2f\n", c.saldo);
                } else {
                    printf("Saldo insuficiente!\n");
                    printf("Saldo disponivel: R$ %.2f\n", c.saldo);
                }
            }
            break;
        }
    }
    
    if(achou == 0) {
        printf("Conta nao encontrada!\n");
    }
    fclose(arquivo);
}

void listarContas() {
    FILE *arquivo = fopen("contas.dat", "rb");
    if(arquivo == NULL) {
        printf("Nenhuma conta cadastrada!\n");
        return;
    }
    
    Conta c;
    
    printf("========================================\n");
    printf("CONTAS CADASTRADAS\n");
    printf("========================================\n");
    
    while(fread(&c, sizeof(Conta), 1, arquivo)) {
        printf("Conta: %d\n", c.numero);
        printf("Titular: %s\n", c.titular);
        printf("Saldo: R$ %.2f\n", c.saldo);
        if(c.status == 1) {
            printf("Status: ATIVA\n\n");
        } else {
            printf("Status: INATIVA\n\n");
        }
    }
    fclose(arquivo);
}

int main() {
    int opcao = 0;
    
    while(opcao != 6) {
        printf("\nCAIXA ELETRONICO\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Consultar conta\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Listar contas\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            cadastrarConta();
        } else if(opcao == 2) {
            consultarConta();
        } else if(opcao == 3) {
            depositar();
        } else if(opcao == 4) {
            sacar();
        } else if(opcao == 5) {
            listarContas();
        } else if(opcao == 6) {
            printf("Obrigado por utilizar o Caixa Eletronico!\n");
        } else {
            printf("Opcao invalida, tenta de novo.\n");
        }
    }
    return 0;
}
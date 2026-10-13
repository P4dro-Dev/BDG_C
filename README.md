# 🏧| Sistema de Caixa Eletrônico

Um projeto simples de simulador de caixa eletrônico rodando via terminal, desenvolvido em linguagem **C**. O sistema utiliza **estruturas (structs)** e **arquivos binários** para garantir a persistência dos dados, simulando o funcionamento real de um banco onde as informações não se perdem ao fechar o programa.

Projeto desenvolvido como prática para o curso de Ciência da Computação do Instituto Federal do Ceará (IFCE) - Campus Tianguá.

## ⚙️| Funcionalidades

O sistema exibe um menu interativo com as seguintes operações:

- **1 - Cadastrar conta:** Cria uma nova conta bancária (número, titular, CPF, saldo inicial) e salva no arquivo `contas.dat`. Impede o cadastro de números de conta duplicados.
- **2 - Consultar conta:** Busca e exibe as informações completas de uma conta específica através do seu número.
- **3 - Depositar:** Adiciona um valor ao saldo da conta. Possui validações para impedir depósitos de valores negativos ou em contas inativas.
- **4 - Sacar:** Deduz um valor do saldo. O sistema verifica automaticamente se a conta está ativa e se há saldo suficiente antes de concluir a operação.
- **5 - Listar contas:** Exibe um relatório com todas as contas já cadastradas e armazenadas no sistema.
- **6 - Sair:** Encerra a execução do caixa eletrônico.

## 🛠️| Tecnologias e Conceitos Utilizados

- **Linguagem:** C
- **Persistência de Dados:** Arquivos binários (`.dat`) usando `fopen()`, `fclose()`, `fread()` e `fwrite()`.
- **Estruturas de Dados:** Uso de `struct` para agrupar as propriedades das contas.
- **Lógica de Programação:** Estruturas de repetição, condicionais, busca sequencial em arquivos e ponteiros de arquivo (`fseek`, `rewind`).

## 🚀| Como compilar e executar

Certifique-se de ter um compilador C (como o GCC) instalado no seu sistema. 

1. Clone o repositório ou baixe os arquivos.
2. Abra o terminal na pasta do projeto.
3. Compile o código com o comando:
   ```bash
   gcc Ficheiro.c -o caixa

   Execute o programa:

No Linux / Pop!_OS / macOS:

Bash
```
./caixa
No Windows:
```

```
DOS
caixa.exe
```

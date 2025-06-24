#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utils.h"
#include "ArvorePrefixo.h"

//=========================================================
void testarInsercao(char* nome, char* chaves[], int tam){
    printf("\n=== TESTE %s ===\n\n", nome);
    
    pDPrefixo arvore = criarArvorePrefixo();
    int i, r;
    
    printf("Inserindo chaves:\n");
    for(i=0; i<tam; i++){
        printf("  Inserindo: %s ", chaves[i]);
        r = incluirInfoPrefixo(arvore, chaves[i], strlen(chaves[i]));
        if (r == 0)
            printf("- ERRO: ja existe ou eh prefixo de outra chave!");
        else
            printf("- OK");
        printf("\n");
    }
    
    printf("\nArvore resultante:\n");
    desenhaArvorePrefixo(arvore);
    printf("\n");
}

//=========================================================
void testarBusca(char* nome, char* chaves[], int tam, char* buscas[], int tamBuscas){
    printf("\n=== TESTE BUSCA %s ===\n\n", nome);
    
    pDPrefixo arvore = criarArvorePrefixo();
    int i, r;
    
    // Inserir chaves
    printf("Construindo arvore com chaves: ");
    for(i=0; i<tam; i++){
        incluirInfoPrefixo(arvore, chaves[i], strlen(chaves[i]));
        printf("%s ", chaves[i]);
    }
    printf("\n\n");
    
    // Testar buscas
    printf("Testando buscas:\n");
    for(i=0; i<tamBuscas; i++){
        r = buscarInfoPrefixo(arvore, buscas[i], strlen(buscas[i]));
        printf("  Buscar '%s': %s\n", buscas[i], r ? "ENCONTRADO" : "NAO ENCONTRADO");
    }
    printf("\n");
}

//=========================================================
void testarExclusao(char* nome, char* chaves[], int tam, char* exclusoes[], int tamExclusoes){
    printf("\n=== TESTE EXCLUSAO %s ===\n\n", nome);
    
    pDPrefixo arvore = criarArvorePrefixo();
    int i, r;
    
    // Inserir chaves
    printf("Construindo arvore com chaves: ");
    for(i=0; i<tam; i++){
        incluirInfoPrefixo(arvore, chaves[i], strlen(chaves[i]));
        printf("%s ", chaves[i]);
    }
    printf("\n\nArvore inicial:\n");
    desenhaArvorePrefixo(arvore);
    
    // Testar exclusoes
    printf("\nTestando exclusoes:\n");
    for(i=0; i<tamExclusoes; i++){
        r = excluirInfoPrefixo(arvore, exclusoes[i], strlen(exclusoes[i]));
        printf("  Excluir '%s': %s\n", exclusoes[i], r ? "REMOVIDO" : "NAO ENCONTRADO");
        if(r) {
            printf("  Arvore apos exclusao:\n");
            desenhaArvorePrefixo(arvore);
            printf("\n");
        }
    }
    printf("\n");
}

//=========================================================
pDPrefixo constroiArvorePrefixo(char* chaves[], int tam){
    pDPrefixo arvore = criarArvorePrefixo();
    int i, r;
    for(i=0; i<tam; i++){
        r = incluirInfoPrefixo(arvore, chaves[i], strlen(chaves[i]));
        if (r == 0)
            printf("\n Erro na inclusao da chave [%s] - ja existe ou eh prefixo de outra chave!", chaves[i]);
    }
    return arvore;
}

//=========================================================
void testarOperacoesCompletas(){
    printf("\n=== TESTE OPERACOES COMPLETAS ===\n\n");
    
    char* chaves[] = {"101", "110", "1101", "1110", "000", "001"};
    pDPrefixo arvore = constroiArvorePrefixo(chaves, 6);
    
    printf("\nArvore construida:\n");
    desenhaArvorePrefixo(arvore);
    
    // Teste de buscas
    printf("\nTestes de busca:\n");
    char* testeBusca[] = {"101", "110", "111", "000", "010", "1101"};
    for(int i=0; i<6; i++){
        int found = buscarInfoPrefixo(arvore, testeBusca[i], strlen(testeBusca[i]));
        printf("  Buscar '%s': %s\n", testeBusca[i], found ? "ENCONTRADO" : "NAO ENCONTRADO");
    }
    
    // Teste de exclusoes
    printf("\nExcluindo '110':\n");
    int excluido = excluirInfoPrefixo(arvore, "110", 3);
    printf("  Resultado: %s\n", excluido ? "REMOVIDO" : "NAO ENCONTRADO");
    desenhaArvorePrefixo(arvore);
    
    printf("\nExcluindo '000':\n");
    excluido = excluirInfoPrefixo(arvore, "000", 3);
    printf("  Resultado: %s\n", excluido ? "REMOVIDO" : "NAO ENCONTRADO");
    desenhaArvorePrefixo(arvore);
    printf("\n");
}

//=========================================================
void mostrarMenu(){
    printf("\n" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    printf("=== MENU DE TESTES DA ARVORE PATRICIA ===\n");
    printf("=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    printf("1.  Teste Basico (exemplo original)\n");
    printf("2.  Teste de Prefixos Simples\n");
    printf("3.  Teste de Strings Curtas\n");
    printf("4.  Teste de Busca\n");
    printf("5.  Teste de Exclusao\n");
    printf("6.  Teste de Strings Longas\n");
    printf("7.  Teste de Prefixos Conflitantes\n");
    printf("8.  Teste de Operacoes Completas\n");
    printf("9.  Teste de Strings Similares\n");
    printf("10. Teste de String Unica\n");
    printf("----------\n");
    printf("11. Executar TODOS os testes\n");
    printf("0.  Sair\n");
    printf("=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    printf("Escolha uma opcao: ");
}

//=========================================================
void executarTeste(int opcao){
    switch(opcao){
        case 1: {
            char* ex1[] = {"001100", "01",  "001101", "1010", "11", "0011001"};
            testarInsercao("BASICO", ex1, 6);
            break;
        }
        case 2: {
            char* ex2[] = {"1", "10", "101", "1011", "11"};
            testarInsercao("PREFIXOS SIMPLES", ex2, 5);
            break;
        }
        case 3: {
            char* ex3[] = {"0", "1", "00", "01", "10", "11"};
            testarInsercao("STRINGS CURTAS", ex3, 6);
            break;
        }
        case 4: {
            char* dadosBusca[] = {"100", "101", "110", "111", "000"};
            char* buscas[] = {"100", "101", "110", "001", "111", "1100", "10"};
            testarBusca("BUSCA", dadosBusca, 5, buscas, 7);
            break;
        }
        case 5: {
            char* dadosExclusao[] = {"1000", "1001", "1010", "1100", "1101"};
            char* exclusoes[] = {"1001", "1100", "9999", "1010"};
            testarExclusao("EXCLUSAO", dadosExclusao, 5, exclusoes, 4);
            break;
        }
        case 6: {
            char* ex6[] = {"1", "10101010101010", "101", "10101010101011"};
            testarInsercao("STRINGS LONGAS", ex6, 4);
            break;
        }
        case 7: {
            char* ex7[] = {"abc", "ab", "abcd", "a"};
            printf("\nNota: Este teste usa strings nao-binarias para demonstrar comportamento\n");
            testarInsercao("PREFIXOS CONFLITANTES", ex7, 4);
            break;
        }
        case 8: {
            testarOperacoesCompletas();
            break;
        }
        case 9: {
            char* ex9[] = {"11110000", "11110001", "11110010", "11110011", "11111000"};
            testarInsercao("STRINGS SIMILARES", ex9, 5);
            break;
        }
        case 10: {
            char* ex10[] = {"1010101"};
            testarInsercao("STRING UNICA", ex10, 1);
            break;
        }
        case 11: {
            printf("\n=== EXECUTANDO TODOS OS TESTES ===\n\n");
            for(int i = 1; i <= 10; i++){
                executarTeste(i);
                if(i < 10) {
                    printf("\n" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
                    printf("Pressione Enter para continuar com o proximo teste...");
                    getchar();
                }
            }
            printf("\n" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
            printf("TODOS OS TESTES FORAM EXECUTADOS!\n");
            break;
        }
        default:
            printf("Opcao invalida!\n");
    }
}

//-------------------------------------------------------
int main(){
    int opcao;
    
    printf("\n=== SISTEMA DE TESTES DA ARVORE PATRICIA ===\n");
    printf("Bem-vindo ao sistema de testes!\n\n");
    
    do {
        mostrarMenu();
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer
        
        if(opcao != 0) {
            executarTeste(opcao);
            
            if(opcao != 11) { // Se nao executou todos os testes
                printf("\n" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
                printf("Pressione Enter para voltar ao menu...");
                getchar();
            }
        }
        
    } while(opcao != 0);
    
    printf("\n" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "=" "\n");
    printf("Obrigado por usar o sistema de testes!\n");
    printf("=== PROGRAMA FINALIZADO ===\n\n");
    
    return 0;
}

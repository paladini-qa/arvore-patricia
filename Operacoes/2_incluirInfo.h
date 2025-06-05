#ifndef INCLUIR_INFO_PREFIXO_H
#define INCLUIR_INFO_PREFIXO_H

int buscarInfoPrefixo(pDPrefixo, char[], int);

int getBitInsercao(char chave[], int bitIndex, int tamanhoChave)
{
    if (bitIndex >= tamanhoChave)
        return 0;
    return (chave[bitIndex] == '1') ? 1 : 0;
}

int encontrarDivergencia(char chave1[], int tam1, char chave2[], int tam2)
{
    int maxLen = (tam1 > tam2) ? tam1 : tam2;
    int i;

    for (i = 0; i < maxLen; i++)
    {
        int bit1 = (i < tam1) ? getBitInsercao(chave1, i, tam1) : 0;
        int bit2 = (i < tam2) ? getBitInsercao(chave2, i, tam2) : 0;

        if (bit1 != bit2)
        {
            return i;
        }
    }
    return maxLen;
}

void construirChaveDoNo(pNohPrefixo raiz, char chaveAtual[], int *posicao, char chaveResultado[], int maxTam)
{
    if (raiz == NULL)
        return;

    if (raiz->terminal == 1)
    {
        int i;
        for (i = 0; i < *posicao && i < maxTam - 1; i++)
        {
            chaveResultado[i] = chaveAtual[i];
        }
        chaveResultado[i] = '\0';
        return;
    }

    if (raiz->esquerda != NULL)
    {
        if (*posicao < maxTam - 1)
        {
            chaveAtual[*posicao] = '0';
            (*posicao)++;
            construirChaveDoNo(raiz->esquerda, chaveAtual, posicao, chaveResultado, maxTam);
            (*posicao)--;
        }
        return;
    }

    if (raiz->direita != NULL)
    {
        if (*posicao < maxTam - 1)
        {
            chaveAtual[*posicao] = '1';
            (*posicao)++;
            construirChaveDoNo(raiz->direita, chaveAtual, posicao, chaveResultado, maxTam);
            (*posicao)--;
        }
        return;
    }
}

pNohPrefixo incluirInfoPrefixoRecursivo(pNohPrefixo raiz, char chave[], int tamanhoChave, int bitAtual)
{

    if (bitAtual >= tamanhoChave)
    {
        if (raiz == NULL)
        {
            return criarNohPrefixo(1, bitAtual);
        }
        else
        {
            raiz->terminal = 1;
            return raiz;
        }
    }

    if (raiz == NULL)
    {
        raiz = criarNohPrefixo(0, bitAtual);
    }

    int bit = getBitInsercao(chave, bitAtual, tamanhoChave);

    if (bit == 0)
    {
        raiz->esquerda = incluirInfoPrefixoRecursivo(raiz->esquerda, chave, tamanhoChave, bitAtual + 1);
    }
    else
    {
        raiz->direita = incluirInfoPrefixoRecursivo(raiz->direita, chave, tamanhoChave, bitAtual + 1);
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int incluirInfoPrefixo(pDPrefixo arvore, char chave[], int k)
{

    printf("\n Buscando a chave: %s", chave);
    int r = buscarInfoPrefixo(arvore, chave, k);

    printf("\n Achou chave ou prefixo= %d \n", r);
    if (r == 0)
    {
        if (arvore->raiz->esquerda == NULL && arvore->raiz->direita == NULL)
        {
            int primeiroBit = getBitInsercao(chave, 0, k);
            if (primeiroBit == 0)
            {
                arvore->raiz->esquerda = incluirInfoPrefixoRecursivo(NULL, chave, k, 1);
            }
            else
            {
                arvore->raiz->direita = incluirInfoPrefixoRecursivo(NULL, chave, k, 1);
            }
        }
        else
        {
            int primeiroBit = getBitInsercao(chave, 0, k);
            if (primeiroBit == 0)
            {
                arvore->raiz->esquerda = incluirInfoPrefixoRecursivo(arvore->raiz->esquerda, chave, k, 1);
            }
            else
            {
                arvore->raiz->direita = incluirInfoPrefixoRecursivo(arvore->raiz->direita, chave, k, 1);
            }
        }
        arvore->quantidadeNohs++;
        return 1;
    }

    return 0;
}

#endif

#ifndef BUSCAR_INFO_PREFIXO_H
#define BUSCAR_INFO_PREFIXO_H

int getBit(char chave[], int bitIndex, int tamanhoChave)
{
    if (bitIndex >= tamanhoChave)
        return 0;
    return (chave[bitIndex] == '1') ? 1 : 0;
}

int encontrarPrimeiraBitDiferente(char chave1[], int tam1, char chave2[], int tam2)
{
    int maxLen = (tam1 > tam2) ? tam1 : tam2;
    int i;

    for (i = 0; i < maxLen; i++)
    {
        int bit1 = (i < tam1) ? getBit(chave1, i, tam1) : 0;
        int bit2 = (i < tam2) ? getBit(chave2, i, tam2) : 0;

        if (bit1 != bit2)
        {
            return i;
        }
    }
    return maxLen;
}

int buscarInfoPrefixoRecursivo(pNohPrefixo raiz, char chave[], int tamanhoChave)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (raiz->terminal == 1)
    {
        return 1;
    }

    int bit;
    if (raiz->bitIndex == -1)
    {
        if (raiz->esquerda == NULL && raiz->direita == NULL)
        {
            return 0;
        }
        bit = getBit(chave, 0, tamanhoChave);
    }
    else
    {
        bit = getBit(chave, raiz->bitIndex, tamanhoChave);
    }

    if (bit == 0)
    {
        return buscarInfoPrefixoRecursivo(raiz->esquerda, chave, tamanhoChave);
    }
    else
    {
        return buscarInfoPrefixoRecursivo(raiz->direita, chave, tamanhoChave);
    }
}

/* ----------------------------------------------------------*/
int buscarInfoPrefixo(pDPrefixo arvore, char chave[], int k)
{
    return buscarInfoPrefixoRecursivo(arvore->raiz, chave, k);
}

#endif

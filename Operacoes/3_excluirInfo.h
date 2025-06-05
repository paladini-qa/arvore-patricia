#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

int getBitExclusao(char chave[], int bitIndex, int tamanhoChave)
{
    if (bitIndex >= tamanhoChave)
        return 0;
    return (chave[bitIndex] == '1') ? 1 : 0;
}

int temApenasUmFilho(pNohPrefixo noh)
{
    return (noh->esquerda == NULL && noh->direita != NULL) ||
           (noh->esquerda != NULL && noh->direita == NULL);
}

pNohPrefixo obterUnicoFilho(pNohPrefixo noh)
{
    if (noh->esquerda != NULL)
    {
        return noh->esquerda;
    }
    return noh->direita;
}

pNohPrefixo excluirInfoRecursivo(pNohPrefixo raiz, char chave[], int tamanhoChave, int *removido)
{

    if (raiz == NULL)
    {
        *removido = 0;
        return NULL;
    }

    if (raiz->terminal == 1)
    {
        *removido = 1;
        free(raiz);
        return NULL;
    }

    int bit;
    if (raiz->bitIndex == -1)
    {
        bit = getBitExclusao(chave, 0, tamanhoChave);
    }
    else
    {
        bit = getBitExclusao(chave, raiz->bitIndex, tamanhoChave);
    }

    if (bit == 0)
    {
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, chave, tamanhoChave, removido);
    }
    else
    {
        raiz->direita = excluirInfoRecursivo(raiz->direita, chave, tamanhoChave, removido);
    }

    if (*removido && raiz->terminal == 0 && temApenasUmFilho(raiz))
    {
        pNohPrefixo unicoFilho = obterUnicoFilho(raiz);
        free(raiz);
        return unicoFilho;
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfoPrefixo(pDPrefixo arvore, char chave[], int k)
{

    int removido = 0;
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, chave, k, &removido);

    if (removido)
    {
        arvore->quantidadeNohs--;
        return 1;
    }

    return 0;
}

#endif

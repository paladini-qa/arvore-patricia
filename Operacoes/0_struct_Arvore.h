#ifndef STRUCT_ARVORE_H
#define STRUCT_ARVORE_H

struct nohPrefixo
{
   int terminal;
   int bitIndex;
   struct nohPrefixo *esquerda;
   struct nohPrefixo *direita;
};

#endif

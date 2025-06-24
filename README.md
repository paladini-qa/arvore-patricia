# Árvore Patricia (Prefix Tree)

Uma implementação completa de **Árvore Patricia** (também conhecida como Prefix Tree ou Radix Tree) em linguagem C, com sistema de testes interativo e visualização da estrutura da árvore.

## 📖 Sobre o Projeto

A **Árvore Patricia** é uma estrutura de dados especializada para armazenamento eficiente de strings com prefixos comuns. Esta implementação oferece operações de inserção, busca, exclusão e visualização, ideal para:

- Armazenamento eficiente de strings binárias
- Busca rápida por prefixos
- Detecção automática de conflitos de prefixos
- Visualização da estrutura interna da árvore

## 🚀 Funcionalidades

### ✅ Operações Básicas

- **Inserção**: Adiciona strings à árvore com verificação de prefixos
- **Busca**: Localiza strings na árvore de forma eficiente
- **Exclusão**: Remove strings mantendo a integridade da estrutura
- **Visualização**: Exibe a árvore em formato ASCII

### ✅ Sistema de Testes

- **Menu interativo** com 10 cenários de teste diferentes
- **Testes específicos** para cada funcionalidade
- **Execução individual** ou completa de todos os testes
- **Interface amigável** com formatação organizada

## 📁 Estrutura do Projeto

```
arvore-patricia/
├── main.c                          # Programa principal com sistema de testes
├── ArvorePrefixo.h                 # Header principal
├── TAD_ArvorePrefixo.h            # Definições do TAD
├── Utils.h                        # Utilitários
├── Operacoes/                     # Implementações das operações
│   ├── 0_struct_Arvore.h         # Estrutura do nó
│   ├── 0_struct_Descritor.h      # Estrutura do descritor
│   ├── 1_criarArvore.h           # Criação da árvore
│   ├── 2_incluirInfo.h           # Operação de inserção
│   ├── 3_excluirInfo.h           # Operação de exclusão
│   ├── 4_buscarInfo.h            # Operação de busca
│   └── 12_desenhaArvore.h        # Visualização da árvore
└── README.md                      # Este arquivo
```

## 🛠️ Compilação e Execução

### Pré-requisitos

- Compilador GCC
- Sistema operacional Windows/Linux/macOS

### Compilar

```bash
gcc -o teste_arvore main.c -I.
```

### Executar

```bash
./teste_arvore
```

## 🎮 Como Usar

### Menu Principal

Ao executar o programa, você verá o menu interativo:

```
====================
=== MENU DE TESTES DA ARVORE PATRICIA ===
====================
1.  Teste Basico (exemplo original)
2.  Teste de Prefixos Simples
3.  Teste de Strings Curtas
4.  Teste de Busca
5.  Teste de Exclusao
6.  Teste de Strings Longas
7.  Teste de Prefixos Conflitantes
8.  Teste de Operacoes Completas
9.  Teste de Strings Similares
10. Teste de String Unica
----------
11. Executar TODOS os testes
0.  Sair
====================
```

### Opções Disponíveis

| Opção  | Descrição                         | Exemplo de Uso                                  |
| ------ | --------------------------------- | ----------------------------------------------- |
| **1**  | Teste básico com strings variadas | `["001100", "01", "001101", "1010", "11"]`      |
| **2**  | Demonstra rejeição de prefixos    | `["1", "10", "101"]` - apenas "1" é aceito      |
| **3**  | Strings binárias de 1 bit         | `["0", "1"]`                                    |
| **4**  | Testa operações de busca          | Busca por strings existentes e inexistentes     |
| **5**  | Testa operações de exclusão       | Remove strings e mostra reestruturação          |
| **6**  | Strings de tamanhos variados      | Mistura strings curtas e longas                 |
| **7**  | Strings não-binárias              | Demonstra comportamento com caracteres diversos |
| **8**  | Teste integrado completo          | Combina inserção, busca e exclusão              |
| **9**  | Strings com bits similares        | Testa eficiência com dados similares            |
| **10** | Árvore com um único elemento      | Caso edge simples                               |
| **11** | Executa todos os testes           | Demonstração completa                           |

## 💡 Exemplos de Uso

### Exemplo 1: Teste Básico

```
=== TESTE BASICO ===

Inserindo chaves:
  Inserindo: 001100 - OK
  Inserindo: 01 - OK
  Inserindo: 001101 - OK
  Inserindo: 1010 - OK
  Inserindo: 11 - OK
  Inserindo: 0011001 - ERRO: ja existe ou eh prefixo de outra chave!

Arvore resultante:
     +----T:1 B:2
+----T:0 B:1
|    |    +----T:0 B:3
|    +----T:0 B:2
R:0
```

### Exemplo 2: Detecção de Prefixos

```
=== TESTE PREFIXOS SIMPLES ===

Inserindo chaves:
  Inserindo: 1 - OK
  Inserindo: 10 - ERRO: ja existe ou eh prefixo de outra chave!
  Inserindo: 101 - ERRO: ja existe ou eh prefixo de outra chave!
```

### Exemplo 3: Operações de Busca

```
=== TESTE BUSCA ===

Testando buscas:
  Buscar '100': ENCONTRADO
  Buscar '101': ENCONTRADO
  Buscar '001': NAO ENCONTRADO
  Buscar '111': ENCONTRADO
```

## 🔧 Características Técnicas

### Algoritmo

- **Estrutura**: Árvore binária com índices de bits
- **Inserção**: O(k) onde k é o comprimento da string
- **Busca**: O(k) onde k é o comprimento da string
- **Exclusão**: O(k) com reestruturação automática

### Recursos Especiais

- **Prevenção de Prefixos**: Impede inserção de strings que são prefixos de outras
- **Visualização ASCII**: Mostra a estrutura interna da árvore
- **Reestruturação Automática**: Otimiza a árvore após exclusões
- **Interface Interativa**: Sistema de menu para facilitar testes

## 🎯 Casos de Teste

### Testes de Inserção

- ✅ Strings binárias válidas
- ✅ Detecção de prefixos duplicados
- ✅ Strings de diferentes tamanhos
- ✅ Casos edge (string única, strings vazias)

### Testes de Busca

- ✅ Busca por strings existentes
- ✅ Busca por strings inexistentes
- ✅ Busca por prefixos de strings existentes

### Testes de Exclusão

- ✅ Remoção de folhas
- ✅ Remoção de nós internos
- ✅ Reestruturação da árvore
- ✅ Tentativa de remoção de strings inexistentes

## 🐛 Solução de Problemas

### Erro de Compilação

```bash
# Se houver erro de permissão, tente:
gcc -o teste_arvore_novo main.c -I.
```

### Caracteres Especiais

- O programa foi otimizado para usar apenas caracteres ASCII
- Não há problemas de codificação em diferentes sistemas

### Performance

- Para strings muito longas (>1000 caracteres), considere ajustar o algoritmo
- A visualização pode ficar extensa com muitos nós

## 🤝 Contribuição

Este projeto foi desenvolvido como material educacional. Sugestões e melhorias são bem-vindas!

### Possíveis Melhorias

- [ ] Suporte a strings não-binárias completo
- [ ] Implementação de iteradores
- [ ] Operações de união e interseção
- [ ] Persistência em arquivo
- [ ] Interface gráfica

## 📚 Referências

- **Árvore Patricia**: Estrutura de dados para armazenamento eficiente de strings
- **Radix Tree**: Variação otimizada para prefixos comuns
- **Prefix Tree**: Implementação clássica para busca de prefixos

## 📝 Licença

Este projeto é disponibilizado para fins educacionais.

---

**Desenvolvido em C** | **Sistema de Testes Interativo** | **Visualização ASCII**

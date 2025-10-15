# 📘 Disciplina: Listas e Ordenação em C

> Material de apoio baseado no conteúdo da Prof.ª Daisy Albuquerque — Estácio de Sá  
> Tema: Estruturas de Dados, Listas, Busca e Ordenação

---

## 🧠 Objetivo da Disciplina

Compreender e aplicar os **conceitos fundamentais de estruturas lineares** em linguagem C, utilizando listas estáticas e dinâmicas, e implementando algoritmos de busca e ordenação para solucionar problemas de armazenamento e manipulação de dados.

---

## 🧩 Conteúdo Programático

### 🧱 Nível Novato — Fundamentos e Listas Estáticas

**Conceitos abordados:**
- Estruturas (`struct`) em C;
- Vetores (listas lineares estáticas);
- Inserção, remoção, listagem e busca linear;
- Introdução à modularização (funções separadas).

**Mini Projeto:**  
> Sistema de inventário do jogador (*Free Fire*).  
> Cada item possui: `nome`, `tipo`, `quantidade`.

**Habilidades desenvolvidas:**
- Criação e manipulação de structs;
- Uso de vetores para armazenar dados;
- Aplicação de lógica condicional e repetição;
- Implementação de menus interativos.

---

### ⚙️ Nível Aventureiro — Listas Dinâmicas e Ordenação

**Conceitos abordados:**
- Alocação dinâmica (`malloc`, `free`);
- Estruturas encadeadas (listas simples e duplas);
- Comparação entre **listas e vetores**;
- Implementação de **busca binária** (em vetores ordenados);
- Introdução a **algoritmos de ordenação** (Bubble e Selection Sort).

**Mini Projeto:**  
> Ampliação do sistema de inventário com duas versões:  
> - Mochila com vetor (sequencial)  
> - Mochila com lista encadeada (dinâmica)

**Funções principais:**
- Inserir, remover, listar e buscar itens em ambas as estruturas;
- Ordenar por nome ou tipo;
- Comparar número de comparações entre buscas lineares e binárias.

---

### 🧠 Nível Mestre — Algoritmos de Ordenação

**Conceitos abordados:**
- Análise de desempenho dos algoritmos de ordenação;
- Casos: melhor, médio e pior caso;
- Contagem de comparações e trocas.

**Algoritmos estudados:**
1. **Bubble Sort**
2. **Insertion Sort**
3. **Selection Sort**

**Mini Projeto Final:**  
> Sistema de inventário completo, com:
> - Inserção e exibição de itens;
> - Escolha do tipo de ordenação;
> - Exibição do número de comparações e trocas;
> - Avaliação da eficiência de cada método.

---

## 🔍 Busca e Ordenação — Conceitos-Chave

| Conceito | Descrição |
|-----------|------------|
| **Busca Linear** | Percorre todos os elementos até encontrar o item desejado. |
| **Busca Binária** | Divide o vetor ao meio repetidamente, buscando em vetores ordenados. |
| **Bubble Sort** | Troca vizinhos fora de ordem até que o vetor esteja ordenado. |
| **Insertion Sort** | Insere cada elemento na posição correta, comparando com anteriores. |
| **Selection Sort** | Seleciona o menor elemento e o coloca na posição correta. |

---

## ⚔️ Projeto Integrador — Modo Sobrevivência

Inspirado em jogos de sobrevivência, o aluno cria um sistema de inventário (mochila) que evolui conforme os níveis:

| Nível | Estrutura | Algoritmos aplicados |
|-------|------------|----------------------|
| 🧩 Novato | Vetor fixo (`struct` + array) | Busca linear |
| ⚙️ Aventureiro | Vetor + Lista encadeada | Busca binária + Ordenação simples |
| 🧠 Mestre | Vetor ordenado | Bubble, Insertion e Selection Sort |

**Aprendizados finais:**
- Diferença entre estruturas estáticas e dinâmicas;
- Entendimento de complexidade algorítmica;
- Comparação de desempenho entre diferentes estratégias de ordenação.

---

## 💻 Tecnologias e Ferramentas

- **Linguagem:** C  
- **Compilador:** GCC (GNU Compiler Collection)  
- **Ambiente sugerido:** Code::Blocks, Dev-C++, ou terminal Linux  
- **Paradigma:** Estruturado

---

## 🧮 Exemplo de Execução (Saída Esperada)

```
========== MODO SOBREVIVÊNCIA =========
1. Inserir item
2. Listar itens
3. Ordenar inventário
4. Buscar item
0. Sair
Escolha: 1

Nome: Granada
Tipo: Explosivo
Quantidade: 2
✅ Item adicionado com sucesso!

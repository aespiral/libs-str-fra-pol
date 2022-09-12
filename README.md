# Uso de ponteiros e alocação dinâmica em funções (bibliotecas)

## Pontuação

| Quesito | Nota |
|---------|------|
| Str     |      |
| Pol     |      |
| Fra     |      |
| TOTAL   |      |

## Objetivos

- Praticar o uso de ponteiros e alocação dinâmica no projeto de funções
- Exercitar duas estratégias: mutabilidade e imutabilidade nos parâmetros

A biblioteca `string` da Linguagem C usa a estratégia de mutabilidade.

Isso significa que um dos parâmetros é passado por referência, e o resultado
da função é passado como alterações no próprio parâmetro.

A versão imutável não coloca o resultado em algum parâmetro passado,
mas aloca sua própria área na memória, e copia o resultado lá.

Esse conceito pode ser visto no arquivo `mystring.c`.

Perguntas para orientar o exame do arquivo `mystring.c`.
1. Qual a diferença entre as duas variáveis abaixo? 
(Desenhe o _stack frame_ da pilha.)
```c
    char alocado[10];
    char* nao_alocado;
```
2. Qual a diferença das duas funções nas chamadas abaixo?
```c
    mystrcpy(alocado, b);  // Versao mutavel 
    nao_alocado = mystrcpy_imm(NULL, c);  // Versao imutavel 
```

## Atividades

1. Biblioteca `mystring` (1 ponto)
   - Estude a funçâo `strcat` da biblioteca `string`. Escreva um trecho de programa (na `main`) para observar seu funcionamento. 
   - Reimplemente a função com o nome `mystrcat` (consulte o ítem no Capítulo 7 do livro-texto).
   - Implemente a função `mystrcat_imm`, que retorna um ponteiro para
   uma string que é o resultado da concatenação das strings nos parâmetros.
2. Biblioteca `polinomial` (6 pontos)
   - Escolha 3 funções da biblioteca que resultem em um polinômio. Confira o arquivo de README correspondente.
   - Implemente as funções nas duas versões: mutável e imutável.
3. Biblioteca `fracional` (3 pontos)
   - Implemente 2 funções na forma imutável.

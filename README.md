# EX02 - Uso de ponteiros e alocação dinâmica em funções (bibliotecas)

## Pontuação

| Quesito | Nota |
|---------|------|
| Str     |      |
| Pol     |      |
| Fra     |      |

## Objetivos

- Praticar o uso de ponteiros e alocação dinâmica no projeto de funções
- Exercitar duas estratégias: mutabilidade e imutabilidade nos parâmetros

A biblioteca `string` da Linguagem C usa a estratégia de mutabilidade.

Isso significa que um dos parâmetros é passado por referência, e o resultado
da função é passado como alterações no próprio parâmetro.

## Atividades

1. Reimplementar algumas funções da biblioteca `string` no arquivo `mystring.c`, 
na forma mutável também, e, se possível, na forma imutável. 
2. Implementar algumas funções da biblioteca de polinômios obrigatoriamente
nas formas mutável e imutável. É preciso alterar o código fornecido a fim de
que os parâmetros e o resultado sejam passados por referência.
3. Implementar algumas funções da biblioteca de frações. 
## Exercício 2: Leitura de dados de um arquivo texto

**Objetivo:**  
Reaplicar o cálculo de médias de alunos, desta vez lendo tudo de um arquivo em disco, sem interação direta pelo teclado.

**Formato do arquivo**  
Crie um arquivo chamado `alunos.txt` com este conteúdo de exemplo:

```
João
7.5
8.0
6.0
-1
Maria
9.0
8.5
-1
-1
```

**Instruções**  
1. Abra `alunos.txt` em modo de leitura.  
2. Percorra as linhas em sequência, removendo quebras de linha.  
3. Para cada bloco de aluno:  
   - **Linha 1:** nome do aluno.  
   - **Linhas seguintes:** notas (numero real).  
   - **Sentinela:** quando ler `-1`, significa “fim das notas desse aluno”.  
   - Calcule a média aritmética das notas lidas e imprima no console:
     ```
     Nome: João, Média: 7.17
     Nome: Maria, Média: 8.75
     ```
4. Pare o programa quando encontrar `-1` como nome de aluno.

> **Dica:** use as operações de abertura de arquivo, loop de leitura linha a linha e condição de sentinela.


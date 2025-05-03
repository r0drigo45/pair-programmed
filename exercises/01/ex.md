### **Exercício: Cálculo de Médias de Alunos**

Você deve escrever um programa que leia o nome de vários alunos e suas respectivas notas. Para cada aluno, o programa deve calcular a média das notas informadas e exibir o nome do aluno seguido da sua média.

#### **Regras:**

1. O programa deve aceitar um número indefinido de alunos.
2. Para cada aluno:

   * Primeiro, o nome do aluno deve ser lido.
   * Em seguida, devem ser lidas as notas do aluno (números de ponto flutuante), uma por uma.
   * O comando de saída para as notas é `-1`. Quando `-1` for lido, significa que não há mais notas para aquele aluno e a média pode ser calculada.
3. O programa deve repetir o processo para um novo aluno até que seja digitado o nome `-1`, o que indica que não há mais alunos a serem processados.
4. Para cada aluno, imprima uma linha no formato:

   ```
   Nome: <nome_do_aluno>, Média: <media_com_duas_casas_decimais>
   ```

#### **Exemplo de entrada:**

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

#### **Exemplo de saída:**

```
Nome: João, Média: 7.17
Nome: Maria, Média: 8.75
```

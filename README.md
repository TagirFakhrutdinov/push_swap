# push_swap

Цель данного проекта сортировка массива чисел за как можно меньшее число инструкций, используя ограниченный набор инструкций.
Бонусом создания тестера для проверки правильности выполнения сортировки.

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

## Клонирование проекта:
```
git clone git@github.com:iamrustamov/push_swap.git

```
## Как запустить программу:
```
Производим клонирование!
cd push_swap/
make
ARG="random numbers"; /.push_swap $ARG // Печать всех интрукций которые потребовались для сортировки стека
// Вместо random numbers любые целые числа через пробел
ARG="random numbers"; ./push_swap $ARG | wc -l // Печать колличества инструкций которые потребовались для сортировки стека
make bonus // Собрать checker для проверки правильности выполнения сортировки
ARG="random numbers"; ./push_swap $ARG | ./checker $ARG // Вывод "ОК" если стек отсортировался, иначе "Error!"

*random numbers - последовательность целых чисел без дубликатов в интервале int (integer)
```

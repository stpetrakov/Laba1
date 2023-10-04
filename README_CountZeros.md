# CountZeros
***Все измерения проводились для натуральных чисел в пределах 1e6***

**Результаты измерений для int32_t:**
```
Quantity of tests is 1:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 10:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 100:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 1000:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 10000:
Slow algo: 2ms
Fast algo: 1ms
Quantity of tests is 100000:
Slow algo: 18ms
Fast algo: 13ms
Quantity of tests is 1000000:
Slow algo: 150ms
Fast algo: 170ms
Quantity of tests is 10000000:
Slow algo: 2392ms
Fast algo: 1961ms
Quantity of tests is 100000000:
Slow algo: 30039ms
Fast algo: 25910ms
```
Мы видим, что время работы кода с масками в среднем в 1,2 раза быстрее работы интуинивного, переборного алгоритма. 

**Результаты измерений для size_t:**
```
Quantity of tests is 1:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 10:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 100:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 1000:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 10000:
Slow algo: 3ms
Fast algo: 2ms
Quantity of tests is 100000:
Slow algo: 34ms
Fast algo: 30ms
Quantity of tests is 1000000:
Slow algo: 329ms
Fast algo: 301ms
Quantity of tests is 10000000:
Slow algo: 2739ms
Fast algo: 1847ms
Quantity of tests is 100000000:
Slow algo: 30553ms
Fast algo: 25547ms
```
Мы видим, что время работы кода с масками в среднем в 1,3 раза быстрее работы интуинивного, переборного алгоритма. 

**Результаты измерений для double:**
```
Quantity of tests is 1:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 10:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 100:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 1000:
Slow algo: 0ms
Fast algo: 0ms
Quantity of tests is 10000:
Slow algo: 4ms
Fast algo: 1ms
Quantity of tests is 100000:
Slow algo: 38ms
Fast algo: 10ms
Quantity of tests is 1000000:
Slow algo: 330ms
Fast algo: 106ms
Quantity of tests is 10000000:
Slow algo: 3695ms
Fast algo: 1276ms
Quantity of tests is 100000000:
Slow algo: 36952ms
Fast algo: 8790ms
```
*Важно отметить, что де-факто измерения проводились с int64_t, так как бинарные операции и double несовместимы. Поэтому мы спомощью функции ```DoubleToInt64Bits(double value);``` 
передавали указатель на double типу int64_t. Таким образом, все последующие вычисления производились с int64_t. Таким образом условие задачи было выполнено и не возникло проблем и несовместимостью double и бинарных операций.*

Мы видим, что время работы кода с масками в среднем в 3,5 раза быстрее работы интуинивного, переборного алгоритма. 

**Подытожим измерения:**

Заметим, что $\delta = Slowalgo / Fastalgo$ наибольшая для типа double. Попробуем разобраться, почему такое может быть.
Размер int32_t и size_t - 4 байта, а double - 8. Поэтому бинарный алгоритм работает быстрее для double.

##Контролна работа 1

## Задачи

Решенията на задачите се предават по e-mail на следния адрес:

> upassistant2014@gmail.com

Време за работа: 2 часа.

Решението на всяка задача трябва да бъде под формата на файлове с окончание *.cpp* и *.h* (не целите проекти, ако използвате Visual Studio). Файловете се изпращат като attachment-и в mail-a. Освен решения на задачите самият mail трябва да съдържа име и факултен номер. Успех!

### Задача 1 ###
Дефинирайте клас Prisoner, който има за член данни:
* ```име``` - символен низ с дължина до 30 символа.
* ```идентификатор``` - Идентификаторът трябва да бъде уникален за всеки затворник.
* ```година на излизане```

дефинирайте конструктор по подразбиране, конструктор с параметри, подходящи set и get методи.

дефинирайте също:
* ```operator <``` - сравнява годините на излизане на двама затворници.
* ```Бонус* operator ++``` - в префиксен и постфиксен вариант. Увеличава годината на излизане с еденица.
* ```Бонус* operator --``` - в префиксен и постфиксен вариант. Намалява годината на излизане с еденица, ако тя е по-голям от 2015.

### Задача 2 ###
Дефинирайте клас Prison със следните член данни:

* ```масив``` - масив от обекти от клас Prisoner с произволна дължина.

Реализирайте канонично представяне (това включва конструктор по подразбиране и конструктор с параметри).
Реализирайте също следните методи:

* ```size``` - връща броя на елементите в масива.
* ```sortByYear``` - сортира масива от затворници по година на излизане.
* ```addPrisoner``` - добавя нов затворник в масива.
* ```removePrisoner``` - премахва затворник по зададен идентификатор.
* ```Бонус clear()``` - премахва от масива всички затворници с година на излизане по-малка от 2015.
* ```Бонус shrink_to_size()``` - смалява масива до неговия реален размер.

### Задача 3 *Бонус* ###

Напишете клас Automaton, който моделира краен недетерминиран автомат. Нека класът има следните член данни:

```transitions``` - квадратна матрица от символи. Ако transitions[i][j] е символ от английската азбука, то това означава, че има преход от състояние i до j със символа transitions[i][j]. Ако между две състояния няма преход, тогава на позиция transitions[i][j] стои символа '#'. (За епсилон преходи може да използвате '\0'.)
```root``` - начално състояние. 

Реализирайте канонично представяне.

Реализирайте също следните функции:
```setRoot(int newRoot)``` - за смяна на началното състояние.
```areAdjacent(int i, int j)``` - връща истина ако има директен преход от състояние i до състояние j.
```setTransition(int i, int j, char c)``` - добавя преход от състояние i до състояние j със символа c, като се премахва предишния преход от i до j, ако такъв е имало.
```removeTransition(int i, int j)``` - премахва прехода от състояние i до състояние j.
```filterAdjancentNodes(int i, char c)``` - принтира на екрана номерата на всички състояния, до които можем да стигнем от състояние i със символ c.
```shoot``` - накарайте автомата да гърми. *Hint: '\a'*.

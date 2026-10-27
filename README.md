# Домашнее задание к работе 9 (Вариант 13)

## Условие задачи
Составьте программу, которая для заданной пользователем фигуры, например прямоугольника (треугольника или другой фигуры см. индивидуальное задание работы 9) предлагает меню выбора одной из операций:
<img width="787" height="148" alt="image" src="https://github.com/user-attachments/assets/3d163119-db98-476a-b15f-661a6e8ef831" />
<img width="1022" height="792" alt="image" src="https://github.com/user-attachments/assets/5206fdf3-9109-4a38-ace9-1769b8f2bfef" />

---

## 1. Алгоритм и блок-схема

## Алгоритм решения
1. **НАЧАЛО**
2. Объявление переменных: h, b, a (размеры), symbol (символ), choice (выбор), repeat (флаг цикла).
3. Вывод "Введите символ из которого будет строиться фигура: ".
4. Ввод значения `symbol` с клавиатуры.
5. Вывод "Введите высоту (h): ".
6. Ввод значения `h` с клавиатуры.
7. Вывод "Введите ширину верхнего основания (b): ".
8. Ввод значения `b` с клавиатуры.
9. Вывод "Введите угол наклона (a): ".
10. Ввод значения `a` с клавиатуры.
11. **Цикл `do-while` (пока `repeat != 0`):**
   * Вывод текстового меню на экран.
   * Ввод значения `choice`.
   * **Оператор `switch(choice)`:**
     * **`case 1`:** Вызов `area_trapezoid(h, b, a)`. Вывод результата (площади) на экран.
     * **`case 2`:** Вызов `print_definition()`. Вывод текстового определения.
     * **`case 3`:** Вызов `draw_trapezoid('*', ...)`. Отрисовка фигуры звездочками.
     * **`case 4`:** Вызов `draw_trapezoid(symbol, ...)`. Отрисовка фигуры выбранным символом.
     * **`case 5`:** Вызов `print_parameters(...)`. Вывод всех параметров фигуры.
     * **`case 6`:** 
       * Запрос и ввод параметров второй фигуры (`h2`, `b2`, `a2`).
       * Вычисление площади первой (`area1`) и второй (`area2`) фигуры.
       * Вызов `compare_areas(area1, area2)`.
       * Вывод результата сравнения (какая фигура больше или они равны).
     * **`case 0`:** Вывод сообщения о выходе. Установка `repeat = 0`.
     * **`default`:** Вывод сообщения "Неверный выбор".
12. **КОНЕЦ**
```mermaid
flowchart TD
    Start([Начало]) --> Init[/Ввод параметров: symbol, h, b, a/]
    
    Init --> Menu[Вывод меню действий]
    Menu --> Choice[/Ввод choice/]
    
    Choice --> Switch{choice?}
    
    Switch -- 1 --> CalcArea["Вызов area_trapezoid<br>Вывод площади"]
    Switch -- 2 --> Def["Вызов print_definition<br>Вывод определения"]
    Switch -- 3 --> Draw1["Вызов draw_trapezoid<br>с символом '*'"]
    Switch -- 4 --> Draw2["Вызов draw_trapezoid<br>с символом symbol"]
    Switch -- 5 --> Params["Вызов print_parameters<br>Вывод всех данных"]
    
    Switch -- 6 --> CompareStep1[/Ввод h2, b2, a2/]
    CompareStep1 --> CompareStep2["Вызов area_trapezoid<br>для 1-й и 2-й фигуры"]
    CompareStep2 --> CompareStep3["Вызов compare_areas<br>Вывод разницы"]
    
    Switch -- 0 --> End([Конец])
    Switch -- default --> Wrong[/Вывод: Неверный выбор/]
    
    CalcArea --> Menu
    Def --> Menu
    Draw1 --> Menu
    Draw2 --> Menu
    Params --> Menu
    CompareStep3 --> Menu
    Wrong --> Menu

### Блок-схема 

<img width="1286" height="1713" alt="12 drawio" src="https://github.com/user-attachments/assets/5760f44c-3ce2-493e-9553-de6cca23f313" />

## 2. Результат работы программы

<img width="1467" height="736" alt="image" src="https://github.com/user-attachments/assets/62393875-57b5-43c1-94b6-2f5da2b40dc7" />

## 3. Информация о разработчике

### Маслов Александр Евгеньевич бИЦТ-262

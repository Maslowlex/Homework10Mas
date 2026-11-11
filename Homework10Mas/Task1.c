#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "10.h"
int main() {
    setlocale(LC_ALL, "RUS");

    float h =0, b=0, a=0;
    char symbol ="*";
    int choice;
    int repeat = 1;

    do {
        printf("\n--- МЕНЮ ---\n");
        printf("1 - Задать/изменить параметры фигуры\n"); 
        printf("2 - Рассчитать площадь\n");
        printf("3 - Вывести определение фигуры\n");
        printf("4 - Нарисовать фигуру звездочками (*)\n");
        printf("5 - Нарисовать фигуру (вашим символом)\n");
        printf("6 - Вывести параметры фигуры\n");
        printf("7 - Сравнить с другой фигурой (по площади)\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n--- Установка параметров ---\n");
            char get_symbol(char symbol);
            float get_h(float h);
            float get_b(float b);
            float get_a(float a);
            printf("Параметры успешно установлены!\n");
            break;
        case 2: {
            float s = area_trapezoid(h, b, a);
            printf("\nПлощадь трапеции: %.2f\n", s);
            break;
        }
        case 3:
            print_definition();
            break;
        case 4:
            printf("\n--- Отрисовка стандартными звездочками ---\n");
            draw_trapezoid('*', (int)h, (int)b, (int)a);
            break;
        case 5:
            draw_trapezoid(symbol, (int)h, (int)b, (int)a);
            break;
        case 6:
            print_parameters(h, b, a, symbol);
            break;
        case 7: {
            float h2, b2, a2;
            printf("\nВведите параметры второй фигуры для сравнения:\n");
            printf("Высота: "); scanf("%f", &h2);
            printf("Верхнее основание: "); scanf("%f", &b2);
            printf("Угол наклона: "); scanf("%f", &a2);

            float area1 = area_trapezoid(h, b, a);
            float area2 = area_trapezoid(h2, b2, a2);

            int diff = compare_areas(area1, area2);
            if (diff > 0) printf("Первая фигура больше на %d (кв. ед.)\n", diff);
            else if (diff < 0) printf("Вторая фигура больше на %d (кв. ед.)\n", -diff);
            else printf("Площади равны.\n");
            break;
        }
        case 0:
            printf("Выход из программы.\n");
            repeat = 0;
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (repeat != 0);

    return 0;
}

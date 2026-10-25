#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

float area_trapezoid(float h, float b, float a);
void draw_trapezoid(char symbol, int h, int b, int a);
void print_definition();
void print_parameters(float h, float b, float a, char symbol); 
int compare_areas(float area1, float area2);

int main() {
    setlocale(LC_ALL, "RUS");

    float h, b, a;
    char symbol;
    int choice;
    int repeat = 1;

    printf("--- Настройка параметров фигуры ---\n");
    printf("Введите основной символ для рисования: ");
    scanf(" %c", &symbol);
    printf("Введите высоту (h): ");
    scanf("%f", &h);
    printf("Введите ширину верхнего основания (b): ");
    scanf("%f", &b);
    printf("Введите угол наклона (a) (целое число, например 1 или 2): ");
    scanf("%f", &a);

    do {
        printf("\n--- МЕНЮ ---\n");
        printf("1 - Рассчитать площадь\n");
        printf("2 - Вывести определение фигуры\n");
        printf("3 - Нарисовать фигуру звездочками (*)\n");
        printf("4 - Нарисовать фигуру (вашим символом)\n");
        printf("5 - Вывести параметры фигуры\n"); 
        printf("6 - Сравнить с другой фигурой (по площади)\n"); 
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            float s = area_trapezoid(h, b, a);
            printf("\nПлощадь трапеции: %.2f\n", s);
            break;
        }
        case 2:
            print_definition();
            break;
        case 3:
            printf("\n--- Отрисовка стандартными звездочками ---\n");
            draw_trapezoid('*', (int)h, (int)b, (int)a);
            break;
        case 4:
            draw_trapezoid(symbol, (int)h, (int)b, (int)a);
            break;
        case 5:
            print_parameters(h, b, a, symbol);
            break;
        case 6: {
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

float area_trapezoid(float h, float b, float a) {
    float base_bottom = b + (a * h);
    return (b + base_bottom) / 2.0 * h;
}

void print_definition() {
    printf("\n--- ОПРЕДЕЛЕНИЕ ---\n");
    printf("Прямоугольная трапеция — это трапеция, у которой одна из боковых сторон перпендикулярна основаниям (образует прямой угол).\n");
}

void draw_trapezoid(char symbol, int h, int b, int a) {
    printf("\nТрапеция:\n");
    if (h <= 0 || b <= 0 || a < 0) {
        printf("Ошибка: некорректные размеры для рисования.\n");
        return;
    }
    for (int row = 0; row < h; row++) {
        int current_width = b + row * a;
        if (row == 0) {
            for (int col = 0; col < b; col++) {
                printf("%c", symbol);
            }
        }
        else {
            printf("%c", symbol);
            if (row == h - 1) {
                for (int col = 1; col < current_width; col++) {
                    printf("%c", symbol);
                }
            }
            else {
                for (int col = 1; col < current_width - 1; col++) {
                    printf(" ");
                }
                printf("%c", symbol);
            }
        }
        printf("\n");
    }
}

void print_parameters(float h, float b, float a, char symbol) {
    printf("\n--- ПАРАМЕТРЫ ФИГУРЫ ---\n");
    printf("Тип фигуры: Прямоугольная трапеция\n");
    printf("Символ отрисовки: '%c'\n", symbol);
    printf("Высота (h): %.2f\n", h);
    printf("Верхнее основание (b): %.2f\n", b);
    printf("Смещение/угол наклона (a): %.2f\n", a);
    printf("Вычисленное нижнее основание: %.2f\n", b + (a * h));
    printf("Площадь: %.2f\n", area_trapezoid(h, b, a));
}

int compare_areas(float area1, float area2) {
    return (int)(area1 - area2);
}
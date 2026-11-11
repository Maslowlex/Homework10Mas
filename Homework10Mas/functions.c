char get_symbol(char symbol) {
    printf("Введите основной символ для рисования: ");
    scanf(" %c", &symbol);
    return symbol;
}
float get_h(float h) {
    printf("Введите высоту (h): ");
    scanf("%f", &h);
    return h;
}
float get_b(float b) {
    printf("Введите ширину верхнего основания (b): ");
    scanf("%f", &b);
    return b;
}
float get_a(float a) {
    printf("Введите угол наклона (a) (целое число, например 1 или 2): ");
    scanf("%f", &a);
    return a;
}
float area_trapezoid(float h, float b, float a) {
    float base_bottom = b + (a * h);
    return (b + base_bottom) / 2.0 * h;
}

void print_definition() {
    printf("\n ОПРЕДЕЛЕНИЕ \n");
    printf("Прямоугольная трапеция — это трапеция, у которой одна из боковых сторон перпендикулярна основаниям (образует прямой угол).\n");
}

int draw_trapezoid(char symbol, int h, int b, int a) {
    int count = 0;
    printf("\nТрапеция:\n");
    if (h <= 0 || b <= 0 || a < 0) {
        printf("Ошибка: некорректные размеры для рисования.\n");
        return 0;
    }
    for (int row = 0; row < h; row++) {
        int current_width = b + row * a;
        if (row == 0) {
            for (int col = 0; col < b; col++) {
                printf("%c", symbol);
                count++;
            }
        }
        else {
            printf("%c", symbol);
            count++;
            if (row == h - 1) {
                for (int col = 1; col < current_width; col++) {
                    printf("%c", symbol);
                    count++;
                }
            }
            else {
                for (int col = 1; col < current_width - 1; col++) {
                    printf(" ");
                }
                printf("%c", symbol);
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}
int count_trapezoid_symbols(int h, int b, int a) {
    if (h <= 0 || b <= 0 || a < 0) return 0;
    int count = 0;
    for (int row = 0; row < h; row++) {
        int current_width = b + row * a;
        if (row == 0) {
            count += b;
        }
        else if (row == h - 1) {
            count += current_width;
        }
        else {
            count += 2;
        }
    }
    return count;
}
void print_parameters(float h, float b, float a, char symbol) {
    printf("\n--- ПАРАМЕТРЫ ФИГУРЫ ---\n");
    printf("Тип фигуры: Прямоугольная трапеция\n");
    printf("Символ отрисовки: '%c'\n", symbol);
    printf("Высота (h): %.2f\n", h);
    printf("Верхнее основание (b): %.2f\n", b);
    printf("Смещение/угол наклона (a): %.2f\n", a);
    printf("Количество символов %d\n", count_trapezoid_symbols(h, b, a));
    printf("Площадь: %.2f\n", area_trapezoid(h, b, a));
}

int compare_areas(float area1, float area2) {
    return (int)(area1 - area2);
}
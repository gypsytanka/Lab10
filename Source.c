#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>

float area_trapezoid(float a, float b, float h) {
    return (a + b) * h / 2.0;
}

void name() {
    printf("Равнобедренная трапеция - четырехугольник с двумя параллельными сторонами\n");
    printf("и равными боковыми сторонами\n");
}

void draw_trapezoid(int a, int b, int h, char symbol) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("\nРисунок равнобедренной трапеции:\n");

    // смещение для каждого уровня
    int diff = b - a;

    for (int i = 0; i < h; i++) {
        int spaces = (diff * (h - i - 1)) / h;
        int width = b - 2 * spaces;

        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        for (int j = 0; j < width; j++) {
            printf("%c", symbol);
        }

        printf("\n");
    }
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    float a, b, h;
    int choice;
    char symbol = '*';

    printf("Введите длину большего основания трапеции: ");
    scanf("%f", &b);
    printf("Введите длину меньшего основания трапеции: ");
    scanf("%f", &a);
    printf("Введите высоту трапеции: ");
    scanf("%f", &h);

    do {
        printf("\nМЕНЮ\n");
        printf("1. Рассчитать площадь трапеции\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Площадь трапеции: %.2f\n", area_trapezoid(a, b, h));
            break;

        case 2:
            name();
            break;

        case 3:
            draw_trapezoid((int)a, (int)b, (int)h, symbol);
            break;

        case 0:
            break;

        default:
            printf("ошибка!\n");
        }

    } while (choice != 0);

    return 0;
}
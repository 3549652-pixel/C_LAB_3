
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
 * Лабораторна робота №3
 * Розгалужувані алгоритми та умовні конструкції
 * K = 3
 * Варіанти: 11, 18, 37, 74, 22, 113, 14, 70, 61, 106
 */

static void print_number(double value)
{
    char text[128];
    size_t n;
    char *dot;

    if (!isfinite(value)) {
        printf("невизначене число");
        return;
    }

    if (fabs(value) < 0.00005) {
        value = 0.0;
    }

    snprintf(text, sizeof(text), "%.4f", value);
    dot = strchr(text, '.');
    n = strlen(text);

    if (dot != NULL) {
        while (n > (size_t)(dot - text) + 3 &&
               text[n - 1] == '0') {
            text[--n] = '\0';
        }
    }

    printf("%s", text);
}

static double middle(double a, double b, double c)
{
    if ((a >= b && a <= c) ||
        (a <= b && a >= c)) {
        return a;
    }

    if ((b >= a && b <= c) ||
        (b <= a && b >= c)) {
        return b;
    }

    return c;
}

int main(void)
{
    int n, first, last, a_int;
    int a3, a2, a1, b2, b1;
    int num1, num2, total, selected, digit_sum;

    double a, b, c, d, e, f;
    double temp, s, area;
    double h, qa, qb, qc, disc;
    double div, base, rad, theta;

    const double EPS = 1e-12;

    /* Завдання 1, варіант 11 */
    /* Порівняння цифр двозначного числа */

    printf("\nЗавдання 1 (варіант 11). Введіть двозначне число: ");

    if (scanf("%d", &n) != 1) return 1;

    if (n < 10 || n > 99) {
        puts("Результат: потрібне додатне двозначне число.");
    } else {
        first = n / 10;
        last = n % 10;

        if (first > last) {
            puts("Результат: перша цифра більша за другу.");
        } else if (first < last) {
            puts("Результат: друга цифра більша за першу.");
        } else {
            puts("Результат: цифри однакові.");
        }

        printf("Цифри однакові: %s.\n",
               first == last ? "так" : "ні");
    }

    /* Завдання 2, варіант 18 */
    /* Квадрат числа та сума кубів його цифр */

    printf("\nЗавдання 2 (варіант 18). Введіть тризначне число: ");

    if (scanf("%d", &n) != 1) return 1;

    if (n < 100 || n > 999) {
        puts("Результат: потрібне додатне тризначне число.");
    } else {
        int hundreds = n / 100;
        int tens = (n / 10) % 10;
        int units = n % 10;

        int cube_sum = hundreds * hundreds * hundreds
                     + tens * tens * tens
                     + units * units * units;

        printf("Результат: %d^2 = %d; сума кубів цифр = %d. Рівні: %s.\n",
               n, n * n, cube_sum,
               n * n == cube_sum ? "так" : "ні");
    }

    /* Завдання 3, варіант 37 */
    /* У a більше значення, у b менше */

    printf("\nЗавдання 3 (варіант 37). Введіть a, b: ");

    if (scanf("%lf %lf", &a, &b) != 2) return 1;
    if (!isfinite(a) || !isfinite(b)) return 1;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    printf("Результат: a = ");
    print_number(a);
    printf(", b = ");
    print_number(b);
    putchar('\n');

    /* Завдання 4, варіант 74 */
    /* Оплата покупки в книгарні */

    printf("\nЗавдання 4 (варіант 74). Введіть вартість книжок та внесену суму: ");

    if (scanf("%lf %lf", &a, &b) != 2) return 1;

    if (!isfinite(a) || !isfinite(b) || a < 0 || b < 0) {
        puts("Результат: вартість і внесена сума мають бути невід'ємними числами.");
    } else if (fabs(a - b) < EPS) {
        puts("Результат: дякую, здача не потрібна.");
    } else if (b > a) {
        printf("Результат: візьміть здачу ");
        print_number(b - a);
        puts(" грн.");
    } else {
        printf("Результат: недостатньо грошей, бракує ");
        print_number(a - b);
        puts(" грн.");
    }

    /* Завдання 5, варіант 22 */
    /* Цифри суми або різниці двох чисел */

    printf("\nЗавдання 5 (варіант 22). Введіть цифри a3 a2 a1 b2 b1: ");

    if (scanf("%d %d %d %d %d",
              &a3, &a2, &a1, &b2, &b1) != 5) return 1;

    if (a3 < 1 || a3 > 9 ||
        a2 < 0 || a2 > 9 ||
        a1 < 0 || a1 > 9 ||
        b2 < 1 || b2 > 9 ||
        b1 < 0 || b1 > 9) {
        puts("Результат: некоректні цифри тризначного або двозначного числа.");
    } else {
        num1 = a3 * 100 + a2 * 10 + a1;
        num2 = b2 * 10 + b1;
        total = num1 + num2;

        if (total % 2 == 0) {
            selected = total;
            printf("Результат: сума %d + %d = %d парна. Цифри: ",
                   num1, num2, selected);
        } else {
            selected = num1 - num2;
            printf("Результат: сума %d непарна; різниця %d - %d = %d. Цифри: ",
                   total, num1, num2, selected);
        }

        if (selected >= 1000) {
            printf("%d ", selected / 1000);
        }
        if (selected >= 100) {
            printf("%d ", (selected / 100) % 10);
        }
        if (selected >= 10) {
            printf("%d ", (selected / 10) % 10);
        }

        printf("%d\n", selected % 10);
    }

    /* Завдання 6, варіант 113 */
    /* Середнє арифметичне середніх чисел двох трійок */

    printf("\nЗавдання 6 (варіант 113). Введіть першу трійку a b c: ");

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    printf("Введіть другу трійку d e f: ");

    if (scanf("%lf %lf %lf", &d, &e, &f) != 3) return 1;

    if (!isfinite(a) || !isfinite(b) || !isfinite(c) ||
        !isfinite(d) || !isfinite(e) || !isfinite(f) ||
        a == b || a == c || b == c ||
        d == e || d == f || e == f) {
        puts("Результат: у кожній трійці мають бути три різні скінченні числа.");
    } else {
        double m1 = middle(a, b, c);
        double m2 = middle(d, e, f);

        printf("Результат: середні числа ");
        print_number(m1);
        printf(" і ");
        print_number(m2);
        printf("; їхнє середнє арифметичне = ");
        print_number(m1 / 2.0 + m2 / 2.0);
        putchar('\n');
    }

    /* Завдання 7, варіант 14 */
    /* Кратність суми цифр числам 3 та a */

    printf("\nЗавдання 7 (варіант 14). Введіть двозначне число та ціле a: ");

    if (scanf("%d %d", &n, &a_int) != 2) return 1;

    if (n < 10 || n > 99) {
        puts("Результат: потрібне додатне двозначне число.");
    } else {
        digit_sum = n / 10 + n % 10;

        printf("Результат: сума цифр = %d; кратна 3: %s; ",
               digit_sum,
               digit_sum % 3 == 0 ? "так" : "ні");

        if (a_int == 0) {
            puts("кратність a не визначена (a = 0).");
        } else {
            printf("кратна a (%d): %s.\n",
                   a_int,
                   digit_sum % a_int == 0 ? "так" : "ні");
        }
    }

    /* Завдання 8, варіант 70 */
    /* Чи є додатною сума хоча б двох чисел */

    printf("\nЗавдання 8 (варіант 70). Введіть три числа a b c: ");

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;
    if (!isfinite(a) || !isfinite(b) || !isfinite(c)) return 1;

    printf("Результат: існує пара з додатною сумою: %s.\n",
           (a + b > 0 || a + c > 0 || b + c > 0)
           ? "так" : "ні");

    /* Завдання 9, варіант 61 */
    /* Існування трикутника та обчислення площі */

    printf("\nЗавдання 9 (варіант 61). Введіть сторони a b c: ");

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    if (!isfinite(a) || !isfinite(b) || !isfinite(c) ||
        a <= 0 || b <= 0 || c <= 0 ||
        a + b <= c || a + c <= b || b + c <= a) {
        puts("Результат: трикутник не існує.");
    } else {
        s = (a + b + c) / 2.0;
        area = sqrt(s * (s - a) * (s - b) * (s - c));

        printf("Результат: трикутник існує; площа = ");
        print_number(area);
        putchar('\n');
    }

    /* Завдання 10, варіант 106 */
    /* Квадратне рівняння a*x^2 + b*x + c = 0 */

    printf("\nЗавдання 10 (варіант 106). Введіть h: ");

    if (scanf("%lf", &h) != 1 || !isfinite(h)) return 1;

    theta = h * h;
    base = 1.0 - sin(4.0 * h) * cos(theta + 18.0);

    if (!isfinite(base) || fabs(base) < EPS) {
        puts("Результат: неможливо обчислити a (нульовий знаменник).");
    } else {
        rad = (fabs(sin(8.0 * h)) + 17.0)
              / (base * base);

        qa = sqrt(rad);
        div = cos(qa * theta);

        if (!isfinite(qa) ||
            !isfinite(div) ||
            fabs(div) < EPS) {
            puts("Результат: неможливо обчислити b (тангенс не визначений).");
        } else {
            qb = 1.0 - sqrt(
                3.0 / (3.0 +
                fabs(tan(qa * theta) - sin(qa * h)))
            );

            qc = qa * theta * sin(qb * h)
                 + qb * h * theta * cos(qa * h);

            disc = qb * qb - 4.0 * qa * qc;

            if (!isfinite(qb) ||
                !isfinite(qc) ||
                !isfinite(disc)) {
                puts("Результат: числове переповнення під час обчислень.");
            } else {
                printf("Коефіцієнти: a = ");
                print_number(qa);

                printf(", b = ");
                print_number(qb);

                printf(", c = ");
                print_number(qc);

                printf("; дискримінант D = ");
                print_number(disc);
                putchar('\n');

                if (disc < 0.0) {
                    puts("Результат: дійсних коренів немає.");
                } else if (disc == 0.0) {
                    printf("Результат: один дійсний корінь x = ");
                    print_number(-qb / (2.0 * qa));
                    putchar('\n');
                } else {
                    printf("Результат: два дійсні корені x1 = ");
                    print_number((-qb + sqrt(disc)) / (2.0 * qa));

                    printf(", x2 = ");
                    print_number((-qb - sqrt(disc)) / (2.0 * qa));
                    putchar('\n');
                }
            }
        }
    }

    return 0;
}

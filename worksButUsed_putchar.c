#include <stdarg.h>
#include <string.h>
#include <math.h>

void my_printf(const char *format, ...)
{
    va_list args; // naming the list
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd')
            {
                int num = va_arg(args, int);

                if (num < 0)
                {
                    putchar('-');
                    num = num * -1;
                }
                else if (num == 0)
                {
                    putchar('0');
                }

                char buff[10]; // taking the max size of integer
                int i = 0;

                while (num != 0)
                {
                    buff[i++] = (num % 10) + '0'; // as the ASCII value of '0' is 48, and hence every number (0-9) has some ASCII value
                    num = num / 10;
                }
                while (i > 0)
                {
                    putchar(buff[--i]);
                }
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);

                while (*str != '\0')
                {
                    putchar(*str);
                    str++;
                }
            }
            else if (*format == 'c')
            {
                char c = va_arg(args, int);

                putchar(c);
            }
            else if (*format == 'f')
            {
                double num = va_arg(args, double);
                if (num < 0)
                {
                    putchar('-');
                    num = num * -1;
                }

                int intPart = (int)num;
                int decPart = (int)((num - intPart) * 1000000); // taking max precision in mind
                int integer[15], decimal[15];
                int i = 0;
                while (intPart != 0)
                {
                    integer[i++] = (intPart % 10) + '0';
                    intPart = intPart / 10;
                }
                while (i > 0)
                {
                    putchar(integer[--i]);
                }

                putchar('.');

                while (decPart != 0)
                {
                    decimal[i++] = (decPart % 10) + '0';
                    decPart = decPart / 10;
                }
                while (i > 0)
                {
                    putchar(decimal[--i]);
                }
            }
            else if (*format == '%')
            {
                putchar('%');
            }
            else if (*format == '.')
            {
                format++;                // here the pointer points at the precision number
                int prec = *format - 48; // as the ASCII value of '0' is 48;
                format++;                // now the pointer points at 'f'
                double num = va_arg(args, double);

                int intPart = (int)num;
                int decPart = (int)((num - intPart) * pow(10, prec));
                int integer[15];
                int decimal[15];
                int i = 0;
                while (intPart != 0)
                {
                    integer[i++] = (intPart % 10) + '0';
                    intPart = intPart / 10;
                }
                while (i > 0)
                {
                    putchar(integer[--i]);
                }

                putchar('.');

                while (decPart != 0)
                {
                    decimal[i++] = (decPart % 10) + '0';
                    decPart = decPart / 10;
                }
                while (i > 0)
                {
                    --i;
                    putchar(decimal[i]);
                }
            }
            else if (*format == 'l')
            {
                format++;
                if (*format == 'd')
                {
                    long num = va_arg(args, long);

                    if (num < 0)
                    {
                        putchar('-');
                        num = num * -1;
                    }
                    else if (num == 0)
                    {
                        putchar('0');
                    }

                    char buff[19];
                    int i = 0;

                    while (num != 0)
                    {
                        buff[i] = (num % 10) + '0'; // as the ASCII value of '0' is 48, and hence every number (0-9) has some ASCII value
                        num = num / 10;
                        i++;
                    }
                    while (i > 0)
                    {
                        --i;
                        putchar(buff[i]);
                    }
                }
            }
        }
        else
        {
            putchar(*format);
        }
        format++;
    }
    va_end(args);
}

int main()
{
    my_printf("Hello, world!\n");
    my_printf("The value of x is %d\n", 42);
    my_printf("My name is %s\n", "Alice");
    my_printf("The sum of %d and %d is %d\n", 10, 20, 10 + 20);
    my_printf("The value of pi is %.2f\n", 3.14159);
    my_printf("%s bought %d apples for $%.2f each\n", "Bob", 5, 1.25);
    my_printf("Escape sequence: %% \n");
    my_printf("");
    my_printf("This is a static message\n");
    my_printf("Large number: %ld\n", 123456789012345);

    return 0;
}

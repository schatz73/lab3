#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <ctype.h>


#include "headers.h"

int main() {

    size_t current_memory = START_MEMORY;
    char *seq = malloc(current_memory);
    char *tmp;
    size_t len=0;
    char *piece;
    double number=0.0;
    char extra;
    int ok=0;
    int index=0;

    
    printf("Введите последовательность чисел через пробел!\n");
    while (1) {
        ok=1;
        fgets(seq, START_MEMORY, stdin);

        while(strchr(seq, '\n')==NULL) {
            len = strlen(seq);
            current_memory *=2;
            tmp = realloc(seq, current_memory);

            fgets(tmp + len, (int)(current_memory - len), stdin);

            seq = tmp;

        }

        len = strlen(seq);
        *(seq + len-1) = '\0';
    
        piece = strtok(seq, " ");

        if (piece == NULL) {
            printf("Вы не ввели ни одного числа. Попробуйте снова.\n");
            continue;
        }

        while (piece !=NULL) {
  
            if ((sscanf(piece, "%lf%c", &number, &extra))!=1) {
                printf("Ошибка: %s не число.\n", piece);
                printf("Ввод последовательности чисел через пробел заново:\n");
                ok=0;
                break;
            }

            for (int i=0; *(piece + i)!='\0'; i++) {
                index = i;
            }

            if (piece + index + 1 == seq + len - 1) {
                break;
            }
            
            piece = piece + index+2;
            piece = strtok(piece, " ");
            index=0;

        }

        if (ok!=0) {
            break;
        }

    }


    for (size_t i = 0; i + 1 < len; i++) {
        if (*(seq + i) == '\0') {
            *(seq + i) = ' ';
        }
    }


    printf("Текст: %s\n", seq);

    free(seq);

    return 0;

}


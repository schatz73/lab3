#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#include "headers.h"
#include "push_back.c"
#include "digit.c"
#include "clear_deq.c"



int main() {

    struct Deque d = {0};
    struct Deque *deque = &d;

    struct Node *start;

    int c=0;
    char *piece;

    char *temp;
    int piece_capacity=0;
    int len_piece=0;
    int v_f=0;
    int ok=0;
    

    while (1) {
        ok=0;
        piece_capacity = START_MEMORY;


        printf("Введите последовательность чисел через пробел!\n");
        printf("Числа должны быть от %d до %d\n", INT_MIN, INT_MAX);


        while (2) {

            piece = malloc(START_MEMORY);
      
            if (piece == NULL) {
                printf("Не удалось выделить память!\n");
                return 1;
            }

            while ((c=getchar())!= ' ' && c!= EOF && c!='\n') {

                if (len_piece== piece_capacity-1) {

                    temp = malloc(piece_capacity*2);
                    
                    if (temp == NULL) {
                        printf("Не удалось выделить память!\n");
                        return 1;
                    }

                    piece_capacity *=2;

                    for (int i=0; i<len_piece; i++) {
                        *(temp + i) = *(piece + i);
                    }

                    free(piece);
                    piece = temp;

                }

                *(piece + len_piece) = (char)c;
                len_piece++;
                *(piece + len_piece) = '\0';

            }

            if (c==EOF) {
                printf("\nПользователь ввел EOF! Программа завершена\n");
                return 1;
            }

            // printf("кусочек: %s\n", piece);
            // printf("длина: %d\n", len_piece);

            if (len_piece==0 && c!='\n') {
                scanf("%*[^\n]%*c");
                ok=1;

                free(piece);

                clear_deq(deque);

                printf("Ошибка! space - не может быть числом!\n");
                break;
            }

            if ((v_f = digit(piece, len_piece-1))==0) {
                if (push_back(deque, strtod(piece, NULL)) == 1) {
                    printf("Ошибка выделения памяти для узла!");
                    free(piece);
                    clear_deq(deque);
                    return 1;
                }

            } else {

                if (c != '\n') {
                    // printf("\nочистил!\n");
                    scanf("%*[^\n]%*c");
                }

                if (v_f==1) {
                    printf("Ошибка! %s - не число! Попробуйте заново!\n", piece);

                } else {
                    printf("Ошибка! Введенное число %s не лежит в диапозоне от %d до %d\n", piece, INT_MIN, INT_MAX);

                }

                clear_deq(deque);
                ok=1;
            }

            free(piece);
            piece_capacity = START_MEMORY;
            len_piece=0;

            if (c=='\n' || ok==1) {
                break;
            }
        }
        
        if (ok==0) {
            break;
        }

    }

    printf("\nДЕК:\n");
    
    start = deque->front;

    while (start !=NULL) {

        if (start->next == NULL) {
            printf("%g\n", start->value);
        } else {
            printf("%g ", start->value);
        }

        start = start->next;

    }

    // printf("\nОТСОРТИРОВАННЫЙ ДЕК:\n");

    

    clear_deq(deque);
    return 0;

}


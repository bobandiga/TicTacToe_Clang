//
//  main.c
//  TicTacToe
//
//  Created by Максим Шаптала on 22.02.2021.
//

#include <stdio.h>

#define rows 3
#define columns 3
#define space 'N'

typedef struct {
    int x;
    int y;
    char value;
} Toe;

typedef struct  {
    Toe arr[rows][columns];
} Field;

typedef enum {
    win = 1,
    draw = 0,
    lose = -1,
    undefine = -9
} Result ;

typedef enum {
    comp = 0,
    user = 1,
} Step;

void fillArray(Field *f);
Result check(Field f, Step s);
void addToe(Field *f, Toe t);
void printGUI(Field f);

int main() {
    
    Result r = undefine;
    Step s = user;
    Field f;
    
    fillArray(&f);
    
    while (r == undefine) {
        
        printGUI(f);
        
        Toe t;
        
        printf("print value: ");
        scanf("%c", &t.value);
        
        printf("select row: ");
        scanf("%d", &t.x);
        
        printf("select column: ");
        scanf("%d", &t.y);
        
        
        printf("\n");
        
        addToe(&f, t);
        r = check(f, s);
        
        s = s == user ? comp : user;
    }
    
    printf("The end. %d\n", r);
    
    return 0;
}

void printGUI(Field f) {
    printf("Matrix:");
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("%5c %10c %10c", f.arr[i][0].value, f.arr[i][1].value, f.arr[i][2].value);
        printf("\n");
    }
    printf("\n");
}

void fillArray(Field *f) {
    
    for (int i = 0; i < rows ; i++) {
        for (int j = 0; j < columns ; j++) {
            Toe t;
            t.x = i;
            t.y = j;
            t.value = space;
            f->arr[i][j] = t;
        }
    }
    
    
}

void addToe(Field *f, Toe t) {
    f->arr[t.x][t.y] = t;
    return;
}

Result check(Field f, Step s) {
    
    // Проверка закончились ли клетки
    for (int i = 0; i < rows ; i++) {
        for (int j = 0; j < columns ; j++) {
            if (f.arr[i][j].value == space) {
                return undefine;
            }
        }
    }
    
    char *p;
    
    // проверка по строкам
    for (int i = 0; i < rows; i++) {
        p = &f.arr[i][0].value;
        
        if (*p == *(p+1) && *p == *(p+2) ) {
            return s == comp ? lose : win;
        }
        
    }
    
    // проверка по столбам
    for (int i = 0; i < columns; i++) {
        p = &f.arr[0][i].value;
        
        if (*p == *(p+1) && *p == *(p+2) ) {
            return s == comp ? lose : win;
        }
        
    }
    
    // проверка по диагоналям
    if (f.arr[0][0].value == f.arr[1][1].value == f.arr[2][2].value) {
        return s == comp ? lose : win;
    }
    
    if (f.arr[0][2].value == f.arr[1][1].value == f.arr[2][0].value) {
        return s == comp ? lose : win;
    }
    
    return draw;
}



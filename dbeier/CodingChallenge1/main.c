#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int random_number(int max){
    return rand()%max;
}

void shuffle(int *data, int length){
    for(int i = 0; i < length; i++){
        int rand = random_number(length);
        int buf = data[rand];
        data[rand] = data[i];
        data[i] = buf;
    }
}

int *create(int max){
    int *array = malloc(max * sizeof(int));
    for(int i = 1; i <= max; i++){
        array[i-1] =  i;
    }
    return array;
}

void print_array(int *data, int max)
{
    for(int i = 0; i < max; i++){
        printf("%d\n", data[i]);
    }
    printf("\n");
}
/**
 * @brief sort
 * @param data
 * @param max
 *
 * Braucht maximal 2*n - 1 schleifendurchläufe.
 * Worst Case Szenarion für i=0 ist das bevor
 * data[0] == 1 n Schritte gebraucht werden.
 * Bei jedem Schritt wird mindestens 1 Element an die richtige
 * Stelle geschoben, wenn also n Schritte gebraucht werden, ist
 * es schon sortiert und die Schleife läuft noch n-1 mal weiter.
 */

void sort(int *data, int max){
    for(int i = 0;i<max;i++){
        int current = data[i];
        if(current == i+1)
            continue;
        int newpos = current - 1;
        int buff = data[newpos];
        data[newpos] = current;
        data[i] = buff;
        i--;
    }
}

int main()
{
    srand (time(NULL));
    const long max = 1000000;
    printf("%s","Hello world!\n");
    int *array = create(max);
    shuffle(array, max);
    //print_array(array,max);
    sort(array,max);
    //print_array(array,max);
    //array = create(max);
    return 0;
}

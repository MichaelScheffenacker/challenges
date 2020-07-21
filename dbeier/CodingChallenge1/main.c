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
int main()
{
    srand (time(NULL));
    const long max = 100;
    const long min = 0;
    printf("%s","Hello world!\n");
    int *array = create(max);
    shuffle(array, max);
    for(int i = 0; i < max; i++){
        printf("%d\n", array[i]);
    }
    array = create(max);
    return 0;
}

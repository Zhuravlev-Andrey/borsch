#include <stdio.h>
#include <unistd.h> // Для использования функции sleep
#include <inttypes.h> // Для использования int8_t

// Функция добавления воды
void addWater(){
    int pan = 0;
    int water = 0;

    printf("Сколько миллилитров воды добавить в кастрюлю?\n");
    scanf("%d", &water);

    if (water == 1000) {
        pan = water;
        printf("В кастрюле %d мл воды\n", pan);
    } else if (water < 1000) {
        printf("Не хватает %d мл воды\n", 1000 - water);
    } else {
        printf("Нужно меньше воды!\n");
    }
}

// Функция добавления ингредиентов
void addIngredients(){
    char beef[] = "говядина";
    char potato[] = "картофель";
    char beet[] = "свёкла";

    printf("В кастрюлю с водой положили: %s, %s, %s\n", beef, potato, beet);
}

// Функция смешивания ингредиентов 1
void mix_1(){
    int i = 0;
    while(i < 3){
        printf("Помешать\n");
        i++;
    }
}

// Функция жарки лука и моркови
void fry(int *onion, int *carrot) {
    int plate; // Новая тарелка

    // Перекладываем лук в новую тарелку
    plate = *onion;

    // Кладем морковь на тарелку, где был лук
    *onion = *carrot;

    // Кладем лук на тарелку, где была морковь
    *carrot = plate;
}

// Функция смешивания ингредиентов 2
void mix_2(){
    for(int i = 0; i < 3; i++){
        printf("Помешать\n");
    }
}

// Посолить
void addSalt(){
    int8_t salt;

    salt = 99;
    printf("Посолить %d крупинок\n", salt); // Посолили

    salt *= 2;
    printf("Посолить %d крупинок\n", salt); // Посолили дважды
}

// Функция смешивания ингредиентов 3
void mix_3(int n) {
    if (0 >= n) {
        return; // Базовый случай: когда n становится не положительным, выходим из рекурсии
    }

    printf("Помешать\n"); // Печатаем "Помешать"

    mix_3(n - 1); // Рекурсивный вызов функции mix с аргументом n-1
}

int main() {
    addWater();
    sleep(2); // Задержка в 2 секунды

    addIngredients();
    sleep(2); // Задержка в 2 секунды

    mix_1();
    sleep(2); // Задержка в 2 секунды

    // Жарим лук и морковь
    int onion = 1; // Тарелка с луком
    int carrot = 2; // Тарелка с морковью
    printf("До жарки:\n");
    printf("Лук в тарелке № %d \n", onion);
    printf("Морковь в тарелке № %d \n", carrot);
    sleep(2); // Задержка в 2 секунды

    fry(&onion, &carrot); // Пожарили лук
    printf("После жарки:\n");
    printf("Лук в тарелке № %d \n", onion);
    printf("Морковь в тарелке № %d \n", carrot);
    sleep(2); // Задержка в 2 секунды

    mix_2();
    sleep(2); // Задержка в 2 секунды

    addSalt();
    sleep(2); // Задержка в 2 секунды

    mix_3(3);
    sleep(5); // Задержка в 5 секунд

    printf("Борщ готов!\n");

    return 0;
}



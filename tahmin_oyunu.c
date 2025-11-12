#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int number, guess, attempts;
    int score;
    char choice;

    srand(time(NULL)); // Rastgele sayý üretmek için

    do {
        number = rand() % 101; // 0-100 arasýnda sayý
        attempts = 0;
        score = 10;

        printf("\n0-100 arasinda bir sayi tuttum.\n");

        while (attempts < 3) {
            printf("Tahmininizi girin: ");
            scanf("%d", &guess);
            attempts++;

            if (guess == number) {
                if (attempts == 1) {
                    printf("Tebrikler! Ýlk denemede bildiniz. 10 tam puan!\n");
                } else {
                    printf("Tebrikler! %d. denemede bildiniz. Puaniniz: %d\n", attempts, score);
                }
                break;
            } else {
                if (guess < number) {
                    printf("Daha buyuk bir sayi girin.\n");
                } else {
                    printf("Daha kucuk bir sayi girin.\n");
                }

                // Puan düþürme kurallarý
                if (attempts == 1) score -= 3;
                else if (attempts == 2) score -= 4;
                else if (attempts == 3) score -= 3;

                if (attempts == 3) {
                    printf("Tahmin hakkiniz bitti. Dogru sayi: %d\n", number);
                    printf("Puaniniz: %d\n", score);
                }
            }
        }

        printf("\nOyuna devam etmek icin herhangi bir tusa, cikmak icin 'E/e' tusuna basiniz: ");
        scanf(" %c", &choice);

    } while (tolower(choice) != 'e');

    printf("Oyun bitti.\n");
    return 0;
}

#include <stdio.h>

const int values[] = {8, 7, 6, 3, 2};

void find_combos(int target, int partial_combo[], int partialsum, int start){
    if (partialsum == target){
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", partial_combo[0], partial_combo[1], partial_combo[2], partial_combo[3], partial_combo[4]);
        return;
    }
    else if (partialsum > target){
        return;
    }

    for (int i = start; i < 5; i++){
        int newval = partial_combo[i] + 1;
        int newsum = partialsum + values[i];
        int newcombo[5];

        //creating new combo list
        for (int j = 0; j < 5; j++){
            if (j == i){
                newcombo[j] = newval;
            }
            else{
                newcombo[j] = partial_combo[j];
            }
        }

        find_combos(target, newcombo, newsum, i);
    }
}

int main(){
    while (1){
        int partialsum[] = {0,0,0,0,0};
        int score;
        printf("Enter a score (a score of 0 or 1 will exit the program): ");
        scanf("%d", &score);
        if (score <= 1){
            return 0;
        }
        printf("\n");
        find_combos(score, partialsum, 0, 0);
    }
    return 0;
}
#include <stdio.h>

void bubble_sort(int indices[], float list_comp[]){
    for (int i = 0; i<12; i++){
        for (int j = i; j < 12 - i - 1; j++){
            if (list_comp[j] > list_comp[j+1]){
                float temp = list_comp[j];
                list_comp[j] = list_comp[j+1];
                list_comp[j+1] = temp;
                int tempf = indices[j];
                indices[j] = indices[j+1];
                indices[j+1] = tempf;
            }
        }
    }
}

char months[12][30] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int main(){
    printf("Please enter filename: ");
    char filename[20];
    float temp;
    float nums[12];
    scanf("%s", filename);

    FILE *in = fopen(filename, "r");
    if (in == NULL){
        printf("File doesn't exist");
    }
    else{
        for (int i = 0; i < 12; i ++){
            fscanf(in, "%f", &temp);
            nums[i] = temp;
        }
    }

    int minIndex = 0, maxIndex = 0;
    float min = 10000000.0, max = 0.0;
    for (int i = 0; i < 12; i++){
        if (nums[i] < min){
            minIndex = i;
            min = nums[i];
        }
        if (nums[i] > max){
            maxIndex = i;
            max = nums[i];
        }
    }

    printf("\nMonthly Sales Report for 2022\n");
    printf("%-15s\tSales\n", "Month");
    for (int i = 0; i < 12; i++){
        printf("%-15s\t$%-.2f\n", months[i], nums[i]);
    }

    printf("\nSales Summary: \n");
    printf("Minimum Sales:\t$%-.2f (%s)\n", min, months[minIndex]);
    printf("Maximum Sales:\t$%-.2f (%s)\n", max, months[maxIndex]);

    printf("\nSales Summary: \n");
    for (int i = 0; i <= 6; i++){
        float movingAvg = 0.0;
        for (int j = i; j < i+6; j++){
            movingAvg += nums[j];
        }
        movingAvg /= 6;
        printf("%-15s\t- %-15s$%-.2f\n", months[i], months[i+5], movingAvg);
    }

    int indices[12];
    for (int i = 0; i < 12; i++){
        indices[i] = i;
    }

    bubble_sort(indices, nums);

    printf("\nSales Report (Highest to Lowest)\n");
    printf("%-15s\tSales\n", "Month");
    for (int i = 11; i >= 0; i--){
        printf("%-15s\t$%-.2f\n", months[indices[i]], nums[indices[i]]);
    }
    return 0;
}
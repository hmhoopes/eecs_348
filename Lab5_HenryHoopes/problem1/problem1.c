#include <stdio.h>

void bubble_sort(int indices[], float list_comp[]){
    for (int i = 0; i<12; i++){
        for (int j = 0; j < 12 - i - 1; j++){
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
    printf("Please enter sales for each month, starting from January: \n");
    float temp;
    float nums[12];
    for (int i = 0; i < 12; i++){
        scanf("%f", &nums[i]);
    }

    int minIndex = 0, maxIndex = 0;
    float min = 10000000.0, max = 0.0;
    float average = 0.0;
    for (int i = 0; i < 12; i++){
        average += nums[i];
        if (nums[i] < min){
            minIndex = i;
            min = nums[i];
        }
        if (nums[i] > max){
            maxIndex = i;
            max = nums[i];
        }
    }
    average /= 12;

    printf("\nMonthly Sales Report for 2022\n");
    printf("%-15s\tSales\n", "Month");
    for (int i = 0; i < 12; i++){
        printf("%-15s\t$%-.2f\n", months[i], nums[i]);
    }

    printf("\nSales Summary: \n");
    printf("Minimum Sales:\t$%-.2f (%s)\n", min, months[minIndex]);
    printf("Maximum Sales:\t$%-.2f (%s)\n", max, months[maxIndex]);
    printf("Average Sales:\t$%-.2f \n", average);

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
        printf("%-15s\t$%-.2f\n", months[indices[i]], nums[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


int** create_lists_of_list(int number_of_arrays, int *len_of_arr){
    int **arr;

    arr = malloc(sizeof(int*)*number_of_arrays);

    for (int i = 0; i < number_of_arrays; ++i){
        printf("Enter number of elements in list %d: ", i);
        int m;
        scanf("%d", &m);
        *(len_of_arr + i) = m;
        *(arr+i) = malloc(sizeof(int)*m);
        printf("Enter the elements: \n");
        int k;
        for (int j = 0; j < m; ++j){
            scanf("%d", &k);
            *(*(arr+i)+j) = k;
        }
    }
    return arr;
}

void print_arrays(int** arr, int *len_of_arr, int n){
for (int j = 0; j < n; ++j){
    printf("the list number %d is: \n", j);
    for (int i = 0; i < *(len_of_arr + j); i++){
        printf("%d ", *(*(arr+j)+ i));
        }
    printf("\n");
}
}


void clean_memory(int** arr, int n,  int *len_of_arr){
    for (int j = 0; j < n; ++j){
            free(*(arr+j));
        }
    free(arr);
    free(len_of_arr);
}

int main(){

printf("Enter number of lists: ");
int n;
scanf("%d", &n);
int* len_of_arr = malloc(sizeof(int) * n);
int** a = create_lists_of_list(n, len_of_arr);
print_arrays(a, len_of_arr, n);
clean_memory(a, n, len_of_arr);
print_arrays(a, len_of_arr, n);
}
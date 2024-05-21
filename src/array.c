#include "array.h"

bool RAND_SEEDED = false;

void
__swap_int32_ptr_vals(int32_t *ptr1, int32_t *ptr2) {
	int32_t tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
	return;
}

void 
int32_arr_print(int32_t *arr, size_t n) {

	printf("[ ");

	for (size_t i = 0; i < n; i++) {
		printf("%" PRId32 , arr[i]);
		if (n != 0 && i != n - 1) {
			printf(", ");
		}
	}

	printf(" ]\n");
	return;
}

int
int32_arr_set_all_rand(int32_t *arr, size_t n, int32_t upper) {

	if (!RAND_SEEDED) {
		srand(time(NULL));
		RAND_SEEDED = true;
	}

	for (size_t i = 0; i < n; i++) {
		arr[i] = rand() % upper;
	}

	return 0;
}

int
int32_arr_sort_selection(int32_t *arr, size_t n) {

	for (size_t i = 0; i < n; i++) {
		int32_t min = arr[i];
		size_t min_idx = i;
		for (size_t j = i; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				min_idx = j;
			}
		}
		int32_t tmp = arr[i];
		arr[i] = min;
		arr[min_idx] = tmp;
	}
	return 0;
}

int 
int32_arr_sort_bubble(int32_t *arr, size_t n) {

	if (n <= 1) {
		return 0;
	}

	for (size_t i = 0; i < n; i++) {

		for (size_t j = 1; j < n; j++) {
			if (arr[j - 1] > arr[j]) {
				__swap_int32_ptr_vals(&arr[j - 1], &arr[j]);
			}
		}
	}

	return 0;
}

int
int32_arr_sort_insertion(int32_t *arr, size_t n) {

	if (n <= 1) {
		return 0;
	}

	for (size_t i = 1; i < n; i++) {
		//int32_t key = arr[i];
		for (size_t j = i; j > 0; j--) {
			if (arr[j - 1] > arr[j]) {
				__swap_int32_ptr_vals(&arr[j - 1], &arr[j]);
			}
		}
	}

	return 0;
}

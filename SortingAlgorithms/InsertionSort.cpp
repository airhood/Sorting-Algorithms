
void InsertionSort(int* arr, int n) {
	int key;
	for (int i = 1; i < n; i++) {
		key = arr[i];

		int j;
		for (j = i - 1; (j >= 0) && (arr[j] > key); j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
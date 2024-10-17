
void Merge(int* arr, int left, int mid, int right) {
	int* temp = new int[right - left + 1];
	int i = left;
	int j = mid + 1;
	int k = 0;

	while ((i <= mid) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			k++;
			i++;
		}
		else {
			temp[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		temp[k] = arr[i];
		k++;
		i++;
	}

	while (j <= right) {
		temp[k] = arr[j];
		k++;
		j++;
	}

	for (int l = left; l <= right; l++) {
		arr[l] = temp[l - left];
	}
}

void MergeSort(int* arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}
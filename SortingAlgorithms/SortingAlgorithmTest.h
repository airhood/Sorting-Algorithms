#pragma once

#include <iostream>

#define TEST_SORTING_FUNCTION(func) \
    do { \
        int arr1[] = {64, 25, 12, 22, 11}; \
        int arr2[] = {5, 3, 8, 6, 2}; \
        int arr3[] = {1, 4, 2, 9, 7}; \
        int arr4[] = {99, 1, 23, 45, 67}; \
        int arr5[] = {10, 30, 20, 40, 50}; \
        int* datasets[] = {arr1, arr2, arr3, arr4, arr5}; \
        const int sizes[] = {sizeof(arr1) / sizeof(arr1[0]), \
                              sizeof(arr2) / sizeof(arr2[0]), \
                              sizeof(arr3) / sizeof(arr3[0]), \
                              sizeof(arr4) / sizeof(arr4[0]), \
                              sizeof(arr5) / sizeof(arr5[0])}; \
        const int numDatasets = sizeof(datasets) / sizeof(datasets[0]); \
        for (int k = 0; k < numDatasets; k++) { \
            int size = sizes[k]; \
            std::cout << "Before sorting (Dataset " << k + 1 << "): "; \
            for (int i = 0; i < size; i++) { \
                std::cout << datasets[k][i] << " "; \
            } \
            std::cout << std::endl; \
            func(datasets[k], size); \
            std::cout << "After sorting (Dataset " << k + 1 << "): "; \
            for (int i = 0; i < size; i++) { \
                std::cout << datasets[k][i] << " "; \
            } \
            std::cout << std::endl; \
            if (isSorted(datasets[k], size)) { \
                std::cout << "Dataset " << k + 1 << " is sorted correctly." << std::endl; \
            } else { \
                std::cout << "Dataset " << k + 1 << " is not sorted correctly." << std::endl; \
            } \
        } \
    } while (0)

#define TEST_SORTING_FUNCTION_MERGE_ONLY(func) \
    do { \
        int arr1[] = {64, 25, 12, 22, 11}; \
        int arr2[] = {5, 3, 8, 6, 2}; \
        int arr3[] = {1, 4, 2, 9, 7}; \
        int arr4[] = {99, 1, 23, 45, 67}; \
        int arr5[] = {10, 30, 20, 40, 50}; \
        int* datasets[] = {arr1, arr2, arr3, arr4, arr5}; \
        const int sizes[] = {sizeof(arr1) / sizeof(arr1[0]), \
                              sizeof(arr2) / sizeof(arr2[0]), \
                              sizeof(arr3) / sizeof(arr3[0]), \
                              sizeof(arr4) / sizeof(arr4[0]), \
                              sizeof(arr5) / sizeof(arr5[0])}; \
        const int numDatasets = sizeof(datasets) / sizeof(datasets[0]); \
        for (int k = 0; k < numDatasets; k++) { \
            int size = sizes[k]; \
            std::cout << "Before sorting (Dataset " << k + 1 << "): "; \
            for (int i = 0; i < size; i++) { \
                std::cout << datasets[k][i] << " "; \
            } \
            std::cout << std::endl; \
            func(datasets[k], 0, size - 1); \
            std::cout << "After sorting (Dataset " << k + 1 << "): "; \
            for (int i = 0; i < size; i++) { \
                std::cout << datasets[k][i] << " "; \
            } \
            std::cout << std::endl; \
            if (isSorted(datasets[k], size)) { \
                std::cout << "Dataset " << k + 1 << " is sorted correctly." << std::endl; \
            } else { \
                std::cout << "Dataset " << k + 1 << " is not sorted correctly." << std::endl; \
            } \
        } \
    } while (0)

#define isSorted(arr, n) \
    ([](int* array, int size) { \
        for (int i = 1; i < size; i++) { \
            if (array[i] < array[i - 1]) return false; \
        } \
        return true; \
    }(arr, n))
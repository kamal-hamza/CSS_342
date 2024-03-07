def swap(arr, index1, index2):
    arr[index1], arr[index2] = arr[index2], arr[index1]

def bubble_sort(arr):
    length = len(arr)
    for i in range(length - 1, 0, -1):
        for j in range(i):
            if arr[j] > arr[j + 1]:
                swap(arr, j, j + 1)

def insertion_sort(arr):
    length = len(arr)
    for i in range(1, length):
        val = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > val:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = val

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        merge_sort(left)
        merge_sort(right)
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

def iterative_merge_sort(arr):
    length = len(arr)
    temp = [0] * length
    size = 1
    while size < length:
        left = 0
        while left < length - size:
            mid = left + size
            right = min(left + 2 * size, length)
            merge(arr, left, mid, right, temp)
            left += 2 * size
        size += 2

def merge(arr, left, mid, right, temp):
    i = left
    j = mid
    k = left
    while i < mid and j < right:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            j += 1
        k += 1
    while i < mid:
        temp[k] = arr[i]
        i += 1
        k += 1
    while j < right:
        temp[k] = arr[j]
        j += 1
        k += 1
    for l in range(left, right):
        arr[l] = temp[l]

def median(val1, val2, val3):
    if (val1 < val2 and val2 < val3) or (val3 < val2 and val2 < val1):
        return val2
    elif (val2 < val1 and val1 < val3) or (val3 < val1 and val1 < val2):
        return val1
    else:
        return val3

def partition(arr, left, right):
    pivot = arr[right]
    i = left - 1
    for j in range(left, right):
        if arr[j] <= pivot:
            i += 1
            swap(arr, i, j)
    swap(arr, i + 1, right)
    return i + 1

def median_pivot(arr, left, right):
    mid = right // 2
    mid_val = median(arr[left], arr[mid], arr[right])
    tmp = arr[right]
    arr[right] = mid_val
    if mid_val == arr[left]:
        arr[left] = tmp
    elif mid_val == arr[mid]:
        arr[mid] = tmp
    return partition(arr, left, right)

def quick_sort_helper(arr, left, right):
    if left < right:
        pivot = partition(arr, left, right)
        quick_sort_helper(arr, left, pivot - 1)
        quick_sort_helper(arr, pivot + 1, right)

def quick_sort(arr, left, right):
    if left >= right:
        return
    elif left < right:
        median_pivot(arr, left, right)
        quick_sort_helper(arr, left, right)

def shell_sort(arr):
    gap = len(arr) // 2
    while gap >= 1:
        for j in range(gap, len(arr)):
            i = j - gap
            while i >= 0:
                if arr[i + gap] > arr[i]:
                    break
                else:
                    swap(arr, i + gap, i)
                i -= gap
        gap //= 2

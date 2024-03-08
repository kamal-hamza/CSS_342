import os
import sys
import time
import random
import matplotlib.pyplot as plt

sys.setrecursionlimit(30000)

from sort import bubble_sort, iterative_merge_sort, insertion_sort, merge_sort, quick_sort, shell_sort

def generate_list(size):
    return [random.randint(1, size) for _ in range(size)]

def measure_time(sort_func, size, repetitions=5):
    total_time = 0
    for _ in range(repetitions):
        lst = generate_list(size)
        start_time = time.time()
        if sort_func.__name__ == "quick_sort":
            sort_func(lst, 0, len(lst) - 1)
        else:
            sort_func(lst)
        end_time = time.time()
        total_time += end_time - start_time
    avg_time = total_time / repetitions
    return (size, float(avg_time))

list_sizes = [100, 150, 200, 250, 300, 350, 400, 500, 600, 700, 800, 900, 1000, 1250, 1500, 1750, 2000, 2050, 2100, 2200, 2300, 2400, 2500, 2750, 3000, 3250, 3500, 3750, 4000]


sorting_algorithms = {
    "Bubble_Sort": bubble_sort,
    "Insertion_Sort": insertion_sort,
    "Merge_Sort": merge_sort,
    "Iterative_Merge_Sort": iterative_merge_sort,
    "Quick_Sort": quick_sort,
    "Shell_Sort": shell_sort
}

algorithm_data = {algo_name: [] for algo_name in sorting_algorithms}

for algorithm_name, algorithm in sorting_algorithms.items():
    print(f"Algorithm: {algorithm_name}")
    times = []
    for size in list_sizes:
        avg_time = measure_time(algorithm, size)
        times.append(avg_time)
        print(f"List size: {size}, Avg. Time: {avg_time[1]:.6f} seconds")
    algorithm_data[algorithm_name] = times
    print()

print(algorithm_data)

saveDir = './Report/img/'

for algorithm, times in algorithm_data.items():
    plt.figure()
    plt.xlabel = ('Size')
    plt.ylabel = ('Time')
    plt.title({algorithm})
    sizes, times = zip(*times)
    plt.plot(sizes, times, marker="o")
    plt.savefig(os.path.join(saveDir, 'plot_'+algorithm+'.png'))

for algorithm, times in algorithm_data.items():
    plt.figure()
    plt.xlabel = ('Size')
    plt.ylabel = ('Time')
    plt.title({algorithm})
    sizes, times = zip(*times)
    plt.loglog(sizes, times, marker="o")
    plt.savefig(os.path.join(saveDir, 'loglog_'+algorithm+'.png'))

plt.figure()
for algorithm, times, in algorithm_data.items():
    sizes, times = zip(*times)
    plt.plot(sizes, times, marker="o", label={algorithm})

plt.xlabel = ('Size')
plt.ylabel = ('Time')
plt.title("Algorithm Comparison")
plt.legend()
plt.savefig(os.path.join(saveDir, 'plot_combined.png'))

plt.figure()
for algorithm, times, in algorithm_data.items():
    sizes, times = zip(*times)
    plt.loglog(sizes, times, marker="o", label={algorithm})

plt.xlabel = ('Size')
plt.ylabel = ('Time')
plt.title("Algorithm Comparison")
plt.legend()
plt.savefig(os.path.join(saveDir, 'loglog_combined.png'))


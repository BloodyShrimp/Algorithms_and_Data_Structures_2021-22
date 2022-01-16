import matplotlib.pyplot as plt
import numpy as np

# n = [1000, 10000, 50000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]
# bubble_time = [0.0008936, 0.121517, 3.87714, 15.5879, 62.3659, 140.589]
# insertion_time = [0.0001344, 0.0150839, 0.335001, 1.34346, 5.3223, 11.9314, 21.3647, 34.2357, 49.4232, 67.1734, 90.3073, 114.045, 139.028]
# selection_time = [0.0003455, 0.0279207, 0.670129, 2.71051, 10.6386, 24.4203, 43.9563, 68.608, 98.7537, 133.817]

bubble_x, bubble_y = [], []
insertion_x, insertion_y = [], []
selection_x, selection_y = [], []
counting_x, counting_y = [], []
theor_bubble = np.arange(0, 300000)
theor_insert = np.arange(0, 1000000)
theor_select = np.arange(0, 700000)

for line in open('bubble_sort_time.txt', 'r'):
    values = [float(s) for s in line.split()]
    bubble_x.append(values[0])
    bubble_y.append(values[1])

for line in open('insertion_sort_time.txt', 'r'):
    values = [float(s) for s in line.split()]
    insertion_x.append(values[0])
    insertion_y.append(values[1])

for line in open('selection_sort_time.txt', 'r'):
    values = [float(s) for s in line.split()]
    selection_x.append(values[0])
    selection_y.append(values[1])

for line in open('counting_sort_time.txt', 'r'):
    values = [float(s) for s in line.split()]
    counting_x.append(values[0])
    counting_y.append(values[1])

# plt.plot(n[0:6], bubble_time, label="BubbleSort", linestyle = 'dashed', marker = 'o', linewidth = 1)
# plt.plot(n, insertion_time, label="InsertionSort", linestyle = 'dashed', marker = 'o', linewidth = 1)
# plt.plot(n[0:10], selection_time, label="SelectionSort", linestyle = 'dashed', marker = 'o', linewidth = 1)

# plt.plot(bubble_x, bubble_y, label="BubbleSort", linewidth = 2)
# plt.plot(insertion_x, insertion_y, label="InsertionSort", linewidth = 2)
# plt.plot(selection_x, selection_y, label="SelectionSort", linewidth = 2)
# plt.plot(theor_bubble, 0.00000000155 * theor_bubble * theor_bubble, label="BubbleTheoretical", linestyle = 'dashed', linewidth = 1, color = 'orange')
# plt.plot(theor_insert, 0.00000000014 * theor_insert * theor_insert, label="InsertionTheoretical", linestyle = 'dashed', linewidth = 1, color = 'blue')
# plt.plot(theor_select, 0.000000000275 * theor_select * theor_select, label="SelectionTheoretical", linestyle = 'dashed', linewidth = 1, color = 'red')
plt.plot(counting_x, counting_y, label="CountingSort", linewidth = 1)

plt.ticklabel_format(style='plain')
# plt.xscale('log')
# plt.yscale('log')
plt.xlabel("N")
plt.ylabel("Czas [s]")
plt.legend()
plt.title("Czas sortowania")
plt.savefig("wykres_counting.png")
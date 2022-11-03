import matplotlib.pyplot as plt
import csv
import math

x = []
y = []

with open('Ass5 1.3.csv', 'r') as csvfile:
    plots = csv.reader(csvfile, delimiter=',')

    for row in plots:
        x.append(row[2])
        # x.append(row[1])
        y.append(row[0])
    plt.plot(x, y, color='g', label="QuickSort Logarithmic Running Time")
    for row in plots:
        x.append(row[2])
        # x.append(row[1])
        y.append(row[1])
    plt.scatter(x, y, color='r', label="MergeSort Logarithmic Running Time")

plt.ylabel('log(Time)')
plt.xlabel('logn')
plt.title('Log(Time) vs logn')
plt.legend()
plt.show()

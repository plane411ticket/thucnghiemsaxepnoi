import numpy as np
import time

with open("dataset.txt", "r") as input:
    dataset = input.readlines()
    i = 1
    for line in dataset:
        list1 = [float (x) for x in line.split()]
        start = time.time()
        list1 = np.sort(list1)
        end = time.time()
        print("Excution time: ", round((end-start)*1000), "\n")
        i+=1
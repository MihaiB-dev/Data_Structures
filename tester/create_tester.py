import random
#Caz 1: Toate lementele sunt deja sortate
with open("sorted_10000000.txt","w") as file:
    for x in range(1,10000001):
        file.write(f"{str(x)}\n")

#Caz 2: reversed

with open("reversed_10000000.txt", "w") as file:
    for x in range(10000000,0,-1):
        file.write(f"{str(x)}\n")
#Caz 3 : random

with open("random_10.000.000.txt", "w") as file:
    for x in range(10000000):
        file.write(f"{str(random.randint(1,100000))}\n")
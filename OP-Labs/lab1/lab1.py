import math

#Точка A
x1 = int(input("Введіть значення x1: "))
y1 = int(input("Введіть значення y1: "))

#Точка B
x2 = int(input("Введіть значення x2: "))
y2 = int(input("Введіть значення y2: "))

#Точка C
x3 = int(input("Введіть значення x3: "))
y3 = int(input("Введіть значення y3: "))

#Сторони трикутника
AB = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
BC = math.sqrt((x2 - x3) ** 2 + (y2 - y3) ** 2)
AC = math.sqrt((x1 - x3) ** 2 + (y1 - y3) ** 2)

#Периметр трикутника
P = AB + BC + AC

#Півпериметр трикутника
HP = P / 2

#Площа трикутника
S = str(math.sqrt(HP * (HP - AB) * (HP - BC) * (HP - AC)))

#Виведення результату
print("Периметр трикутника ABC: " + str(P))
print("Площа трикутника ABC: " + S)

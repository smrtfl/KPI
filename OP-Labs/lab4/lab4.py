#Введення початкових значень
n = float(input("Введіть число n: "))
a = float(input("Введіть число a: "))
b = float(input("Введіть число b: "))

i = 1
h = (b - a)/n

#Якщо n не є натуральним
while (n * 10) % 10 != 0  or n < 0:
    n = float(input("\nn має бути натуральним числом!\nВведіть нове значення n: "))

#Якщо a дорівнює b
while a == b:
    b = float(input("\na не може дорівнювати b!\nВведіть нове значення b: "))

#Обчислення членів послідовності
print("\nПослідовність чисел r: ")
for i in range(1, int(n)):
    ri = a + i * h
    print("r" + str(i) + " = " + str(ri))
    i += 1

#Якщо n дорівнює 1
if n == 1:
    ri = a + i * h
    print("r" + str(i) + " = " + str(ri))

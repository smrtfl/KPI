import math

#eps = float(input("Введіть точність обчислення: "))
#a = float(input("Введіть дійсне a : "))
#b = float(input("Введіть дійсне b: "))

n = 0

def cos(x):

    sum = (((-1) ** n) * (x ** (2 * n))) / math.factorial(2 * n)
    n += 1

    if math.fabs(sum) < eps:
        return 0

    return cos(x)

print(cos(4))

#y = cos(a) + (cos(b) ** 2) + cos (a + b)
#print("cos(a) + (cos(b) ** 2) + cos (a + b) = " + y)

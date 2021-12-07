import math

a = float(input("Введіть дійсне a: "))
b = float(input("Введіть дійсне b: "))
eps = float(input("Введіть точність обчислення: "))

n = 0

#Функція обчислення ряду Тейлора
def cos(x1, n1, eps1):

    sum = (((-1) ** n1) * (x1 ** (2 * n1))) / math.factorial(2 * n1)

    if math.fabs(sum) < eps1:
        return 0
    else:
        return sum + cos(x1, n1 + 1, eps1)

y =  cos(a, n, eps) + (cos(b, n, eps) ** 2) + cos (a + b, n, eps)
print("\ncos({a}) + cos({b})^2 + cos({c}) = {y}".format(a=a, b=b, c=a+b, y=y))

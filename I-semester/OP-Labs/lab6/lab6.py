import math

#Функція обчислення факторіалу
def fact(i):
    if i <= 1:
        return 1
    else:
        return i * fact(i - 1)

#Функція обчислення ряду Тейлора
def cos(x1, n1, eps1, sum, sum0):
    term = (((-1) ** n1) * (x1 ** (2 * n1))) / fact(2 * n1)

    if n1 == 0:
        sum = x1;
        print("n = " + str(n1) + "; sum = " + str(sum))
        return x1 + cos(x1, n1 + 1, eps1, sum, sum0)
    elif math.fabs(sum - sum0) < eps1:
        sum += term
        print("next sum = " + str(sum))
        return 0
    else:
        sum0 = sum
        sum += term
        print("n = " + str(n1) + "; sum = " + str(sum))
        return term + cos(x1, n1 + 1, eps1, sum, sum0)

a = float(input("Введіть дійсне a: "))
b = float(input("Введіть дійсне b: "))
eps = float(input("Введіть точність обчислення: "))

n = 0
s = 0 #Сума ряду
s0 = 0 #Попередня сума ряду

print("\n", end = '')

#Виведення значень ряду cos(a)
cos_a = cos(a, n, eps, s, s0)
print("cos(" + str(a) + ") = " + str(cos_a) + "\n")

#Виведення значень ряду cos(b)
cos_b = cos(b, n, eps, s, s0)
print("cos(" + str(b) + ") = " + str(cos_b) + "\n")

#Виведення значень ряду cos(a + b)
cos_ab = cos(a + b, n, eps, s, s0)
print("cos(" + str(a + b) + ") = " + str(cos_ab) + "\n")

#Кінцевий результат
y =  cos_a + (cos_b ** 2) + cos_ab
print("y = cos({a}) + cos({b})^2 + cos({c}) = {y}".format(a=a, b=b, c=a+b, y=y))

n = 1000000
x = 0

#Задаємо проміжок числу х
while n <= 1000000000:

    temp = n
    rev = 0

    #"Перегортаємо" числа
    while temp > 0:
        num = temp % 10
        rev = rev * 10 + num
        temp = temp // 10

    #Порівнюємо число х з його дзеркальним відображенням
    if rev == n:
        print(str(n), end = ' ')
        x += 1

    n += 1

#Виводимо число паліндром на інтервалі
print("\n" + str(x) + " palindromes")

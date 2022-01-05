def InputText(s): #Введення тексу
    for i in s:
        s = input("Введіть рядок: ")
        return s

def AllWords(s, w): #Пошук усіх слів у рядку
    w = s.split(' ')
    return w

def OutputWords(w): #Функція виведення усіх слів (можна і без функції)
    print("\nУсі слова рядку: [", end = '')
    for i in range(len(w)):
        if i == len(w) - 1:
            print(w[i], end = '')
        else: print(w[i], end = ', ')
    print("]")
    print("Всього слів: " + str(len(w)))

def Palindromes(w): #Пошук усіх слів-паліднром
    count = 0
    print("\nУсі слова-паліндроми рядку: [", end = ' ')
    for i in range(len(w)):
        if w[i] == w[i][::-1]:
            print(w[i], end = ' ')
            count += 1
    print("]")
    print("Всього слів-паліднромів: " + str(count))

text = ' ' #Заданий рядок
text = InputText(text)
words = ' ' #Список слів
words = AllWords(text, words)
OutputWords(words) #Виведеннях усіх слів
Palindromes(words) #Пошук і виведення слів-паліндромів

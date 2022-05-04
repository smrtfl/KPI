class Student: # group-FullName-Birthday
    def __init__(self, group, surname, name, patronymic, month, day, year):
        self.group = group
        self.fullname = self.FullName(surname, name, patronymic)
        self.birthday = self.Birthday(month, day, year)

    class FullName:  # surname-name-patronymic
        def __init__(self, surname, name, patronymic):
            self.surname = surname
            self.name = name
            self.patronymic = patronymic

    class Birthday:  # mm-dd-yyyy
        def __init__(self, month, day, year):
            self.month = month
            self.day = day
            self.year = year

    def show(self):
        print("%s %s %s %s %s.%s.%s" % (self.group, self.fullname.surname, self.fullname.name, self.fullname.patronymic,
              self.birthday.month, self.birthday.day, self.birthday.year))

def create_list(s_list):
    # pre-list
    s1 = Student("AD-01", "Melnyk", "Andriy", "Olegovych", "12", "21", "2004")
    s_list.append(s1)
    s2 = Student("AD-01", "Kovalenko", "Oleksiy", "Oleksandrovych", "10", "28", "2002")
    s_list.append(s2)
    s3 = Student("AD-01", "Kravchenko", "Mark", "Evgenovych", "01", "03", "2003")
    s_list.append(s3)

    s4 = Student("IO-05h", "Tkachuk", "Evgen", "Bohdanovych", "11", "17", "2003")
    s_list.append(s4)
    s5 = Student("IO-05h", "Moroz", "Egor", "Markovych", "11", "05", "2003")
    s_list.append(s5)

    s6 = Student("IP-14", "Gaiduchek", "Maxim", "Andriyovych", "05", "28", "2004")
    s_list.append(s6)
    s7 = Student("IP-14", "Kotkov", "Timur", "Maximovych", "07", "07", "2004")
    s_list.append(s7)

    print("List of students:")
    for i in range(len(s_list)):
        s_list[i].show()

def add_yourself(s_list):
    print("\nAdd yourself to list")
    user = Student(input("Group: "), input("Surname: "), input("Name: "), input("Patronymic: "),
                   input("Birth month (mm): "), input("Birth day (dd): "), input("Birth year (yyyy): "))
    s_list.append(user)

    print("\nNew list of students:")
    for i in range(len(s_list)):
        s_list[i].show()

    return s_list

def oldest_student(s_list):
    groups_list = []
    for i in range(len(s_list)):
        if s_list[i].group not in groups_list:
            groups_list.append(s_list[i].group)

    print("\nList of groups:")
    for i in range(len(groups_list)):
        print("%d. %s" % (i + 1, groups_list[i]))

    group_name = groups_list[int(input("\nChoose group number: ")) - 1] # chosen group

    group_students = [] # students from chosen group
    for i in range(len(s_list)):
        if s_list[i].group == group_name:
            group_students.append(s_list[i])

    # looking for the oldest student
    oldest_year = "2023"
    for i in range(len(group_students)):
        if int(group_students[i].birthday.year) < int(oldest_year):
            oldest_year = group_students[i].birthday.year

    oldest_month = "13"
    for i in range(len(group_students)):
        if int(group_students[i].birthday.year) == int(oldest_year) and int(group_students[i].birthday.month) < int(oldest_month):
            oldest_month = group_students[i].birthday.month

    oldest_day = "32"
    for i in range(len(group_students)):
        if int(group_students[i].birthday.year) == int(oldest_year) and int(group_students[i].birthday.month) == int(oldest_month) and int(group_students[i].birthday.day) < int(oldest_day):
            oldest_day = group_students[i].birthday.day

    oldest = group_students[0]
    for i in range(len(group_students)):
        if group_students[i].birthday.year == oldest_year and group_students[i].birthday.month == oldest_month and group_students[i].birthday.day == oldest_day:
            oldest = group_students[i] # the oldest student in chosen group

    print("\nOldest student in group '%s': " % group_name)
    oldest.show()

from datetime import datetime

class Goods:
    def __init__(self, name, date, price, amount):
        self.name = name
        self.date = date
        self.price = price
        self.amount = amount

    def sum_price(self):
        return self.price * self.amount

    def output(self):
        if isinstance(self, MGoods):
            print("%s %s %d$ %d %s %s" % (self.name, '.'.join(self.date), self.price, self.amount, self.transporting, self.status))
        elif isinstance(self, FGoods):
            print("%s %s %d$ %d %s" % (self.name, '.'.join(self.date), self.price, self.amount, '.'.join(self.end_date)))

class MGoods(Goods):
    def __init__(self, name, date, price, amount, transporting, status):
        super().__init__(name, date, price, amount)
        self.transporting = transporting
        self.status = status

class FGoods(Goods):
    def __init__(self, name, date, price, amount, end_date):
        super().__init__(name, date, price, amount)
        self.end_date = end_date

    def overdue_check(self, cd):
        if self.end_date[2] < cd[2]:
            return 1
        elif self.end_date[2] == cd[2]:
            if self.end_date[1] < cd[1]:
                return 1
            elif self.end_date[1] == cd[1]:
                if self.end_date[0] <= cd[0]:
                    return 1
                else:
                    return 0
            else:
                return 0
        else:
            return 0

def init_goods():
    n = int(input("Amount of manufacture goods: "))
    mg = []
    for _ in range(n):
        mg.append(MGoods(input("Item name: "), [x for x in input("Item manufacture date (dd.mm.yyyy): ").split(".")], int(input("Item price: ")), int(input("Item amount: ")), input("Item transportation method: "), input("Item location (warehouse, store): ")))
        print()

    m = int(input("Amount of food goods: "))
    fg = []
    for _ in range(m):
        fg.append(FGoods(input("Item name: "), [x for x in input("Item manufacture date (dd.mm.yyyy): ").split(".")], int(input("Item price: ")), int(input("Item amount: ")), [x for x in input("Item end date (dd.mm.yyyy): ").split(".")]))
        print()

    return mg, fg

def output_goods(mg, fg):
    print("Manufacture goods:")
    for item in mg:
        item.output()

    print("\nFood goods:")
    for item in fg:
        item.output()

def calculations(mg, fg):
    curr_date = [x for x in datetime.today().strftime('%d.%m.%Y').split(".")]
    total_price = 0

    for item in fg:
        if item.overdue_check(curr_date) == 1:
            total_price += item.sum_price()

    print("\nTotal price of expired food goods: " + str(total_price) + "$")

    total_price = 0
    for item in mg:
        if item.status == "warehouse":
            total_price += item.sum_price()

    print("Total price of manufacture goods in warehouse: " + str(total_price) + "$")

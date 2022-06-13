class Cntr_class:
    def __init__(self):
        self.counter = 0

    def edit_cntr(self):
        self.counter += 1

    def reset_cntr(self):
        self.counter = 0

    def output_cntr(self):
        print(self.counter)


cntr = Cntr_class()

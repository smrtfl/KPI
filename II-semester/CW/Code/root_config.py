from tkinter import *

class App:
    def __init__(self):
        self.__master = Tk()

        # window resolution
        root_width = 854
        root_height = 480

        # get the screen dimension
        screen_width = self.__master.winfo_screenwidth()
        screen_height = self.__master.winfo_screenheight()

        # find the center point
        center_x = int(screen_width / 2 - root_width / 2) - 9
        center_y = int(screen_height / 2 - root_height / 2) - 35

        # window settings
        self.__master.title('Course Work')
        self.__master.iconphoto(True, PhotoImage(file='files/kpi_logo.png'))
        self.__master.geometry(f'{root_width}x{root_height}+{center_x}+{center_y}')
        self.__master.resizable(width=True, height=True)

    # access methods
    def mainloop(self):
        return self.__master.mainloop()

    def access(self):
        return self.__master

    def destroy(self):
        return self.__master.destroy()

    def winfo_children(self):
        return self.__master.winfo_children()


root = App() # create window

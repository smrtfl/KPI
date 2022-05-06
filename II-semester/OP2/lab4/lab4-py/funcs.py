class Vector:
    def __init__(self, *args): # overloading constructor = multiple constructors
        if len(args) == 0:
            self._x = 0
            self._y = 0
            self._z = 0
        elif len(args) == 1:
            self._x = args[0]
            self._y = 0
            self._z = 0
        elif len(args) == 2:
            self._x = args[0]
            self._y = args[1]
            self._z = 0
        elif len(args) >= 3:
            self._x = args[0]
            self._y = args[1]
            self._z = args[2]

    def __add__(self, other): # overloading +
        return self._x + other._x, self._y + other._y, self._z + other._z

    def __mul__(self, other): # overloading *
        return self._x * other._x, self._y * other._y, self._z * other._z

    # getters
    def get_x(self):
        return self._x

    def get_y(self):
        return self._y

    def get_z(self):
        return self._z

    def length(self): # method
        return (self._x ** 2 + self._y ** 2 + self._z) ** (1 / 2)

def set_vectors(v_list):
    print("Set coordinates for M1 and M2. Enter 'done' to go to next vector:") # skipping allows using multiple constructors
    for i in range(2):
        a = input("\nx coordinate for vector №%d: " % (i + 1))
        if a == "done":
            v_list.append(Vector())
            continue
        b = input("y coordinate for vector №%d: " % (i + 1))
        if b == "done":
            v_list.append(Vector(int(a)))
            continue
        c = input("z coordinate for vector №%d: " % (i + 1))
        if c == "done":
            v_list.append(Vector(int(a), int(b)))
            continue

        v_list.append(Vector(int(a), int(b), int(c)))

    m3 = v_list[0] + v_list[1] # add coordinates using overloaded +
    v_list.append(Vector(m3[0], m3[1], m3[2]))

    print("\nVectors:")
    for i in range(3):
        print("Vector №%d = (%d, %d, %d)" % ((i + 1), v_list[i].get_x(), v_list[i].get_y(), v_list[i].get_z()))

    return v_list

def calculations(v_list):
    print("\nLength of vectors:")
    for i in range(3):
        print("Vector №%d = %f" % ((i + 1), v_list[i].length()))

    scalar = 0
    temp = v_list[0] * v_list[2] # multiply coordinates using overloaded *
    for i in range(len(temp)):
        scalar += temp[i]

    print("\nScalar product of M1 and M3:\nM1 * M3 = %d" % scalar)

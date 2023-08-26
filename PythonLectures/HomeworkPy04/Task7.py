# 7. Задача: Създайте класове Bird, Swimmer, и Penguin, където Penguin наследява и двата класа и комбинира техните
# свойства.
# Вход: създаване на пингвин и извикване на методите за плуване и летене
# Изход: "Swimming" и "Can't fly"

class Bird:
    @staticmethod
    def fly():
        print("fly fly")


class Swimmer:
    @staticmethod
    def swim():
        print("Swimming")


class Penguin(Swimmer, Bird):
    @staticmethod
    def fly():
        print("Can't swim")


birdie = Penguin()
birdie.swim()
birdie.fly()

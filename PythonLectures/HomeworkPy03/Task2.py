# 2.Animal Hierarchy
#
# Task: Create a class Animal with basic properties like name and sound.
# Extend it with subclasses for specific animals like Dog, Cat,
# and implement their specific behaviors.
#
# Example Input: dog = Dog(); dog.sound()
# Example Output: “Woof!”


# Note to assessor: I discussed if such small class can be in same module
# Decision was left to me, therefore 3 classes are part of this *.py file

class Animal:
    __name = str

    def __init__(self, name):
        if type(name) == str:
            self.__name = name

    def __str__(self):
        return self.__name

    def sound(self):
        pass


class Dog(Animal):

    def sound(self):
        print("Woof!")

    def __str__(self):
        print("I, dog, am ", end='')
        return super().__str__()
        # return Animal.__str__(self)


class Cat(Animal):

    def sound(self):
        print("meow")

    def __str__(self):
        print("This great cat is named ", end='')
        # return Animal.__str__(self)
        return super().__str__()


kuche_test = Dog("Dogo")
kote_test = Cat("Gato")
kuche_test.sound()
kote_test.sound()
print(kuche_test)
print(kote_test)

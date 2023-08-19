# 3.File Reader Class
#
# Task: Implement a FileReader class that takes a file path and
# provides methods to read the file line by line or all at once.
# Example Input: reader = FileReader(“file.txt”); reader.read_line()
# Example Output: “First line of file.”

class FileReader:
    def __init__(self, filepath):
        self.__file = open(filepath, 'r')

    def read_line(self):
        if not self.__file.closed:
            return str(self.__file.readline())
        return None

    def read_all(self):
        if not self.__file.closed:
            self.__file.seek(0)
            return self.__file.read()
        return None


f = FileReader("testTask3")
print(f.read_line())
print(f.read_line())
print(f.read_all())
print(f.read_line())

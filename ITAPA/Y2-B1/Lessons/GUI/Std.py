import sqlite3
import numpy as np

class Exemption(Exception):
    pass

class Std():
    def __init__(self, name, surname, id, department, faculty):
        self.name = name
        self.surname = surname
        self.id = id
        self.department = department
        self.faculty = faculty
      

def Student_data():
    name = input("Enter your name: ")
    surname = input("Enter your surname: ")
    id = input("Enter your ID: ")
    department = input("Enter your Department: ")
    faculty = input("Enter your faculty: ")
    return name, surname, id, department, faculty
    

if __name__ == "__main__":
    studentData = Student_data()
    studentInstance = Std(*studentData)
    print(studentInstance.name)

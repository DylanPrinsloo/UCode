import sqlite3
import pandas as pd
 
# Create the SQLite database and tables
conn = sqlite3.connect('company.db')
c = conn.cursor()
 
c.execute('''CREATE TABLE IF NOT EXISTS employees
             (emp_id INTEGER PRIMARY KEY, emp_name TEXT, emp_age INTEGER, department_id INTEGER)''')
 
c.execute('''CREATE TABLE IF NOT EXISTS departments
             (dept_id INTEGER PRIMARY KEY, dept_name TEXT)''')


 
# Insert records into the employees table
employees_records = [
    (1, 'John Doe', 32, 1),
    (2, 'Jane Smith', 28, 2),
    (3, 'Michael Johnson', 45, 1),
    (4, 'Emily Williams', 37, 3),
    (5, 'David Brown', 29, 2)
]



c.executemany("INSERT INTO employees (emp_id, emp_name, emp_age, department_id) VALUES (?, ?, ?, ?)", employees_records)
 
# Insert records into the departments table
departments_records = [
    (1, 'Sales'),
    (2, 'Marketing'),
    (3, 'IT')
]
c.executemany("INSERT INTO departments (dept_id, dept_name) VALUES (?, ?)", departments_records)
 
# Perform an INNER JOIN operation
c.execute('''SELECT e.emp_id, e.emp_name, e.emp_age, d.dept_name
             FROM employees e
             INNER JOIN departments d ON e.department_id = d.dept_id''')


result = c.fetchall()
 
# Convert the result to a pandas DataFrame
df = pd.DataFrame(result, columns=['Employee ID', 'Employee Name', 'Employee Age', 'Department'])
 
# Display the DataFrame
print(df)
 
# Commit the changes and close the connection
conn.commit()
conn.close()


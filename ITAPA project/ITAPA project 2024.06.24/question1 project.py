import re
import pandas as pd
from concurrent.futures import ThreadPoolExecutor
import tkinter as tk
from tkinter import filedialog, messagebox, ttk

def read_csv(file_path):
    df = pd.read_csv(file_path)
    return df

def convert_value(value):
    if re.match(r'^\d+$', str(value)):
        return int(value)
    return value

def process_row(row, weights):
    name = row['name']
    scores = [convert_value(row[col]) for col in row.index[1:]]
    grade = sum(score * weight for score, weight in zip(scores, weights))
    return name, grade

def calculate_grades_multithreaded(df, weights):
    grades = []
    with ThreadPoolExecutor() as executor:
        futures = [executor.submit(process_row, row, weights) for _, row in df.iterrows()]
        for future in futures:
            grades.append(future.result())
    return grades

def open_file():
    file_path = filedialog.askopenfilename(filetypes=[("CSV Files", "*.csv")])
    if not file_path:
        return
    try:
        df = read_csv(file_path)
        weights = [0.3, 0.3, 0.4]  # Example weights for assignment, midterm, final_exam
        grades = calculate_grades_multithreaded(df, weights)
        display_grades(grades)
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

def display_grades(grades):
    for widget in result_frame.winfo_children():
        widget.destroy()
    
    for name, grade in grades:
        label = ttk.Label(result_frame, text=f"{name}: {grade}")
        label.pack()

# Create the main application window
root = tk.Tk()
root.title("Student Grade Calculator")

# Create a frame for the file selection and calculation
frame = ttk.Frame(root, padding="10")
frame.grid(row=5, column=5, sticky=(tk.W, tk.E))

# Add a button to open the CSV file
open_button = ttk.Button(frame, text="Open CSV File", command=open_file)
open_button.grid(row=0, column=0, padx=5, pady=5)

# Create a frame to display the results
result_frame = ttk.Frame(root, padding="20")
result_frame.grid(row=0, column=0, sticky=(tk.W, tk.E))

# Start the GUI event loop
root.mainloop()


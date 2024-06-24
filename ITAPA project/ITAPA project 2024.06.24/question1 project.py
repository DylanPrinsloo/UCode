import tkinter as tk
from tkinter import filedialog, messagebox, ttk
import re
import pandas as pd
from concurrent.futures import ThreadPoolExecutor

class GradeCalculator:
    def __init__(self, root):
        self.root = root
        self.root.title("Grade Calculator")

        self.file_path = tk.StringVar()

        # CSV file path entry
        self.label_file_path = tk.Label(root, text="CSV file path:")
        self.label_file_path.grid(row=0, column=0, padx=10, pady=10)

        self.entry_file_path = tk.Entry(root, textvariable=self.file_path, width=50)
        self.entry_file_path.grid(row=0, column=1, padx=10, pady=10)

        # Load CSV button
        self.button_load_csv = tk.Button(root, text="Load CSV File", command=self.load_csv)
        self.button_load_csv.grid(row=1, column=0, padx=10, pady=10, columnspan=2)

        # Calculate Grades button
        self.button_calculate_grades = tk.Button(root, text="Calculate Grades", command=self.calculate_grades)
        self.button_calculate_grades.grid(row=2, column=0, padx=10, pady=10, columnspan=2)

        # Display grades area
        self.text_display_grades = tk.Text(root, height=20, width=60)
        self.text_display_grades.grid(row=3, column=0, columnspan=2, padx=10, pady=10)
        self.text_display_grades.insert(tk.END, "Display Grades Here")

    def load_csv(self):
        file_path = filedialog.askopenfilename(filetypes=[("CSV Files", "*.csv")])
        if file_path:
            self.file_path.set(file_path)

    def read_csv(self, file_path):
        df = pd.read_csv(file_path)
        return df

    def convert_value(self, value):
        if re.match(r'^\d+$', str(value)):
            return int(value)
        return value

    def process_row(self, row, weights):
        name = row['name']
        scores = [self.convert_value(row[col]) for col in row.index[1:]]
        grade = sum(score * weight for score, weight in zip(scores, weights))
        return name, grade

    def calculate_grades_multithreaded(self, df, weights):
        grades = []
        with ThreadPoolExecutor() as executor:
            futures = [executor.submit(self.process_row, row, weights) for _, row in df.iterrows()]
            for future in futures:
                grades.append(future.result())
        return grades

    def calculate_grades(self):
        file_path = self.file_path.get()
        if not file_path:
            messagebox.showerror("Error", "Please load a CSV file first.")
            return
        try:
            df = self.read_csv(file_path)
            weights = [0.3, 0.3, 0.4]  # Example weights for assignment, midterm, final_exam
            grades = self.calculate_grades_multithreaded(df, weights)
            self.display_grades(grades)
        except Exception as e:
            messagebox.showerror("Error", f"An error occurred: {e}")

    def display_grades(self, grades):
        self.text_display_grades.delete(1.0, tk.END)
        for name, grade in grades:
            self.text_display_grades.insert(tk.END, f"{name}: {grade}\n")

if __name__ == "__main__":
    root = tk.Tk()
    app = GradeCalculator(root)
    root.mainloop()



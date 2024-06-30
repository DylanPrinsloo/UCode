import tkinter as tk
from tkinter import messagebox
from PIL import Image, ImageTk
import json
import os
import re

# File where data will be stored
DATA_FILE = "students_data.json"

if not os.path.exists(DATA_FILE):
    with open(DATA_FILE, 'w') as file:
        json.dump({}, file)

# The file will be opened outside the Folder!

def load_image(image_path, target_height):
    image = Image.open(image_path)
    width, height = image.size
    new_width = int(width * (target_height / height))
    resized_image = image.resize((new_width, target_height), Image.Resampling.LANCZOS)
    return ImageTk.PhotoImage(resized_image)

def save_student_profile():
    raw_input = entry_input.get()
    
    pattern = r'^(.+),\s*(\d+),\s*(.+),\s*(\d\.\d+)$'
    match = re.match(pattern, raw_input)

    if not match:
        messagebox.showerror("Error", "Input must be in the format: Name, Student Number, Field of Study, GPA")
        return

    name, student_number, field_of_study, gpa = match.groups()

    try:
        gpa = float(gpa)
        if gpa < 0.0 or gpa > 4.0:
            raise ValueError
    except ValueError:
        messagebox.showerror("Error", "GPA must be a number between 0.0 and 4.0.")
        return

    student_profile = {
        "name": name,
        "student_number": student_number,
        "field_of_study": field_of_study,
        "gpa": gpa
    }

    with open(DATA_FILE, 'r') as file:
        data = json.load(file)

    data[student_number] = student_profile

    with open(DATA_FILE, 'w') as file:
        json.dump(data, file)

    messagebox.showinfo("Success", "Profile saved successfully!")
    entry_input.delete(0, tk.END)

def view_student_profile():
    name = entry_login_name.get()
    student_number = entry_login_student_number.get()

    if not name or not student_number:
        messagebox.showerror("Error", "Both name and student number are required.")
        return

    with open(DATA_FILE, 'r') as file:
        data = json.load(file)

    student_profile = data.get(student_number)

    if not student_profile or student_profile["name"] != name:
        messagebox.showerror("Error", "No matching profile found.")
        return

    profile_info = f"Name: {student_profile['name']}\n" \
                   f"Student Number: {student_profile['student_number']}\n" \
                   f"Field of Study: {student_profile['field_of_study']}\n" \
                   f"GPA: {student_profile['gpa']}"

    messagebox.showinfo("Student Profile", profile_info)

root = tk.Tk()
root.title("Student Portal")

root.geometry("1000x600")

image_path = "C:/University/University Files/class-coding/class-python/University-Code/ITAPA/Y2-B1/Exercises/STADPRIN-rocket-scientist.jpg"

img = load_image(image_path, 600)

left_frame = tk.Frame(root, width=500, height=600)
left_frame.pack(side="left", fill="y")

image_label = tk.Label(left_frame, image=img)
image_label.image = img  
image_label.pack(fill="both", expand=True)

right_frame = tk.Frame(root)
right_frame.pack(side="right", expand=True, fill="both")

tk.Label(right_frame, text="Create Profile").pack(pady=10)

tk.Label(right_frame, text="Enter details (Name, Student Number, Field of Study, GPA):").pack()
entry_input = tk.Entry(right_frame, width=80)
entry_input.pack(pady=5)

tk.Button(right_frame, text="Save Profile", command=save_student_profile).pack(pady=20)

tk.Label(right_frame, text="View Profile").pack(pady=10)

tk.Label(right_frame, text="Name:").pack()
entry_login_name = tk.Entry(right_frame, width=40)
entry_login_name.pack(pady=5)

tk.Label(right_frame, text="Student Number:").pack()
entry_login_student_number = tk.Entry(right_frame, width=40)
entry_login_student_number.pack(pady=5)

tk.Button(right_frame, text="View Profile", command=view_student_profile).pack(pady=20)

root.mainloop()
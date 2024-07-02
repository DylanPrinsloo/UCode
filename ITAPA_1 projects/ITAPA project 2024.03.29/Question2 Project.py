import tkinter as tk
from tkinter import ttk

def calculate_tax():
    try:
        monthly_inc = float(income_entry.get())
        tax_period = period_entry.get().lower()

        taxable_inc_brackets = [(1, 237100),(237101, 370500),(370501,512801),(512801,673000),(673001,857900),(857901,1817000),(1817001, float('inf'))]
        rates_of_tax = [0.18, 0.26, 0.31, 0.36, 0.39, 0.41, 0.45]

        tax = 0
        remain_inc = monthly_inc * 12 if tax_period == "yearly" else monthly_inc
        
        for bracket, rate in zip(taxable_inc_brackets, rates_of_tax):
            lower_bound, upper_bound = bracket
            if remain_inc <= 0:
                break
            if remain_inc > upper_bound:
                tax += (upper_bound - lower_bound) * rate
                remain_inc -= (upper_bound - lower_bound)
            else:
                tax += remain_inc * rate
                remain_inc = 0

        if tax_period == "yearly":
            result_label.config(text="Yearly Income tax: R{:.2f}".format(tax),foreground="black")
        else:
            result_label.config(text="Monthly Income tax: R{:.2f}".format(tax),foreground="black")
    except ValueError:
        result_label.config(text="Invalid input!", foreground="red")


root = tk.Tk()
root.title("Income Tax Calculator")

income_label = ttk.Label(root, text="Please insert your monthly salary(ZAR):")
income_label.grid(row=0, column=0, padx=5, pady=5, sticky="e")

income_entry = ttk.Entry(root)
income_entry.grid(row=0, column=1, padx=5, pady=5)

period_label = ttk.Label(root, text="Yearly/Monthly:")
period_label.grid(row=1, column=0, padx=5, pady=5, sticky="e")

period_entry = ttk.Entry(root)
period_entry.grid(row=1, column=1, padx=5, pady=5)

calculate_button = ttk.Button(root, text="Calculate income tax:", command=calculate_tax)
calculate_button.grid(row=2, column=0, columnspan=2, padx=5, pady=5)

result_label = ttk.Label(root, text="")
result_label.grid(row=3, column=0, columnspan=2, padx=5, pady=5)

root.mainloop()

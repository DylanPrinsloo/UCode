import unittest
import pandas as pd
from io import StringIO

# Assuming the following functions are imported from the main code
# from main_code import read_csv, convert_value, process_row, calculate_grades_multithreaded

class TestGradeCalculator(unittest.TestCase):

    def setUp(self):
        # Sample CSV data for testing
        self.csv_data = """name,assignment,midterm,final_exam
        John,85,90,88
        Jane,78,85,92
        Jim,89,94,84
        Jill,90,80,86"""
        
        # Read the CSV data into a DataFrame
        self.df = pd.read_csv(StringIO(self.csv_data))
        
        # Define weights for the assessments
        self.weights = [0.3, 0.3, 0.4]

    def test_convert_value(self):
        self.assertEqual(convert_value('85'), 85)
        self.assertEqual(convert_value('John'), 'John')
        self.assertEqual(convert_value('90.5'), '90.5')
        self.assertEqual(convert_value(''), '')

    def test_process_row(self):
        row = self.df.iloc[0]
        name, grade = process_row(row, self.weights)
        self.assertEqual(name, 'John')
        self.assertAlmostEqual(grade, 87.7, places=1)

    def test_calculate_grades_multithreaded(self):
        grades = calculate_grades_multithreaded(self.df, self.weights)
        expected_grades = [
            ('John', 87.7),
            ('Jane', 85.5),
            ('Jim', 88.0),
            ('Jill', 85.2)
        ]
        for (name, grade), (expected_name, expected_grade) in zip(grades, expected_grades):
            self.assertEqual(name, expected_name)
            self.assertAlmostEqual(grade, expected_grade, places=1)

if __name__ == '__main__':
    unittest.main()

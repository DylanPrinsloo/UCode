import unittest
import pandas as pd

class TestGradeCalculator(unittest.TestCase):

    def setUp(self):
        # Sample CSV data for testing
        self.csv_data = """
        Module Name,Quiz,Project,Final Exam,Practical
        Mathematics for Programming,85,90,78,82
        Python Programming,75,89,5,30
        Research Studies,100,80,65,90
        IT and Communication,22,88,55,80
        """
        # Read CSV data into a DataFrame

        self.df = pd.read_csv(self.csv_data)
        
        # Weights for the assessments , used other

        self.weights = [0.3, 0.3, 0.4]

    def test_convert_value(self,):
        self.assertEqual(convert_value('60'), 60)
        self.assertEqual(convert_value('Mathematics'), 'Mathematics')
        self.assertEqual(convert_value('60.5'), '60.5')
        self.assertEqual(convert_value(''), '')

    def test_process_row(self,):
        row = self.df.iloc[0]
        name, grade = process_row(row, self.weights)
        self.assertEqual(name, 'John')
        self.assertAlmostEqual(grade, 60.0, places=1)

    def test_calculate_grades_multithreaded(self):
        grades = calculate_grades_multithreaded(self.df, self.weights)
        expected_grades = [
            ('Mathematics', 60.0),
            ('Python Programming', 60.0),
            ('Tesearch studies', 60.0),
            ('IT and Communication', 60.0)
        ]
        for (name, grade), (expected_name, expected_grade) in zip(grades, expected_grades):
            self.assertEqual(name, expected_name)
            self.assertAlmostEqual(grade, expected_grade, places=1)

if __name__ == '__main__':
    unittest.main()

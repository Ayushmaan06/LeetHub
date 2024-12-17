import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    unique_students = courses.groupby('class')['student'].nunique().reset_index()
    
    # Rename the columns for clarity
    unique_students.columns = ['class', 'unique_student_count']

    unique_students=unique_students[unique_students['unique_student_count']>4]

    return unique_students[['class']]
import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    # Create all combinations of students and subjects
    all_combinations = pd.merge(students, subjects, how='cross')

    # Count the attended exams
    exam_counts = examinations.groupby(['student_id', 'subject_name']).size().reset_index(name='attended_exams')

    # Merge all combinations with the exam counts
    result = pd.merge(all_combinations, exam_counts, on=['student_id', 'subject_name'], how='left')
    
    # Fill missing values in the attended_exams column with 0
    result['attended_exams'] = result['attended_exams'].fillna(0).astype(int)
    
    # Select and reorder the columns
    result = result[['student_id', 'student_name', 'subject_name', 'attended_exams']]
    
    # Sort by student_id and subject_name
    result = result.sort_values(by=['student_id', 'subject_name']).reset_index(drop=True)
    
    return result

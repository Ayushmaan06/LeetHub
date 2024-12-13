import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    # Correct regex to match 'DIAB1' as a separate condition, accounting for spaces and delimiters
    filtered_patients = patients[patients['conditions'].str.contains(r'(^|\s)DIAB1\d*(\s|$)', na=False)]
    
    # Select relevant columns and maintain the result format
    result = filtered_patients[['patient_id', 'patient_name', 'conditions']]
    
    return result

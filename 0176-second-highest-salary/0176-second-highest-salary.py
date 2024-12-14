import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    unique_salaries = employee['salary'].drop_duplicates()

    sorted_salaries = unique_salaries.sort_values(ascending=False)
    if (2 > len(sorted_salaries)):
        return pd.DataFrame({'SecondHighestSalary': [None]})

    two=sorted_salaries.iloc[1]
    return pd.DataFrame({f'SecondHighestSalary': [two]})

    

 
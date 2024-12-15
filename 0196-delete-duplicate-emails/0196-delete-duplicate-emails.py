import pandas as pd

def delete_duplicate_emails(person: pd.DataFrame) -> None:
    # Sort by 'id' to ensure the smallest 'id' comes first for each email
    person.sort_values(by='id', inplace=True)
    # Drop duplicates based on 'email', keeping the first occurrence
    person.drop_duplicates(subset=['email'], inplace=True)
    # Reset index to maintain a clean DataFrame
    person.reset_index(drop=True, inplace=True)

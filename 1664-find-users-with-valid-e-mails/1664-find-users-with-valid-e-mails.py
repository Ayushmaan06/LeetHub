def is_valid_email(email: str) -> bool:
    # Define the regex pattern for a valid email
    pattern = r'^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\.com$'
    return re.match(pattern, email) is not None

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    # Filter rows where the email is valid
    valid_emails = users[users['mail'].apply(is_valid_email)]
    
    return valid_emails

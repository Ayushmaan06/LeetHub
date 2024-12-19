import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Check if 'RED' exists in the company table
    red_company = company[company['name'] == 'RED']
    
    if red_company.empty:
        # If no company named 'RED', return all salespersons
        return sales_person[['name']].sort_values(by='name').reset_index(drop=True)
    
    # Get the company ID for 'RED'
    red_company_id = red_company['com_id'].values[0]
    
    # Find salespersons who made orders with 'RED'
    sales_with_red_orders = orders[orders['com_id'] == red_company_id]['sales_id'].unique()
    
    # Exclude salespersons who made orders with 'RED'
    result = sales_person[~sales_person['sales_id'].isin(sales_with_red_orders)][['name']]
    
    # Sort the result by 'name'
    result = result.sort_values(by='name').reset_index(drop=True)
    
    return result

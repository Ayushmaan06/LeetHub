import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Rename columns in the orders table to match the customers table
    orders = orders.rename(columns={'id': 'order', 'customerId': 'id'})
    
    # Perform an outer join to find all customers, with and without orders
    df = pd.merge(customers, orders, on='id', how='outer')
    
    # Replace NaN values with 0
    df.fillna(0, inplace=True)
    
    # Filter customers who have no orders
    ez = df[df['order'] == 0]
    
    # Select only the 'name' column and rename it to 'Customers'
    ez = ez[['name']].rename(columns={'name': 'Customers'})
    
    return ez

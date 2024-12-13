import pandas as pd

def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    # Use the melt function to reshape the DataFrame
    reshaped_df = pd.melt(report, id_vars=['product'], var_name='quarter', value_name='sales')
    
    return reshaped_df

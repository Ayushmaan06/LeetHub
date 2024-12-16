import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Convert event_date to datetime
    activity['event_date'] = pd.to_datetime(activity['event_date'])
    
    # Group by player_id and get the minimum event_date
    df = activity.groupby('player_id', as_index=False)['event_date'].min()
    
    # Rename the column to first_login
    df.rename(columns={'event_date': 'first_login'}, inplace=True)
    
    return df
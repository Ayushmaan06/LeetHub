import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    # Filter rows where 'author_id' is equal to 'viewer_id'
    df = views[views['author_id'] == views['viewer_id']]
    
    # Select the 'author_id' column and drop duplicates
    df = df[['author_id']].drop_duplicates()

    df = df.rename(columns={'author_id': 'id'})
    
    return df.sort_values(by='id')
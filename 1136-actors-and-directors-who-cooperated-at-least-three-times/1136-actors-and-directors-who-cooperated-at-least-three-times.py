import pandas as pd

def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    collaboration_counts = actor_director.groupby(['actor_id', 'director_id']).size().reset_index(name='count')

    frequent_collaborations = collaboration_counts[collaboration_counts['count'] >= 3]

    result = frequent_collaborations[['actor_id', 'director_id']]
    
    return result
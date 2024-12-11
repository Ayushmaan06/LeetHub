import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    k=players['player_id'].count()
    l=players.size//k
    return[int(k),int(l)]
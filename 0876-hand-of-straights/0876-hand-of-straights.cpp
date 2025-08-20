class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        std::unordered_map<int, int> counts;
        for (int card : hand) counts[card]++;
        sort(hand.begin(), hand.end());
        for (int card : hand) {
            if (counts[card] == 0) continue;
            for (int i = 0; i < groupSize; i++) {
                int current_card = card + i;
                if (counts[current_card] == 0) {
                    return false;
                }
                counts[current_card]--;
            }
        }

        return true;
    }
};
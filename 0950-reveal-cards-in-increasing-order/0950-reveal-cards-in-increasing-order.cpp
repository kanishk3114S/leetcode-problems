class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> result(deck.size() , -1);
        sort(deck.begin() , deck.end());

        queue<int> q; // to simulate the 

        for (int i=0; i<deck.size(); i++) q.push(i);

        for (int i=0; i<deck.size(); i++) {

            result[q.front()] = deck[i];
            q.pop();

            if (!q.empty()) {
                int el = q.front();
                q.pop();
                q.push(el);
            }

        }

        return result;

    }
};
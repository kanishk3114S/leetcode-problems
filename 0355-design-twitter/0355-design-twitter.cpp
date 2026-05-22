class Twitter {
    unordered_map<int,set<int>> following;
    unordered_map<int,set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
unordered_map<int, set<pair<int,int>, greater<pair<int,int>>>> feed;    int t;
public:
    Twitter() {
        t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t , tweetId});
        feed[userId].insert({t , tweetId});
        for (auto it:followers[userId]) {

            feed[it].insert({t , tweetId});

        }
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        // if (!following.count(userId)) return result;
        int idx = 0;
        for (auto it:feed[userId]) {

            result.push_back(it.second);
            idx++;
            if (idx==10) break;

        }

        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        followers[followeeId].insert(followerId);
        for (auto it:tweets[followeeId]) {
        feed[followerId].insert(it);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase((followeeId));
        followers[followeeId].erase((followerId));
        for (auto it:tweets[followeeId]) {

            feed[followerId].erase(it);

        }

    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
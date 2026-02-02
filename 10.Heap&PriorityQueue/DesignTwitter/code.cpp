class Twitter {
private:
    int time;
    unordered_map<int , vector<pair<int , int>>> tweets;
    unordered_map<int , unordered_set<int>> following;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        following[userId].insert(userId);
        priority_queue<vector<int>> pq;

        for(int user : following[userId]){
            if(!tweets[user].empty()){
                int idx = tweets[user].size() - 1;
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        while(!pq.empty() && result.size() < 10){
        auto top = pq.top();
        pq.pop();

        int tweetTime = top[0];
        int tweetId = top[1];
        int user = top[2];
        int idx = top[3];

        result.push_back(tweetId);

        if(idx > 0){
            idx--;
            pq.push({
                tweets[user][idx].first,
                tweets[user][idx].second,
                user , 
                idx
            });
        }
      }

      return result;
    }

    
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if( followerId != followeeId)
            following[followerId].erase(followeeId);
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

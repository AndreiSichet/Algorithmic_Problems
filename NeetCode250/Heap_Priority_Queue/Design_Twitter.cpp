/*
Design Twitter:

Need 3 main data structures:

1. tweets
   map<userId, vector<pair<time, tweetId>>>

   Each user stores their tweets in chronological order.

2. following
   map<userId, unordered_set<userId>>

   Stores who each user follows.

3. max heap
   Used in getNewsFeed() to merge tweets from multiple users and always get the most recent tweet.

Each tweet stores:
    {time, tweetId}

postTweet():
    Add tweet to user's tweet list.
    Increase global timestamp.

follow():
    Add followee to follower's set.

unfollow():
    Remove followee from follower's set.

getNewsFeed():
    The user's feed contains:
        - their own tweets
        - tweets from everyone they follow

    Put the most recent tweet from each user into a max heap.

    Heap gives the most recent tweet.

    After taking a tweet:
        move to the previous tweet from that same user and put it into the heap.

    Repeat until we have 10 tweets.

Main idea:
    This is basically K-way merge using a max heap.

Example:

User 1:
    A B C

User 2:
    D E

User 3:
    F G

Instead of putting all tweets into the heap:

    Put only:
        C
        E
        G

    Take the newest one.

    If C came from user 1:
        add B

    If G came from user 3:
        add F

This keeps only the next possible tweet from each user.

Time:
    postTweet: O(1)
    follow: O(1) average
    unfollow: O(1) average
    getNewsFeed: O(F + 10 log F)

    F = number of users in the feed

Space:
    O(T + F)
    T = number of tweets
*/

class Twitter {
private:
    // userId -> people they follow
    unordered_map<int, unordered_set<int>> following;
    // userId -> {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;
    // Global time used to determine tweet order.
    int time = 0;
public:
    Twitter() {
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        /*
        Heap entry:

        {time, tweetId, userId, index}

        index tells us which tweet from that user we are currently looking at.
        */

        priority_queue<tuple<int, int, int, int>> maxHeap;
        // Add the user themself.
        vector<int> users;
        users.push_back(userId);
        // Add everyone the user follows.
        for (int followee : following[userId]) {
            if (followee != userId) {
                users.push_back(followee);
            }
        }
        // Put the newest tweet from every user
        // into the heap.
        for (int u : users) {
            if (!tweets[u].empty()) {
                int index = tweets[u].size() - 1;
                auto [tweetTime, tweetId] = tweets[u][index];
                maxHeap.push({tweetTime,tweetId,u,index});
            }
        }
        vector<int> result;
        // Get at most 10 newest tweets.
        while (!maxHeap.empty() && result.size() < 10) {
            auto [tweetTime, tweetId, user, index] = maxHeap.top();
            maxHeap.pop();
            result.push_back(tweetId);
            // Move to the previous tweet
            // from the same user.
            index--;
            if (index >= 0) {
                auto [nextTime, nextTweetId]= tweets[user][index];
                maxHeap.push({nextTime,nextTweetId,user,index});
            }
        }
        return result;
    }
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
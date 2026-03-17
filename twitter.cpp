#include <bits/stdc++.h>

using namespace std;

/*
     @description: class to implement a simple Twitter-like social media platform
 */
class Twitter
{
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time = 0;

    Twitter() { time = 0; }

    /**
     * @description: post a new tweet
     * @param: userId - ID of the user posting the tweet, tweetId - ID of the tweet
     * @return: void
     * @time complexity: O(1)
     * @space complexity: O(1)
     */
    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time++, tweetId});
    }

    /**
     * @description: get the news feed for a user
     * @param: userId - ID of the user
     * @return: vector of tweet IDs in the news feed
     * @time complexity: O(log k)
     * @space complexity: O(k)
     */
    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto t : tweets[userId])
        {
            pq.push(t);

            if (pq.size() > 10)
                pq.pop();
        }

        for (auto t : following[userId])
        {
            for (auto f : tweets[t])
            {
                pq.push(f);

                if (pq.size() > 10)
                    pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    /**
     * @description: follow a user
     * @param: followerId - ID of the user following, followeeId - ID of the user being followed
     * @return: void
     * @time complexity: O(1)
     * @space complexity: O(1)
     */
    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    /**
     * @description: unfollow a user
     * @param: followerId - ID of the user unfollowing, followeeId - ID of the user being unfollowed
     * @return: void
     * @time complexity: O(1)
     * @space complexity: O(1)
     */
    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};
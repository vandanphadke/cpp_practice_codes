/*
Given a url startUrl and an interface HtmlParser, implement a web crawler
to crawl all links that are under the same hostname as startUrl.

Return all urls obtained by your web crawler in any order.

Your crawler should:

Start from the page: startUrl
Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
Do not crawl the same link twice.
Explore only the links that are under the same hostname as startUrl.


As shown in the example url above, the hostname is example.org.
For simplicity sake, you may assume all urls use http protocol
without any port specified.
For example, the urls http://leetcode.com/problems
and http://leetcode.com/contest are under the same hostname,
while urls http://example.org/test and http://example.com/abc
are not under the same hostname.

The HtmlParser interface is defined as such:

interface HtmlParser {
  // Return a list of all urls from a webpage of given url.
  public List<String> getUrls(String url);
}
Below are two examples explaining the functionality of the problem,
for custom testing purposes you'll have three variables urls, edges and startUrl.
Notice that you will only have access to startUrl in your code, while urls and
edges are not directly accessible to you in code.

Example 1:



Input:
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com",
  "http://news.yahoo.com/us"
]
edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
startUrl = "http://news.yahoo.com/news/topics/"
Output: [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.yahoo.com/us"
]
Example 2:



Input:
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com"
]
edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
startUrl = "http://news.google.com"
Output: ["http://news.google.com"]
Explanation: The startUrl links to all other pages that do not share the same hostname.
*/

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
private:
    unordered_set<string> parsedLinks;
    vector<string> result;

    bool checkSameSubstring(string a, string b) {
        string subA = a.substr(7);
        string subB = b.substr(7);

        size_t foundA = subA.find("/");
        size_t foundB = subB.find("/");

        return (subA.substr(0, foundA) == subB.substr(0, foundB));

    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        crawlWebsitesBfs(startUrl, htmlParser);
        return result;
    }

    void crawlWebsitesBfs(string startUrl, HtmlParser htmlParser) {
        queue<string> bfsQueue;
        bfsQueue.push(startUrl);
        parsedLinks.emplace(startUrl);
        result.emplace_back(startUrl);

        while (!bfsQueue.empty()) {
            string currentUrl = bfsQueue.front();
            bfsQueue.pop();
            for (string connection: htmlParser.getUrls(currentUrl)) {
                if (parsedLinks.find(connection) == parsedLinks.end() &&
                    (checkSameSubstring(currentUrl, connection))) {
                    parsedLinks.emplace(connection);
                    bfsQueue.push(connection);
                    result.emplace_back(connection);
                }
            }
        }
    }
};

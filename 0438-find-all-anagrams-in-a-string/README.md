# [Find All Anagrams in a String] - Medium

**Tags:** Hash Table, String, Sliding Window

[LeetCode Problem Link](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

---

Given two strings s and p, return an array of all the start indices of p&#39;s anagrams in s. You may return the answer in any order.

&nbsp;
Example 1:


Input: s = &quot;cbaebabacd&quot;, p = &quot;abc&quot;
Output: [0,6]
Explanation:
The substring with start index = 0 is &quot;cba&quot;, which is an anagram of &quot;abc&quot;.
The substring with start index = 6 is &quot;bac&quot;, which is an anagram of &quot;abc&quot;.


Example 2:


Input: s = &quot;abab&quot;, p = &quot;ab&quot;
Output: [0,1,2]
Explanation:
The substring with start index = 0 is &quot;ab&quot;, which is an anagram of &quot;ab&quot;.
The substring with start index = 1 is &quot;ba&quot;, which is an anagram of &quot;ab&quot;.
The substring with start index = 2 is &quot;ab&quot;, which is an anagram of &quot;ab&quot;.


&nbsp;
Constraints:


	1 &lt;= s.length, p.length &lt;= 3 * 104
	s and p consist of lowercase English letters.



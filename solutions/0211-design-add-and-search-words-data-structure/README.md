# [Design Add and Search Words Data Structure] - Medium

**Tags:** String, Depth-First Search, Design, Trie

[LeetCode Problem Link](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

---

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:


	WordDictionary()&nbsp;Initializes the object.
	void addWord(word) Adds word to the data structure, it can be matched later.
	bool search(word)&nbsp;Returns true if there is any string in the data structure that matches word&nbsp;or false otherwise. word may contain dots &#39;.&#39; where dots can be matched with any letter.


&nbsp;
Example:


Input
[&quot;WordDictionary&quot;,&quot;addWord&quot;,&quot;addWord&quot;,&quot;addWord&quot;,&quot;search&quot;,&quot;search&quot;,&quot;search&quot;,&quot;search&quot;]
[[],[&quot;bad&quot;],[&quot;dad&quot;],[&quot;mad&quot;],[&quot;pad&quot;],[&quot;bad&quot;],[&quot;.ad&quot;],[&quot;b..&quot;]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord(&quot;bad&quot;);
wordDictionary.addWord(&quot;dad&quot;);
wordDictionary.addWord(&quot;mad&quot;);
wordDictionary.search(&quot;pad&quot;); // return False
wordDictionary.search(&quot;bad&quot;); // return True
wordDictionary.search(&quot;.ad&quot;); // return True
wordDictionary.search(&quot;b..&quot;); // return True


&nbsp;
Constraints:


	1 &lt;= word.length &lt;= 25
	word in addWord consists of lowercase English letters.
	word in search consist of &#39;.&#39; or lowercase English letters.
	There will be at most 2 dots in word for search queries.
	At most 104 calls will be made to addWord and search.



# [Implement Magic Dictionary] - Medium

**Tags:** Hash Table, String, Depth-First Search, Design, Trie

[LeetCode Problem Link](https://leetcode.com/problems/implement-magic-dictionary/)

---

Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.

Implement the&nbsp;MagicDictionary&nbsp;class:


	MagicDictionary()&nbsp;Initializes the object.
	void buildDict(String[]&nbsp;dictionary)&nbsp;Sets the data structure&nbsp;with an array of distinct strings dictionary.
	bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.


&nbsp;
Example 1:


Input
[&quot;MagicDictionary&quot;, &quot;buildDict&quot;, &quot;search&quot;, &quot;search&quot;, &quot;search&quot;, &quot;search&quot;]
[[], [[&quot;hello&quot;, &quot;leetcode&quot;]], [&quot;hello&quot;], [&quot;hhllo&quot;], [&quot;hell&quot;], [&quot;leetcoded&quot;]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict([&quot;hello&quot;, &quot;leetcode&quot;]);
magicDictionary.search(&quot;hello&quot;); // return False
magicDictionary.search(&quot;hhllo&quot;); // We can change the second &#39;h&#39; to &#39;e&#39; to match &quot;hello&quot; so we return True
magicDictionary.search(&quot;hell&quot;); // return False
magicDictionary.search(&quot;leetcoded&quot;); // return False


&nbsp;
Constraints:


	1 &lt;=&nbsp;dictionary.length &lt;= 100
	1 &lt;=&nbsp;dictionary[i].length &lt;= 100
	dictionary[i] consists of only lower-case English letters.
	All the strings in&nbsp;dictionary&nbsp;are distinct.
	1 &lt;=&nbsp;searchWord.length &lt;= 100
	searchWord&nbsp;consists of only lower-case English letters.
	buildDict&nbsp;will be called only once before search.
	At most 100 calls will be made to search.



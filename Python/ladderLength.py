import string
class Solution:
    def bfs(self,beginWord,endWord,word_dict):
        queue = []
        queue.append([beginWord,1])
        while queue:
            word,step = queue[0][0],queue[0][1]
            queue.pop(0)
            if word == endWord:
                return step
            nextwords = self.getNewWords(word,word_dict)
            for nextword in nextwords:
                queue.append([nextword,step+1])
        return 0

    def getNewWords(self,word,word_dict):
        res_list = []
        for i in range(len(word)):
            for j in string.ascii_lowercase:
                new_word = list(word) #转成列表，不然无法赋值
                if j != word[i]:
                    new_word[i] = j
                    new_word = ''.join(new_word) #组合成字符串
                    if new_word in word_dict:
                        res_list.append(new_word)
                        del word_dict[new_word]
        return res_list

    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        if beginWord in wordList:
            wordList.remove(beginWord)
        word_dict = {}
        for w in wordList:
            word_dict[w] = 1
        return self.bfs(beginWord,endWord,word_dict)




solution = Solution()
beginWord = 'hit'
endWord = 'cog'
wordList =  ["hot","dot","dog","lot","log"]

print(solution.ladderLength(beginWord,endWord,wordList))

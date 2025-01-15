from collections import Counter

def isSimilar(word1, word2):
    count1 = Counter(word1)
    count2 = Counter(word2)

    if abs(len(word1)-len(word2)) > 1:
        return False 
    
    if(count1 == count2):
            return True
    
    diff1 = sum((count1 - count2).values())
    diff2 = sum((count2 - count1).values())
    
    if (len(word1)==len(word2)):
         if diff1 == 1 and diff2 ==1:
             return True
    elif (len(word1)>len(word2)):
         if diff1 == 1 and diff2 ==0:
             return True
    elif (len(word1)<len(word2)):
         if diff1 == 0 and diff2 ==1:
             return True
    return False
    
n = int(input())
first_word = input()
count = 0

for i in range(n - 1):
    word = input()
    if isSimilar(first_word, word):
        count += 1

print(count)

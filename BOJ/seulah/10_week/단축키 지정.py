N = int(input())
words = [input() for _ in range(N)]
shortkey = []
result = []

for word in words:
    multi_words = word.split()

    for i in range(len(multi_words)):
        if multi_words[i][0].lower() not in shortkey:
            shortkey.append(multi_words[i][0].lower())
            multi_words[i] = "[" + multi_words[i][0] + "]" + multi_words[i][1:]
            break
    else:
        for i in range(len(multi_words)):
            for j in range(len(multi_words[i])):
                if multi_words[i][j].lower() not in shortkey:
                    shortkey.append(multi_words[i][j].lower())
                    multi_words[i] = multi_words[i][:j] + "[" + multi_words[i][j] + "]" + multi_words[i][j+1:]
                    break
            else:
                continue
            break

    result.append(' '.join(multi_words))

for r in result:
    print(r)

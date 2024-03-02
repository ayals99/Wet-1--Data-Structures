def wtc(word):
    w = ""
    count = 0
    word = word.strip()
    for i in range(len(word)):
        if(word[i] != " "):
            w+=word[i] 
        else:
            if(count == 0):
                w+="("
                count+=1
            elif(word[i-1] !=" "): 
                w+=","
            
    w+=");"
    return w


with open("newTest.in", "r") as f:
    with open("K.txt", "w") as o:
        o.write("Olympics *olim= new Olympics();\n")
        for line in f:
            o.write("olim->")
            o.write(wtc(line))
            o.write("\n")
filename = input()

f = open(filename,'r')

for i in f:
    i=i.strip("\n")        
    i="\""+i+"\","
    print(i)
f.close()


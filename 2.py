

l = []
n = int(input("enter the number of elements:"))
for i in range(0,n):
	temp = input("enter the string:")
	l.append(temp)

for i in range(0,len(l)):
	if len(l[i])==4:
		print(l[i])

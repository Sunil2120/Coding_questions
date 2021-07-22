result = True
score = 1.0
message = '\n'
    
X = 0
Y = 0
    
RES = 0

testcase_input_path = 'impetus_sack_test_case.txt'
testcase_output_path = 'first_output.txt';
    
try:
	fout = open(testcase_output_path, 'r')
	fin = open(testcase_input_path, 'r')
            
except IOError:
	result = False
	score = 0
	message = 'Wrong output format'
        
try:
	T = int(fin.readline())

	for i in range(T):
		N, M = map(int, fin.readline().split())
		A = list(map(int, fin.readline().split()))

		K = int(fout.readline())
		B = set(map(int, fout.readline().split()))
		B = list(B)

		if len(B) != K:
			result = False
			score = 0
			message = 'Test case '
			message += str(i)
			message += ': Wrong output format in list of indices\n'
			continue

		SS = 0

		for j in range(0, K):
			SS += A[B[j]-1]

		if SS > M:
			SS = 0

		message += 'Score for test case '
		message += str(i)
		message += ': '
		message += str(SS)
		message += '\n'

		RES += ((SS**2)/(M**2))
        
except IOError:
	result = False
	score = 0
	message = 'Wrong output format'
    
except ValueError:
	result = False
	score = 0
	message = 'Wrong output format'

score = RES/3
score *= 100
score -= score%(0.1)

print(message)
print('Final score =', score)
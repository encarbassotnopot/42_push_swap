import sys

if len(sys.argv) < 2:
	print("Error, not enough arguments")

a = {'content': [int(sys.argv[i])
				 for i in range(1, len(sys.argv))],
	 'name': 'a'}
b = {'content': [], 'name': 'b'}

def swap(stack):
	print (f's{stack["name"]}')
	stack['content'][0], stack['content'][1] = stack['content'][1], stack['content'][0]
	#print(stack['content'])

def rotate(stack):
	if len(stack['content']) < 2:
		return
	print (f'r{stack["name"]}')
	stack['content'].append(stack['content'].pop(0))
	#print(stack['content'])

def rev_rotate(stack):
	if len(stack['content']) < 2:
		return
	print (f'rr{stack["name"]}')
	stack['content'].insert(0, stack['content'].pop())
	#print(stack['content'])

def push(orig, dest):
	print (f'p{dest["name"]}')
	dest['content'].insert(0, orig['content'].pop(0))
	#print(dest['content'])

sorted = False
first_el = None
	

while (a['content'][-1] < a['content'][0]):
	rev_rotate(a)

print(a['content'])

def split_a():
	i = 0
	while (i < len(a['content'])):
		rotate(a)
		i+=1
	
		if a['content'][i] > a['content'][i+1]:
			rotate(a)
			break

def split_b():
	i = 0
	while (i < len(a['content'])):
		push(a, b)
		rotate(b)
		i+=1
		if a['content'][i] > a['content'][i+1]:
			push(a, b)
			rotate(b)
			break

first_el = a['content'][0]
while not sorted:
	split_a()
	if first_el == a['content'][0]:
		break
	print(a['content'])
	print(b['content'])
	split_b()
	if first_el == a['content'][0]:
		break
	print(a['content'])
	print(b['content'])

print(a['content'])
print(b['content'])

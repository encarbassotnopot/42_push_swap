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
    if orig == dest:
        return
    print (f'p{dest["name"]}')
    dest['content'].insert(0, orig['content'].pop(0))
    #print(dest['content'])

sorted = False
first_el = None
    

while (a['content'][-1] < a['content'][0]):
    rotate(a)

def split_a():
    i = 0
    breakNext = False
    while (i < len(a['content'])):
        rotate(a)
        if breakNext:
            break
        if a['content'][i] > a['content'][i+1]:
            breakNext = True
        i+=1

def split_b():
    i = 0
    breakNext = False
    while (i < len(a['content']) - 1):
        push(a, b)
        rotate(b)
        if breakNext:
            break
        if a['content'][i] > a['content'][i+1]:
            breakNext = True
        i+=1

def split():
    first_el = a['content'][0]
    while not sorted:
        print(a['content'])
        print(b['content'])
        split_a()
        if first_el == a['content'][0]:
            break
        print(a['content'])
        print(b['content'])
        split_b()
        if first_el == a['content'][0]:
            break

def merge():
    first_el = a['content'][0]
    while len(b['content']) > 0:
        if a['content'][0] < b['content'][0]:
            push(b, a)
        rotate(a)
        if first_el == a['content'][0]:
            while len(b['content']) > 0:
                push(b, a)
                rotate(b)
             

def sort():
    sorted = all(a['content'][i] <= a['content'][i+1] for i in range(len(a['content'])-1))
    while not sorted:
        split()
        merge()
        sorted = all(a['content'][i] <= a['content'][i+1] for i in range(len(a['content'])-1))



sort()
print(a['content'])
print(b['content'])

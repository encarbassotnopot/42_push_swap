def swap(stack):
    #print (f's{stack["name"]}')
    stack['content'][0], stack['content'][1] = stack['content'][1], stack['content'][0]

def rotate(stack):
    if len(stack['content']) < 2:
        return
    #print (f'r{stack["name"]}')
    stack['content'].append(stack['content'].pop(0))

def rev_rotate(stack):
    if len(stack['content']) < 2:
        return
    #print (f'rr{stack["name"]}')
    stack['content'].insert(0, stack['content'].pop())

def push(orig, dest):
    if orig == dest:
        return
    if len(orig['content']) < 1:
        return
    #print (f'p{dest["name"]}')
    dest['content'].insert(0, orig['content'].pop(0))

def get_run_end(stack):
    if len(stack['content']) == 0:
        return None
    i = 0
    while (i < len(stack['content'])):
        if i + 1 == len(stack['content']):
            break
        elif stack['content'][i] < stack['content'][i+1]:
            i += 1
        else:
            break
    return(stack['content'][i])

def get_run_len(stack, i = 0):
    if len(stack['content']) == 0:
        return None
    while (i < len(stack['content'])):
        if i + 1 == len(stack['content']):
            break
        elif stack['content'][i] < stack['content'][i+1]:
            i += 1
        else:
            break
    return(i+1)

def get_run_count(stack):
    if len(stack['content']) == 0:
        return None
    count = 0
    i = 0
    while (i < len(stack['content'])):
        i = get_run_len(stack, i)
        count += 1
    return(count)

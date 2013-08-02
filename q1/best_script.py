with open('numbers.txt') as n, open('run_result.txt', 'w') as r:
    for i in set(range(10000)) - {int(i) for i in n}:
        r.write('{:04d}\n'.format(i))

from collections import Counter
with open('numbers.txt') as n, open('run_result.txt', 'w') as r:
    for k, v in Counter(n.readlines()).iteritems():
        if v > 1:
            r.write('"{}", {}\n'.format(k.strip(), v))
